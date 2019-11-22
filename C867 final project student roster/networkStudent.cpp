#include "networkStudent.h"
#include <iostream>
using std::cout;

//Constructor 
networkStudent::networkStudent(std::string stuID, std::string first, std::string last, std::string address,
	int age, double daysInCourse[], Degree degree)
	:student(stuID, first, last, address, age, daysInCourse)
{
	degreeProgram = NETWORKING;
}

//Destructor
networkStudent::~networkStudent() {}


Degree networkStudent::GetDegreeProgram()
{
	return degreeProgram; 
}

void networkStudent::print()
{
	this->student::print(); //Calls method from student class
	cout << "Degree Program: " << "NETWORKING" << ".\n";
}