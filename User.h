#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    int QuizNumber = {};
    pair<string, string>user;
    pair<string,string> GetUser();
    void PlayQuiz();
    //void TrackProgress(string name);
};

#endif // USER_H
