#pragma once
#include"Functions.h"


using namespace std;



bool SearchBook(string pid) {
    string temp;
    fstream data;
    data.open("data.txt");
    if (data.is_open())
    {
        while (data >> temp)
        {
            if (pid == temp)
            {

                data.close();
                return true;
            }
        }
    }
    else {
        
    }
    cout << "This Book is not Registered!\n";
    data.close();
    return false;
}


class Book
{
private:
    string pid;       //Publication-ID
    char* title;        //Book Title
    char* author;           //Author Nmae
    int list;                //List of Pattron Subscribers

public:
    Book();
    ~Book();
    void addbook();
    friend void Edit(string pid);

    Book(const Book& obj) {
        pid = obj.pid;
        strcpy_s(title, strlen(obj.title) + 1, obj.title);
        strcpy_s(author, strlen(obj.author) + 1, obj.author);
        this->list = obj.list;
    }
};

Book::Book()
{
    pid = "NULL";
    title = NULL;
    author = NULL;
    list = NULL;
}

Book::~Book()
{
    delete[] title;
    delete[] author;
}

void Book::addbook() {
    ofstream data;
    data.open("data.txt", ios::app);
    if (data.is_open())
    {
        cout << "Enter The Publication-ID of Book (B-1234): \t";
        cin >> pid;
        string str = pid;
        title = new char[50];
        cout << "Enter The title of Book :\t";
        cin.ignore();
        cin.getline(title, 50);
        author = new char[50];
        cout << "Enter author Name : \t";
        cin.getline(author, 50);
        cout << "Enter the Number of Subscribers(60) : \t";
        cin >> list;

        if (!SearchBook(str))
        {
            data << endl;
            data << "Publication-ID-> " << pid << "\t";
            data << "Book-Title->" << title << "\t";
            data << "Author->" << author << "\t";
            data << "Subscribers->" << list << endl;

        }
        else
        {
            cout << "Sorry This Book is already Present!\n";
            Sleep(3000);
        }
        data.close();
    }
    else
    {
        cout << "Sorry!Can't Open Data File!!\n";
    }
}

void printmenu2() {
    system("cls");
    cout << "\x1b[32m" << "\t\t\t\t\t\t***********************\n";
    cout << "\t\t\t\t\t\t*        Welcome      *\n";
    cout << "\t\t\t\t\t\t*   in the E-Library  *\n";
    cout << "\t\t\t\t\t\t***********************\n" ;
    cout << "\n\n------------------------------------------------------------------------------------------------------------------------\n" << "\x1b[37m";
    cout << "\x1b[35m";
}

void viewallbooks() {
    ifstream data;
    string x;
    data.open("data.txt");
    if (data.is_open())
    {
        int i = 0, j = 1;
        cout << "\x1b[31m" << "\n\n\t\t\t\t\t\t(Book 1) \n" << "\x1b[37m";
        while (data >> x)
        {
            cout << x << endl;
            i++;
            if (i == 5)
            {
                i = 0;
                ++j;
                cout << "\x1b[31m" << "\n\n\t\t\t\t\t\t(Book " << j << ")" << "\x1b[37m" << endl;
            }
        }
        data.close();
    }
    else
    {
        cout << "Sorry!Can't Open Data File!!\n";
    }
}

void Edit(string pid) {
    string temp;
    fstream data;
    data.open("data.txt");
    if (data.is_open())
    {
        while (data >> temp)
        {
            if (pid == temp)
            {
                Book obj;
                cout << "Enter The Publication-ID of Book (B-1234): \t";
                cin >> obj.pid;

                obj.title = new char[50];
                cout << "Enter The title of Book :\t";
                cin.ignore();
                cin.getline(obj.title, 50);

                obj.author = new char[50];
                cout << "Enter author Name : \t";
                cin.getline(obj.author, 50);

                cout << "Enter the Number of Subscribers(60) : \t";
                cin >> obj.list;
                data.seekg(-22, ios::cur);
                data << "Publication-ID-> " << obj.pid << "\t";
                data << "Book-Title->" << obj.title << "\t";
                data << "Author->" << obj.author << "\t";
                data << "Subscribers->" << obj.list << "\n";
                data.close();
            }
        }
    }
    else {
        cout << "This Book is not Registered!\n";
    }
    data.close();
}

void viewBook(string pid) {
    string temp;
    fstream data;
    bool search = SearchBook(pid);
    if (search)
    {
        data.open("data.txt");
        if (data.is_open())
        {
            int i = 0;
            while (data >> temp)
            {
                if (pid == temp)
                {
                    cout << "\x1b[31m" << "\t\t\t\t\t(Book Search)\n" << "\x1b[37m";
                    cout << "Book Publication-ID -> " << pid << endl;
                    while (data >> temp)
                    {
                        if (i < 3) {
                            cout << temp << endl;
                            i++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else {

                }
            }
        }
        else
        {
            cout << "System has failed in Opening the File\n";
        }
        data.close();
    }
    
}

void Delete(string pid) {
    string temp;
    fstream data;
    data.open("data.txt");
    if (data.is_open())
    {
        while (data >> temp)
        {
            if (pid == temp)
            {
                data.seekg(-22, ios::cur);
                data << "Publication-ID-> NULL	Book-Title->NULL	Author->NULL	Subscribers->NULL\n";
                cout << "Record Successfully Delleted!!\n";
                data.close();

            }
        }
    }
    else {
        cout << "This Book is not Registered!\n";
    }
    data.close();
}

