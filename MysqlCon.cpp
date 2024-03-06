#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "localhost:3306";
const string username = "root";
const string password = "#1Eskoitis";

static void connection()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	//please create database "quickstartdb" ahead of time
	con->setSchema("quickstartdb");

	stmt = con->createStatement();
	//stmt->execute("drop table if exists inventory");
	//cout << "finished dropping table (if existed)" << endl;
	stmt->execute("create table inv (id serial primary key, name varchar(50), quantity integer);");
	cout << "finished creating table" << endl;
	delete stmt;

	pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
	pstmt->setString(1, "banana");
	pstmt->setInt(2, 150);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "orange");
	pstmt->setInt(2, 154);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "apple");
	pstmt->setInt(2, 100);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "mango");
	pstmt->setInt(2, 120);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "kiwi");
	pstmt->setInt(2, 100);
	pstmt->execute();
	cout << "One row inserted." << endl;

	delete pstmt;
	delete con;
	system("pause");

}