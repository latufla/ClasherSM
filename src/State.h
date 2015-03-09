#pragma once
#include <string>
#include "Task.h"
#include <memory>
#include <vector>
#include "Condition.h"
#include <unordered_map>

namespace csm {
	class State {
	public:
		State(std::string name, std::shared_ptr<Task> task);
		virtual ~State();

		virtual bool process(long long step);
	
		virtual void link(std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState);
		
		typedef std::unordered_map<std::shared_ptr<Condition>, std::shared_ptr<State>> ConditionToStateMap;
		ConditionToStateMap const& getLinks() const { return links; }

	protected:
		std::string name;
		std::shared_ptr<Task> task;

		ConditionToStateMap links;
	};
}

