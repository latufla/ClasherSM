#include "Task.h"


namespace csm {
	Task::Task(std::string name) 
		: name(name) {
	}

	Task::~Task() {
	}

	bool Task::process(long long step) {
		return true;
	}

}
