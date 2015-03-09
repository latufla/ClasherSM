#include "TaskBlackboard.h"


namespace csm {
	TaskBlackboard::TaskBlackboard() {
	}

	TaskBlackboard::~TaskBlackboard() {
	}

	void TaskBlackboard::setSuccess(bool val) {
		success = val;
	}

	bool TaskBlackboard::getSuccess() const {
		return success;
	}

	void TaskBlackboard::clear() {
		success = false;
	}

}
