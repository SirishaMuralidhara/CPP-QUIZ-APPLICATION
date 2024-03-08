#pragma once

#include <iostream>


#include "mysql_connection.h"
using namespace sql;
using namespace std;
#include "Admin.h"



class AdminDao {
public:
	sql::Connection* conn;
	AdminDao(Connection* conn);

	bool checkExistenceA(string admin);
	bool confirmAuthenticationA(string admin, string pass);


	bool addAdmin(Admin ad);

	bool addQuiz(Quiz ob);
/*
	bool checkExistence(string user);
	bool confirmAuthentication(string user, string pass);
	bool addUser(Admin admin);
	*/

};

