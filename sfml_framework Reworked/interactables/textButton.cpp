#include "interactable.hpp"
#include "textButton.hpp"

namespace sff
{
    void button::updateRectanglePosition()
    {
        sf::FloatRect textBounds = text.getGlobalBounds();

        //sf::Vector2f* pos = new sf::Vector2f;
        //(*pos) = sf::Vector2f( textBounds.width, textBounds.height );

        buttonRect.setSize(sf::Vector2f(textBounds.width, textBounds.height));
        buttonRect.setPosition(text.getPosition());
        //buttonRect.setOrigin((sf::Vector2f){textBounds.width/2, textBounds.height/2});
    }

    button::button()
    {
        pointsOfInterest = nullptr;
        pointsCnt = 0;

        onClick = nullptr;
        onHover = nullptr;
    };

    button::button(const char* displayText, sf::Font& font, unsigned int characterSize)
    {
        pointsOfInterest = nullptr;
        pointsCnt = 0;

        textString = displayText;
        text.setString(textString);

        text.setFont(font);
        text.setCharacterSize(characterSize);

        //for centering the text
        //sf::FloatRect textBounds = text.getGlobalBounds();
        //text.setOrigin((sf::Vector2f){textBounds.width/2, textBounds.height/2});
        
        onClick = nullptr;
        onHover = nullptr;

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
    };

    void button::setOnClick(std::function<void()>& onClick)
    {
        this->onClick = &onClick;
    }

    void button::setOnHover(std::function<void()>& onHover)
    {
        this->onHover = &onHover;
    }

    void button::setPosition(sf::Vector2f& pos) 
    {
        text.setPosition(pos);
        
        updateRectanglePosition();
        updatePointsOfInterest();
    }

    void button::setScale(sf::Vector2f &scale)
    {
        text.setScale(scale);
        buttonRect.setScale(scale);

        updatePointsOfInterest();
    }


    void button::click()
    {
        (*onClick)();
    }

    void button::hover()
    {
        (*onHover)();
    }

    void button::updatePointsOfInterest()
    {
        if (pointsOfInterest != nullptr)
            delete pointsOfInterest;

        pointsOfInterest = new sf::FloatRect;
        pointsCnt = 1;

        pointsOfInterest[0] = buttonRect.getGlobalBounds();
    }

    void button::render(sf::RenderWindow* win)
    {
        win->draw(text);
        win->draw(buttonRect);
    }
}