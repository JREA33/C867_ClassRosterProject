#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//Constructor
Roster::Roster() {

}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < maxStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

//Functions

void Roster::parseAndAdd(string row) {
	
	//Find ID
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	//Find First Name
	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	//Find Last Name
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	//Find email address
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	//Find age
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = std::stoi(row.substr(lhs, rhs - lhs));

	//Find daysInCourse1
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = std::stoi(row.substr(lhs, rhs - lhs));

	//Find daysInCourse2
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = std::stoi(row.substr(lhs, rhs - lhs));

	//Find daysInCourse3
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = std::stoi(row.substr(lhs, rhs - lhs));

	//Find degreeProgram
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string stringDegreeProgram = row.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (stringDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (stringDegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	
	int courseDays[] = {daysInCourse1, daysInCourse2, daysInCourse3};
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
			break;
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int courseDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
			break;
		}
	}
}

bool validStudentID = false;
void Roster::remove(string studentID) {
	cout << "Removing " << studentID << ":" << endl << endl;
	validStudentID = false;
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			if (classRosterArray[i]->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				validStudentID = true;
			}
		}
	}
	if (validStudentID == false) {
		cout << "The student with the ID: " << studentID << " was not found." << endl;
	}
}

void Roster::printAll() {
	cout << "Displaying all students:" << endl << endl;
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->print();
		}
	}
}

int tempID;
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			tempID = i;
		}
	}
	cout << "Student ID: " << classRosterArray[tempID]->getStudentID() << ", average days in course is: " << classRosterArray[tempID]->getAverageDaysInCourses() << endl;
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid email addresses:" << endl << endl;
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i]->validateEmailAddress() == true) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}

void Roster::printByDegreeeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: " << degreeProgram << endl << endl;
	for (int i = 0; i < maxStudents; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

string Roster::getStuID(int stuID) {
	return classRosterArray[stuID]->getStudentID();
}