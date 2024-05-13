#include "QuizGUI.h"

QuizGUI::QuizGUI(Sprite* sprite, sf::Vector2f position, float rot, sf::Vector2f scale)
    :Entity(sprite, "quizGUI", position, rot, scale)
{

    if (font.loadFromFile("res/square-deal.ttf"))
    {
        this->questionText.setFont(font);
        this->questionText.setString("");
        this->questionText.setCharacterSize(26);
        this->questionText.setFillColor(sf::Color::White);
        this->questionText.setPosition(position.x, position.y);
        this->questionText.setOrigin(400, 0);
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
    window->setView(window->getDefaultView()); // ma simt jeat ca las asta aici

    Entity::draw(window);
    window->draw(questionText);
}

void QuizGUI::setQuestion(Question* q)
{
    question = q;
    questionText.setString(q->question + "\n\n apple " + q->options[0] + "\n orange " + q->options[1] + "\n lemon " + q->options[2] + "\n melon " + q->options[3]);
}


