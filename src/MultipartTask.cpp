#include "MultipartTask.h"


namespace csm {
	MultipartTask::MultipartTask(std::string name, std::shared_ptr<TaskBlackboard> blackboard, std::vector<std::shared_ptr<Task>> const& subTasks)
		: Task(name, blackboard), subTasks(subTasks) {
	}

	MultipartTask::~MultipartTask() {
	}

	// Liski dying
	bool MultipartTask::process(long long step) {
		bool res = true;
		for(auto i : subTasks) {
			bool subRes = i->process(step);
			res = res && subRes;
		}
		blackboard->setSuccess(res);
		return res;
	}
}
