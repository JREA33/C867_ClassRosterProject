#pragma once

#include "student.h"

using namespace std;

class Roster {

private:
	const static int maxStudents = 5;
	const int maxCourses = 3;
	Student* classRosterArray[maxStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	

public:
	Roster();
	~Roster();
	void parseAndAdd(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeeProgram(DegreeProgram degreeProgram);
	string getStuID(int stuID);
};