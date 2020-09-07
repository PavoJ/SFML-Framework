#include "stdafx.hpp"
#include"sprite.hpp"

namespace sff
{
	void sprite::updatePointsOfInterest() 
	{
		if (pointsOfInterest == nullptr)
		{
			pointsOfInterest = new sf::FloatRect;
			pointsCnt = 1;
		}
		
		
		(*pointsOfInterest) = sfSprite.getGlobalBounds();
	}

	sprite::sprite(const char* spriteSheetDir, sf::IntRect giorgio)
	{
		spriteSheet.loadFromFile(spriteSheetDir);

		sfSprite.setTexture(spriteSheet);
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