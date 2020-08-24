#include<SFML/Graphics.hpp>
#include<sfml_logic.hpp>

class mainMenu : public sff::menu
{
protected:
	virtual void additionalInputs(sf::Event::EventType eType) {};

};

int main()
{
	sf::Font defaultFont;
	defaultFont.loadFromFile("PlayfairDisplay-Regular.ttf");
	
	sff::button heyButton("hey", defaultFont, 70);

	mainMenu mainMenuInstance;
	mainMenuInstance.add(&heyButton);

	sf::RenderWindow win(sf::VideoMode(1920, 1080), "ci incontriamo di nuovo");

	mainMenuInstance.mainLoop(&win);
}