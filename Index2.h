#pragma once
#include"E-Library.h"

char PU = ' ';            //Powerful Uchiha (only for Warning issue!) 

using namespace std;

int Studentttt(string Rollnoc) {
A:	system("cls");
	Printmenu();
	int Uchiha;                                  //Signature
	cout << "\t\t\t\t1) Your ID \n";
	cout << "\t\t\t\t2) E-Library \n";
	cout << "\t\t\t\t3) Attendance \n";
	cout << "\t\t\t\t4) Acadamic Report\n";
	cout << "\t\t\t\t5) Complain Box\n";
	cout << "\t\t\t\t6) Time Table\n";
	cout << "\t\t\t\t7) Exit Application\n";
	cout << "\n\n\n\n\nEnter Your Choice : \t";
	cin >> Uchiha;
	if (Uchiha == 1)
	{
		system("cls");
		Printmenu();
		cout << "\x1B[37m";
		cout << "\x1B[31m" << "\n\n\t\t\t\t\tDetail Printer : \n\n\n" << "\x1B[37m";
		cout << "\x1B[33m";
		SearchSTUDENT(Rollnoc);
		int test = SearchSTUDENT(Rollnoc);
		if (test)
		{
			string x;
			fstream STudent;
			STudent.open(Rollnoc);
			if (STudent.is_open()) {
				{
					int i = 0;
					int j = 0;
					while (STudent >> x)
					{
						if (i == 0)
						{
							cout << "Roll Number       : \t" << x << endl;
						}
						else if (i == 1)
						{
							cout << "Student Name      : \t" << x << endl;
						}
						else if (i == 2)
						{
							cout << "Father Name       : \t" << x << endl;
						}
						else if (i == 3)
						{
							cout << "Phone Number      : \t" << x << endl;
						}
						else if (i == 4)
						{
							cout << "Pronoun(Gender)   : \t" << x << endl;
						}
						else if (i == 5)
						{
							cout << "ID-CARD Number    : \t" << x << endl;
						}
						else if (i == 6)
						{
							cout << "Course Discipline : \t" << x << endl;
						}
						else if (i == 7)
						{
							cout << "Batch             : \t" << x << endl;
						}
						else if (i == 8)
						{
							cout << "Section           : \t" << x << endl;
						}
						else if (i == 9)
						{
							cout << "Semester          : \t" << x << endl;
						}
						else if (i == 10)
						{
							cout << "Fee               : \t" << x << endl;
						}
						else if (i == 11)
						{
							cout << "Paid Fee          : \t" << x << endl;
						}
						else
						{

							if (j == 0)
							{
								cout << "\t\t\t\t\t";
							}
							else if (j == 1) {
								cout << "\t\t\t\t";
							}
							else if (j == 4) {
								j = -1;
							}
							cout << x << endl;
							j++;
						}
						i++;
					}
				}
			}
			else
			{
				cout << Error_404;
			}

		}
		else
		{
			cout << Error_405;
		}
		PU = _getch();
		goto A;
	}
	else if (Uchiha == 2)
	{
	elib:	system("cls");
		Printmenu();
		printmenu2();
		cout << "\t\t\t\t1)View all Books \n";
		cout << "\t\t\t\t2)Search a Book \n";
		cout << "\t\t\t\t3)Exit E-Library \n";

		int Uchihaa;                                               //Signature
		cout << "\n\nEnter Your Choice : \t";
		cin >> Uchihaa;
		if (Uchihaa == 1)
		{
			printmenu2();
			cout << "\t\t\t\t4)View all Books \n";
			viewallbooks();
			PU = _getch();
			goto elib;
		}
		else if (Uchihaa == 2)
		{
			printmenu2();
			cout << "\t\t\t\t4)Search a Book \n";
			cout << "Enter the Publication ID of Book :\t";
			string piid;
			cin >> piid;
			viewBook(piid);
			PU = _getch();
			goto elib;
		}
		else if (Uchihaa == 3)
		{
			cout << "\x1b[37m";
			goto A;
		}
		else
		{
			cout << "\t\t\t\t\tInvalid Choice!!\n";
			goto elib;
		}
	}
	else if (Uchiha == 3)
	{
		system("cls");
		Printmenu();
		cout << "\t\t\t\tAttendance";
		checkattendance(Rollnoc);
		PU = _getch();
		goto A;
	}
	else if (Uchiha == 4)
	{
		system("cls");
		Printmenu();
		cout << "\t\t\t\tAcademic Report";
		showresult(Rollnoc);
		PU = _getch();
		goto A;
	}
	else if (Uchiha == 5)
	{
		Stcomplains(Rollnoc);
		goto A;
	}
	else if (Uchiha == 6)
	{
		system("cls");
		Printmenu();
		ifstream tt;
		tt.open("Timetable.txt");
		if (tt.is_open())
		{
			string line;
			while (tt >> line)
			{
				if (line == ".")
				{
					cout << endl;
				}
				else if (line == ";")
				{
					cout << " \t";
				}
				else
				{
					cout << line << " ";
				}

			}
			tt.close();
			cout << "\n\n\n\n\n\t\tDownload Detailed Time Table through link : http\\timetableprojectn2024fd.com\n";
		}
		else
		{
			cout << No_Record << endl;
		}
		PU = _getch();
		goto A;
	}
	else if (Uchiha == 7)
	{
		system("cls");
		Printmenu();
		cout << Program_Completed;
	}
	else
	{
		cout << "\nInvalid Choice!!!!\n";
		Sleep(4000);
		goto A;
	}

	return 0;
}
