#ifndef VALUEBAR_HPP
#define VALUEBAR_hpp

#include <SFML\Graphics.hpp>

namespace sff
{
	class valueBar
	{
	protected:
		sf::RectangleShape backBar;
		sf::RectangleShape frontBar;

		int progress, maxProgress;

		bool drawBackBar, drawFrontBar;


	public:
		valueBar();
		valueBar(sf::Vector2f barSize, sf::Vector2f BarPos, sf::Color frontBarColor, bool drawBbar, bool drawFbar, int maxP);
		~valueBar();

		void addProgress(int prog);
		void setBarColor(sf::Color frontBarColor);
		void setBarOutlineColor(sf::Color frontBarOutlineColor);
		void setBarPosition(sf::Vector2f BarPos);
		void setBarSize(sf::Vector2f barSize);
		void setBarRotation(float rotation);
		void setMaxProgress(int newMaxProgress);

		bool barIsCompleted();

		int getprogress();
		int getMaxProgress();
		int getBarPercentage();


		sf::RectangleShape* getBackBar();
		sf::RectangleShape* getFrontBar();

		void renderBar(sf::RenderWindow* win);

	};
}

#endif VALUEBAR_HPP
