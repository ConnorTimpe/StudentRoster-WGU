#pragma once
#include <string>
#include "degree.h"

class student 
{
public:
	//constructor
	student(std::string stuID, 
		std::string first, 
		std::string last, 
		std::string address, 
		int age,  
		double daysInCourse[]); 
	
	//destructor
	~student(); 
	
	//Setters:
	void SetStudentID(std::string stuID);
	void SetFirstName(std::string first);
	void SetLastName(std::string last);
	void SetEmailAddress(std::string address);
	void SetAge(int age);
	void SetDaysInCourse(double daysInCourse[]);
	void SetDegreeProgram(Degree degree); 
	
	//Getters:
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmailAddress();
	int GetAge();
	double* GetDaysInCourse();
	virtual Degree GetDegreeProgram() = 0;
	
	void PrintDaysInCourse();
	virtual void print() = 0;
	
	const static int daysToCompleteArraySize = 3;
	
protected:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int studentAge;
	double daysToCompleteCourse[daysToCompleteArraySize]; //array of ints
	Degree degreeProgram; //populated in subclasses 

	
	
};