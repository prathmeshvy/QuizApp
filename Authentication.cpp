#include<iostream>
#include "User.h"
#include "Authentication.h"
#include "MysqlCon.h"
#include "QuizManager.h"


using namespace std;


void Auth::RegisterUser()
{
	cout << "-----New User Registration:-----";
	pair<string, string> user;
	User newuser;
	user = newuser.GetUser();
	Connection store;
	store.StoreUserInfo(user);
}

void Auth::LoginUser()
{
	pair<string, string> user;
	User newuser;
	user = newuser.GetUser();
	Connection obj;

	if (obj.RetrieveUserInfo(user)) {
		newuser.PlayQuiz();  //user bhetlyantr quiz start kara
	}
	else
	{
		cout << "Register Before Logging in...\n";
		RegisterUser();
	}
}

void Auth::RegisterQuizManager()
{
	cout << "New Quiz Manager Registration:-";
	pair<string, string> quizmanager;
	QuizManager newquizmanager;
	quizmanager = newquizmanager.GetQuizManager();
	Connection obj;
	obj.StoreQuizManagerInfo(quizmanager);
}

void Auth::LoginQuizManager()
{
	pair<string, string> quizmanager;
	QuizManager newquizmanager;
	quizmanager = newquizmanager.GetQuizManager();
	Connection obj;
	if (obj.RetrieveQuizManagerInfo(quizmanager)) {
		//cout << "\nWhat do you want to do?";
		//cout << "\n1) Add Quiz";
		//cout << "\n2) Remove Quiz";
		//int choice = 0;
		//do {
		//	cout << "\nEnter your choice: ";
		//	cin >> choice;

		//	switch (choice) {
		//	case 1:
		//		//newquizmanager.AddQuiz();
		//		break;
		//	case 2:
		//		cout << "Wait I have to do it...!";
		//		//newquizmanager.RemoveQuiz();
		//		break;
		//	default:
		//		cout << "\nEnter valid Choice!";
		//		break;
		//	}
		//} while (choice != 1 && choice != 2);
	}
	else
	{
		cout << "Register Before Logging in:\n";
		RegisterQuizManager();
	}
}