// ClasherSM.cpp : Defines the entry point for the console application.
//

#include "src\StateMachine.h"
#include <memory>
#include "src\Task.h"
#include "src\MultipartTask.h"
#include <vector>
#include "src\TaskBlackboard.h"
#include "IfSuccess.h"
#include <tchar.h>

// TODO: Factory
std::shared_ptr<csm::MultipartTask> createRetreat();
std::shared_ptr<csm::Task> createDissapear();
std::shared_ptr<csm::Task> createDeath();
//

int _tmain(int argc, _TCHAR* argv[])
{
	csm::StateMachine sm;
	
	auto retreat = createRetreat();
	auto retreating = std::make_shared<csm::State>("retreating", retreat);
	sm.add(retreating);
	
	auto disappear = createDissapear();
	auto disappearing = std::make_shared<csm::State>("disappearing", disappear);
	sm.add(disappearing);

	auto ifRetreatSuccess = std::make_shared<csm::IfSuccess>();
	sm.from(retreating, ifRetreatSuccess, disappearing);	

	auto death = createDeath();
	auto dying = std::make_shared<csm::State>("dying", death);
	auto ifLowHp = std::make_shared<csm::Condition>();
	//sm.addFromAny(ifLowHp, dying);

	sm.hardSetState(retreating);

	sm.process(16);
	sm.process(16);

	return 0;
}

std::shared_ptr<csm::MultipartTask> createRetreat() {
	auto blackboard = std::make_shared<csm::TaskBlackboard>();
	auto searchTarget = std::make_shared<csm::Task>("searchTarget", blackboard);
	auto searchPath = std::make_shared<csm::Task>("searchPath", blackboard);
	auto moveByPath = std::make_shared<csm::Task>("moveByPath", blackboard);
	std::vector<std::shared_ptr<csm::Task>> subTasks{searchTarget, searchPath, moveByPath};
	auto res = std::make_shared<csm::MultipartTask>("retreat", blackboard, subTasks);
	return res;
}

std::shared_ptr<csm::Task> createDissapear() {
	auto blackboard = std::make_shared<csm::TaskBlackboard>();
	auto disappear = std::make_shared<csm::Task>("disappearSub", blackboard);
	std::vector<std::shared_ptr<csm::Task>> subTasks{disappear};
	auto res = std::make_shared<csm::MultipartTask>("disappear", blackboard, subTasks); // we have only one sub task but whatever
	return res;
}

std::shared_ptr<csm::Task> createDeath() {
	auto blackboard = std::make_shared<csm::TaskBlackboard>();
	auto disappear = std::make_shared<csm::Task>("deathSub", blackboard);
	std::vector<std::shared_ptr<csm::Task>> subTasks{disappear};
	auto res = std::make_shared<csm::MultipartTask>("death", blackboard, subTasks);
	return res;
}
