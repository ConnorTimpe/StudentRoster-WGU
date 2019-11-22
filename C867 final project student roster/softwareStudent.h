#pragma once
#include "student.h"
#include "degree.h"

class softwareStudent : public student
{
public:
	
	//constructor
	softwareStudent(
		std::string stuID, 
		std::string first, 
		std::string last, 
		std::string address, 
		int age, 
		double daysInCourse[], 
		Degree degree
	);
	
	//destructor
	~softwareStudent();

	//overridden methods from student class
	Degree GetDegreeProgram() override;
	void print();


};

