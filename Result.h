#pragma once
#include "Quiz.h"
using namespace std;
class Result {
public:
	string quizID;
	string username;
	int score;

	vector<string> answers;
	Result();
	Result(string quizID, string username, int score,vector<string> answers);
	bool startQuiz(string username,Quiz ob);

};