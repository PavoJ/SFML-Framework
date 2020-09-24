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
	
	sff::sprite* mainChar;
public:

	mainMenu() {
		mainChar = new sff::sprite("herochar_run_anim_strip_6.png", sf::IntRect(0,0,16,16));
		
		sf::Vector2f mainCharScale(10.f, 10.f);
		mainChar->setScale(mainCharScale);

		sf::Vector2f mainCharPos(500.f, 500.f);
		mainChar->setPosition(mainCharPos);

		sff::anim walkingAnim(0, 5, 0.15f, "walking");
		mainChar->createState(walkingAnim);
		

		std::cout << mainChar->setState(0);

		this->addUpdate(mainChar);
		this->add(mainChar);

		/*
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

		this->add(heyButton, true);*/
	}

	~mainMenu()
	{
		delete mainChar;
	}
};


int main()
{
	sf::RenderWindow win(sf::VideoMode(1920, 1080), "ci incontriamo di nuovo", sf::Style::Close | sf::Style::Titlebar);

	mainMenu mainMenuInstance;
	mainMenuInstance.mainLoop(&win);
}