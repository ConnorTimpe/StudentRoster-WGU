#include "softwareStudent.h"
#include <iostream>
using std::cout; 

//Constructor 
softwareStudent::softwareStudent(std::string stuID, std::string first, std::string last, std::string address, 
	int age, double daysInCourse[], Degree degree)
	:student(stuID, first, last, address, age, daysInCourse)
{
	degreeProgram = SOFTWARE;
}

//Destructor
softwareStudent::~softwareStudent(){}


Degree softwareStudent::GetDegreeProgram()
{
	return degreeProgram; 
}

void softwareStudent::print() 
{
	this->student::print(); //Calls method from student class
	cout << "Degree Program: " << "SOFTWARE" << ".\n";
}

