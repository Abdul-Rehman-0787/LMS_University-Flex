#pragma once
#include<Windows.h>                //For Sleep
#include<fstream>
#include<conio.h>                   //For _getch();
#include"OOP_Classes.h"

using namespace std;



#define Error_405              "\n==================================== ERROR !!! Input Doesn't Matched=======================================\n"
#define Program_Completed      "\n========================================== Program Completed ==============================================\n"
#define Wrong_Entry            "\n==================================== Wrong User Name or Password !! =======================================\n"
#define No_Record              "\n==================================== Unable to Find any Record !! =========================================\n"
#define Loading                "\n\n\n\n\n\tLoading\x1b[5m.....\x1b[25m\n"
                                   




void Printmenu();                                                             //Functions
bool SearchHOD(string ID_Check);
bool SearchTEACHER(string ID_Check);
bool SearchFACALITY_MEMBER(string ID_Check);
bool SearchSTUDENT(string roll_check);



void Printmenu()                              //Functions
{
	cout << "\x1B[32m" << "\n\t\t\t\t\t\t***********************";
	cout << "\n\t\t\t\t\t\t*     UNIVERSITY      *";
	cout << "\n\t\t\t\t\t\t*        LMS          *";
	cout << "\n\t\t\t\t\t\t*    STUDENT-FLEX     *";
	cout << "\n\t\t\t\t\t\t***********************\n\n" << "\x1B[37m" <<endl;
	cout << "\x1B[32m" << "\n\n------------------------------------------------------------------------------------------------------------------------\n" << "\x1B[37m" << endl;
	cout << "\x1b[33m";
}

bool SearchHOD(string ID_Check) {
	string temp;
	ifstream fout;
	fout.open("HOD's.txt");
	if (fout.is_open())
	{
		while (fout >> temp)
		{
			if (ID_Check == temp)
			{
				fout.close();
				return true;
			}
		}
	}
	else {
		cout << "You are not Registered as HOD!\nPlease consult to the Head Office.\nThank you\n";
		Sleep(3000);
	}
	fout.close();
	return false;
}

bool SearchTEACHER(string ID_Check) {
	string temp;
	ifstream fout;
	fout.open("TEACHER's.txt");
	if (fout.is_open())
	{
		while (fout >> temp)
		{
			if (ID_Check == temp)
			{
				fout.close();
				return true;
			}
		}
	}
	else {
		cout << "You are not Registered as TEACHER!\nPlease consult to the Head Office.\nThank you\n";
		Sleep(3000);
	}
	fout.close();
	return false;
}



bool SearchFACALITY_MEMBER(string ID_Check) {
	string temp;
	ifstream fout;
	fout.open("FACALITY_MEMBER's.txt");
	if (fout.is_open())
	{
		while (fout >> temp)
		{
			if (ID_Check == temp)
			{
				fout.close();
				return true;
			}
		}
	}
	else {
		cout << "You are not Registered as FACALITY_MEMBER !\nPlease consult to the Head Office.\nThank you\n";
		Sleep(2000);
	}
	fout.close();
	return false;
}



bool SearchSTUDENT(string roll_check) {
	string temp;
	ifstream fout;
	fout.open("STUDENT's.txt");
	if (fout.is_open())
	{
		while (fout >> temp)
		{
			if (roll_check == temp)
			{
				fout.close();
				return true;
			}
		}
	}
	else {
		cout << "You are not Registered as STUDENT!\nPlease consult to the Head Office.\nThank you\n";
		Sleep(3000);
	}
	fout.close();
	return false;
}

bool searchstudentinstyle(string rno) {                           //Just for the practice of throw and catch
	bool find = SearchSTUDENT(rno);
	if (find) {
		return true;
	}
	else {
		throw std::runtime_error("No Student ID exist with this Roll Number");
	}
}

void takestudentrecord(int size, Student ss[])            //ADD STUDENT FUNCTION OF OOP_CLASSES
{
	ofstream STUDENTs;
	STUDENTs.open("STUDENT's.txt", ios::app);
	if (STUDENTs.is_open())
	{

		cout << "Please Enter the Student's Deatils :\n";
		for (int i = 1; i <= size; i++)
		{
			cout << "For Student (" << i << ") : \n";
			cin >> ss[i];
			STUDENTs << endl << ss[i].getRollno() << "\t" << ss[i].person.getName();
			STUDENTs.close();
			ofstream fout;
			fout.open(ss[i].getRollno());
			if (!fout.is_open())
			{
				cout << "Sorry!\nCan't create " << ss[i].getRollno() << " File!\n";
			}
			else
			{
				fout << ss[i].getRollno() << endl;
				fout << ss[i].person.getName() << endl;
				fout << ss[i].person.getFathername() << endl;
				fout << ss[i].person.getPhonenumber() << endl;
				fout << ss[i].person.getGender() << endl;
				fout << ss[i].person.getIDCardnumber() << endl;
				fout << ss[i].getDiscipline() << endl;
				fout << ss[i].getBatch() << endl;
				fout << ss[i].getSection() << endl;
				fout << ss[i].getSemesterSeason() << endl;
				fout << ss[i].getFee() << "/-Rupees" << endl;
				fout << ss[i].getPaidFee() << "/-Rupees" << endl;
				

				
				for (int j = 0; j < ss[i].getnumCourses(); j++)
				{
					fout << "\n\t\t\t\t\t(" << ss[i].getSemesterSeason() << ")\n";
					fout << "\t\t\t\tCourse_No.->" << ss[i].sc[j].getNumstc() << "\n";
					fout << "Course_Name->" << ss[i].sc[j].getCname() << "\t";
					fout << "Course_Teacher->" << ss[i].sc[j].getCtec() << "\t";
					fout << "Course_Code->" << ss[i].sc[j].getCcstc() << "\n";
				}

				fout.close();

				cout << "\t\tCongratulation! New Student is Successfully Registered Now.\n";
				Sleep(3000);
			}
		}
	}
	else
	{
		cout << Error_404;
	}

}

int addcoursestoold() {
	cout << "Please Enter the Roll No. of the student : \t";
	string Rollnum;
	cin >> Rollnum;
	cout << "Enter Semester(First->Fall-2024) : \t";
	string sem;
	cin >> sem;
	StCourse c[6];
	int n;
noo: cout << "Enter the number of courses you Want to register : \t";
	cin >> n;
	if (n > 6)
	{
		cout << "Sorry!!!\nA Student can only register maximum 6 Courses!";
		Sleep(4000);
		goto noo;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
		}
		ofstream fout;
		int result = SearchSTUDENT(Rollnum);
		if (result)
		{
			fout.open(Rollnum, ios::app);

			if (!fout.is_open())
			{
				cout << "Sorry!\nCan't create " << Rollnum << " File!\n";
			}
			else
			{
				
				for (int i = 0; i < n; i++)
				{
					fout << "\n\t\t\t\t\t(" << sem << ")" << endl;
					fout << "\t\t\t\tCourse_No.->" << c[i].getNumstc() << "\n";
					fout << "Course_Name->" << c[i].getCname() << "\t";
					fout << "Course_Teacher->" << c[i].getCtec() << "\t";
					fout << "Course_Code->" << c[i].getCcstc() << "\n";
				}
				fout.close();
				cout << "\n\t\tCourse is Added Successfully!!\n";
			}
		}
		else
		{
			cout << Error_404;
		}
	}
	return 0;
}


void checkstd() {                      //not used!!!!
	system("cls");
	Printmenu();
	try 
	{
		cout << "\t\t\t\t\tStudent Verification";
		cout << "Eter the Roll_No of Student : \t";
		string rno;
		cin >> rno;
		bool find = searchstudentinstyle(rno);
		if (find)
		{
			cout << "This Roll_No do Exist!";
		}

	}
	catch (const runtime_error &e) {
		cerr << "Caught an Exception : " << e.what() << endl;

	}
 } 
        

                                                    //Attandence Function with file handling
void attonfile(string Rollno,string Date) {
	bool test = SearchSTUDENT(Rollno);
	if (test)
	{
		ofstream fout;
		fout.open("Attendance.txt", ios::app);
		if (fout.is_open())
		{
			
			cout << "Enter the Attendance Status : \t";
			char st;
			cin >> st;
			st = toupper(st);
			if (st == 'A' || st == 'P' || st == 'L') {
				fout << endl << Rollno << "\t" << Date << "\t" << toupper(st) << "\n";
			}
			//else cout << "\nInvalid Choice!!!\n";
			
			fout.close();
			cout << "\nAttendance Marked Successfully!\n";
			Sleep(1000);
		}
		else
		{
			cout << Error_404;
		}

	}
	else
	{
		cout << "\n\t\t\t Invalid Roll Number! \n";
	}
}


void checkattendance(string Rollno) {                 //RESULT OF ATTANDANCE
	bool test = SearchSTUDENT(Rollno);
	int l = 0, p = 0, a = 0,sp=0;
	if (test)
	{
		ifstream fout;
		fout.open("Attendance.txt");
		if (fout.is_open())
		{
			
			string x,date;
			while (fout >> x)
			{
				if (x == Rollno)
				{
					fout >> date;
					fout >> x;
					if (x == "P")
					{
						p++;
						cout << date << "\t" << "P";
					}
					else if (x == "A")
					{
						a++;
						cout << date << "\t" << "A";
					}
					else if (x == "L")
					{
						l++;
						cout << date << "\t" << "L";
					}
					else {
						cout << "\nError!\n";
					}
				}
			}
			fout.close();
		}
		else
		{
			cout << Error_404;
		}

	}
	else
	{
		cout << "\n\t\t\t Invalid Roll Number! \n";
	}
	cout << "\n\n\t\t\tTotal Presents        : \t" << p << endl;
	cout << "\t\t\tTotal Absenties       : \t" << a << endl;
	cout << "\t\t\tTotal Leaves          : \t" << l << "\n";
	sp = (p - (l / 2));
	int t = p + l + a;
	if (t == 0)
	{
		cout << No_Record;
	}
	else
	{
		int perrr = 0;
		perrr = sp;
		perrr = perrr / t;
		perrr = perrr * 100;
		cout << "\t\t\tAttendance Percentage : \t" << perrr << "%" << endl;
		if (perrr >= 85)
		{
			cout << "\n\tStudent is Eligible for Exams.\n";
		}
		else
		{
			cout << "\n\tStudent is Not Eligible for Exams!!!!!\n";
		}
	}
}


void UploadMarks(string Rollno) {                             //UPLOADING MARKS
	bool test = SearchSTUDENT(Rollno);
	if (test)
	{
		ofstream fout;
		string x;
		fout.open("Marks.txt", ios::app);
		if (fout.is_open())
		{
			fout << Rollno << "\t";
			cout << "Enter subject Name : \t";
			cin >> x;
			fout << x << "\t";
			cout << "Enter Teacher Name : \t";
			cin >> x;
			fout << x << "\t";
			cout << "Enter Total Marks : \t";
			cin >> x;
			fout << x << "\t";
			cout << "Enter Obtained Marks : \t";
			cin >> x;
			fout << x << "\t";
			cout << "Enter Obtained Grade : \t";
			cin >> x;
			fout << x << "\n";
			
			fout.close();
			cout << "\nMarks Uploaded Successfully!\n";
			Sleep(1000);
		}
		else
		{
			cout << Error_404;
		}

	}
	else
	{
		cout << "\n\t\t\t Invalid Roll Number! \n";
	}
}



void showresult(string Rollno) {                             //RESULT OF A STUDENT
	bool test = SearchSTUDENT(Rollno);
	if (test)
	{
		ifstream fout;
		fout.open("Marks.txt", ios::app);
		if (fout.is_open())
		{
			string x;
			int i = 0;
			cout << endl;
			while (fout >> x)
			{
				if (x == Rollno)
				{
					i++;
					cout << "Marks (" << i << ") : \n";

					cout << "Roll Number : \t" << Rollno << endl;
					fout >> x;
					cout << "Subject Name : \t" << x << endl;
					fout >> x;
					cout << "Teacher Name : \t" << x << endl;
					fout >> x;
					cout << "Total Marks : \t" << x << endl;
					fout >> x;
					cout << "Obtained Marks : \t" << x << endl;
					fout >> x;
					cout << "Obtained Grade : \t" << x << endl;
					cout << "\n\n\n\n";

				}
			}
			

			fout.close();
		}
		else
		{
			cout << Error_404;
		}

	}
	else
	{
		cout << "\n\t\t\t Invalid Roll Number! \n";
	}
}

void EnterComplain(string Rollno) {                      //COMPLAIN BOX
	system("cls");
	Printmenu();
	cout << "\t\t\t\tComplain Box\n";
	cout << "Instructions : \n";
	cout << "\t\t* Only Formal complains are accaptable.\n";
	cout << "\t\t* Reply will be given in 72 hours. You are not allowed to visit the office physically before 72 hours.\n";
	ofstream comp;
	comp.open("Complains.txt",ios::app);
	if (comp.is_open())
	{
		cout << "********************************************************************************************\n";
		cout << "Complain : \n\t\t";
		int i = 0;
		string com;
		cin >> com;
		comp << Rollno;
		comp << " -->> ";
		comp << com;
		comp << endl;
		comp.close();
	}

	else {
		cout << Error_404;
	}
}

void Stcomplains(string Rollno) {                           //COMPLAINS FROM STUDENT
	system("cls");
	Printmenu();
	cout << "\t\t\t\tComplain Box\n";
	cout << "Instructions : \n";
	cout << "\t\t* Only Formal complains are accaptable.\n";
	cout << "\t\t* Press 4 to submit your Complain -OR- Any other key to Close.\n";
	cout << "\t\t* Reply will be given in 72 hours. You are not allowed to visit the office physically before 72 hours.\n";
	cout << "********************************************************************************************\n";
	ifstream comp;
	comp.open("Complains.txt");
	if (comp.is_open())
	{
		string x;
		while (comp>>x)
		{
			bool test = SearchSTUDENT(x);
			if (test || x == "@Management")
			{
				cout << endl;
				cout << x << " ";
			}
			else
			{
				cout << x << " ";
			}
			
		}	
		comp.close();
	}
	else
	{
		cout << Error_404;
	}
	string a;
	cin >> a;
	if (a=="4")
	{
		EnterComplain(Rollno);
	}
	else {
		cout << "\n\t\t\t\tClosing Complain Box\n";
		Sleep(800);
	}
}

void Adcomplains() {                                                         //REPLY FROM UNI
	system("cls");
	Printmenu();
	cout << "\t\t\t\tComplain Box\n";
	cout << "Instructions : \n";
	cout << "\t\t* Only Formal complains are accaptable.\n";
	cout << "\t\t* Press 4 to reply\n";
	cout << "\t\t* Give reply as soon as possible.\n";
	cout << "********************************************************************************************\n";
	ifstream comp;
	comp.open("Complains.txt");
	if (comp.is_open())
	{
		string x;
		while (comp >> x)
		{
			bool test = SearchSTUDENT(x);
			if (test || x == "@Management")
			{
				cout << endl;
				cout << x << " ";
			}
			else
			{
				cout << x << " ";
			}

		}
		comp.close();
	}
	else
	{
		cout << Error_404;
	}
	string a;
	cin >> a;
	if (a == "4")
	{
		system("cls");
		Printmenu();
		string Rollno;
		cout << "Menstion the Rollno of Student whome you are going to reply : \t";
		cin >> Rollno;
		cout << "Write your message : \t";
		ofstream comp;
		comp.open("Complains.txt", ios::app);
		if (comp.is_open())
		{
			string com;
			cin >> com;
			int i = 0;
			comp << "@Management";
			comp << " _______ ";
			comp << "@" << Rollno << " -->> ";
			comp << com;
			comp << endl;
			comp.close();
		}

		else {
			cout << Error_404;
		}

	}
	else {
		cout << "\n\t\t\t\tClosing Complain Box\n";
		Sleep(800);
	}
}