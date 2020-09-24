#ifndef MENU_HPP
#define MENU_HPP

#include "stdafx.hpp"

#include"interactables/drawable.hpp"
#include"interactables/interactable.hpp"
#include"interactables/textButton.hpp"
#include"interactables/imageButton.hpp"
#include"interactables/sprite.hpp"

#include"linked_list.hpp"
#include"linked_list.cpp"

namespace sff
{
    enum class type
    {
        sffDrawable = 0,
        sfDrawable
    };

    struct element {
        enum class type elType;

        union drawables {
            drawable* sffDraw;
            sf::Drawable* sfDraw;
        } toDraw;
    };

    //Superclass holding the concept of a menu: an interactable with active and passive elements.
    //Interactive elements are buttons, text, dialog boxes...
    //Passive elements are loading screens, scripts running in the background...
    class menu
    {
    protected:
        //drawables
        sff::linked_list<element> drawables;

        //logic
        sff::linked_list<updateable*> updateables;
        sff::linked_list<interactable*> interactables;

        bool menuIsOpen;
        sf::Color clearColor;

        //can handle additional inputs you may want to track
        virtual void additionalInputs(sf::Event::EventType eType) = 0;
        
        clock_t tickTime;
        clock_t elapsedTime;
    public:
        menu();
        virtual ~menu();

        virtual void Update();
        virtual void FixedUpdate();
        
        void add(drawable*);
        void add(sf::Drawable*);
        void add(interactable*);

        void addUpdate(updateable*);

        void mainLoop(sf::RenderWindow* win);

    };
}

#endif //MENU_HPP