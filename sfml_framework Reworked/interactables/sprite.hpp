#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "stdafx.hpp"
#include "interactable.hpp"
#include "animation.hpp"

namespace sff
{
	class sprite : public interactable, public animation
	{
	protected:
		sf::Sprite sfSprite;

		void updatePointsOfInterest();
	public:
		sprite(const char* spriteSheetDir, sf::IntRect startRect);

		sf::Sprite* getSprite();
		sf::Texture* getTexture();


	};
}

#endif //SPRITE_HPP