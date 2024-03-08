#pragma once
#include <iostream>
#include <stdlib.h>

#include <vector>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "Quiz.h"
#include "UserDao.h"

using namespace sql;
using namespace std;


sql::Statement* stmt;
sql::ResultSet* res;
sql::ResultSet* result;




UserDao::UserDao(Connection* conn) {
	this->conn = conn;
}

UserDao::UserDao()
{
}



bool UserDao::setResult(string user, string quizID, int score, vector<string> answers)
{

	try {
		sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO result VALUES(?,?,?)");
		pstmt->setString(1,user );
		pstmt->setString(2,quizID);
		pstmt->setInt(3,score);
		pstmt->execute();

		delete pstmt;


		

		for (int i = 0; i < 10; i++) {
			//Progress(username varchar(30),quizID varchar(30),questionID int,userAnswer varchar(30)
			sql::PreparedStatement* pstmt1 = conn->prepareStatement("INSERT INTO progress VALUES(?,?,?,?)");
			pstmt1->setString(1,user);
			pstmt1->setString(2,quizID);
			pstmt1->setInt(3,i+1);
			pstmt1->setString(4,answers[i]);
			pstmt1->execute();
			delete pstmt1;
			
		}
		return true;
		
	}

	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

}

bool UserDao::viewResult(string user)
{
	try {
		sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * from result where username=?");
		pstmt->setString(1, user);

		res = pstmt->executeQuery();
		cout << "Quiz ID" << "    " << "Score(out of 10)" << endl;
		while (res->next()) {
			cout << res->getString("quizID") << "    " << res->getInt("score") << endl;
		}

		delete pstmt;
		delete res;

		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

}

bool UserDao::viewProgress(string user, string quizID)
{
	try{
	sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * from progress where username=? and quizID=?");
	pstmt->setString(1, user);
	pstmt->setString(2, quizID);

	res = pstmt->executeQuery();
	//cout << "Quiz ID" << "    " << "Score(out of 10)" << endl;
	cout << "QuestionID" << "          " << "User Answer" << endl;

	while (res->next()) {
		cout << res->getString("questionID") << "                  " << res->getString("userAnswer") << endl;
	}

	delete pstmt;
	delete res;


	return true;
  }
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

	
}



bool UserDao::checkExistence(string user){
	sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT COUNT(*) from userinfo where username=?");
	pstmt->setString(1, user);
	result = pstmt->executeQuery();
	result->next();
	if (result->getInt(1) == 0) {
		return false;
	}
	delete pstmt;
	delete result;
	
	return true;
}

bool UserDao::confirmAuthentication(string user,string pass)
{
	try {


		sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT password from userinfo where username=?");
		pstmt->setString(1, user);

		result = pstmt->executeQuery();
		result->next();
		if (pass == result->getString(1)) {
			return true;
		}
		delete pstmt;
		delete result;

		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

}

bool UserDao::addUser(User user)
{
	try {
		sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO userinfo VALUES(?,?,?)");
		pstmt->setString(1, user.getUsername());
		pstmt->setString(2, user.getPassword());
		pstmt->setInt(3, user.getQuizTaken());
		pstmt->execute();
		delete pstmt;
		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
	
}



void UserDao::allQuiz() {
	vector<vector<string>> result;
	//stmt = conn->createStatement();
	sql::PreparedStatement* pstmt= conn->prepareStatement("SELECT quizID,title,description from quizinfo");
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "Quiz ID : " << res->getString("quizID")<<endl;
		cout << "TITLE: " << res->getString("title")<<endl;
		cout << "DESCRIPTION: " << res->getString("description")<<endl;

	}
	delete res;
	delete pstmt;
}



Quiz UserDao::fetchQuiz(string quizIDd)
{
	Quiz ob;
	try {
	sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT quizID,title,description from quizinfo where quizID = ?");
	pstmt->setString(1, quizIDd);

	res = pstmt->executeQuery();
	while (res->next()) {
		ob.quizID = res->getString("quizID");
		ob.title = res->getString("title");
		ob.description = res->getString("description");
		
		
	}
	delete pstmt;
	delete res;

	sql::PreparedStatement* pst = conn->prepareStatement("SELECT * from questions where quizID = ?");
	pst->setString(1, quizIDd);

	res = pst->executeQuery();
	string question, ch1, ch2, ch3, ch4, ans;
	int qid;

	while (res->next()) {
		int i = 0;
		qid = res->getInt("questionID");
		question= res->getString("question");
		ch1 = res->getString("option1");
		ch2 = res->getString("option2");
		ch3 = res->getString("option3");
		ch4 = res->getString("option4");
		ans = res->getString("answer");

		vector<string> choices = { ch1, ch2, ch3, ch4 };

		Question q;
		q.question = question;
		q.choices = choices;
		q.questionID = i;
		q.answer = ans;
		ob.questions.push_back(q);
		i++;
	}
	delete pst;
	delete res;
	return ob;

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}


