#include"interactable.hpp"

namespace sff
{
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
}