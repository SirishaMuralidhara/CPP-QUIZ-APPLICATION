#pragma once
#include <iostream>
#include<string>
#include<vector>
#include "Question.h"
using namespace std;
class Quiz {
public:
	string quizID;
	string title;
	string description;

	vector<Question> questions;
	
	Quiz();
	Quiz(string quizID,string title,string description,vector<Question> q);

};