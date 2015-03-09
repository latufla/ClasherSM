#pragma once
#include <string>
#include "TaskBlackboard.h"
#include <memory>

namespace csm {
	class Task {
	public:
		Task(std::string name, std::shared_ptr<TaskBlackboard> blackboard);
		virtual ~Task();

		virtual bool process(long long step);

	protected:
		std::string name;

		std::shared_ptr<TaskBlackboard> blackboard;
	};
}

