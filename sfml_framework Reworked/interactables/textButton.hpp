#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP

#include "stdafx.hpp"
#include "interactable.hpp"

namespace sff
{
    class textButton : public interactable
    {
    protected:
        sf::Text text;
        sf::String textString;
        
         struct padding_struct{
            float top;
            float bottom;
            float right;
            float left;

            void set(float value);
         } padding;

        sf::RectangleShape buttonRect;

        std::function<void()>* onClick;
        std::function<void()>* leaveOnClick;
        std::function<void()>* onHover;
        std::function<void()>* leaveOnHover;

        void updateRectanglePosition();
        void updatePointsOfInterest();
    public:
        //creates an empty button
        textButton();
        //creates a button
        textButton(const char* displayText, sf::Font &font, unsigned int characterSize = 70U);

        //padding setters
        void setPadding(float value);
        void setPadding(float top, float bottom, float right, float left);
        void setTopPadding(float value);
        void setBottomPadding(float value);
        void setRightPadding(float value);
        void setLeftPadding(float value);

        void setString(const char* str);

        float getRotation();
        void setRotation(float rotation);

        void setFont(sf::Font& font);

        sf::Text* getText();
        sf::RectangleShape* getRectangle();

        padding_struct getPadding();

        void setOnHover(std::function<void()>& onHover);
        void setLeaveOnHover(std::function<void()>& leaveOnHover);
        void setOnClick(std::function<void()>& onClick);
        void setLeaveOnClick(std::function<void()>& leaveOnClick);

        void setPosition(sf::Vector2f &pos);
        void setPosition(float x, float y);

        void setScale(sf::Vector2f &scale);

        void hover();
        void leaveHover();
        void click();
        void leaveClick();

        void render(sf::RenderWindow* win);
    };
}

#endif //TEXTBUTTON_HPP