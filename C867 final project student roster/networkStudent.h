#pragma once
#include "student.h"
#include "degree.h"

class networkStudent : public student
{
public:

	//constructor
	networkStudent(
		std::string stuID,
		std::string first,
		std::string last,
		std::string address,
		int age,
		double daysInCourse[],
		Degree degree
	);

	//destructor
	~networkStudent();

	//overridden methods from student class
	Degree GetDegreeProgram() override;
	void print();


};


