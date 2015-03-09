// ClasherSM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "src\StateMachine.h"
#include <memory>
#include "src\Task.h"


int _tmain(int argc, _TCHAR* argv[])
{

	csm::StateMachine sm;

	auto retreat = std::make_shared<csm::Task>("retreat");
	auto retreating = std::make_shared<csm::State>("retreating", retreat);
	sm.add(retreating);
	
	auto disappear = std::make_shared<csm::Task>("disappear");
	auto disappearing = std::make_shared<csm::State>("disappearing", disappear);
	sm.add(disappearing);

	auto ifRetreatSuccess = std::make_shared<csm::Condition>();
	sm.from(retreating, ifRetreatSuccess, disappearing);
	

	auto death = std::make_shared<csm::Task>("death");
	auto dying = std::make_shared<csm::State>("dying", death);
	auto ifLowHp = std::make_shared<csm::Condition>();
	sm.addFromAny(ifLowHp, dying);

	sm.hardSetState(retreating);

	sm.process(16);
	sm.process(16);

	return 0;
}

