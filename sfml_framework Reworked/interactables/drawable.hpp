#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "stdafx.hpp"

namespace sff
{
    class drawable
    {
    public:
        virtual void setPosition(sf::Vector2f& pos) = 0;
        virtual void setScale(sf::Vector2f& scale) = 0;

        virtual void render(sf::RenderWindow* win) = 0;
    };
}

#endif //DRAWABLE_HPP