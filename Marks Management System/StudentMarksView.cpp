#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class student
{
	public:
		string name, roll_no, OOP, DBMS, CN, OS, ML;
		void display();
		int totalMarks(); 
};

void student::display()
{
	system("cls");
	fstream file;
	vector<student> students;

	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;

	file.open("studentRecord.txt", ios::in);
	if (!file)
	{
		cout << "\nNo Data Is Present...";
		file.close();
		return;
	}

	while (file >> name >> roll_no >> OOP >> DBMS >> CN >> OS >> ML)
	{
		students.push_back(*this); 
	}
	file.close();

	sort(students.begin(), students.end(), [](student a,student b) {
			return a.totalMarks() > b.totalMarks();
			});

	file.open("sortedStudentRecord.txt", ios::out);
	for (size_t i = 0; i < students.size(); ++i)
	{
		file << students[i].name << " " << students[i].roll_no << " " << students[i].OOP << " " << students[i].DBMS << " " << students[i].CN << " " << students[i].OS << " " << students[i].ML << endl;
	}
	file.close();

	for (size_t i = 0; i < students.size(); ++i)
	{
		cout << "\n\n Student No.: " << i + 1 << endl;
		cout << " Student Name: " << students[i].name << endl;
		cout << " Student Roll No.: " << students[i].roll_no << endl;
		cout << " Student OOP: " << students[i].OOP << endl;
		cout << " Student DBMS: " << students[i].DBMS << endl;
		cout << " Student CN: " << students[i].CN << endl;
		cout << " Student OS " << students[i].OS << endl;
		cout << " Student ML " << students[i].ML << endl;
		cout << " Total Marks "<<students[i].totalMarks()<<endl;
	}
}

int student::totalMarks()
{
	return stoi(OOP) + stoi(DBMS) + stoi(CN) + stoi(OS) + stoi(ML);
}

int main()
{
	student project;
	project.display();
	return 0;
}
