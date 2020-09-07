#include "stdafx.hpp"
#include "animation.hpp"

namespace sff
{
	anim::anim(int startPosition, int frames, float delta, std::string name): 
		startPosition(startPosition),
		frames(frames),
		delta(delta),
		name(name)
	{}

	void animation::calculateSpriteSheetGrid()
	{
		sf::Vector2i sSDim = sf::Vector2i(spriteSheet.getSize());
		
		spriteSheetGrid.x = (sSDim.x - startPos.x) / cellDim.x;
		spriteSheetGrid.y = (sSDim.y - startPos.y) / cellDim.y;
	}

	animation::animation()
	{
		animList.reserve(3);
		currentState = 0;
		animIndex = 0;
	}

	animation::animation(const char* textureDir, sf::IntRect startRect) : 
		startPos{sf::Vector2i(startRect.left,	startRect.top	)},
		cellDim	{sf::Vector2i(startRect.width,	startRect.height)}
	{
		animList.reserve(3);
		currentState = 0;//idle
		animIndex = 0;
		std::cout << animList.size();

		spriteSheet.loadFromFile(textureDir);
		calculateSpriteSheetGrid();
	}
	
	void animation::createState(anim& state)
	{
		animList[animList.size()] = state;
	}

	bool animation::setState(int state)
	{
		animIndex = 0;
		currentState = state;

		return true;
	}

	bool animation::setState(std::string& name)
	{
		std::string* placeHolderStr;
		bool success = false;
		int stateIndex = 0;

		while ((stateIndex < animList.size()) && !success)
		{
			placeHolderStr = &animList[stateIndex].name;
			
			if ((*placeHolderStr) == name)
			{
				success = true;
				animIndex = 0;
				currentState = stateIndex;
			}

			stateIndex++;
		}

		return success;
	}

	void animation::update()
	{
		if ((sheetRectIndex.x++) >= spriteSheetGrid.x)
		{
			sheetRectIndex.x = 0;

			if ((sheetRectIndex.y++) >= spriteSheetGrid.y)
			{
				sheetRectIndex.y = 0;
			}
		}

		sheetRect.left = startPos.x + (sheetRectIndex.x * cellDim.x);
		sheetRect.top = startPos.y + (sheetRectIndex.y * cellDim.y);

		if ((animIndex++) == animList[currentState].frames)
		{
			animIndex = 0;
		}
	}
}