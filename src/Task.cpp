#include "Task.h"


namespace csm {
	Task::Task(std::string name, std::shared_ptr<TaskBlackboard> blackboard)
		: name(name), blackboard(blackboard) {
	}

	Task::~Task() {
	}

	bool Task::process(long long step) {
		return true;
	}

	std::shared_ptr<TaskBlackboard> Task::getBlackboard() const {
		return blackboard;
	}

}
