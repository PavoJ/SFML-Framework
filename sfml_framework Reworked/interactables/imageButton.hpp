#ifndef IMAGEBUTTON_HPP
#define IMAGEBUTTON_HPP

#include "interactable.hpp"
#include <SFML\Graphics.hpp>
#include <functional>

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

		imageButton();//tested
		imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize, bool drawBackground);//tested
		~imageButton();//tested

		void setImage(const char* Image);//tested
		void setPosition(sf::Vector2f& pos);//tested
		void setTextureSize(sf::Vector2f& size);//tested
		void setBackgroundSize(sf::Vector2f& size);//tested
		void setRotation(float rotation);//tested
		void setScale(sf::Vector2f& scale);//tested
		void setColor(sf::Color color);//tested
		void setImageOpacity(float opacity);//tested
		void setDrawBackground(bool drawBackground);//tested

		void render(sf::RenderWindow* win);//tested


		void setOnClick(std::function<void()>& onClick);
		void setOnHover(std::function<void()>& onHover);

		void click();
		void hover();

		void updatePointsOfInterest();//tested
		
	};
}



#endif //IMAGEBUTTON_HPP
