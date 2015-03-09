#pragma once
#include "src\Condition.h"

namespace csm {
	class IfSuccess : public Condition{
	public:
		IfSuccess();
		~IfSuccess();

		virtual bool process(std::shared_ptr<TaskBlackboard> blackboard, long long step) override;

	};
}

