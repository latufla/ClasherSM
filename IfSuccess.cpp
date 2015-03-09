#include "IfSuccess.h"


namespace csm {
	IfSuccess::IfSuccess() {
	}


	IfSuccess::~IfSuccess() {
	}

	bool IfSuccess::process(std::shared_ptr<TaskBlackboard> blackboard, long long step) {
		return blackboard->getSuccess();
	}

}
