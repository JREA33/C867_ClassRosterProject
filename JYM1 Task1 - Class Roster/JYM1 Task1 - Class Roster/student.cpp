#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Constructors and Destructors
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newCourseDays[], DegreeProgram newDegreeProgram) {
	setStudentID(newStudentID);
	setFirstName(newFirstName);
	setLastName(newLastName);
	setEmailAddress(newEmailAddress);
	setAge(newAge);
	setCourseDays(newCourseDays);
	setDegreeProgram(newDegreeProgram);
}

Student::~Student() {

}

//Getters
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int Student::getCourseDays(int i) {
	return courseDays[i];
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//Setters
void Student::setStudentID(string newStudentID) {
	studentID = newStudentID;
}

void Student::setFirstName(string newFirstName) {
	firstName = newFirstName;
}

void Student::setLastName(string newLastName) {
	lastName = newLastName;
}

void Student::setEmailAddress(string newEmailAddress) {
	emailAddress = newEmailAddress;
}

void Student::setAge(int newAge) {
	age = newAge;
}

void Student::setCourseDays(int newCourseDays[]) {
	for (int i = 0; i < maxCourses; i++) {
		courseDays[i] = newCourseDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
	degreeProgram = newDegreeProgram;
}


//Print Student Info
void Student::print() {
	cout << getStudentID() << "\t" << getFirstName() << "\t" << getLastName() << "\t" << getAge() << "\t";
	cout << "{";
	cout << courseDays[0];
	for (int i = 1; i < maxCourses; ++i) {
		cout << ", " << getCourseDays(i);
	}
	cout << "}\t";
	cout << strDegreeProgram[getDegreeProgram()] << endl;
}

//Figure Average Days in Courses
double Student::getAverageDaysInCourses() {
	int sum = 0;
	for (int i = 0; i < maxCourses; ++i) {
		sum += courseDays[i];
	}
	return sum / maxCourses;
}

bool Student::validateEmailAddress() {
	if (emailAddress.find("@") == string::npos) {
		return true;
	}
	if (emailAddress.find(".") == string::npos) {
		return true;
	}
	if (emailAddress.find(" ") != string::npos) {
		return true;
	}
	else {
		return false;
	};
}