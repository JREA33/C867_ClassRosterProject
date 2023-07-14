#pragma once

#include <string>
#include "degree.h"

using namespace std;

class Student {
public:

	const static int maxCourses = 3;

	//Constructors
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram);
	~Student();
	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getCourseDays(int i);
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseDays(int courseDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print Student Info
	void print();

	//Function for Average Days in Course
	double getAverageDaysInCourses();

	//Function to Validate Email Address
	bool validateEmailAddress();


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[maxCourses];
	DegreeProgram degreeProgram;
	string strDegreeProgram[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

};