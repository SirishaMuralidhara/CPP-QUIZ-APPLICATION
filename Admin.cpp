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
		  cout << "-----------------------------------------------------------------------" << endl;

		  cout << "Enter Quiz ID:"<<endl;
		  getline(cin>>ws,qid);
		  cout << "enter quiz title:"<<endl;
		  getline(cin>>ws, title);
		  cout << "Enter Description:"<<endl;
		  getline(cin>>ws, desc);
		  string question, ch1, ch2, ch3, ch4, answer;
		  cout << "-----------------------------------------------------------------------" << endl;

		  for (int i = 0; i < 10; i++) {

			  cout << "Enter the question:	";
			  getline(cin>>ws, question);
			  cout << "Enter first option:	";
			  getline(cin>>ws,ch1);
			  cout << "Enter second option:";
			  getline(cin>>ws, ch2);
			  cout << "Enter third option:	";
			  getline(cin>>ws,ch3);
			  cout << "Enter fourth option:	";
			  getline(cin>>ws,ch4);
			  cout << "Enter correct answer:	";
			  getline(cin>>ws,answer);

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
	  