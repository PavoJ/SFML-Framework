#ifndef MENU_HPP
#define MENU_HPP

#include"interactables/interactable.hpp"
#include"interactables/textButton.hpp"

#include<SFML\Graphics.hpp>

namespace sff
{

    //Superclass holding the concept of a menu: an interactable with active and passive elements.
    //Interactive elements are buttons, text, dialog boxes...
    //Passive elements are loading screens, scripts running in the background...
    class menu
    {
    protected:
        typedef struct elements {
            interactable* element;
            //specifies wether or not the destructor destroys the element
            //when the scene is done, reccomended to true if the element is
            //allocated dynamically
            bool deleteOnSceneEnd;
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
        virtual ~menu();
        
        void add(interactable* element, bool deleteOnSceneEnd = false);

        void mainLoop(sf::RenderWindow* win);

    };
}

#endif //MENU_HPP