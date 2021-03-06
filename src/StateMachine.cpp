#include "StateMachine.h"


namespace csm {
	StateMachine::StateMachine() {
	}


	StateMachine::~StateMachine() {
	}

	void StateMachine::add(std::shared_ptr<State> state) {
		allStates.push_back(state);
	}

	void StateMachine::from(std::shared_ptr<State> state, std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState) {
		state->link(withCondition, toState);
	}
	
	void StateMachine::addFromAny(std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState) {
		add(toState);
		fromAny.emplace(withCondition, toState);
	}


	void StateMachine::process(long long step) {
		for(auto i : fromAny) {
			auto condition = i.first;
			std::shared_ptr<TaskBlackboard> blackboard; // waste, from any has no blackboard
			if(condition->process(blackboard, step)) {
				state->clear();
				state = i.second;
				break;
			}
		}
		findNextState(step);
		state->process(step);
	}

	void StateMachine::findNextState(long long step) {
		auto links = state->getLinks();
		for(auto i : links) {
			auto condition = i.first;
			auto blackboard = state->getBlackboard();
			if(condition->process(blackboard, step)) {
				state->clear();
				state = i.second;
				findNextState(step);
				return;
			}
		}		
	}


	void StateMachine::hardSetState(std::shared_ptr<State> state) {
		this->state = state;
	}
}
