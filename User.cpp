#include "User.h"
#include "MysqlCon.h";

pair<string,string> User::GetUser()
{
	pair<string, string> user;

	cout << "\nEnter Your Name:\n";
	cin >> user.first;
	cout << "\nEnter Your Password:\n";
	cin >> user.second;

	return user;
}


void User::PlayQuiz()
{
	cout << "\n-----Welcome to Quiz Mania-----";
	ShowAllQuizzes();
	cout << "\n-----Enter the quiz number you want to play-----\n";
	cin >> QuizNumber;	//getting quiz number from user
	StartQuiz(QuizNumber);

}

//void User::TrackProgress(string name) {
//
//}

