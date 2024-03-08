#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
private:
	string username;
	string password;
	int quizTaken;
public:
	User(string user, string pass, int quizTaken);
	string getUsername();
	string getPassword();
	int getQuizTaken();
};