#pragma once
#include "student.h"
#include "degree.h"

class securityStudent : public student
{
public:

	//constructor
	securityStudent(
		std::string stuID,
		std::string first,
		std::string last,
		std::string address,
		int age,
		double daysInCourse[],
		Degree degree
	);

	//destructor
	~securityStudent();

	//overridden methods from student class
	Degree GetDegreeProgram() override;
	void print();


};


