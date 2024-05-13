#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include "QuizGUI.h"
#include "Question.h"

using namespace std;

class QuizManager {

public:

    ~QuizManager();

    
    static QuizManager* getInstance();



    // Function prototypes
    bool answerQuestion(int answer);
    void chooseRandomQuestion();
    void readQuestionsFromFile(const string& filename);
    void setGUI(QuizGUI* gui);
    Question* getActiveQuestion();

    private:
        int activeQuestion;
        QuizGUI* gui;
        vector<Question*> questions;
        static QuizManager* instance;
        QuizManager();
};

#define QuizManagerInstance QuizManager::getInstance()
