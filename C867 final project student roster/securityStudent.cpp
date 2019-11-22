#include "securityStudent.h"
#include <iostream>
using std::cout;

//Constructor 
securityStudent::securityStudent(std::string stuID, std::string first, std::string last, std::string address,
	int age, double daysInCourse[], Degree degree)
	:student(stuID, first, last, address, age, daysInCourse)
{
	degreeProgram = SECURITY;
}

//Destructor
securityStudent::~securityStudent() {}


Degree securityStudent::GetDegreeProgram()
{
	return degreeProgram; //maybe return SOFTWARE directly instead
}

void securityStudent::print()
{
	this->student::print(); //Calls method from student class
	cout << "Degree Program: "<< "SECURITY" << ".\n";
}