#include<iostream>
#include "QuizManager.h"
#include "Quiz.h"
#include "MysqlCon.h"

pair<string, string> QuizManager::GetQuizManager()
{
	pair<string, string> quizmanager;

	cout << "\nEnter Your Name:\n";
	cin >> quizmanager.first;
	cout << "\nEnter Your Password:\n";
	cin >> quizmanager.second;

	return quizmanager;
}

//void QuizManager::AddQuiz()
//{
//	Quiz quiz;
//	string QuizTitle=quiz.GetQuizTitle();
//	AddQuizToDb(QuizTitle);
//
//}

//void QuizManager::RemoveQuiz()
//{
//
//}
