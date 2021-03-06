/*
 * Copyright 2018 Aman Mehara
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "greedy_iterative_activity_selector.h"

#include <algorithm>
#include <vector>

#include "activity.h"

std::vector<Activity> GreedyIterativeActivitySelector::select() {

	std::sort(activities_.begin(), activities_.end(), [](Activity& a1, Activity& a2) {
		return a1.FinishTime() < a2.FinishTime();
	});

	std::vector<Activity> selected_activities;

	if (activities_.empty()) {
		return selected_activities;
	}

	selected_activities.push_back(activities_[0]);
	int last_selected_activity_index = 0;

	for (int index = 1; index < activities_.size(); index++) {
		if (activities_[last_selected_activity_index].FinishTime() <= activities_[index].StartTime()) {
			selected_activities.push_back(activities_[index]);
			last_selected_activity_index = index;
		}
	}

	return selected_activities;

}