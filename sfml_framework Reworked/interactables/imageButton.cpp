#include "imageButton.hpp"

namespace sff
{
	imageButton::imageButton()
	{
		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;
	}


	imageButton::imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize)
	{
		onClick = nullptr;
		onHover = nullptr;

		pointsOfInterest = nullptr;
		pointsCnt = 0;

		rectangleButton.setPosition(textureButtonPosition);
		rectangleButton.setSize(textureButtonSize);

		textureButton.loadFromFile(titleImage);
		rectangleButton.setTexture(&textureButton);
	}


	void imageButton::setTitleImage(const char* titleImage)
	{
		textureButton.loadFromFile(titleImage);
	}


	void imageButton::setPosition(sf::Vector2f& pos)
	{
		rectangleButton.setPosition(pos);
	}


	void imageButton::setSize(sf::Vector2f& pos)
	{
		rectangleButton.setSize(pos);
	}


	void imageButton::setRotation(float rotation)
	{
		rectangleButton.setRotation(rotation);
	}


	void imageButton::render(sf::RenderWindow* win)
	{
		win->draw(rectangleButton);
	}


	void imageButton::setOnClick(std::function<void()>& onClick)
	{
		this->onClick = &onClick;
	}


	void imageButton::setOnHover(std::function<void()>& onHover)
	{
		this->onHover = &onHover;
	}
}


