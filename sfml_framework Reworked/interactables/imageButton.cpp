#include "imageButton.hpp"
#include <iostream>

namespace sff
{
	imageButton::imageButton()
	{
		rectangleButton = new sf::RectangleShape;

		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;

		equalize = true;
		draw = true;
	}

	imageButton::imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize, bool drawBackground = true)
	{
		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;

		equalize = false;

		if (drawBackground) draw = true;
		else draw = false;

		rectangleButton = new sf::RectangleShape;

		rect.rectSize.x = textureButtonSize.x; rect.rectSize.y = textureButtonSize.y;
		rect.rectPos.x = textureButtonPosition.x; rect.rectPos.y = textureButtonPosition.y;
		
		rectangleButton->setPosition(textureButtonPosition);
		rectangleButton->setSize(textureButtonSize);

		backgroundButton.setPosition(textureButtonPosition);
		backgroundButton.setSize(textureButtonSize);

		rectangleButton->setOrigin(textureButtonSize.x / 2, textureButtonSize.y / 2);
		backgroundButton.setOrigin(textureButtonSize.x / 2, textureButtonSize.y / 2);

		textureButton.loadFromFile(titleImage);
		rectangleButton->setTexture(&textureButton);
	}

	imageButton::~imageButton()
	{

	}


	void imageButton::setImage(const char* Image)
	{	
		delete rectangleButton;
		rectangleButton = new sf::RectangleShape;

		setPosition(rect.rectPos);
		setTextureSize(rect.rectSize);
		rectangleButton->setOrigin(rect.rectSize.x / 2, rect.rectSize.y / 2);

		textureButton.loadFromFile(Image);
		rectangleButton->setTexture(&textureButton);
	}

	void imageButton::setPosition(sf::Vector2f& pos)
	{
		rect.rectPos.x = pos.x;
		rect.rectPos.y = pos.y;

		rectangleButton->setPosition(pos);
		backgroundButton.setPosition(pos);
	}

	void imageButton::setTextureSize(sf::Vector2f& size)
	{
		rect.rectSize.x = size.x;
		rect.rectSize.y = size.y;

		rectangleButton->setSize(size);
		rectangleButton->setOrigin(size.x / 2, size.y / 2);

		if (equalize)
		{
			backgroundButton.setSize(size);
			backgroundButton.setOrigin(size.x / 2, size.y / 2);

			updatePointsOfInterest();
			equalize = false;
		}	
	}

	void imageButton::setBackgroundSize(sf::Vector2f& size)
	{
		backgroundButton.setSize(size);
		backgroundButton.setOrigin(size.x / 2, size.y / 2);

		updatePointsOfInterest();

		if (equalize)
		{
			rectangleButton->setSize(size);
			rectangleButton->setOrigin(size.x / 2, size.y / 2);

			equalize = false;
		}
	}

	void imageButton::setRotation(float rotation)
	{
		rectangleButton->setRotation(rotation);
		backgroundButton.setRotation(rotation);
	}

	void imageButton::setColor(sf::Color color)
	{
		backgroundButton.setFillColor(color);
	}

	void imageButton::setScale(sf::Vector2f& scale)
	{
		rectangleButton->setScale(scale);
		backgroundButton.setScale(scale);

		updatePointsOfInterest();
	}

	void imageButton::setImageOpacity(float opacity)
	{
		opacity *= 2.55;
		rectangleButton->setFillColor(sf::Color(255, 255, 255, (int)opacity));
	}


	void imageButton::setDrawBackground(bool drawBackground)
	{
		draw = drawBackground;
	}


	void imageButton::setOnClick(std::function<void()>& onClick)
	{
		this->onClick = &onClick;
	}

	void imageButton::setOnHover(std::function<void()>& onHover)
	{
		this->onHover = &onHover;
	}

	void imageButton::click()
	{
		if (onHover != nullptr)
			(*onClick)();
	}

	void imageButton::hover()
	{
		if (onHover != nullptr)
			(*onHover)();
	}


	void imageButton::updatePointsOfInterest()
	{
		if (pointsOfInterest != nullptr)
			delete pointsOfInterest;

		pointsOfInterest = new sf::FloatRect;
		pointsCnt = 1;

		pointsOfInterest[0] = backgroundButton.getGlobalBounds();
	}


	void imageButton::render(sf::RenderWindow* win)
	{
		if (draw) win->draw(backgroundButton);
		win->draw(*rectangleButton);	
	}
}


