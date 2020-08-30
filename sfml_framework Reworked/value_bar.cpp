#include "value_bar.hpp"
#include <iostream>

namespace sff
{
	valueBar::valueBar()
	{
		progress = 0;
		maxProgress = 100;

		drawBackBar = true;
		drawFrontBar = true;
	}

	valueBar::valueBar(sf::Vector2f barSize, sf::Vector2f BarPos, sf::Color frontBarColor, bool drawBbar, bool drawFbar, int maxP)
	{
		progress = 0;
		maxProgress = maxP;

		backBar.setSize(barSize);
		frontBar.setSize(sf::Vector2f(progress, barSize.y));

		backBar.setPosition(BarPos);
		frontBar.setPosition(BarPos);

		frontBar.setFillColor(frontBarColor);

		drawBackBar = drawBbar;
		drawFrontBar = drawFbar;
	}

	valueBar::~valueBar()
	{

	}


	void valueBar::addProgress(int prog)
	{
		sf::Vector2f fBarDim = frontBar.getSize();
		sf::Vector2f bBarDim = backBar.getSize();
		progress += prog;
		if (progress > maxProgress) progress = maxProgress;
		frontBar.setSize(sf::Vector2f(bBarDim.x*((float)getBarPercentage() / 100.f), bBarDim.y));
	}

	void valueBar::setBarColor(sf::Color frontBarColor)
	{
		frontBar.setFillColor(frontBarColor);
	}

	void valueBar::setBarOutlineColor(sf::Color backBarOutlineColor)
	{
		backBar.setFillColor(backBarOutlineColor);
	}

	void valueBar::setBarPosition(sf::Vector2f BarPos)
	{
		frontBar.setPosition(BarPos);
		backBar.setPosition(BarPos);
	}

	void valueBar::setBarSize(sf::Vector2f barSize)
	{
		backBar.setSize(barSize);
	}

	void valueBar::setBarRotation(float rotation)
	{
		frontBar.setRotation(rotation);
		backBar.setRotation(rotation);
	}

	void valueBar::setMaxProgress(int newMaxProgress)
	{
		maxProgress = newMaxProgress;
	}


	bool valueBar::barIsCompleted()
	{
		bool end;
		end = progress == maxProgress ? true : false;
		return end;
	}


	int valueBar::getprogress()
	{
		return progress;
	}

	int valueBar::getMaxProgress()
	{
		return maxProgress;
	}

	int valueBar::getBarPercentage()
	{
		return ((float)progress / (float)maxProgress) * 100;
	}


	sf::RectangleShape* valueBar::getBackBar()
	{
		return &backBar;
	}

	sf::RectangleShape* valueBar::getFrontBar()
	{
		return &frontBar;
	}

	void valueBar::renderBar(sf::RenderWindow* win)
	{
		win->draw(backBar);
		win->draw(frontBar);
	}
}