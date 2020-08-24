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

		std::function<void()>* onClick;
		std::function<void()>* onHover;

	public:

		imageButton();
		imageButton(const char* titleImage, sf::Vector2f textureButtonPosition, sf::Vector2f textureButtonSize);

		void setTitleImage(const char* titleImage);
		void setPosition(sf::Vector2f& pos);
		void setSize(sf::Vector2f& pos);
		void setRotation(float rotation);
		void render(sf::RenderWindow* win);

		void setOnClick(std::function<void()>& onClick);
		void setOnHover(std::function<void()>& onHover);
		

			



	};
}



#endif //IMAGEBUTTON_HPP
