#pragma once
#include"E-Library.h"

using namespace std;

char EU;            //Elite Uchiha (only for Warning issue!)

int management() {

	//const char* TPptr = new char[9];
	//TPptr = "Teacher";                                              //Main Code
	string TPptr = "Teacher";
	Student ss[10];
	int size;

A: system("cls");
	Printmenu();
	cout << "\t\t\t\t\t\t\tGood Morning!\n\n\n\n\n";

	int Uchiha;
	//MAIN PAGE
	cout << "\t\t\t\t\t 1)Admin ID\n";
	cout << "\t\t\t\t\t 2)Teacher ID\n";
	cout << "\t\t\t\t\t 3)View HOD\n";
	cout << "\t\t\t\t\t 4)View Teacher\n";
	cout << "\t\t\t\t\t 5)View FACALITY_MEMBER(WORKER)\n";
	cout << "\t\t\t\t\t 6)Exit & Save\n";


	cout << "\n\nPlease Enter the Selected Option : \t";
	cin >> Uchiha;
	if (Uchiha == 1) {                                                 //ADMIN MAIN PAGE

	C:	system("cls");
		Printmenu();
		string Username = "Abdul-Rehman", Password = "23L-0787";
		string usernmae, password;
		cout << "\t\t\t\t\t  ADMIN ID\n";
		cout << "\t\t\t\t\t LOG-IN  PAGE\n";
		cout << "Enter your Username : \t";
		cin >> usernmae;
		cout << "Enter your Password : \t";
		cin >> password;
		if (usernmae == Username && password == Password)
		{
			cout << "\n\nLog In Complete Successfully !";
			Sleep(1000);
		D: 	system("cls");
			Printmenu();
			cout << "\n\t\t\t\t\t1)Add Student";
			cout << "\n\t\t\t\t\t2)Print Student";
			cout << "\n\t\t\t\t\t3)Edit Student";
			cout << "\n\t\t\t\t\t4)Add New Courses in Student ID";
			cout << "\n\t\t\t\t\t5)Add HOD";
			cout << "\n\t\t\t\t\t6)Add Teacher";
			cout << "\n\t\t\t\t\t7)Add Worker (Facality)";
			cout << "\n\t\t\t\t\t8)Manage E-Library";
			cout << "\n\t\t\t\t\t9)Go To Main Page";
			string Uchiha2;
			cout << "\n\n\n\nYou can Enter 'C' to open comment box.\nEnter Your choice : ";
			cin >> Uchiha2;
			if (Uchiha2 == "1")                                           //ENTER STUDENT
			{
				system("cls");
				Printmenu();
				cout << "\nEnter the number of students : \t";
				cin >> size;
				takestudentrecord(size, ss);
				goto D;
			}

			else if (Uchiha2 == "2")                                      // STUDENT DETAIL PRINTER
			{
				system("cls");
				Printmenu();
				cout << "\x1B[37m";
				cout << "\x1B[31m" << "\n\n\t\t\t\t\tDetail Printer : \n\n\n" << "\x1B[37m";
				cout << "\x1B[33m";
				string Rollnoc;
				cout << "Please Enter the Roll number of Student :\t";
				cin >> Rollnoc;
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
				EU = _getch();
				goto D;
			}

			else if (Uchiha2 == "3")                                      //  STUDENT DETAIL CHANGER
			{

			B:	cout << "\x1B[37m";
				cout << "\x1B[31m" << "\n\n\t\t\t\t\t\tDetail Changer : \n" << "\x1B[37m";
				cout << "\x1B[33m";
				string Rollnoc;
				cout << "Please Enter the student Roll number of which you want to change the detail : \t";
				cin >> Rollnoc;
				system("cls");
				Printmenu();
				cout << "\x1B[31m" << "\n\n\t\t\t\t\t\tDetail Changer : \n" << "\x1B[37m";
				int test = SearchSTUDENT(Rollnoc);
				if (test)
				{
					string x;
					fstream STudent;
					STudent.open(Rollnoc);
					if (STudent.is_open())
					{

						int i = 0;
						while (STudent >> x)
						{
							if (i == 0)
							{

								cout << "\n\nRoll Number       : \t" << x << endl;
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
								cout << x << "\n";
							}
							i++;
						}
						Student y;
						cout << "Note : Roll Number Should Not be Change! \nPlease Enter Edited Details :\n";
						cin >> y;
						STudent.close();
					

					    STudent.open(Rollnoc);
					   if (STudent.is_open())
					   {
						STudent << y.getRollno() << endl;
						STudent << y.person.getName() << endl;
						STudent << y.person.getFathername() << endl;
						STudent << y.person.getPhonenumber() << endl;
						STudent << y.person.getGender() << endl;
						STudent << y.person.getIDCardnumber()<< endl;
						STudent << y.getDiscipline() << endl;
						STudent << y.getBatch() << endl;
						STudent << y.getSection() << endl;
						STudent << y.getSemesterSeason() << endl;
						STudent << y.getFee() << endl;
						STudent << y.getPaidFee() << endl;
						
						STudent << "\t\t\t\t\t(" << y.getSemesterSeason() << ")\n";
						for (int j = 0; j < y.getnumCourses(); j++)
						{
							STudent << "\t\t\t\tCourse_No.->" << y.sc[j].getNumstc() << "\n";
							STudent << "Course_Name->" << y.sc[j].getCname() << "\t";
							STudent << "Course_Teacher->" << y.sc[j].getCtec() << "\t";
							STudent << "Course_Code->" << y.sc[j].getCcstc() << "\n";
						}

						STudent.close();
						cout << "\n\t\tCongratulations! Student File is Successfully Edited!\n";
						EU = _getch();
					   }
					   else
					   {
						cout << Error_404;
					   }

				    }
					else
					{
						cout << Error_404;
					}
			    }
			    else
			    {
					cout << "\n\t\t\t\tInvalid Roll Number !\n";
			    }
						
					char option1;
					cout << "Press 'A' If you want to change another student's Detail (OR any other key to close the option) : \t";
					cin >> option1;
					if (toupper(option1) == 'A')
					{
						goto B;                     //GO BACK TO EDIT STUSENT
					}
					else {
						goto D;                    //GO BACK TO THE ADMIN PAGE
					}
				
		    }
			else if (Uchiha2 == "4")                    //ADD COURSES IN OLD ID
			{
				system("cls");
				Printmenu();
				addcoursestoold();
				EU = _getch();
				goto D;
			}
			else if (Uchiha2 == "5")                             //Add HOD
			{
				system("cls");
				Printmenu();
				cout << "\n\t\t\t\t\tADDING NEW HOD\n";
				HOD New;
				cin >> New;
				ofstream  Hods;
				Hods.open("HOD's.txt", ios::app);
				Hods << endl << New.getID() << "\t" << New.getName();
				Hods.close();
				ofstream fout;
				fout.open(New.getID(), ios::out);
				if (fout.is_open())
				{
					fout << New.getName() << endl;
					fout << New.getFathername() << endl;
					fout << New.getGender() << endl;
					fout << New.getPhonenumber() << endl;
					fout << New.getIDCardnumber() << endl;
					fout << New.getDepartment() << endl;
					fout << New.getID() << endl;
					fout << New.getPay() << "/-Rupees" << endl;
					fout.close();
					cout << "\n\n\t\t\t\tNew HOD Registered Successfully! \n";
					Sleep(2000);
					goto D;     //GO BACK TO ADMIN PAGE
				}
				else
				{
					cout << "Sorry! Can't create new file. " << endl;
				}

			}


			else if (Uchiha2 == "6")                             //Add TEACHER
			{
				system("cls");
				Printmenu();
				cout << "\n\t\t\t\t\tADDING NEW FACULTY MEMBER\n";
				Teacher New;
				cin >> New;
				ofstream  TEACHERs;
				TEACHERs.open("TEACHER's.txt", ios::app);
				TEACHERs << endl << New.getID() << "\t" << New.getName();
				TEACHERs.close();
				ofstream fout;
				fout.open(New.getID(), ios::out);
				if (fout.is_open())
				{
					fout << New.getName() << endl;
					fout << New.getFathername() << endl;
					fout << New.getGender() << endl;
					fout << New.getPhonenumber() << endl;
					fout << New.getIDCardnumber() << endl;
					fout << New.getDepartment() << endl;
					fout << New.getSection() << endl;
					fout << New.getSubject() << endl;
					fout << New.getID() << endl;
					fout << New.getPay() << "/-Rupees" << endl;
					fout.close();
					cout << "\n\n\t\t\t\tNew Teacher Registered Successfully! \n";
					Sleep(2000);
				}
				else
				{
					cout << "Sorry! Can't create new file. " << endl;
				}
				goto D;              //GO BACK TO ADMIN PAGE
			}

			else if (Uchiha2 == "7")                              //ADD FACULTY
			{
				system("cls");
				Printmenu();
				cout << "\n\t\t\t\t\tADDING NEW FACULTY MEMBER\n";
				FacultyMember New;
				cin>>New;
				ofstream  FacultyMembers;
				FacultyMembers.open("FACALITY_MEMBER's.txt", ios::app);
				FacultyMembers << endl << New.getID() << "\t" << New.getName();
				FacultyMembers.close();
				ofstream fout;
				fout.open(New.getID(), ios::out);
				if (fout.is_open())
				{
					fout << New.getName() << endl;
					fout << New.getFathername() << endl;
					fout << New.getID() << endl;
					fout << New.getDepartment() << endl;
					fout << New.getPhonenumber() << endl;
					fout << New.getIDCardnumber() << endl;
					fout << New.getBuilding() << endl;
					fout << New.getRank() << endl;
					fout << New.getGender() << endl;
					fout << New.getPay() << "/-Rupees" << endl;
					fout.close();
					cout << "\n\n\t\t\t\tNew FACALITY_MEMBER Registered Successfully! \n";
					Sleep(2000);
				}
				else
				{
					cout << "Sorry! Can't create new file. " << endl;
				}
				goto D;              //GO BACK TO ADMIN PAGE

			}
			else if (Uchiha2 == "8")                              //GO BACK TO MAIN PAGE
			{
				int num = 0;
				Book* books = new Book[100];
			G:   printmenu2();
				cout << "\t\t\t\t1)Add  New Book \n";
				cout << "\t\t\t\t2)Edit Old Book \n";
				cout << "\t\t\t\t3)Delete a Book \n";
				cout << "\t\t\t\t4)View all Books \n";
				cout << "\t\t\t\t5)Search a Book \n";
				cout << "\t\t\t\t6)Exit E-Library \n";
				int Uchiha;//Signature
				cout << "\n\nEnter Your Choice : \t";
				cin >> Uchiha;
				if (Uchiha == 1)
				{
					printmenu2();
					cout << "\t\t\t\t1)Add  New Book \n";
					cout << "Enter Number of Books you want to add : \t";
					int n, d = num;
					cin >> n;
					for (int i = d; i < d + n; i++)
					{
						cout << "Book " << i << " : \n";
						books[i].addbook();
						cout << "Book is Successfully added!\n";
						++num;
					}
					goto G;
				}
				else if (Uchiha == 2)
				{
					printmenu2();
					cout << "\t\t\t\t2)Edit Old Book \n";
					string pid;
					cout << "Enter the Publication-ID of the Book (1234)\t";
					cin >> pid;
					Edit(pid);
					cout << "Record Successfully Updated!!\n";
					EU = _getch();
					goto G;
				}
				else if (Uchiha == 3)
				{
					printmenu2();
					cout << "\t\t\t\t3)Delete a Book \n";
					string pid;
					cout << "Enter the Publication-ID of the Book (1234)\t";
					cin >> pid;
					Delete(pid);
					EU = _getch();
					goto G;
				}
				else if (Uchiha == 4)
				{
					printmenu2();
					cout << "\t\t\t\t4)View all Books \n";
					viewallbooks();
					EU = _getch();
					goto G;
				}
				else if (Uchiha == 5)
				{
					printmenu2();
					cout << "\t\t\t\t4)Search a Book \n";
					cout << "Enter the Publication ID of Book :\t";
					string piid;
					cin >> piid;
					viewBook(piid);
					EU = _getch();
					goto G;
				}
				else if (Uchiha == 6)
				{
					delete[] books;
					cout << "\x1b[37m";
					goto D;
				}
				else
				{
					cout << "\t\t\t\t\tInvalid Choice!!\n";
					goto G;
				}

			}
			else if (Uchiha2 == "9")                              //GO BACK TO MAIN PAGE
			{
				goto A;
			}
			else if (Uchiha2 == "C") {
				Adcomplains();
				goto D;
			}

			else {                                              //GO BACK TO ADMIN  PAGE
				goto D;
			}
		}



		else {                                         //GO BACK TO ADMIN LOG IN PAGE
			cout << "Wrong Password!";
			Sleep(1000);
			goto C;
		}


	}
	else if (Uchiha == 2) {                               //TEACHER LOG IN
	F:	system("cls");
		Printmenu();
		cout << "\t\t\t\t\t\tTeacher LOG IN\n\n\n\n";
		string TPassword, TUsername;
		cout << "\t\t\tEnter User-Name     : \t";
		cin >> TUsername;
		cout << "\t\t\tEnter Your Password : \t";
		cin >> TPassword;
		if (TPassword == TPptr && TUsername == TPptr)
		{
		E:	system("cls");                                        //TEACHER MAIN PAGE
			Printmenu();
			cout << "\t\t\t\t\t\tTeacher LOG IN\n\n\n\n";
			cout << "\t\t\t\t\t\t1) Check Student ID\n";
			cout << "\t\t\t\t\t\t2) GPA Registeration\n";
			cout << "\t\t\t\t\t\t3) Teacher Detail \n";
			cout << "\t\t\t\t\t\t4) Mark Attendance\n";
			cout << "\t\t\t\t\t\t5) Upload Course Marks \n";
			cout << "\t\t\t\t\t\t6) Go To Main Page\n\n\n";
			cout << "Enter the selected Option : \t";
			char Uchiha3;
			cin >> Uchiha3;
			switch (Uchiha3)
			{
			case'1': {
				system("cls");
				Printmenu();
				cout << "\x1B[37m";
				cout << "\x1B[31m" << "\n\n\t\t\t\t\tDetail Printer : \n\n\n" << "\x1B[37m";
				cout << "\x1B[33m";
				string Rollnoc;
				cout << "Please Enter the Roll number of Student :\t";
				cin >> Rollnoc;
				SearchSTUDENT(Rollnoc);
				int test = SearchSTUDENT(Rollnoc);
				if (test)
				{
					string x;
					fstream STudent;
					STudent.open(Rollnoc);
					if (STudent.is_open())
					{
						int i = 0, j = 0;
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
					else
					{
						cout << Error_404;
					}
				}
				else
				{
					cout << Error_405;
				}
				EU = _getch();
				goto E;

				break;
			}
			case'2': {
				system("cls");
				Printmenu();
				cout << "\x1B[37m";
				cout << "\x1B[31m" << "\n\n\t\t\t\t\tGPA Registeration\n\n\n" << "\x1B[37m";
				cout << "\x1B[33m";
				string Rollnoc;
				cout << "Please Enter the Roll number of Student :\t";
				cin >> Rollnoc;
				int test = SearchSTUDENT(Rollnoc);

				if (test)
				{
					float SGPA = 0, CGPA = 0;
					//float oldCGPA;
					cout << "Please Enter the SGPA of Student : \t";
					cin >> SGPA;
					if (SGPA >= 0 && SGPA <= 4)
					{
						CGPA = (SGPA + CGPA) / 2;
						//CGPA = SGPA + oldCGPA / 2;
						cout << "Moderated CGPA according to the Given SGPA is : \t" << CGPA;
						cout << "CGPA is Successfully Updated!\n";
						Sleep(2000);
						//EnterGrade(ss.[0],SGPA,CGPA);                  FOR ONLY ONE TIME USE
						goto E;
					}
					else
					{
						cout << "Invalid CGPA!!!\n";
						Sleep(3000);
						goto E;
					}

				}
				else
				{
					cout << "Invalid Roll NO.     !!!!!!!!!!\n";
					Sleep(3000);
					goto E;
				}
				break;
			}
			case'3': {

				system("cls");
				Printmenu();
				string ID_Checker;
				cout << "\n\t\t\t\t\t\tTEACHER DETAIL CHECKER\n\n";
				cout << "Please Enter your Registered ID Number : ";
				cin >> ID_Checker;
				SearchTEACHER(ID_Checker);
				int test = SearchTEACHER(ID_Checker);
				if (test)
				{
					system("cls");
					Printmenu();
					string x;
					fstream fout;
					fout.open(ID_Checker);
					if (fout.is_open())
					{

						int i = 1;
						cout << "\n\t\t\t\t\t\tTEACHER DETAIL CHECKER\n\n";
						while (fout >> x)
						{

							
							if (i == 1)cout << "Teacher name   : \t" << x << endl;
							else if (i == 2)cout << "Father Name    : \t" << x << endl;
							else if (i == 3)cout << "Gender(Pronoun): \t" << x << endl;
							else if (i == 4)cout << "Phone Number   : \t" << x << endl;
							else if (i == 5)cout << "ID-CARD Number : \t" << x << endl;
							else if (i == 6)cout << "Department     : \t" << x << endl;
							else if (i == 7)cout << "Section        : \t" << x << endl;
							else if (i == 8)cout << "Subject        : \t" << x << endl;
							else if (i == 9)cout << "Teacher ID     : \t" << x << endl;
							else if (i == 10)cout << "Pay            : \t" << x << " ";
							else cout << x << endl;
							i++;
						}
						EU = _getch();
						fout.close();
					}
					else
					{
						cout << Error_404;
					}
				}
				else
				{
					cout << "Sorry Sir!\nYou are not Registered as Teacher!\nPlease Consult to the Head Office!\nThank You!\n ";
					Sleep(1000);
				}
				goto E;                //GO TO MAIN PAGE 
				break;
			}
			case'4': {
				system("cls");
				printmenu2();
				cout << "\n\t\t\t\t Mark Attandance\n\n";
				cout << "Enter todays Date : \t";
				string date,rollno;
				cin >> date;
				int x = 1;
				while (x==1)
				{
					cout << "Enter Student Roll Number : \t";
					cin >> rollno;
					attonfile(rollno,date);
					cout << "Enter 1 if you want to mark another attandance : \t";
					cin >> x;
				}
				goto E;
				break;
			}
			case'5': {
				system("cls");
				printmenu2();
				cout << "\n\t\t\t\t Uploading Marks\n\n";
				string  rollno;
				int x = 1;
				while (x == 1)
				{
					cout << "Enter Student Roll Number : \t";
					cin >> rollno;
					UploadMarks(rollno);
					cout << "Enter 1 if you want to Register another Student's Marks.  : \t";
					cin >> x;
				}
				goto E;
				break;
			}
			case'6': {
				goto A;
				break;
			}
			default:
				goto E;
				break;
			}

		}
		else
		{
			goto F;
		}


	}
	else if (Uchiha == 3)              //VIEW HOD
	{
		system("cls");
		Printmenu();
		string ID_Checker;
		cout << "\n\t\t\t\t\t\tHOD DETAIL CHECKER\n\n";
		cout << "Please Enter your Registered ID Number : ";
		cin >> ID_Checker;
		int test = SearchHOD(ID_Checker);
		if (test)
		{
			system("cls");
			Printmenu();
			ifstream hod;
			hod.open(ID_Checker);
			if (hod.is_open())
			{
				string x;
				int i = 1;
				cout << "\n\t\t\t\t\t\tHOD DETAIL CHECKER\n\n";
				while (hod >> x)
				{
					
					if (i == 1)cout << "HOD name       : \t" << x << endl;
					else if (i == 2)cout << "Father Name    : \t" << x << endl;
					else if (i == 3)cout << "Gender(Pronoun): \t" << x << endl;
					else if (i == 4)cout << "Phone Number   : \t" << x << endl;
					else if (i == 5)cout << "ID-CARD Number : \t" << x << endl;
					else if (i == 6)cout << "Department     : \t" << x << endl;
					else if (i == 7)cout << "ID             : \t" << x << endl;
					else if (i == 8)cout << "Pay            : \t" << x << endl;
					else cout << x << endl;
					i++;
				}
				EU = _getch();
				hod.close();
			}
			else
			{
				cout << Error_404;
				Sleep(1000);
			}
		}
		else
		{
			cout << "Sorry Sir!\nYou are not Registered as HOD!\nPlease Consult to the Head Office!\nThank You!\n ";
			Sleep(2000);
		}
		goto A;                //GO TO MAIN PAGE 
	}

	else if (Uchiha == 4)                      //VIEW TEACHER
	{
		system("cls");
		Printmenu();
		string ID_Checker;
		cout << "\n\t\t\t\t\t\tTEACHER DETAIL CHECKER\n\n";
		cout << "Please Enter your Registered ID Number : ";
		cin >> ID_Checker;
		SearchTEACHER(ID_Checker);
		int test = SearchTEACHER(ID_Checker);
		if (test)
		{
			system("cls");
			Printmenu();
			string x;
			fstream fout;
			fout.open(ID_Checker);
			if (fout.is_open())
			{
				cout << "\n\t\t\t\t\t\tTEACHER DETAIL CHECKER\n\n";
				int i = 1;
				while (fout >> x)
				{

					
					if (i == 1)cout << "Teacher name   : \t" << x << endl;
					else if (i == 2)cout << "Father Name    : \t" << x << endl;
					else if (i == 3)cout << "Gender(Pronoun): \t" << x << endl;
					else if (i == 4)cout << "Phone Number   : \t" << x << endl;
					else if (i == 5)cout << "ID-CARD Number : \t" << x << endl;
					else if (i == 6)cout << "Department     : \t" << x << endl;
					else if (i == 7)cout << "Section        : \t" << x << endl;
					else if (i == 8)cout << "Subject        : \t" << x << endl;
					else if (i == 9)cout << "Teacher ID     : \t" << x << endl;
					else if (i == 10)cout << "Pay            : \t" << x << " ";
					else cout << x << endl;
					i++;
				}
				EU = _getch();
				fout.close();
			}
			else
			{
				cout << Error_404;
				Sleep(2000);
			}
		}
		else
		{
			cout << "Sorry Sir!\nYou are not Registered as Teacher!\nPlease Consult to the Head Office!\nThank You!\n ";
			Sleep(1000);
		}
		goto A;                //GO TO MAIN PAGE 

	}

	else if (Uchiha == 5)                      //VIEW FACALITY_MEMBER
	{
		system("cls");
		Printmenu();
		string ID_Checker;
		cout << "\n\t\t\t\t\t\tFACALITY_MEMBER DETAIL CHECKER\n\n";
		cout << "Please Enter your Registered ID : ";
		cin >> ID_Checker;
		SearchFACALITY_MEMBER(ID_Checker);
		int test = SearchFACALITY_MEMBER(ID_Checker);
		if (test)
		{
			system("cls");
			Printmenu();
			string x;
			fstream fout;
			fout.open(ID_Checker);
			if (fout.is_open())
			{
				cout << "\n\t\t\t\t\t\tFACALITY_MEMBER DETAIL CHECKER\n\n";
				int i = 1;
				while (fout >> x)
				{

					
					if (i == 1)cout << "Name          : \t" << x << endl;
					else if (i == 2)cout << "Father Name   : \t" << x << endl;
					else if (i == 3)cout << "ID            : \t" << x << endl;
					else if (i == 4)cout << "Department    : \t" << x << endl;
					else if (i == 5)cout << "Phone Number  : \t" << x << endl;
					else if (i == 6)cout << "ID-CARD Number: \t" << x << endl;
					else if (i == 7)cout << "BUILDING      : \t" << x << endl;
					else if (i == 8)cout << "RANK          : \t" << x << endl;
					else if (i == 8)cout << "GENDER        : \t" << x << endl;
					else if (i == 9)cout << "Pay           : \t" << x << endl;
					else cout << x << endl;
					i++;
				}
				EU = _getch();
				fout.close();
			}
			else
			{
				cout << Error_404;
			}
		}
		else
		{
			cout << "Sorry Sir!\nYou are not Registered as FACALITY_MEMBER!\nPlease Consult to the Head Office!\nThank You!\n ";
			Sleep(3000);
		}
		goto A;                //GO TO MAIN PAGE 

	}
	else if (Uchiha == 6)                   //SAVE AND EXIT
	{
		cout << Program_Completed;
		Sleep(1000);
	}

	else {
		cout << "\t\t\t\tWrong Choice!\n";
		goto A;
	}

	cout << "\x1b[37m";
	cout << "\x1B[32m" << "\n------------------------------------------------------------------------------------------------------------------------\n" << "\x1B[37m" << endl;
	//delete[] TPptr;
	return 0;
}