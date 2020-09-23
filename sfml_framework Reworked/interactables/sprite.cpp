#include "stdafx.hpp"
#include "sprite.hpp"

namespace sff
{
	sprite::sprite(const char* spriteSheetDir, sf::IntRect cell) : animation{ spriteSheetDir, cell }, updateable{}
	{
		sfSprite.setTexture(spriteSheet);
		sfSprite.setTextureRect(sheetRect);

		std::cout << getUpdateTime();
	}

	void sprite::onUpdate()
	{
		advanceAnimation();
		sfSprite.setTextureRect(sheetRect);
	}

	void sprite::setPosition(sf::Vector2f& pos)
	{
		sfSprite.setPosition(pos);
	}

	void sprite::setScale(sf::Vector2f& scale)
	{
		sfSprite.setScale(scale);
	}

	void sprite::render(sf::RenderWindow* win)
	{
		win->draw(sfSprite);
	}

	sf::Sprite* sprite::getSprite()
	{
		return &sfSprite;
	}

	sf::Texture* sprite::getTexture()
	{
		return &spriteSheet;
	}

}