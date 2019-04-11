/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/planning/planner/dummy_planner/dummy_planner.h"

#include <utility>

//included for adding adebug 
#include "cyber/common/log.h"
#include "modules/common/util/string_tokenizer.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::TrajectoryPoint;

DummyPlanner::DummyPlanner() {

    ADEBUG << "DEBUG_SVS : Constructor of Dummy Planner";
  
}

Status DummyPlanner::Init(const PlanningConfig&) { 
    ADEBUG << "DEBUG_SVS : Init of Dummy Planner";

    return Status::OK(); }

Status DummyPlanner::Plan(const TrajectoryPoint& planning_start_point,
                              Frame* frame,
                              ADCTrajectory* ptr_computed_trajectory) {
  auto status = Status::OK();
  return status;
}

Status DummyPlanner::PlanOnReferenceLine(
    const TrajectoryPoint& planning_init_point, Frame*,
    ReferenceLineInfo* reference_line_info) {
    return Status::OK();
}


}  // namespace planning
}  // namespace apollo
