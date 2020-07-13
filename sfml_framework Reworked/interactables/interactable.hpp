#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include<SFML\Graphics.hpp>

namespace sff
{
    //interactables are any element that responds if hovered with the mouse
    //or clicked on.
    //examples: buttons, dialog boxes...
    class interactable
    {
    protected:
        /*the bounds that contain the areas that are affected by mouse hovers or
            mouse clicks. For example, the buttons in a dialog box, or the individual buttons
            on a drop down menu*/
        sf::FloatRect* pointsOfInterest;
        int pointsCnt;//pointsOfInterest counter

        virtual void updatePointsOfInterest() = 0;
    public:

        bool contains(sf::Vector2f point);

        virtual void setPosition(sf::Vector2f& pos) = 0;
        virtual void setScale(sf::Vector2f& scale) = 0;

        virtual void render(sf::RenderWindow* win) = 0;

        virtual void click() = 0;
        virtual void hover() = 0;
    };

}

#endif //INTERACTABLE_HPP