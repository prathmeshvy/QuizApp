#include <stdlib.h>
#include <iostream>
#include "MysqlCon.cpp"
#include "User.cpp"
#include "QuizManager.cpp"
#include "Authentication.cpp"
#include "Menu.cpp"
#include "Quiz.cpp"
#include "Question.cpp"





int main()
{
	//connection();
	User user1;
	user1.GetUser();
	user1.DisplayUser();
	

	return 0;
}