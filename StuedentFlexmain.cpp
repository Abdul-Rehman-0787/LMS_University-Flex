#include"Index.h"
#include"Index2.h"
#include"Snake-Game.h"

using namespace std;

#pragma message ("Bismillahirrehmannirraheem.")

int main() {
	char ch;     
	cout << "\x1b[91m";
	cout << "\n\t\t\t\t\t\x1b[1m\x1b[3mWelcome to our Learning Management System\n\n\n";
	cout << "\n\n\t\t\t\t\t MADE BY :" << endl;
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << "\t\t\t\t\t\tAbdul-Rehman Naseer (23L-0787) " << endl;
	cout << "\t\t\t\t\t---------------------------------------" << endl;
	cout << Loading;
	cout << "\x1b[0m";

	ch = _getch();
	system("cls");
	int Uchiha;                              //Signature
	string Username, Password;
neww:
	system("cls");
	Printmenu();
	cout << "\t\t\t\t1) Student\n";
	cout << "\t\t\t\t2) Management\n";
	cout << "\t\t\t\t3) Exit Menu\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou may play Snake Game by pressing '9' incase of any Server Issue! \n Please Enter your choice : \t";
	cin >> Uchiha;
	if (Uchiha == 1)
	{
	a:	system("cls");
	 	Printmenu();
		std::cout <<  "\n\t\t\t\t\t\t***********************";
		std::cout << "\n\t\t\t\t\t\t*   Student Login     *";
		std::cout << "\n\t\t\t\t\t\t***********************\n\n" << std::endl;
		string stdd = "Student";
		cout << "\n\nEnter the Username : \t";
		cin >> Username;
		cout << "Enter the Password(Roll-Number) : \t";
		cin >> Password;
		int test = SearchSTUDENT(Password);
		if (Username == stdd && test)
		{
			Studentttt(Password);                 //Index2.h
			goto neww;
		}
		else
		{
			cout << Wrong_Entry ;
			Sleep(2000);
			goto a;
		}

	}
	else if (Uchiha == 2)
	{
		

	b:	system("cls"); 
		Printmenu();
		std::cout << "\n\t\t\t\t\t\t***********************";
		std::cout << "\n\t\t\t\t\t\t*  Management Login   *";
		std::cout << "\n\t\t\t\t\t\t***********************\n\n" << std::endl;
		string manag = "US2";
		cout << "\n\nEnter the Username : \t";
		cin >> Username;
		cout << "Enter the Password : \t";
		cin >> Password;
		if (Username==manag && Password==manag)
		{
			management();                   //Index.h
			goto neww;
		}
		else 
		{
			cout << Wrong_Entry;
			Sleep(2000);
			goto b;
		}
	}
	else if (Uchiha == 3)
	{
		std::cout << "\x1b[37m";
		std::cout << "\x1B[32m" << "\n------------------------------------------------------------------------------------------------------------------------\n" << "\x1B[37m" << std::endl;
		std::cout << "\x1b[34m" << Program_Completed;
		

		std::cout << "\t\t\t\t\tThank You for your Trust" << endl;
		std::cout << "\x1b[37m";
		return 1;
	}
	else if (Uchiha==9)
	{
		mainsnake();
		goto neww;
	}
	else
	{
		goto neww;
	}

	return 0;
}

#pragma message ("Allhamdulillah.")