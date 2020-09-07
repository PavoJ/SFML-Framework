#ifndef IMAGEBUTTON_HPP
#define IMAGEBUTTON_HPP

#include "stdafx.hpp"
#include "interactable.hpp"

//da fare -> set image opacity
namespace sff
{
	class imageButton : public interactable
	{
	protected:
		sf::Texture textureButton;
		sf::RectangleShape *rectangleButton;

		sf::RectangleShape backgroundButton;
		
		std::function<void()>* onClick;
		std::function<void()>* onHover;

		struct { sf::Vector2f rectSize; sf::Vector2f rectPos; }rect;

		bool equalize, draw;

	public:

		imageButton();
		imageButton(const char* imageTitle, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize, bool drawBackground);
		~imageButton();

		void setImage(const char* Image);
		void setPosition(sf::Vector2f& pos);
		void setTextureSize(sf::Vector2f& size);
		void setBackgroundSize(sf::Vector2f& size);
		void setRotation(float rotation);
		void setScale(sf::Vector2f& scale);
		void setColor(sf::Color color);
		void setDrawBackground(bool drawBackground);

		void render(sf::RenderWindow* win);

		void setOnClick(std::function<void()>& onClick);
		void setOnHover(std::function<void()>& onHover);

		sf::Texture* getTexture();
		sf::RectangleShape* getTextureRectangle();
		sf::RectangleShape* getBackgroundTexture();

		void click();
		void hover();

		void updatePointsOfInterest();
		
	};
}



#endif //IMAGEBUTTON_HPP
