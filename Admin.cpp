#include <iostream>
#include "Quiz.h"
#include "Question.h"
#include "Admin.h"

	  Admin::Admin(string username, string password) {
		  this->adminName = username;
		  this->password = password;
		
	  }

	 

	
	  string Admin::getUsernameA()
	  {
		  return adminName;
	  }

	  string Admin::getPasswordA()
	  {
		  return password;;
	  }

	  Quiz Admin::addQuizDetails() {

		  vector<Question> questions;
		  string title, desc, qid;
		  cout << "Fill quiz details"<<endl;

		  cout << "Enter Quiz ID:"<<endl;
		  getline(cin,qid);
		  cout << "enter quiz title:"<<endl;
		  getline(cin, title);
		  cout << "Enter Description:"<<endl;
		  getline(cin, desc);
		  string question, ch1, ch2, ch3, ch4, answer;

		  for (int i = 0; i < 10; i++) {

			  cout << "Enter the question:";
			  getline(cin, question);
			  cout << "Enter first option:";
			  getline(cin,ch1);
			  cout << "Enter second option:";
			  getline(cin, ch2);
			  cout << "Enter third option:";
			  getline(cin,ch3);
			  cout << "Enter fourth option:";
			  getline(cin,ch4);
			  cout << "Enter correct answer:";
			  getline(cin,answer);

			  vector<string> choices = { ch1, ch2, ch3, ch4 };

			  Question q;
			  q.question = question;
			  q.choices = choices;
			  q.questionID = i+1;
			  q.answer = answer;

			  questions.push_back(q);

		  }

		  Quiz quiz(qid, title, desc, questions);
		  return quiz;
	  }

	  Admin::Admin()
	  {
	  }
	  