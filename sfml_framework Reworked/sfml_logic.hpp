#ifndef MENU_HPP
#define MENU_HPP

#include"interactables/interactable.hpp"
#include"interactables/button.hpp"

#include<SFML\Graphics.hpp>

namespace sff
{
    //Superclass holding the concept of a menu: an interactable with active and passive elements.
    //Interactive elements are buttons, text, dialog boxes...
    //Passive elements are loading screens, scripts running in the background...
    class menu
    {
    protected:
        typedef struct elements{ 
            interactable* element;
            struct elements* next;
        } elements;
        elements* el;

        elements* getLast(elements* el);

        bool menuIsOpen;
        sf::Color clearColor;

        //can handle additional inputs you may want to track
        virtual void additionalInputs(sf::Event::EventType eType) = 0;

    public:
        menu();
        ~menu();
        
        void add(interactable* element);

        void mainLoop(sf::RenderWindow* win);

    };
}

#endif //MENU_HPP