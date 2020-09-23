#ifndef MENU_HPP
#define MENU_HPP

#include "stdafx.hpp"

#include"interactables/drawable.hpp"
#include"interactables/interactable.hpp"
#include"interactables/textButton.hpp"
#include"interactables/imageButton.hpp"
#include"interactables/sprite.hpp"

namespace sff
{
    namespace type
    {
        enum
        {
            sffDrawable     = 1,
            sffUpdatable    = 1 << 1,
            sffInteractable =(1 << 2) | sffDrawable,
            sfDrawable      = 1 << 3
        };

    }
    
    struct elements {

        union {
            drawable* sffDraw;
            sf::Drawable* sfDraw;
        } element;
        sf::Uint32 elementType;

        //specifies wether or not the destructor destroys the element
        //when the scene is done, reccomended to true if the element is
        //allocated dynamically
        bool deleteOnSceneEnd;

        struct elements* next;
    };

    //Superclass holding the concept of a menu: an interactable with active and passive elements.
    //Interactive elements are buttons, text, dialog boxes...
    //Passive elements are loading screens, scripts running in the background...
    class menu
    {
    protected:
        elements *el;
        
        elements* getLast(elements* el);

        bool menuIsOpen;
        sf::Color clearColor;

        //can handle additional inputs you may want to track
        virtual void additionalInputs(sf::Event::EventType eType) = 0;

        template<typename T>
        const void* genericAdd(bool deleteOnSceneEnd);
        
        clock_t tickTime;
        clock_t elapsedTime;
    public:
        menu();
        virtual ~menu();

        virtual void Update();
        virtual void FixedUpdate();
        
        void add(drawable*      element, bool deleteOnSceneEnd = false, sf::Uint32 additionalTypes = 0);
        void add(interactable*  element, bool deleteOnSceneEnd = false, sf::Uint32 additionalTypes = 0);
        void add(sf::Drawable*  element, bool deleteOnSceneEnd = false, sf::Uint32 additionalTypes = 0);

        void mainLoop(sf::RenderWindow* win);

    };
}

#endif //MENU_HPP