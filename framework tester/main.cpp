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
	std::function<void()> heyButtonLeaveOnHover;
	std::function<void()> heyButtonLeaveOnClick;
	
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
		sff::imageButton* heyButton = new sff::imageButton("hey", *getDefaultFont());
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

		sff::imageButton * ciao = new sff::imageButton("immagine.png", sf::Vector2f(1000, 500), sf::Vector2f(100, 50), true);
		sf::Vector2f s(200, 100);
		ciao->setBackgroundSize(s);

		heyButtonOnHover = [ciao]() mutable {
			ciao->setColor(sf::Color::Cyan);
		};
		ciao->setOnHover(heyButtonOnHover);

		heyButtonLeaveOnHover = [ciao]() mutable {
			ciao->setColor(sf::Color(0, 0, 0, 255));
		};
		ciao->setLeaveOnHover(heyButtonLeaveOnHover);

		heyButtonOnClick = [ciao]() mutable {
			ciao->setColor(sf::Color::Blue);
		};
		ciao->setOnClick(heyButtonOnClick);

		heyButtonLeaveOnClick = [ciao]() mutable {
			ciao->setColor(sf::Color::Yellow);
		};
		ciao->setLeaveOnClick(heyButtonLeaveOnClick);

		this->add(ciao);


		
		sff::textButton* ciao2 = new sff::textButton("salve", *getDefaultFont());
		//sf::Vector2f a(200, 100);
		//ciao2->setBackgroundSize(a);
		sf::Vector2f b(150.f, 500.f);
		ciao2->setPosition(b);
		
		
		
		heyButtonOnHover = [ciao2]() {
			ciao2->getRectangle()->setFillColor(sf::Color::Cyan);
		};
		ciao2->setOnHover(heyButtonOnHover);

		heyButtonLeaveOnHover = [ciao2]() {
			ciao2->getRectangle()->setFillColor(sf::Color(0, 0, 0, 255));
		};
		ciao2->setLeaveOnHover(heyButtonLeaveOnHover);

		heyButtonOnClick = [ciao2]() {
			ciao2->getRectangle()->setFillColor(sf::Color::Blue);
		};
		ciao2->setOnClick(heyButtonOnClick);

		heyButtonLeaveOnClick = [ciao2]() {
			ciao2->getRectangle()->setFillColor(sf::Color::Yellow);
		};
		ciao2->setLeaveOnClick(heyButtonLeaveOnClick);

		this->add(ciao2);
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