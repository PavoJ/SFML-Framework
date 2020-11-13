#include "stdafx.hpp"
#include"interactable.hpp"

namespace sff
{
    interactable::interactable()
    {
        pointsCnt = 0;
        pointsOfInterest = nullptr;
        wasHover = false;
        wasClick = false;
    }


    bool interactable::contains(sf::Vector2f point)
    {
        bool ret = false;
        int i = 0;

        while (i < pointsCnt && !ret)
        {
            if (pointsOfInterest[i].contains(point))
                ret = true;
            
            i++;
        }

        return ret;
    }


    bool interactable::getWasHover()
    {
        return wasHover;
    }

    bool interactable::getWasClick()
    {
        return wasClick;
    }
}