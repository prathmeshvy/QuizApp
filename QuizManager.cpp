#include "QuizManager.h"

pair<string, string> QuizManager::GetQuizManager()
{
	pair<string, string> quizmanager;

	cout << "\nEnter Your Name:\n";
	cin >> quizmanager.first;
	cout << "\nEnter Your Password:\n";
	cin >> quizmanager.second;

	return quizmanager;
}

void QuizManager::AddQuiz()
{

}

void QuizManager::RemoveQuiz()
{

}
