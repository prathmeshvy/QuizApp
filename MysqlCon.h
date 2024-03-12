#pragma once
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include <vector>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class Connection {

private:
	const string server = "localhost:3306";
	const string username = "root";
	const string password = "#1Eskoitis";
	sql::Driver* driver = get_driver_instance();
	sql::Connection* con = driver->connect(server, username, password);

public:

	Connection() {
		con->setSchema("quickstartdb");
	}

	~Connection() {
		delete con;
	}
	void StoreUserInfo(pair<string, string> user);
	bool RetrieveUserInfo(pair<string, string> newuser);
	void StoreQuizManagerInfo(pair<string, string> quizmanager);
	bool RetrieveQuizManagerInfo(pair<string, string> newquizmanager);
	//void AddQuizToDb(string QuizTitle);
	void ShowAllQuizzes();
	void StartQuiz(int QuizNumber);

};

#endif // MYSQLCONNECTION_H