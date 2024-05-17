#include "QuizGUI.h"

QuizGUI::QuizGUI(Sprite* sprite, sf::Vector2f position, float rot, sf::Vector2f scale)
    :Entity(sprite, "quizGUI", position, rot, scale)
{

    if (font.loadFromFile("./res/m6x11plus.ttf"))
    {
        this->questionText.setFont(font);
        this->questionText.setString("");
        this->questionText.setCharacterSize(23);
        this->questionText.setFillColor(sf::Color::White);
        this->questionText.setPosition(position.x, position.y);
        this->questionText.setOrigin(questionText.getGlobalBounds().width, questionText.getGlobalBounds().height);
    }
    else
    {
        std::cout << "Error loading font" << std::endl;
    }
}

QuizGUI::~QuizGUI()
{
}

bool QuizGUI::update(float deltaTime)
{
    Entity::update(deltaTime);

    return false;
}

void QuizGUI::draw(sf::RenderWindow* window)
{
    this->windowPtr = window;
    window->setView(window->getDefaultView()); 

    Entity::draw(window);
    window->draw(questionText);
}

void QuizGUI::setQuestion(Question* q)
{
    question = q;
    questionText.setString(q->question + "\n\n apple - " + q->options[0] + "\n orange - " + q->options[1] + "\n lemon - " + q->options[2] + "\n melon - " + q->options[3]+"\n\n Press e to eat the fruit...");
    questionText.setOrigin(questionText.getGlobalBounds().width / 2, questionText.getGlobalBounds().height / 2);
}


