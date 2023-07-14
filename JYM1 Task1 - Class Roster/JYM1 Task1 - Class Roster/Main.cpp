#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

void courseInfo() {
	cout << "C867 Scripting and Programming - Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU StudentID: 001522405" << endl;
	cout << "Joshua Rea" << endl;
}

int main() {
	const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Josh,Rea,jrea13@wgu.edu,30,21,44,36,SOFTWARE"};

	courseInfo();

	cout << endl;

	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parseAndAdd(studentData[i]);
	}

	classRoster.printAll();

	cout << endl;

	classRoster.printInvalidEmails();

	cout << endl;

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getStuID(i));
	}

	cout << endl;

	classRoster.printByDegreeeProgram(SOFTWARE);

	cout << endl;

	classRoster.remove("A3");

	classRoster.printAll();
	
	cout << endl;

	classRoster.remove("A3");

	return 0;
}