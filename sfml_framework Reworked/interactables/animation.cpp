#include "stdafx.hpp"
#include "animation.hpp"

namespace sff
{
	animationHandler::animationHandler(const char* textureDir, sf::IntRect startRect) : 
		startPos{sf::Vector2i(startRect.left,	startRect.top	)},
		cellDim	{sf::Vector2i(startRect.width,	startRect.height)}
	{
		spriteSheet.loadFromFile(textureDir);
	}
}