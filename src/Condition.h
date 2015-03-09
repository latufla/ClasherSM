#pragma once
#include <string>
#include <memory>
#include "TaskBlackboard.h"

namespace csm {
	class Condition {
	public:
		Condition();
		virtual ~Condition();
	
		virtual bool process(std::shared_ptr<TaskBlackboard> blackboard, long long step);
	protected:
		std::string name = "condition";
	};
}

