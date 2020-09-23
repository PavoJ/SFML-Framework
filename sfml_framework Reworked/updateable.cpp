#include"stdafx.hpp"

#include"updateable.hpp"

namespace sff
{

	updateable::updateable() : updateTime( 0 )
	{
		referenceTime = std::clock();
	}

	updateable::updateable(clock_t updateTime) : updateTime( updateTime )
	{
		referenceTime = std::clock();
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
		clock_t timePassed = std::clock() - referenceTime;
		if (timePassed >= updateTime)
		{
			referenceTime = std::clock();
			onUpdate();
		}
	}
}
