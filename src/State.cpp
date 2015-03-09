#include "State.h"


namespace csm {
	State::State(std::string name, std::shared_ptr<Task> task)
		: name(name), task(task){
	}

	State::~State() {
	}

	bool State::process(long long step) {
		return task->process(step);
	}

	void State::link(std::shared_ptr<Condition> withCondition, std::shared_ptr<State> toState) {
		links.emplace(withCondition, toState);
	}

}
