#include "stdafx.hpp"
#include"sfml_logic.hpp"

namespace sff
{
	menu::menu()
	{
		tickTime = CLOCKS_PER_SEC / (long)10;
		elapsedTime = std::clock();
		menuIsOpen = true;
		clearColor = sf::Color::Black;
	}

	menu::~menu(){}

	void menu::add(drawable* toAdd)
	{
		element placeHolderEl;
		placeHolderEl.elType = type::sffDrawable;
		placeHolderEl.toDraw.sffDraw = toAdd;

		drawables.append(placeHolderEl);
	}

	void menu::add(sf::Drawable* toAdd)
	{
		element placeHolderEl;
		placeHolderEl.elType = type::sfDrawable;
		placeHolderEl.toDraw.sfDraw = toAdd;

		drawables.insert(drawables.length(), placeHolderEl);
	}

	void menu::add(interactable* toAdd)
	{
		interactables.insert(interactables.length(), toAdd);

		element placeHolderEl;
		placeHolderEl.elType = type::sffDrawable;
		placeHolderEl.toDraw.sffDraw = toAdd;

		drawables.insert(drawables.length(), placeHolderEl);
	}

	void menu::addUpdate(updateable* toAdd)
	{
		updateables.append(toAdd);
	}

	void menu::Update(){}
	void menu::FixedUpdate() {};

	void menu::mainLoop(sf::RenderWindow* win)
	{
		elapsedTime = std::clock();
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

						interactable* winElement;

						for(int a=0; a<interactables.length(); a++)
						{
							winElement = interactables[a];

							if (winElement->contains(sf::Vector2f(mousePosition)))
								if (clickReg)
									winElement->click();
								else
									winElement->hover();
						}
						

						break;
					}
				}
			}

			//updating the various elements
			Update();
			if (elapsedTime > tickTime)
			{
				elapsedTime = std::clock();
				FixedUpdate();
			}

			for (int i = 0; i < drawables.length(); i++)
				updateables[i]->update();

			win->clear(clearColor);

			for(int i=0; i<drawables.length(); i++)
			{
				switch (drawables[i].elType)
				{
				case type::sfDrawable:
					win->draw(*drawables[i].toDraw.sfDraw);
					break;

				case type::sffDrawable:
					drawables[i].toDraw.sffDraw->render(win);
					break;
				}
			}

			win->display();
		}
	}
}