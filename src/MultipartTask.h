#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Task.h"

namespace csm {
	class MultipartTask : public Task{
	public:
		MultipartTask(std::string name, std::vector<std::shared_ptr<Task>> const& subTasks);
		virtual ~MultipartTask();
	
		virtual bool process(long long step) override;

	protected:
		std::string name;
		std::vector<std::shared_ptr<Task>> subTasks;
	};
}

