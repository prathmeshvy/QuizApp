#include <iostream>
#include <cctype> // for toupper function
#include <stdlib.h>
#include "User.h"
#include "MysqlCon.h"
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "#1Eskoitis";


void Connection::StoreUserInfo(pair<string, string> newuser) {
	sql::PreparedStatement* pstmt;

	try {
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

	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

bool Connection :: RetrieveUserInfo(pair<string, string> UserCredentials) {
	sql::PreparedStatement* pstmtUsername;
	sql::ResultSet* resUsername;
	sql::PreparedStatement* pstmtPassword;
	sql::ResultSet* resPassword;

	bool userFound = false;

	try {

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
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		return false;
	}
}

void Connection :: StoreQuizManagerInfo(pair<string, string> quizmanager) {
	sql::PreparedStatement* pstmt;
	try {

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
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

bool Connection :: RetrieveQuizManagerInfo(pair<string, string> ManagerCredentials) {
	sql::PreparedStatement* pstmtName;
	sql::ResultSet* resName;
	sql::PreparedStatement* pstmtPassword;
	sql::ResultSet* resPassword;



	bool QuizManagerFound = false;

	try {

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
	}
	catch (sql::SQLException& e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		return false;
	}
}

//void AddQuizToDb(string QuizTitle) {
//	sql::Driver* driver;
//	sql::Connection* con;
//	sql::PreparedStatement* pstmt;
//
//	try {
//		driver = get_driver_instance();
//		con = driver->connect(server, username, password);
//		con->setSchema("quickstartdb");
//
//		pstmt = con->prepareStatement("SELECT COUNT(*) FROM quizmgmt WHERE quiztitle = ?");
//		pstmt->setString(1, QuizTitle);
//		sql::ResultSet* res = pstmt->executeQuery();
//		res->next();
//		int count = res->getInt(1);
//		delete res;
//		delete pstmt;
//
//		if (count > 0) {
//			cout << "Quiz title already exists in the database." << endl;
//			return;
//		}
//
//		pstmt = con->prepareStatement("INSERT INTO quizmgmt (quiztitle) VALUES (?)");
//		pstmt->setString(1, QuizTitle);
//		pstmt->executeUpdate();
//
//		cout << "Quiz title added successfully!" << endl;
//
//		delete pstmt;
//		delete con;
//	}
//	catch (sql::SQLException e) {
//		cout << "Could not add quiz title to the database. Error message: " << e.what() << endl;
//		exit(1);
//	}
//}
void Connection:: ShowAllQuizzes() {
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;

	try {
		pstmt = con->prepareStatement("SELECT quiz_id, title FROM quizmgmt order by quiz_id");
		res = pstmt->executeQuery();

		cout << "\nAvailable Quizzes Are:";
		while (res->next()) {
			cout << "\nQuiz " << res->getInt("quiz_id") << " " << res->getString("title") << endl;
		}

		delete pstmt;
		delete res;
	}
	catch (sql::SQLException e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

void Connection:: StartQuiz(int QuizNumber) {
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;

	int Score = 0;
	try {
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
	}
	catch (sql::SQLException e) {
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}
