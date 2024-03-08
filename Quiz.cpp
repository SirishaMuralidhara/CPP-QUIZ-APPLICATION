#include <iostream>
#include<string>
#include<vector>
#include "Question.h"
#include "Quiz.h"
using namespace std;

Quiz::Quiz()
{
}

Quiz::Quiz(string quizID, string title, string description, vector<Question> q) {
	this->quizID = quizID;
	this->title = title;
	this->description = description;
	this->questions = q;
}