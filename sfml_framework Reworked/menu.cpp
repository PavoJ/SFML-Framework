#include "stdafx.hpp"
#include"sfml_logic.hpp"

namespace sff
{
	menu::elements* menu::getLast(menu::elements* el)
	{
		elements* ret = nullptr;

		if (el == nullptr)
			ret = nullptr;
		else if (el->next == nullptr)
			ret = el;
		else
			ret = getLast(el->next);

		return ret;
	}

	menu::menu()
	{
		el = nullptr;
		menuIsOpen = true;
		clearColor = sf::Color::Black;
	}

	menu::~menu()
	{
		menu::elements* placeHolder = el;
		menu::elements* deletable;

		while (placeHolder != nullptr)
		{
			deletable = placeHolder;
			placeHolder = placeHolder->next;

			if (deletable->deleteOnSceneEnd)
			{
				delete deletable->element;
				delete deletable;
			}
		}
	}

	void menu::add(interactable* element, bool deleteOnSceneEnd)
	{
		elements* lastElement = getLast(el);

		if (lastElement == nullptr)
		{
			el = new elements;
			lastElement = el;
		}
		else {
			lastElement->next = new elements;
			lastElement = lastElement->next;
		}

		lastElement->element = element;
		lastElement->deleteOnSceneEnd = deleteOnSceneEnd;

		lastElement->next = nullptr;
	}

	void menu::mainLoop(sf::RenderWindow* win)
	{
		while (win->isOpen() && menuIsOpen)
		{
			//event handler, generalized by the pure function inputHandler
			sf::Event event;
			while (win->pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
						win->close();
						break;

					case sf::Event::MouseMoved:
					case sf::Event::MouseButtonPressed:
					{
						bool clickReg = sf::Mouse::isButtonPressed(sf::Mouse::Left);

						sf::Vector2i mousePosition = sf::Mouse::getPosition(*win);

						elements* placeHolder = el;
						interactable* winElement;

						while (placeHolder != nullptr)
						{
							winElement = placeHolder->element;
							if (winElement->contains(sf::Vector2f(mousePosition)))
								if (clickReg)
									winElement->click();
								else
									winElement->hover();

							placeHolder = placeHolder->next;
						}
						

						break;
					}
				}
			}

			win->clear(clearColor);

			//this is where you draw every element of the menu
			elements* placeHolder = el;
			while (placeHolder != nullptr)
			{
				placeHolder->element->render(win);
				placeHolder = placeHolder->next;
			}

			win->display();
		}
	}
}