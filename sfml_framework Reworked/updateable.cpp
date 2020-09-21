#include"stdafx.hpp"

#include"updateable.hpp"

namespace sff
{

	updateable::updateable() : updateTime( 0 )
	{
		timeCounter = clock();
	}

	updateable::updateable(clock_t updateTime) : updateTime( updateTime )
	{
		timeCounter = clock();
	}

	clock_t& updateable::getUpdateTime()
	{
		return updateTime;
	}

	void updateable::setUpdateTime(clock_t time)
	{
		updateTime = time;
	}

	void updateable::update()
	{
		if (timeCounter >= updateTime)
		{
			timeCounter = clock();
			onUpdate();
		}
	}
}
