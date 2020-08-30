#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "interactable.hpp"
#include "stdafx.hpp"
#include <functional>

namespace sff
{
	class sprite : public interactable
	{
	protected:
		sf::Texture spriteSheet;
		sf::Sprite sfSprite;

		void updatePointsOfInterest();
	public:
		sprite(const char* spriteSheetDir, sf::IntRect );

		sf::Sprite* getSprite();
		sf::Texture* getTexture();


	};
}

#endif //SPRITE_HPP