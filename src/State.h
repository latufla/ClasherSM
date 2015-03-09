#pragma once
#include <string>
#include "Task.h"
#include <memory>
#include <vector>
#include "Condition.h"

namespace csm {
	class State {
	public:
		State(std::string name, std::shared_ptr<Task> task);
		virtual ~State();

		virtual bool process(long long step);
	
	protected:
		std::string name;
		std::shared_ptr<Task> task;
	};
}

