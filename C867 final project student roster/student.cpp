#include <iostream>
#include "student.h"
using std::cout;



//Constructor
student::student(std::string stuID, std::string first, std::string last, std::string address, int age, double daysInCourse[]) //removed enum Degree degree
{
	this->studentID = stuID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = address;
	this->studentAge = age;
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysToCompleteCourse[i] = daysInCourse[i];
	//degreeProgram = degree; added in subclass
}


//Destructor
student::~student(){}


//Setters:
void student::SetStudentID(std::string stuID) 
{
	studentID = stuID;
	return;
}

void student::SetFirstName(std::string first) 
{
	firstName = first;
	return;
}
void student::SetLastName(std::string last) 
{
	lastName = last;
	return;
}
void student::SetEmailAddress(std::string address) 
{
	emailAddress = address;
	return;
}
void student::SetAge(int age) 
{ 
	studentAge = age;
	return;
}

void student::SetDaysInCourse(double daysInCourse[])
{
	for (int i = 0; i < daysToCompleteArraySize; i++) 
		this->daysToCompleteCourse[i] = daysInCourse[i];
}

 void student::SetDegreeProgram(Degree degree)
{
	degreeProgram = degree;
	return;
}


//Getters:

std::string student::GetStudentID() { return studentID; }
std::string student::GetFirstName() { return firstName; }
std::string student::GetLastName() { return lastName; }
std::string student::GetEmailAddress() { return emailAddress; }
int student::GetAge() { return studentAge; }
double * student::GetDaysInCourse()
{
	return daysToCompleteCourse;
}


void student::print()
{
	cout << GetStudentID() << "\t" << "First Name: " << GetFirstName() << "\t" << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << GetAge() << "\t" << "daysInCourse: {";
	PrintDaysInCourse();
	cout << "} ";
	//<< "Email Address: " << GetEmailAddress() << "\t" (printing email address not required in PA instructions)
}

void student::PrintDaysInCourse() 
{ 
	std::cout << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1] << ", " << daysToCompleteCourse[2];
} 


 
