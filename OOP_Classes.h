#pragma once
#include <iostream>

using namespace std;

#define Error_404              "\n==================================== ERROR !!! Can't Find this File =======================================\n"

struct Person_S
{
    string Name, Fathername, ID_Cardnumber, Phonenumber, Gender;
};

class Person {                          //Base Class
public:
    Person()
    {
        p.Name = "\0";
        p.Fathername = "\0";
        p.ID_Cardnumber = "\0";
        p.Phonenumber = "\0";
        p.Gender = "\0";
    }

    Person(string n, string f, string i, string pnum, string g)
    {
        p.Name = n;
        p.Fathername = f;
        p.ID_Cardnumber = i;
        p.Phonenumber = pnum;
        p.Gender = g;
    }

    Person(const Person& obj)
    {
        p = obj.p;
    }

    Person& operator=(const Person& obj)
    {
        if (this != &obj)
        {
            p = obj.p;
        }
        return *this;
    }

    bool operator==(const Person& obj) const
    {
        return (p.Name == obj.p.Name &&
            p.Fathername == obj.p.Fathername &&
            p.ID_Cardnumber == obj.p.ID_Cardnumber &&
            p.Phonenumber == obj.p.Phonenumber &&
            p.Gender == obj.p.Gender);
    }

    bool operator!=(const Person& obj) const
    {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& os, const Person& person)
    {
        os << "Name                  : \t" << person.p.Name << "\n"
            << "Father's Name         : \t" << person.p.Fathername << "\n"
            << "ID Card Number        : \t" << person.p.ID_Cardnumber << "\n"
            << "Phone Number          : \t" << person.p.Phonenumber << "\n"
            << "Gender                : \t" << person.p.Gender << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Person& person)
    {

        cout << "Enter Name           : \t";
        is >> person.p.Name;

        cout << "Enter Father's Name  : \t";
        is >> person.p.Fathername;

        cout << "Enter ID Card Number : \t";
        is >> person.p.ID_Cardnumber;

        cout << "Enter Phone Number   : \t";
        is >> person.p.Phonenumber;

        cout << "Enter Gender         : \t";
        is >> person.p.Gender;

        return is;
    }

    ~Person()
    {

    }

    string getName() const
    {
        return p.Name;
    }
    string getFathername() const
    {
        return p.Fathername;
    }
    string getIDCardnumber() const
    {
        return p.ID_Cardnumber;
    }
    string getPhonenumber() const
    {
        return p.Phonenumber;
    }
    string getGender() const
    {
        return p.Gender;
    }

    void setName(const string& n)
    {
        p.Name = n;
    }
    void setFathername(const string& f)
    {
        p.Fathername = f;
    }
    void setIDCardnumber(const string& i)
    {
        p.ID_Cardnumber = i;
    }
    void setPhonenumber(const string& pnum)
    {
        p.Phonenumber = pnum;
    }
    void setGender(const string& g)
    {
        p.Gender = g;
    }

private:
    Person_S p;                                          //Using Structure
};

//Derived Class Management Member
class Managementmember : public Person  //Public Inheritance
{
public:
    Managementmember()
    {
        ID = "\0";
        Department = "\0";
    }

    Managementmember(string n, string f, string i, string p, string g, string id, string dept) : Person(n, f, i, p, g)
    {
        ID = id;
        Department = dept;
    }

    Managementmember(const Managementmember& obj) : Person(obj)
    {
        ID = obj.ID;
        Department = obj.Department;
    }

    Managementmember& operator=(const Managementmember& obj)
    {
        if (this != &obj)
        {
            Person::operator=(obj);
            ID = obj.ID;
            Department = obj.Department;
        }
        return *this;
    }

    bool operator==(const Managementmember& obj) const
    {
        return Person::operator==(obj) && (ID == obj.ID) && (Department == obj.Department);
    }

    bool operator!=(const Managementmember& obj) const
    {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& os, const Managementmember& m)
    {
        os << (Person&)m << "\n"
            << "ID                    : \t" << m.ID << "\n"
            << "Department            : \t" << m.Department << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Managementmember& m)
    {
        is >> (Person&)m;
        cout << "Enter ID             : \t";
        is >> m.ID;
        cout << "Enter Department     : \t";
        is >> m.Department;
        return is;
    }

    string getID() const
    {
        return ID;
    }

    string getDepartment() const
    {
        return Department;
    }

    void setID(string id)
    {
        ID = id;
    }

    void setDepartment(string dept)
    {
        Department = dept;
    }

    ~Managementmember()
    {

    }

private:
    string ID, Department;
};
//Derived class of Mangement Member and Person
class HOD : public Managementmember     //Public Inheritance
{
public:
    HOD() : pay(0) {
    }

    HOD(string n, string f, string i, string p, string g, string id, string dept, int salary) : Managementmember(n, f, i, p, g, id, dept), pay(salary) {

    }

    HOD(const HOD& obj)
        : Managementmember(obj), pay(obj.pay) {
    }

    HOD& operator=(const HOD& obj)
    {
        if (this != &obj)
        {
            Managementmember::operator=(obj);
            pay = obj.pay;
        }
        return *this;
    }

    bool operator==(const HOD& obj) const
    {
        return Managementmember::operator==(obj) && (pay == obj.pay);
    }

    bool operator!=(const HOD& obj) const
    {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& os, const HOD& hod)
    {
        os << (Managementmember&)hod << "\n"
            << "Pay                  : \t" << hod.pay << endl;
        return os;
    }

    friend istream& operator>>(istream& is, HOD& hod)
    {
        is >> (Managementmember&)hod;
        cout << "Enter Pay            : \t";
        is >> hod.pay;
        return is;
    }

    int getPay() const
    {
        return pay;
    }

    void setPay(int salary)
    {
        pay = salary;
    }

    ~HOD() { }

private:
    int pay;
};
//Derived class of Mangement Member and Person
class Teacher : public Managementmember    //Public Inheritance
{
public:
    Teacher() : section("\0"), subject("\0"), pay(0)
    {
    }

    Teacher(string n, string f, string i, string p, string g, string id, string dept, string sec, string sub, int salary)
        : Managementmember(n, f, i, p, g, id, dept), section(sec), subject(sub), pay(salary)
    {
    }

    Teacher(const Teacher& obj)
        : Managementmember(obj), section(obj.section), subject(obj.subject), pay(obj.pay)
    {
    }

    Teacher& operator=(const Teacher& obj)
    {
        if (this != &obj)
        {
            Managementmember::operator=(obj);
            section = obj.section;
            subject = obj.subject;
            pay = obj.pay;
        }
        return *this;
    }

    bool operator==(const Teacher& obj) const
    {
        return Managementmember::operator==(obj) &&
            (section == obj.section) &&
            (subject == obj.subject) &&
            (pay == obj.pay);
    }

    bool operator!=(const Teacher& obj) const
    {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& os, const Teacher& t)
    {
        os << (Managementmember&)t << "\n"
            << "Section              : \t" << t.section << "\n"
            << "Subject              : \t" << t.subject << "\n"
            << "Pay                  : \t" << t.pay << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Teacher& t)
    {

        is >> (Managementmember&)t;
        cout << "Enter Section        : \t";
        is >> t.section;
        cout << "Enter Subject        : \t";
        is >> t.subject;
        cout << "Enter Pay            : \t";
        is >> t.pay;
        return is;
    }

    string getSection() const
    {
        return section;
    }

    string getSubject() const
    {
        return subject;
    }

    int getPay() const
    {
        return pay;
    }

    void setSection(const string& sec)
    {
        section = sec;
    }

    void setSubject(const string& sub)
    {
        subject = sub;
    }

    void setPay(int salary)
    {
        pay = salary;
    }

    ~Teacher()
    {
    }

private:
    string section;
    string subject;
    int pay;
};
//Derived class of Mangement Member and Person
class FacultyMember : public Managementmember             //Public Inheritance
{
public:
    FacultyMember() : Building(""), rank(""), pay(0)
    {
    }

    FacultyMember(string n, string f, string i, string p, string g, string id, string dept, string bldg, string rk, int salary)
        : Managementmember(n, f, i, p, g, id, dept), Building(bldg), rank(rk), pay(salary)
    {
    }

    FacultyMember(const FacultyMember& obj)
        : Managementmember(obj), Building(obj.Building), rank(obj.rank), pay(obj.pay)
    {
    }

    FacultyMember& operator=(const FacultyMember& obj)
    {
        if (this != &obj)
        {
            Managementmember::operator=(obj);
            Building = obj.Building;
            rank = obj.rank;
            pay = obj.pay;
        }
        return *this;
    }

    bool operator==(const FacultyMember& obj) const
    {
        return Managementmember::operator==(obj) &&
            (Building == obj.Building) &&
            (rank == obj.rank) &&
            (pay == obj.pay);
    }

    bool operator!=(const FacultyMember& obj) const
    {
        return !(*this == obj);
    }

    friend ostream& operator<<(ostream& os, const FacultyMember& fm)
    {
        os << (Managementmember&)fm << "\n"
            << "Building             : \t" << fm.Building << "\n"
            << "Rank                 : \t" << fm.rank << "\n"
            << "Pay                  : \t" << fm.pay << endl;
        return os;
    }

    friend istream& operator>>(istream& is, FacultyMember& fm)
    {

        is >> (Managementmember&)fm;
        cout << "Enter Building       : \t";
        is >> fm.Building;
        cout << "Enter Rank           : \t";
        is >> fm.rank;
        cout << "Enter Pay            : \t";
        is >> fm.pay;
        return is;
    }

    string getBuilding() const
    {
        return Building;
    }

    string getRank() const
    {
        return rank;
    }

    int getPay() const
    {
        return pay;
    }

    void setBuilding(const string& bldg)
    {
        Building = bldg;
    }

    void setRank(const string& rk)
    {
        rank = rk;
    }

    void setPay(int salary)
    {
        pay = salary;
    }

    ~FacultyMember()
    {
    }

private:
    string Building;
    string rank;
    int pay;
};


// Course for Students Class
class StCourse {
private:
    int numstc;            // Course number
    string ccstc;          // Course code
    string cname;          // Course name
    string ctec;           // Course teacher

public:
    StCourse() : numstc(0), ccstc("NULL"), cname("NULL"), ctec("NULL") {

    }
    StCourse(int num, string c, string n, string t) : numstc(num), ccstc(c), cname(n), ctec(t) {         //Initializer List

    }
    int getNumstc() const
    {
        return numstc;
    }

    void setNumstc(int num)
    {
        numstc = num;
    }


    string getCcstc() const
    {
        return ccstc;
    }

    void setCcstc(const string& code)
    {
        ccstc = code;
    }


    string getCname() const
    {
        return cname;
    }

    void setCname(const string& name)
    {
        cname = name;
    }


    string getCtec() const
    {
        return ctec;
    }

    void setCtec(const string& teacher)
    {
        ctec = teacher;
    }

    void addCourse(int i, const string& Rollno)
    {

        numstc = i + 1;
        cout << "Enter the Course Code: \t";
        cin >> ccstc;
        cout << "Enter the Course Name: \t";
        cin >> cname;
        cout << "Enter Course Teacher : \t";
        cin >> ctec;


        ofstream fout(Rollno, ios::app);
        if (!fout.is_open())
        {
            cout << Error_404;
        }
        else
        {
            fout << "\t\t\t\tCourse_No.->" << numstc << "\n";
            fout << "Course_Name->" << cname << "\t";
            fout << "Course_Teacher->" << ctec << "\t";
            fout << "Course_Code->" << ccstc << "\n";
            fout.close();
        }
    }


    friend ostream& operator<<(ostream& os, const StCourse& c)
    {
        os << "\n\tCourse Number      : \t" << c.numstc << "\n"
            << "\tCourse Code        : \t" << c.ccstc << "\n"
            << "\tCourse Name        : \t" << c.cname << "\n"
            << "\tCourse Teacher     : \t" << c.ctec << endl;
        return os;
    }


    friend istream& operator>>(istream& is, StCourse& c)
    {
        cout << "Enter Course Number  : \t";
        is >> c.numstc;
        cout << "Enter Course Code    : \t";
        is >> c.ccstc;
        cout << "Enter Course Name    : \t";
        is >> c.cname;
        cout << "Enter Course Teacher : \t";
        is >> c.ctec;
        return is;
    }


    bool operator==(const StCourse& other) const
    {
        return (numstc == other.numstc) && (ccstc == other.ccstc) &&
            (cname == other.cname) && (ctec == other.ctec);
    }

    bool operator!=(const StCourse& other) const
    {
        return !(*this == other);
    }
};


class Student
{
private:
    string Rollno, SemesterSeason, Discipline, Section;
    int Batch, Fee, PaidFee;
    float SGPA, CGPA;
    int numCourses;


public:
    StCourse* sc;            //AGRIGRATION                                 //Public for File Hendling
    Person person;           //COMPOSITION

    Student()
    {
        SGPA = 0;
        CGPA = 0;
        Batch = 0;
        Fee = 0;
        PaidFee = 0;
        numCourses = 0;
        Discipline = "\0";
        SemesterSeason = "\0";
        Rollno = "\0";
        Section = "\0";
        sc = nullptr;
    }

    Student(string roll, string season, string Dis, string s, int batch, int fee, int paid, float sgpa, float cgpa, const Person& p, int num, StCourse* courses)
    {
        Rollno = roll;
        SemesterSeason = season;
        Discipline = Dis;
        Section = s;
        Batch = batch;
        Fee = fee;
        PaidFee = paid;
        SGPA = sgpa;
        CGPA = cgpa;
        person = p;
        numCourses = num;

        if (numCourses > 0)
        {
            sc = new StCourse[numCourses];
            for (int i = 0; i < numCourses; ++i)
            {
                sc[i] = courses[i];
            }
        }
        else
        {
            sc = nullptr;
        }
    }

    Student(const Student& obj)
    {
        Rollno = obj.Rollno;
        SemesterSeason = obj.SemesterSeason;
        Discipline = obj.Discipline;
        Batch = obj.Batch;
        Section = obj.Section;
        Fee = obj.Fee;
        PaidFee = obj.PaidFee;
        SGPA = obj.SGPA;
        CGPA = obj.CGPA;
        person = obj.person;
        numCourses = obj.numCourses;

        if (numCourses > 0)
        {
            sc = new StCourse[numCourses];
            for (int i = 0; i < numCourses; ++i)
            {
                sc[i] = obj.sc[i];
            }
        }
        else
        {
            sc = nullptr;
        }
    }

    Student& operator=(const Student& obj)
    {
        if (this != &obj)
        {
            if (sc)
            {
                delete[] sc;
            }


            Rollno = obj.Rollno;
            SemesterSeason = obj.SemesterSeason;
            Batch = obj.Batch;
            Discipline = obj.Discipline;
            Section = obj.Section;
            Fee = obj.Fee;
            PaidFee = obj.PaidFee;
            SGPA = obj.SGPA;
            CGPA = obj.CGPA;
            person = obj.person;
            numCourses = obj.numCourses;

            if (numCourses > 0)
            {
                sc = new StCourse[numCourses];
                for (int i = 0; i < numCourses; ++i)
                {
                    sc[i] = obj.sc[i];
                }
            }
            else
            {
                sc = nullptr;
            }
        }
        return *this;
    }

    /*void addCourse(const StCourse& newCourse)
    {
        StCourse* temp = new StCourse[numCourses + 1];
        if (numCourses == 0)
        {
            temp[numCourses] = newCourse;
        }
        else
        {
            for (int i = 0; i < numCourses; ++i) {
                temp[i] = sc[i];
            }
            temp[numCourses+1-1] = newCourse;
        }
        if (sc)
        {
            delete[] sc;
        }
        sc = temp;
        numCourses++;
    }*/

    ~Student()
    {
        if (sc)
        {
            delete[] sc;
        }

    }

    void setRollno(const string& roll)
    {
        Rollno = roll;
    }

    void setSemesterSeason(const string& season)
    {
        SemesterSeason = season;
    }

    void setDection(string s) {
        Section = s;
    }
    void setBatch(int b)
    {
        Batch = b;
    }

    void setFee(int f)
    {
        Fee = f;
    }

    void setPaidFee(int pf)
    {
        PaidFee = pf;
    }

    void setSGPA(float sg)
    {
        SGPA = sg;
    }

    void setCGPA(float cg)
    {
        CGPA = cg;
    }

    void setPerson(const Person& p)
    {
        person = p;
    }

    void setnumCourses(int n) {
        numCourses = n;
    }

    void setDiscipline(string d) {
        Discipline = d;
    }

    string getRollno() const
    {
        return Rollno;
    }

    string getSemesterSeason() const
    {
        return SemesterSeason;
    }

    string getSection() {
        return Section;
    }

    int getBatch() const
    {
        return Batch;
    }

    int getnumCourses() const {
        return numCourses;
    }

    int getFee() const
    {
        return Fee;
    }

    int getPaidFee() const
    {
        return PaidFee;
    }

    float getSGPA() const
    {
        return SGPA;
    }

    float getCGPA() const
    {
        return CGPA;
    }

    string getDiscipline() {
        return Discipline;
    }

    Person getPerson() const
    {
        return person;
    }

    void EnterGrade(float GPA, float PA) {
        SGPA = GPA;
        CGPA = PA;

    }

    friend istream& operator>>(istream& is, Student& s)
    {
        cout << "\nEnter Roll Number    : \t";
        is >> s.Rollno;

        is >> s.person;

        cout << "Enter Discipline     : \t";
        is >> s.Discipline;

        cout << "Enter Section        : \t";
        is >> s.Section;

        cout << "Enter Batch          : \t";
        is >> s.Batch;

        cout << "Enter Fee            : \t";
        is >> s.Fee;

        cout << "Enter Paid Fee       : \t";
        is >> s.PaidFee;

        cout << "Enter SGPA           : \t";
        is >> s.SGPA;

        cout << "Enter CGPA           : \t";
        is >> s.CGPA;


        cout << "Enter Semester Detail : \t";
        is >> s.SemesterSeason;

        cout << "\n\n\t\t\t\t\tCourse Registration !\n";
        cout << "Enter the number of courses to register (max 6): ";
        is >> s.numCourses;

        if (s.numCourses > 0 && s.numCourses <= 6)
        {
            if (s.sc)
            {
                delete[] s.sc;
            }
            s.sc = new StCourse[s.numCourses];

            for (int i = 0; i < s.numCourses; ++i)
            {
                cout << "\nEnter details for Course " << i + 1 << ":\n";
                cin >> s.sc[i];
            }
        }
        else
        {
            cout << "Invalid number of courses. No courses will be registered.\n";
            s.numCourses = 0;
            if (s.sc)
            {
                delete[] s.sc;
                s.sc = nullptr;
            }


        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& s)
    {
        os << "\nRoll Number         : \t" << s.Rollno << "\n"
            << "Semester Season      : \t" << s.SemesterSeason << "\n"
            << "Discipline           : \t" << s.Discipline << "\n"
            << "Section              : \t" << s.Discipline << "\n"
            << "Batch                : \t" << s.Batch << "\n"
            << "Fee                  : \t" << s.Fee << "\n"
            << "Paid Fee             : \t" << s.PaidFee << "\n"
            << "SGPA                 : \t" << s.SGPA << "\n"
            << "CGPA                 : \t" << s.CGPA << "\n"
            << s.person;

        if (s.sc)
        {
            os << "\n\t\t\t\tRegistered Courses:\n";
            for (int i = 0; i < s.numCourses; ++i)
            {
                os << "Course " << i + 1 << ":\n" << s.sc[i];
            }
        }
        else
        {
            os << "No courses registered.\n";
        }

        return os;
    }
};