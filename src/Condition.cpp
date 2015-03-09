#include "Condition.h"


namespace csm {
	Condition::Condition() {
	}


	Condition::~Condition() {
	}

	bool Condition::process(std::shared_ptr<TaskBlackboard> blackboard, long long step) {
		return step;
	}
}
