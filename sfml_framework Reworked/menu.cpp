#include "stdafx.hpp"
#include"sfml_logic.hpp"

namespace sff
{
	elements* menu::getLast(elements* el)
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
		tickTime = CLOCKS_PER_SEC / (long)10;
		elapsedTime = std::clock();
		el = nullptr;
		menuIsOpen = true;
		clearColor = sf::Color::Black;
	}

	menu::~menu()
	{
		elements* placeHolder = el;
		elements* deletable;

		while (placeHolder != nullptr)
		{
			deletable = placeHolder;
			placeHolder = placeHolder->next;

			if (deletable->deleteOnSceneEnd)
			{
				sf::Uint32 elType = deletable->elementType;
				if		((elType & type::sfDrawable) ==  type::sfDrawable)	delete deletable->element.sfDraw;
				else if	((elType & type::sffDrawable) == type::sffDrawable)	delete deletable->element.sffDraw;

				delete deletable;
			}
		}
	}

	template<typename T>
	const void* menu::genericAdd(bool deleteOnSceneEnd)
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
		
		lastElement->deleteOnSceneEnd = deleteOnSceneEnd;
		lastElement->next = nullptr;
		
		return lastElement;
	}

	void menu::add(drawable* element, bool deleteOnSceneEnd, sf::Uint32 additionalTypes)
	{
		elements* lastElement = (elements*)genericAdd<drawable*>(deleteOnSceneEnd);
		lastElement->elementType = type::sffDrawable | additionalTypes;
		lastElement->element.sffDraw = element;
	}

	void menu::add(interactable* element, bool deleteOnSceneEnd, sf::Uint32 additionalTypes)
	{
		elements* lastElement = (elements*)genericAdd<interactable*>(deleteOnSceneEnd);
		lastElement->elementType = type::sffInteractable | additionalTypes;
		lastElement->element.sffDraw = (drawable*)element;
	}

	void menu::add(sf::Drawable* element, bool deleteOnSceneEnd, sf::Uint32 additionalTypes)
	{
		elements* lastElement = (elements*)genericAdd<sf::Drawable*>(deleteOnSceneEnd);
		lastElement->elementType = type::sfDrawable | additionalTypes;
		lastElement->element.sfDraw = element;
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

						elements* placeHolder = el;
						interactable* winElement;

						while (placeHolder != nullptr)
						{
							if (placeHolder->elementType & type::sffInteractable)
							{
								winElement = ((interactable*)placeHolder->element.sffDraw);

								if (winElement->contains(sf::Vector2f(mousePosition)))
									if (clickReg)
										winElement->click();
									else
										winElement->hover();

							}
							placeHolder = placeHolder->next;
						}
						

						break;
					}
				}
			}

			Update();
			if (elapsedTime > tickTime)
			{
				elapsedTime = std::clock();
				FixedUpdate();
			}

			win->clear(clearColor);

			//this is where we update and draw every element of the menu
			elements* placeHolder = el;

			while (placeHolder != nullptr)
			{
				if (placeHolder->elementType & type::sffUpdatable)
					((updateable*)placeHolder->element.sffDraw)->update();

				if (placeHolder->elementType & type::sffDrawable)
					placeHolder->element.sffDraw->render(win);

				else if (placeHolder->elementType & type::sfDrawable)
					win->draw(*placeHolder->element.sfDraw);
					

				placeHolder = placeHolder->next;
			}

			win->display();
		}
	}
}