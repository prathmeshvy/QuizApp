#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "User.h"
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "#1Eskoitis";


void StoreUserInfo(pair<string, string> newuser) {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		pstmt = con->prepareStatement("INSERT INTO User(Name, Password) VALUES(?,?)");
		pstmt->setString(1, newuser.first);
		pstmt->setString(2, newuser.second);

		int rowsAffected = pstmt->executeUpdate();

		if (rowsAffected > 0) {
			cout << "\nUser: " << newuser.first << " Stored Successfully!!!\n\n" << endl;
		}
		else {
			cout << "Failed to store user information.\n\n";
		}

		delete pstmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

bool RetrieveUserInfo(pair<string, string> UserCredentials) {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmtUsername;
	sql::ResultSet* resUsername;
	sql::PreparedStatement* pstmtPassword;
	sql::ResultSet* resPassword;

	bool userFound = false;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		// Check if username exists
		pstmtUsername = con->prepareStatement("SELECT * FROM User WHERE BINARY Name = ?");
		pstmtUsername->setString(1, UserCredentials.first);
		resUsername = pstmtUsername->executeQuery();

		if (resUsername->next()) {
			// Username found, now check password
			pstmtPassword = con->prepareStatement("SELECT * FROM User WHERE BINARY Name = ? AND BINARY Password = ?");
			pstmtPassword->setString(1, UserCredentials.first);
			pstmtPassword->setString(2, UserCredentials.second);
			resPassword = pstmtPassword->executeQuery();

			if (resPassword->next()) {
				// Username and password match
				cout << "User: " << resPassword->getString("Name") << " Found" << endl;
				userFound = true;
				return userFound;
			}
			else {
				// Incorrect password
				cout << "Invalid Password" << endl;
			}

			delete pstmtPassword;
			delete resPassword;
		}
		else {
			// Username not found
			cout << "\nUser not found." << endl;
			return false;
		}

		delete resUsername;
		delete pstmtUsername;
		delete con;
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		return false;
	}
}

void StoreQuizManagerInfo(pair<string, string> quizmanager) {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		pstmt = con->prepareStatement("INSERT INTO QuizManager(Name, Password) VALUES(?,?)");
		pstmt->setString(1, quizmanager.first);
		pstmt->setString(2, quizmanager.second);

		int rowsAffected = pstmt->executeUpdate();

		if (rowsAffected > 0) {
			cout << "\nUser: " << quizmanager.first << " Stored Successfully!!!\n\n" << endl;
		}
		else {
			cout << "Failed to store quizmanager information.\n\n";
		}

		delete pstmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

bool RetrieveQuizManagerInfo(pair<string, string> ManagerCredentials) {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmtName;
	sql::ResultSet* resName;
	sql::PreparedStatement* pstmtPassword;
	sql::ResultSet* resPassword;

	bool QuizManagerFound = false;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		// Check if manager name exists
		pstmtName = con->prepareStatement("SELECT * FROM QuizManager WHERE BINARY Name = ?");
		pstmtName->setString(1, ManagerCredentials.first);
		resName = pstmtName->executeQuery();

		if (resName->next()) {
			pstmtPassword = con->prepareStatement("SELECT * FROM QuizManager WHERE BINARY Name = ? AND BINARY Password = ?");
			pstmtPassword->setString(1, ManagerCredentials.first);
			pstmtPassword->setString(2, ManagerCredentials.second);
			resPassword = pstmtPassword->executeQuery();

			if (resPassword->next()) {
				// Manager name and password match
				cout << "QuizManager: " << resPassword->getString("Name") << " Found" << endl;
				QuizManagerFound = true;
				return QuizManagerFound;
			}
			else {
				// Incorrect password
				cout << "Invalid Password" << endl;
			}

			delete pstmtPassword;
			delete resPassword;
		}
		else {
			cout << "QuizManager not found." << endl;
		}

		delete resName;
		delete pstmtName;
		delete con;
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		return false;
	}
}

void ShowAllQuizzes() {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		pstmt = con->prepareStatement("SELECT quiz_id, title FROM quizmgmt order by quiz_id");
		res = pstmt->executeQuery();

		cout << "\nAvailable Quizzes Are:";
		while (res->next()) {
			cout << "\nQuiz " << res->getInt("quiz_id") << " " << res->getString("title") << endl;
		}

		delete pstmt;
		delete res;
		delete con;
	}
	catch (sql::SQLException e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

void StartQuiz(int QuizNumber) {
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;

	int Score = 0;
	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("quickstartdb");

		string query = "SELECT * FROM question WHERE quiz_id = ?";
		pstmt = con->prepareStatement(query);
		pstmt->setInt(1, QuizNumber);

		res = pstmt->executeQuery();

		while (res->next()) {
			cout << "Question: " << res->getString("question_name") << endl;
			cout << "Option " << res->getString("option1") << endl;
			cout << "Option " << res->getString("option2") << endl;
			cout << "Option " << res->getString("option3") << endl;
			cout << "Option " << res->getString("option4") << endl;
			cout << endl;

			cout << "Give Your Option Number:(A/B/C/D): ";
			
			string ChosenOption;
			cin >> ChosenOption;

			for (char& c : ChosenOption) {
				c = toupper(c);
			}

			while (ChosenOption != "A" && ChosenOption != "B" && ChosenOption != "C" && ChosenOption != "D") {
				cout << "Invalid input. Please enter A, B, C, or D: ";
				cin >> ChosenOption;

				for (char& c : ChosenOption) {
					c = toupper(c);
				}
			}

			string CorrectAnswer = res->getString("answer");

			if (ChosenOption == CorrectAnswer) {
				cout << "\nCorrect answer!" << endl;
				Score++;
			}
			else {
				cout << "\nIncorrect answer. The correct answer is: " << CorrectAnswer << endl;
			}

			cout << endl;

		}

		cout << "\nWell Played....Congratulations.....!!!";
		cout << "\nYour score: " << Score << " out of " << res->rowsCount() << endl;

		delete res;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}
