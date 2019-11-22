#pragma once
#include "student.h"
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>



class roster
{
public:
	roster(); 
	roster(int rosterMaxSize);
	~roster();

	void parseData(std::string row); // use this to extract data to be used in add method 
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	bool remove(std::string studentID); //removes students from the roster by student ID
	void printAll(); 
	void printDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	void printTitleInfo();

	student * getStudentAt(int index);
	
	
private:
	student** classRosterArray; //array of pointers to students
	int rosterMaxSize;
	int lastIndex;
};

