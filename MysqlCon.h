#pragma once
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include<iostream>
#include <vector>
#include <cctype> // for toupper function
using namespace std;

void StoreUserInfo(pair<string, string> user);
bool RetrieveUserInfo(pair<string, string> newuser);
void StoreQuizManagerInfo(pair<string, string> quizmanager);
bool RetrieveQuizManagerInfo(pair<string, string> newquizmanager);
void ShowAllQuizzes();
void StartQuiz(int QuizNumber);


#endif // MYSQLCONNECTION_H