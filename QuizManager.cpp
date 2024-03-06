#include<iostream>
#include<string>

using namespace std;

class QuizManager
{
private:
	string QuizManagerName;
	string QuizManagerPassword;
public:
	QuizManager()
	{
		QuizManagerName = "";
		QuizManagerPassword = "";
	}

	void GetQuizManager()
	{
		cout << "Enter your username: \n";
		cin >> this->QuizManagerName;
		cout << "\nEnter your password: \n ";
		cin >> this->QuizManagerPassword;
	}

	/*void DisplayQuizManager() const
	{
		cout << "Username is :\n" << this->QuizManagerName << "\nPassword is:\n" << this->QuizManagerPassword;
	}*/

	

};
