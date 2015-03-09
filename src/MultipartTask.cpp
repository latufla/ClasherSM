#include "MultipartTask.h"


namespace csm {
	MultipartTask::MultipartTask(std::string name, std::vector<std::shared_ptr<Task>> const& subTasks)
		: Task(name), subTasks(subTasks) {
	}

	MultipartTask::~MultipartTask() {
	}

	bool MultipartTask::process(long long step) {
		bool res = true;
		for(auto i : subTasks) {
			bool subRes = i->process(step);
			res = res && subRes;
		}
		return res;
	}
}
