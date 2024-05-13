#pragma once
#include "Entity.h"
#include "Question.h"

class QuizGUI : public Entity
{
public:
    QuizGUI(Sprite* sprite, sf::Vector2f position = sf::Vector2f(0, 0), float rot = 0, sf::Vector2f scale = sf::Vector2f(1, 1));
    ~QuizGUI();

    bool update(float deltaTime);
    void draw(sf::RenderWindow* window);
    void setQuestion(Question *q);


private:
    bool hold = false;
    sf::RenderWindow* windowPtr;
    Question* question;
    sf::Text questionText;
    sf::Font font;
};

