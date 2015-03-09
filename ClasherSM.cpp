// ClasherSM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "src\StateMachine.h"
#include <memory>
#include "src\Task.h"
#include "src\MultipartTask.h"
#include <vector>

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

	auto ifRetreatSuccess = std::make_shared<csm::Condition>();
	sm.from(retreating, ifRetreatSuccess, disappearing);	

	auto death = createDeath();
	auto dying = std::make_shared<csm::State>("dying", death);
	auto ifLowHp = std::make_shared<csm::Condition>();
	sm.addFromAny(ifLowHp, dying);

	sm.hardSetState(retreating);

	sm.process(16);
	sm.process(16);

	return 0;
}

std::shared_ptr<csm::MultipartTask> createRetreat() {
	auto searchTarget = std::make_shared<csm::Task>("searchTarget");
	auto searchPath = std::make_shared<csm::Task>("searchPath");
	auto moveByPath = std::make_shared<csm::Task>("moveByPath");
	std::vector<std::shared_ptr<csm::Task>> subTasks{searchTarget, searchPath, moveByPath};
	auto res = std::make_shared<csm::MultipartTask>("retreat", subTasks);
	return res;
}

std::shared_ptr<csm::Task> createDissapear() {
	auto res = std::make_shared<csm::Task>("disappear");
	return res;
}

std::shared_ptr<csm::Task> createDeath(){
	auto res = std::make_shared<csm::Task>("death");
	return res;
}
