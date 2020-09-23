#include "stdafx.hpp"
#include "animation.hpp"

namespace sff
{
	anim::anim(int startPosition, int frames, float delta, std::string name) : startPosition(startPosition),
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

	animation::animation(const char* textureDir, sf::IntRect startRect) : 
		startPos{sf::Vector2i(startRect.left,	startRect.top	)},
		cellDim	{sf::Vector2i(startRect.width,	startRect.height)},
		updateable{}
	{
		animList.reserve(3);
		currentState = 0;//idle
		animIndex = 0;

		sheetRect = startRect;

		spriteSheet.loadFromFile(textureDir);
		calculateSpriteSheetGrid();
	}
	
	int animation::createState(anim& state)
	{
		int animSize = animList.size();

		animList.emplace_back(state);

		return animSize;
	}

	bool animation::setState(int state)
	{
		animIndex = 0;
		bool ret = false;
		
		if (state < animList.size())
		{
			currentState = state;
			ret = true;

			setUpdateTime((clock_t)(animList[currentState].delta * (float)CLOCKS_PER_SEC));
		}

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

				setUpdateTime((clock_t)(animList[currentState].delta * (float)CLOCKS_PER_SEC));
			}

			stateIndex++;
		}

		if (!success)
			currentState = 0;

		return success;
	}

	void animation::advanceAnimation()
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
		sheetRect.top  = startPos.y + (sheetRectIndex.y * cellDim.y);
		
		if ((animIndex++) == animList[currentState].frames)
		{
			animIndex = 0;
		}
	}
}