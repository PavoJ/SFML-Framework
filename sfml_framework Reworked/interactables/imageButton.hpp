#ifndef IMAGEBUTTON_HPP
#define IMAGEBUTTON_HPP

#include "interactable.hpp"
#include <SFML\Graphics.hpp>
#include <functional>


namespace sff
{
	class imageButton : public interactable
	{
	protected:
		sf::Texture textureButton;
		sf::RectangleShape rectangleButton;
		sf::RectangleShape backgroundButton;

		std::function<void()>* onClick;
		std::function<void()>* onHover;

		bool equalize;

	public:

		imageButton();
		imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize);

		void setImage(const char* Image);
		void setPosition(sf::Vector2f& pos);
		void setTextureSize(sf::Vector2f& pos);
		void setBackgroundSize(sf::Vector2f& pos);
		void setRotation(float rotation);
		void setScale(sf::Vector2f& scale);
		void setColor(sf::Color color);

		void render(sf::RenderWindow* win);


		void setOnClick(std::function<void()>& onClick);
		void setOnHover(std::function<void()>& onHover);

		void click();
		void hover();

		void updatePointsOfInterest();
		

			



	};
}



#endif //IMAGEBUTTON_HPP
