#pragma once
#include <string>

namespace csm {
	class Condition {
	public:
		Condition();
		virtual ~Condition();
	
		virtual bool process(long long step);
	protected:
		std::string name = "condition";
	};
}

