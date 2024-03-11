#include <iostream>
#include<string>
#include<vector>
#include "Result.h"
#include "UserDao.h"
#include "DBConnect.h"


Result::Result()
{
}

Result::Result(string quizID, string username, int score, vector<string> answers)
{
	this->quizID = quizID;
	this->answers = answers;
	this->score = score;
	this->username = username;
}

bool Result::startQuiz(string username,Quiz ob)
{

	score = 0;
	string ans;
	cout << "Lets Begin!!!!";
	cout << "Enter the spellings of each answer carefully!!" << endl;
	cout << " ----------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < 10; i++) {
		cout << i+1<<"=>"<<ob.questions[i].question<<endl;
		cout <<"a)" <<ob.questions[i].choices[0] << endl;
		cout << "b)" << ob.questions[i].choices[1] << endl;
		cout << "c)" << ob.questions[i].choices[2] << endl;
		cout << "d)" << ob.questions[i].choices[3] << endl;
		getline(cin >>ws, ans);
		answers.push_back(ans);
		
		if (ans == ob.questions[i].answer) {
			score= score+1;
		}
		ans = "";
	}

	cout << "Quiz successfully completed !!"<<endl;
	cout << " ----------------------------------------------------------------------------" << endl;
	cout << "YOUR  SCORE IS " << score << " out of 10" << endl;
	cout << " ----------------------------------------------------------------------------" << endl;

	DBConnect db;
	UserDao o(db.setConnection());
	string qid = ob.quizID;
	 bool x=o.setResult(username,qid,score,answers);

	score = 0;
	return x;
}
