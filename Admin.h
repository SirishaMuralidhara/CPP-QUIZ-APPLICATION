#pragma once


class Admin {
public:
	string adminName;
	string password;
	Quiz addQuizDetails();
	Admin();
	Admin(string username, string password);
	
	string getUsernameA();
	string getPasswordA();
};