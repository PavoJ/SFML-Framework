#include "stdafx.hpp"
#include "interactable.hpp"
#include "textButton.hpp"

namespace sff{

    void textButton::padding_struct::set(float value) {
        top = value;
        right = value;
        bottom = value;
        left = value;
    }

    void textButton::updateRectanglePosition()
    {
        sf::FloatRect textBounds = text.getGlobalBounds();

        sf::Vector2f textBoundsDim(textBounds.width, textBounds.height);
        sf::Vector2f totalPadding(padding.right+padding.left, padding.bottom+padding.top);
        
        buttonRect.setSize(textBoundsDim + totalPadding);
        buttonRect.setOrigin(sf::Vector2f(padding.left, padding.top));

        buttonRect.setPosition(text.getPosition());

        updatePointsOfInterest();
    }

    textButton::textButton()
    {
        pointsOfInterest = nullptr;
        pointsCnt = 0;

        text.setCharacterSize(70);

        padding.set(8);

        onClick = nullptr;
        onHover = nullptr;
        
        buttonRect.setOutlineThickness(1.f);
        buttonRect.setOutlineColor(sf::Color::White);

        buttonRect.setFillColor(sf::Color::Transparent);
        updateRectanglePosition();
    };

    textButton::textButton(const char* displayText, sf::Font &font, unsigned int characterSize)
    {
        pointsOfInterest = nullptr;
        pointsCnt = 0;

        textString = displayText;
        text.setString(textString);

        text.setFont(font);
        text.setCharacterSize(characterSize);

        padding.set(12);

        /*
        //centering the text
        sf::FloatRect textBounds = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f(textBounds.width/2, textBounds.height/2));

        //centering the rectangle
        sf::FloatRect textButtonBounds = buttonRect.getGlobalBounds();
        buttonRect.setOrigin(sf::Vector2f(textBounds.width / 2, textBounds.height / 2));
        */

        onClick = nullptr;
        onHover = nullptr;
        
        buttonRect.setOutlineThickness(1.f);
        buttonRect.setOutlineColor(sf::Color::White);

        buttonRect.setFillColor(sf::Color::Transparent);
        updateRectanglePosition();
    };

    void textButton::setPadding(float value){
        padding.set(value);

        updateRectanglePosition();
    }

    void textButton::setPadding(float top, float bottom, float right, float left) {
        padding = { top, bottom, right, left };

        updateRectanglePosition();
    }

    void textButton::setTopPadding(float value){
        padding.top = value;

        updateRectanglePosition();
    }

    void textButton::setBottomPadding(float value){
        padding.bottom = value;

        updateRectanglePosition();
    }

    void textButton::setRightPadding(float value){
        padding.right = value;

        updateRectanglePosition();
    }

    void textButton::setLeftPadding(float value) {
        padding.left = value;

        updateRectanglePosition();
    }

    void textButton::setString(const char* str)
    {
        textString = str;
        text.setString(textString);

        updateRectanglePosition();
    }

    float textButton::getRotation()
    {
        return text.getRotation();
    }

    void textButton::setRotation(float angle) 
    {
        angle = angle - (float)((int)angle / 360) * 360;

        text.setRotation(angle);
        buttonRect.setRotation(angle);
        
        updatePointsOfInterest();
    }

    void textButton::setFont(sf::Font& font)
    {
        text.setFont(font);
    }


    textButton::padding_struct textButton::getPadding() {
        return padding;
    }


    sf::Text* textButton::getText(){
        return &text;
    }

    sf::RectangleShape* textButton::getRectangle() {
        return &buttonRect;
    }


    void textButton::setOnClick(std::function<void()>& onClick)
    {
        this->onClick = &onClick;
    }

    void textButton::setOnHover(std::function<void()> &onHover)
    {
        this->onHover = &onHover;
    }

    void textButton::setPosition(sf::Vector2f &pos) 
    {
        text.setPosition(pos);
        
        updateRectanglePosition();
        updatePointsOfInterest();
    }

    void textButton::setPosition(float x, float y)
    {
        text.setPosition(x, y);

        updateRectanglePosition();
        updatePointsOfInterest();
    }

    void textButton::setScale(sf::Vector2f &scale)
    {
        text.setScale(scale);
        buttonRect.setScale(scale);

        updatePointsOfInterest();
    }

    void textButton::click()
    {
        if (onHover != nullptr)
            (*onClick)();
    }

    void textButton::hover()
    {
        if(onHover != nullptr)
            (*onHover)();
    }

    void textButton::updatePointsOfInterest()
    {
        if (pointsOfInterest == nullptr)
        {
            pointsOfInterest = new sf::FloatRect;
            pointsCnt = 1;
        }
            

        pointsOfInterest[0] = buttonRect.getGlobalBounds();
    }

    void textButton::render(sf::RenderWindow* win)
    {
        win->draw(text);
        win->draw(buttonRect);
    }
}