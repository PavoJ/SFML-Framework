#ifndef UPDATEABLE_HPP
#define UPDATEABLE_HPP

#include"stdafx.hpp"

namespace sff
{
	class updateable
	{
	private:
		clock_t updateTime;
		clock_t referenceTime;

		virtual void onUpdate() = 0;
	public:
		updateable();
		updateable(clock_t updateTime);

		clock_t& getUpdateTime();
		void setUpdateTime(clock_t time);

		void update();
	};
}

#endif //UPDATEABLE_HPP