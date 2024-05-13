#pragma once

#include <string>
#include <vector>

using namespace std;

struct Question {
    string question;        // The question itself
    vector<string> options; // Possible options
    int correctAnswerIndex;       // Index of the correct option
};