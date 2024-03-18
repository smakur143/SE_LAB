#include <bits/stdc++.h>
using namespace std;
class student
{
private:
    string name, roll_no, OOP, DBMS,CN, OS,ML;

public:
    void menu();
    void insert();
    void display();
    void modify();
   
};
void student::menu()
{
menustart:
    int choice;
    char x;
    (void)system("cls");

    cout << "-----------------------------" << endl;
    cout << "| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "-----------------------------" << endl;
    cout << " 1. Enter New Record" << endl;
    cout << " 2. Display Record" << endl;
    cout << " 3. Modify Record" << endl;
    cout << " 0. Exit" << endl;

    cout << "---------------------------" << endl;
    cout << "Choose Option:[1/2/3/4]" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    
    case 0:
        exit(0);
    default:
        cout << "\n Invalid choice... Please Try Again..";
    }

    goto menustart;
}
void student::insert() 
{
    (void)system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No.: ";
    cin >> roll_no;
    cout << " Enter OOP: ";
    cin >> OOP;
    cout<< "Enter DBMS: ";
    cin >> DBMS;
    cout << "Enter CN: ";
    cin>> CN;
    cout << " Enter OS: ";
    cin >> OS;
    cout << " Enter ML: ";
    cin >> ML;  
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << OOP << " " << DBMS << " " << CN << " " << OS << " "<< ML  <<"\n";
    file.close();
}

void student::display() 
{
    (void)system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        
        cout << "\nNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> OOP>>DBMS >> CN >> OS >>ML;
        while (!file.eof())
        {
            cout << "\n\n Student No.: " << total++ << endl;
            cout << " Student Name: " << name << endl;
            cout << " Student Roll No.: " << roll_no << endl;
            cout << " Student OOP: " << OOP << endl;
            cout << " Student DBMS: " << DBMS << endl;
            cout << " Student CN: " << CN << endl;
            cout << " Student OS " << OS << endl;
            cout << " Student ML " << ML << endl;
            file >> name >> roll_no >> OOP >> DBMS >> CN >> OS >> ML;
        }
        if (total == 0)
        {
            cout << "\nNo Data Is Present...";
        }
    }
    file.close();
}

void student::modify() 
{
    (void)system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\nNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> OOP >> DBMS >> CN >> OS >> ML;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << OOP << " " << DBMS << " " << CN << " " << OS << " "<< ML<<"\n";
            else
            {
                cout << "\nEnter Name: ";
                cin >> name;
                cout << "Enter Roll No.: ";
                cin >> roll_no;
                cout << "Enter OOP: ";
                cin >> OOP;
                cout << "Enter DBMS: ";
                cin >> DBMS;
                cout << "Enter CN: ";
                cin >> CN;
                cout << "Enter OS: ";
                cin >> OS;
                cout << "Enter ML: ";
                cin >> ML;
                file1 << " " << name << " " << roll_no << " " << OOP << " " << DBMS << " " << CN << " " << OS << " "<< ML <<"\n";
                found++;
            }
            file >> name >> roll_no >> OOP >> DBMS >> CN >> OS >> ML;
            if (found == 0)
            {
                cout << "\n\n Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();
    return 0;
}       
