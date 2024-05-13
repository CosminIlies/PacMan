#include "QuizManager.h"

QuizManager* QuizManager::instance = nullptr;


bool QuizManager::answerQuestion(int answer)
{
    
    bool res = questions[activeQuestion]->correctAnswerIndex == answer;
    chooseRandomQuestion();
    return res;
}

void QuizManager::chooseRandomQuestion()
{
	activeQuestion = rand() % questions.size();
    gui->setQuestion(getActiveQuestion());
}

// Function to read questions from a file
void QuizManager::readQuestionsFromFile(const std::string& filename) {
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        Question* q = new Question();
        q->question = line;  // Read the question

        // Read the options
        for (int i = 0; i < 4; ++i) {
            getline(file, line);
            q->options.push_back(line);
        }

        getline(file, line); // Read the correct answer index
        q->correctAnswerIndex = stoi(line);
        questions.push_back(q);

        getline(file, line); // Skip the empty line between questions
    }

    file.close();
}

void QuizManager::setGUI(QuizGUI* gui)
{
    this->gui = gui;
}

Question* QuizManager::getActiveQuestion()
{
    return questions[activeQuestion];
}


QuizManager::~QuizManager()
{
}

QuizManager::QuizManager()
{
    readQuestionsFromFile("./res/quiz.txt");
}

QuizManager* QuizManager::getInstance()
{
    if(instance == nullptr)
	{
		instance = new QuizManager();
	}
    return instance;
}
