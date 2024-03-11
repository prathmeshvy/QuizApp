#pragma once
#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include <string>
#include <iostream>
using namespace std;

class QuizManager
{
public:
    pair<string, string>quizmanager;
    pair<string, string>GetQuizManager();
    void AddQuiz();
    void RemoveQuiz();
   
};

#endif // QUIZMANAGER_H
