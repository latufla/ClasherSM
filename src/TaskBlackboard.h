#pragma once

namespace csm {
	class TaskBlackboard {
	public:
		TaskBlackboard();
		~TaskBlackboard();

		virtual void setSuccess(bool val);
		virtual bool getSuccess() const;

		virtual void clear();
	protected:
		bool success = false;
	};
}

