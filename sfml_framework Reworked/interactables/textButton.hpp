#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "interactable.hpp"
#include <SFML\Graphics.hpp>
#include <functional>

namespace sff
{
    class button : public interactable
    {
    protected:
        sf::Text text;
        sf::String textString;

        sf::RectangleShape buttonRect;

        std::function<void()>* onClick;
        std::function<void()>* onHover;

        void updateRectanglePosition();
        void updatePointsOfInterest();
    public:
        //creates an empty button
        button();
        //creates a button
        button(const char* displayText, sf::Font& font, unsigned int characterSize);

        void setOnClick(std::function<void()>& onClick);
        void setOnHover(std::function<void()>& onHover);

        void setPosition(sf::Vector2f& pos);
        void setScale(sf::Vector2f& scale);

        void click();
        void hover();

        void render(sf::RenderWindow* win);
    };
}

#endif //BUTTON_HPP