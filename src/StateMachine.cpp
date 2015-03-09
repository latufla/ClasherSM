#include "StateMachine.h"


namespace csm {
	StateMachine::StateMachine() {
		fromAny = std::make_shared<StateData>();
	}


	StateMachine::~StateMachine() {
	}

	void StateMachine::add(std::shared_ptr<State> state) {
		auto data = std::make_shared<StateData>();
		allStates.emplace(state, data);
	}

	void StateMachine::from(std::shared_ptr<State> state, std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState) {
		auto data = allStates.at(state);
		data->conditionToStateList.push_back({withCondition, toState});
	}


	void StateMachine::addFromAny(std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState) {
		add(toState);
		fromAny->conditionToStateList.push_back({withCondition, toState});
	}


	void StateMachine::process(long long step) {
		if(fromAny) {
			for(auto i : fromAny->conditionToStateList) {
				auto condition = i.first;
				auto toState = i.second;
				if(condition->process(step)) {
					state = toState;
					break;
				}
			}
		}
		findNextState(step);
		state->process(step);
	}

	void StateMachine::findNextState(long long step) {
		auto stateData = allStates.at(state);
		for(auto i : stateData->conditionToStateList) {
			auto condition = i.first;
			auto toState = i.second;
			if(condition->process(step)) {
				state = toState;
				findNextState(step);
				return;
			}
		}		
	}


	void StateMachine::hardSetState(std::shared_ptr<State> state) {
		this->state = state;
	}
}
