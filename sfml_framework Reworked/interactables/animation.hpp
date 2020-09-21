#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "stdafx.hpp"
#include "../updateable.hpp"

namespace sff
{
	//linked list containing all the performable animations
	struct anim {
		//frame that starts the animation located in the spritesheet,
		//counted from left to right, top to bottom
		int startPosition;

		//number of frames that compose the animation
		int frames;

		//time between a frame transition
		float delta;

		std::string name;

		anim(int startPosition, int frames, float delta, std::string name);
	};

	class animation : virtual public updateable
	{
	protected:
		//spriteSheet containing all the frames required for the different animations
		sf::Texture spriteSheet;
		//vector rappresenting the frames contained in the spriteSheet
		sf::Vector2i spriteSheetGrid;
		void calculateSpriteSheetGrid();
		
		//start of the spriteSheet
		const sf::Vector2i startPos;
		//dimensions of a frame
		const sf::Vector2i cellDim;

		//position of the current frame
		sf::IntRect sheetRect;
		//index of the current frame
		sf::Vector2i sheetRectIndex;
		
		//list of animations
		std::vector<anim> animList;
		int animIndex;//frame of the current state
		int currentState;//current state

		void onUpdate();

	public:
		animation(const char* textureDir, sf::IntRect startPos);

		int createState(anim& state);

		bool setState(int state);
		bool setState(std::string& name);

		void update();
	};
}

#endif //ANIMATION_HPP
