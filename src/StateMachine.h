#pragma once
#include <memory>
#include "State.h"
#include <unordered_map>

namespace csm {
	class StateMachine {
	public:
		StateMachine();
		~StateMachine();
	
		virtual void add(std::shared_ptr<State> state);
		virtual void from(std::shared_ptr<State> state, std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState);
		
		virtual void addFromAny(std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState);

		virtual void process(long long step);

		virtual void hardSetState(std::shared_ptr<State> state);

	protected:
		virtual void findNextState(long long step);

		std::vector<std::shared_ptr<State>> allStates;
		std::shared_ptr<State> state;

		std::unordered_map<std::shared_ptr<Condition>, std::shared_ptr<State>> fromAny;
	};
}

