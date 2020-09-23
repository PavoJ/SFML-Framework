#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "stdafx.hpp"
#include "interactable.hpp"
#include "animation.hpp"

namespace sff
{
	class sprite : public drawable, public animation, virtual public updateable
	{
	protected:
		sf::Sprite sfSprite;

		void onUpdate();
	public:
		sprite(const char* spriteSheetDir, sf::IntRect startRect);

		void setPosition(sf::Vector2f& pos);
		void setScale(sf::Vector2f& scale);
		void render(sf::RenderWindow* win);

		sf::Sprite* getSprite();
		sf::Texture* getTexture();
	};
}

#endif //SPRITE_HPP