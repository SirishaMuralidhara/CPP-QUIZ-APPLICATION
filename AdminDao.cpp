
#include <iostream>
#include <cppconn/prepared_statement.h>

#include "Quiz.h"
#include "mysql_connection.h"
using namespace sql;
using namespace std;
#include "AdminDao.h"



AdminDao::AdminDao(Connection* conn) {
	this->conn = conn;
}

sql::ResultSet* rest;

bool AdminDao::checkExistenceA(string admin) {
	sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT COUNT(*) from admininfo where adminname=?");
	pstmt->setString(1, admin);
	rest = pstmt->executeQuery();
	rest->next();
	if (rest->getInt(1) == 0) {
		return false;
	}
	delete pstmt;
	delete rest;

	return true;
}

bool AdminDao::confirmAuthenticationA(string admin, string pass)
{
	try {


		sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT password from admininfo where adminname=?");
		pstmt->setString(1, admin);

		rest = pstmt->executeQuery();
		rest->next();
		if (pass == rest->getString(1)) {
			return true;
		}
		delete pstmt;
		delete rest;

		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

}



bool AdminDao::addAdmin(Admin ad)
{
	try {
		sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO admininfo VALUES(?,?)");
		pstmt->setString(1, ad.getUsernameA());
		pstmt->setString(2, ad.getPasswordA());
	
		pstmt->execute();
		delete pstmt;
		delete rest;
		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

}





bool AdminDao::addQuiz(Quiz ob)
{

	try {
		//quizID varchar(30),questionID int, question varchar(100),option1 varchar(50),option2 varchar(50),option3 varchar(50),option4 varchar(50),answer varchar(50)
		sql::PreparedStatement* pst = conn->prepareStatement("Insert into quizinfo values(?,?,?)");
		pst->setString(1, ob.quizID);
		pst->setString(2, ob.title);
		pst->setString(3, ob.description);
		pst->execute();
		delete pst;



		
		for (int i = 0; i < 10; i++) {
			sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO questions VALUES(?,?,?,?,?,?,?,?)");
			pstmt->setString(1, ob.quizID);
			pstmt->setInt(2, ob.questions[i].questionID);
			pstmt->setString(3,ob.questions[i].question);
			pstmt->setString(4, ob.questions[i].choices[0]);
			pstmt->setString(5, ob.questions[i].choices[1]);
			pstmt->setString(6, ob.questions[i].choices[2]);
			pstmt->setString(7, ob.questions[i].choices[3]);
			pstmt->setString(8, ob.questions[i].answer);
			pstmt->execute();
			delete pstmt;
		}
		return true;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}

	return false;
}
