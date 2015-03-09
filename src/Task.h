#pragma once
#include <string>

namespace csm {
	class Task {
	public:
		Task(std::string name);
		virtual ~Task();

		virtual bool process(long long step);

	protected:
		std::string name;
	};
}

