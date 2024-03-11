
#include <iostream>
using namespace std;

#include "Application.h"
#include "Result.h"

Connection* Application::establishConnection() {
	DBConnect dbc;
	return (dbc.setConnection());
}
int main()
{

	Application ap;
	UserDao ud(ap.establishConnection());
	AdminDao aDao(ap.establishConnection());
	Admin ad;


	int ch = 0, loggedIn = 0, iAmUser=1,ch1=0;
	string username, password;
	do {
		cout << "Welcome!!!!" << endl;
		cout << "Please enter your choice:" << endl;
		cout << "1. Login, if you an existing user " << endl;
		cout << "2.Register, if you are a new user !" << endl;
		cout << "3.Quiz Manager Login" << endl;
		cout << "4.Exit" << endl;

		cin >> ch;
		switch (ch) {
		case 1:

		{
			cout << endl << "TO LOGIN :" << endl;
			cout << "Enter username:";
			cin >> username;
			cout << endl << "Enter password:";
			cin >> password;

			if (ud.checkExistence(username)) {
				while (!ud.confirmAuthentication(username, password)) {
					password = "";
					cout << "You have entered wrong password!!! Please try again.";
					cout << "Enter password: ";
					cin >> password;
				}
				loggedIn = 1;
				cout << "You have logged in successfully !!" << endl;
				ch = 0;
			}

			break;
		}
		case 2:
		{

			cout << "Enter new username : ";
			cin >> username;
			cout << endl << "Enter password: ";
			cin >> password;
			User u(username, password, 0);
			ud.addUser(u);
			cout << "User registered successfully!!" << endl;
			
			break;
		}
		case 3:
		{
			iAmUser = 0;
			
			do {
			cout << "1. Login, if you an existing quiz manager " << endl;
			cout << "2.Register, if you are a new quiz manager " << endl;
			cin >> ch1;

				switch (ch1) {
				case 1:

				{
					cout << endl << "TO LOGIN :" << endl;
					cout << "Enter username:";
					cin >> username;
					cout << endl << "Enter password:";
					cin >> password;

					if (aDao.checkExistenceA(username)) {
						while (!aDao.confirmAuthenticationA(username, password)) {
							password = "";
							cout << "You have entered wrong password!!! Please try again.";
							cout << "Enter password: ";
							cin >> password;
						}
						loggedIn = 1;
						cout << "You have logged in successfully !!" << endl;
						
						ch = 0;
					}

					break;
				}
				case 2:
				{

					cout << "Enter new username : ";
					cin >> username;
					cout << endl << "Enter password: ";
					cin >> password;
					Admin a(username, password);
					aDao.addAdmin(a);
					cout << "User registered successfully!!" << endl;
					loggedIn == 0;
					break;
				}
				}

			} while (loggedIn != 1);

			ch = 0;
			break;
		}
		case 4: {
			ch = 0;
			break;
		}
		}

	} while (ch != 0);

	if (loggedIn == 1 && iAmUser==1) {
		string uiQuizID;
		do {
			ch = 0;
			//cout << "After login:" << endl;
			cout << endl << "Welcome Again!!" << endl;
			cout << "Enter '1' to take a quiz " << endl;
			cout << "Enter 2 to view your scores  until now !" << endl;
			//cout << "Enter 3 to see progress level based on your history !" << endl;
			cout << "Enter 4 to quit" << endl;
			cin >> ch;
			switch (ch) {
			case 1: {

				cout << "Here, is the list of quizes available to take the quiz :" << endl;
				ud.allQuiz();
				cout << "Enter the QUIZ ID of the quiz you wish to take: " << endl;
				cin >> uiQuizID;
				Quiz  q1 = ud.fetchQuiz(uiQuizID);
				Result r;
				if (r.startQuiz(username, q1)) {
				
				}
				break;
			}
			case 2: {
				cout << "Here is list of scores which quizes you have attended!!";
				if (ud.viewResult(username)) {
					
				}
			}
			case 3:
			{
				cout << "If you wish to view the individual analysis of any quiz , enter its quizID" << endl;
				cin >> uiQuizID;
				ud.viewProgress(username, uiQuizID);
				break;
			}
			case 4: {
				ch = 0;
				break;
			}
			default:
			{
				cout << "Invalid input !!" << "Try again!!" << endl;
			}
			}

		} while (ch != 0);
	}


	if (loggedIn == 1 && iAmUser == 0) {
		do {
			ch = 0;
			cout << "Welcome Again!!" << endl;
			cout << "Enter 1 to add a quiz !" << endl;
			cin >> ch;
			switch (ch) {
			case 1:
			{
				Quiz q = ad.addQuizDetails();
				aDao.addQuiz(q);
				cout << endl;
				break;
			}
			}
			
		} while (ch != 0);
	}


	return 0;
}

	