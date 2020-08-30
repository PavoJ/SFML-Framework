#include"sprite.hpp"

enum minchia
{
	OK		= 0,
	CANCEL	= 0 << 1
};

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