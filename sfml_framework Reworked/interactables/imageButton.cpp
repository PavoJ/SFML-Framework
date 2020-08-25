#include "imageButton.hpp"

namespace sff
{
	imageButton::imageButton()
	{
		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;

		equalize = true;
	}

	imageButton::imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize)
	{
		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;

		equalize = false;

		rectangleButton.setPosition(textureButtonPosition);
		rectangleButton.setSize(textureButtonSize);
		backgroundButton = rectangleButton;

		textureButton.loadFromFile(titleImage);
		rectangleButton.setTexture(&textureButton);
	}


	void imageButton::setImage(const char* Image)
	{
		textureButton.loadFromFile(Image);
	}

	void imageButton::setPosition(sf::Vector2f& pos)
	{
		rectangleButton.setPosition(pos);
		backgroundButton.setPosition(pos);
	}

	void imageButton::setTextureSize(sf::Vector2f& pos)
	{
		rectangleButton.setSize(pos);
		if (equalize)
		{
			backgroundButton.setSize(pos);
			updatePointsOfInterest();
			equalize = false;
		}	
	}

	void imageButton::setBackgroundSize(sf::Vector2f& pos)
	{
		backgroundButton.setSize(pos);
		updatePointsOfInterest();
		if (equalize)
		{
			rectangleButton.setSize(pos);
			equalize = false;
		}
	}

	void imageButton::setRotation(float rotation)
	{
		rectangleButton.setRotation(rotation);
		backgroundButton.setRotation(rotation);
	}

	void imageButton::setColor(sf::Color color)
	{
		backgroundButton.setFillColor(color);
	}

	void imageButton::setScale(sf::Vector2f& scale)
	{
		rectangleButton.setScale(scale);
		backgroundButton.setScale(scale);

		updatePointsOfInterest();
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
		(*onClick)();
	}

	void imageButton::hover()
	{
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
		win->draw(backgroundButton);
		win->draw(rectangleButton);
	}
}


