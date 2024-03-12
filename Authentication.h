#pragma once
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
using namespace std;

class Auth
{
public:
	pair<string, string> user;

	
	void RegisterUser();
	void LoginUser();
	void RegisterQuizManager();
	void LoginQuizManager();

};

#endif //AUTHENTICATION_H