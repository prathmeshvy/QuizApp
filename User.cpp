#include<iostream>
#include<string>

using namespace std;

class User
{
private:
	string Username;
	string Password;
public:
	User()
	{
		Username = "";
		Password = "";
	}

	void GetUser()
	{
		std::cout << "Enter your username: \n";
		std::cin >> this->Username;
		std::cout << "\nEnter your password: \n ";
		std::cin >> this->Password;
	}

	void DisplayUser() const
	{
		cout << "Username is :\n" << this->Username << "\nPassword is:\n" << this->Password;
	}

	void PlayQuiz()
	{

	}

};
