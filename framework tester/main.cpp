#include "stdafx.hpp"
#include "sfml_logic.hpp"

sf::Font* getDefaultFont()
{
	static bool setup;
	static sf::Font defaultFont;

	if (!setup)
	{
		//defaultFont.loadFromFile("calibrii.ttf");
		defaultFont.loadFromFile("PlayfairDisplay-Regular.ttf");
		setup = true;
	}

	return &defaultFont;
}

class mainMenu : public sff::menu
{
protected:
	virtual void additionalInputs(sf::Event::EventType eType) {};

	std::function<void()> heyButtonOnHover;
	std::function<void()> heyButtonOnClick;
public:
	mainMenu() {
		sff::textButton* heyButton = new sff::textButton("hey", *getDefaultFont());
		heyButton->setPosition(1000.f, 500.f);
		
		heyButtonOnHover = [heyButton]() mutable {
			heyButton->getRectangle()->setFillColor(sf::Color::Cyan);
		};
		heyButton->setOnHover(heyButtonOnHover);

		heyButtonOnClick = [heyButton]() mutable {
			float newRot = heyButton->getRotation() + .5;
			heyButton->setRotation(newRot);
		};
		heyButton->setOnClick(heyButtonOnClick);

		this->add(heyButton, true);
	}
};

int main()
{
	sf::RenderWindow win(sf::VideoMode(1920, 1080), "ci incontriamo di nuovo", sf::Style::Close | sf::Style::Titlebar);

	mainMenu mainMenuInstance;
	mainMenuInstance.mainLoop(&win);
}