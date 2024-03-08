#pragma once



#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "Quiz.h"
#include "User.h"
using namespace sql;
using namespace std;


class UserDao {
public:
	sql::Connection* conn;
	bool checkExistence(string user);
	bool confirmAuthentication(string user, string pass);
	bool addUser(User user);
	void allQuiz();

	Quiz fetchQuiz(string quizID);
	UserDao(Connection* conn);
	UserDao();
	
	bool setResult(string user, string quizID, int score, vector<string> answers);
	bool viewResult(string user);
	bool viewProgress(string user, string quizID);

};
