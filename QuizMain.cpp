#include <stdlib.h>
#include <iostream>
#include <limits>
#include "User.h"
#include "Authentication.h"

void Menu() {
	Auth auth;

	do {
		int choice;
		cout << "\n1. Register As User\n2. Login As User\n3. Register As QuizManager\n4. Login As QuizManager\n5. Exit\n\n";
		cout << "Enter your choice: ";

		if (!(cin >> choice)) {
			cout << "Invalid input. Please enter a valid choice between 1 to 5 ." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (choice) {
		case 1:
			cout << "\nFor Registering User:\n";
			auth.RegisterUser();
			break;
		case 2:
			cout << "\nFor Logging in as User:\n";
			auth.LoginUser();
			break;
		case 3:
			cout << "\nfor registering quizmanager:\n";
			auth.RegisterQuizManager();
			break;
		case 4:
			cout << "\nfor logging in as quizmanager:\n";
			auth.LoginQuizManager(); 
			break;
		case 5:
			cout << "\n-----Exiting...-----\n";
			exit(0);
		default:
			cout << "Invalid entry please give choice between 1 to 5 \n";
			break;
		}
	} while (true);
}

int main()
{

	Menu();
	return 0;
}