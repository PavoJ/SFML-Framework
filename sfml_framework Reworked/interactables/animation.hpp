#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "stdafx.hpp"

namespace sff
{
	class animationHandler
	{
	protected:
		sf::Texture spriteSheet;

		const sf::Vector2i startPos;
		const sf::Vector2i cellDim;
		sf::IntRect sheetRect;
		
		//linked list containing all the performable animations
		struct animations {
			struct{
				//frame that starts the animation located in the spritesheet,
				//counted from left to right, top to bottom
				int startPosition;
				//number of frames that compose the animation
				int frames;
				//time between a frame transition
				float delta;
			} animation;
			std::string name;

			animations* next;
		} *anim;
		

	public:
		animationHandler(const char* textureDir, sf::IntRect startPos);
	};
}

#endif //ANIMATION_HPP
