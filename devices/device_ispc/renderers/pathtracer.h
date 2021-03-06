// ======================================================================== //
// Copyright 2009-2013 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "api/parms.h"
#include "pathtracer_ispc.h"

namespace embree
{
  struct PathTracer
  {
    static void* create(const Parms& parms)
    {
      const int maxDepth = parms.getInt("maxDepth",10);
      const float minContribution = parms.getFloat("minContribution",0.01f);
      const float epsilon = parms.getFloat("epsilon",32.0f)*float(ulp);
      const int spp = max(1,parms.getInt("sampler.spp",1));
      const int sampleLightForGlossy = parms.getInt("sampleLightForGlossy",0);
      ISPCRef backplate = parms.getImage("backplate");
      return ispc::PathTracer__new(maxDepth,minContribution,epsilon,spp,backplate.ptr,sampleLightForGlossy);
    }
  };
}

