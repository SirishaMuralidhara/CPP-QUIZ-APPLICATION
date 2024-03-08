#include <iostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;



User::User(string username, string password, int quizTaken) {
	this->username = username;
	this->password = password;
	this->quizTaken = quizTaken;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;;
}

int User::getQuizTaken()
{
	return quizTaken;
}
