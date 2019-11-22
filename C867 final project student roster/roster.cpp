#include "roster.h"
#include <iostream>
#include <string>



roster::roster()
{
	this->rosterMaxSize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

roster::roster(int rosterMaxSize)
{
	this->rosterMaxSize = rosterMaxSize;
	this->lastIndex = -1;
	this->classRosterArray = new student*[rosterMaxSize];
}


roster::~roster()
{
}

void roster::parseData(std::string row)
{
	if (lastIndex < rosterMaxSize) 
	{
		lastIndex++;

		//read ID
		int rightComma = row.find(",");
		std::string sID = row.substr(0, rightComma);
		
		//read first name
		int leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		std::string sFirstName = row.substr(leftComma, rightComma - leftComma);

		//read last name
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		std::string sLastName = row.substr(leftComma, rightComma - leftComma);

		//read email address
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		std::string sEmailAddress = row.substr(leftComma, rightComma - leftComma);

		//read age and convert from string to int
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		int sAge = std::stoi(row.substr(leftComma, rightComma - leftComma));

		//read daysInCourse1 and convert from string to int
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		int sDaysInCourse1 = std::stoi(row.substr(leftComma, rightComma - leftComma));

		//read daysInCourse2 and convert from string to int
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		int sDaysInCourse2 = std::stoi(row.substr(leftComma, rightComma - leftComma));

		//read daysInCourse3 and convert from string to int
		leftComma = rightComma + 1;
		rightComma = row.find(",", leftComma);
		int sDaysInCourse3 = std::stoi(row.substr(leftComma, rightComma - leftComma));

		//Search for degree type string and convert to enum
		Degree sDegreeProgram;
		if (row.find("SECURITY") != std::string::npos) {
			sDegreeProgram = SECURITY;
		}
		if (row.find("NETWORK") != std::string::npos) {
			sDegreeProgram = NETWORKING;
		}
		if (row.find("SOFTWARE") != std::string::npos) {
			sDegreeProgram = SOFTWARE;
		}
		

		add(sID, sFirstName, sLastName, sEmailAddress, sAge, sDaysInCourse1, sDaysInCourse2, sDaysInCourse3, sDegreeProgram);

	}
}
void roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	if (degreeProgram == SECURITY) 
	{
		double daysInCourse[student::daysToCompleteArraySize];
		daysInCourse[0] = daysInCourse1;
		daysInCourse[1] = daysInCourse2;
		daysInCourse[2] = daysInCourse3;
		classRosterArray[lastIndex] = new securityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
	if (degreeProgram == NETWORKING)
	{
		double daysInCourse[student::daysToCompleteArraySize];
		daysInCourse[0] = daysInCourse1;
		daysInCourse[1] = daysInCourse2;
		daysInCourse[2] = daysInCourse3;
		classRosterArray[lastIndex] = new networkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
	if (degreeProgram == SOFTWARE)
	{
		double daysInCourse[student::daysToCompleteArraySize];
		daysInCourse[0] = daysInCourse1;
		daysInCourse[1] = daysInCourse2;
		daysInCourse[2] = daysInCourse3;
		classRosterArray[lastIndex] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
}

void roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool roster::remove(std::string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			found = true;
			delete	this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
		if (i >= lastIndex && found == false)
		{
			std::cout << "Error, ID not found.";
		}
	}
	return found;
}

void roster::printDaysInCourse(std::string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			found = true;
			double* days = classRosterArray[i]->GetDaysInCourse(); 
			double averageDays = (days[0] + days[1] + days[2]) / 3;
			std::cout << "Average days in course for student " << studentID << " is " << averageDays << ".\n";
		}
		if (found == false && i >= lastIndex) 
		{
			std::cout << "Student not found.\n";
		}
	}
}

void roster::printInvalidEmails()
{
	std::cout << "Printing invalid emails: \n";
	bool invalidCharacterFound = false;
	for (int i = 0; i <= lastIndex; i++) 
	{
		invalidCharacterFound = false;
		std::string currentEmail = classRosterArray[i]->GetEmailAddress();
		if (currentEmail.find('@') == std::string::npos)
		{
			invalidCharacterFound = true;
		}
		if (currentEmail.find('.') == std::string::npos)
		{
			invalidCharacterFound = true;
		}
		if (currentEmail.find(' ') != std::string::npos)
		{
			invalidCharacterFound = true;
		}
		if (invalidCharacterFound)
		{
			std::cout << "Invalid email address found: " << currentEmail << "\n";
		}
	}
}

void roster::printByDegreeProgram(int degreeProgram)
{
	if (degreeProgram == 0)
	{
		std::cout << "Displaying all security students: \n";
	}
	else if (degreeProgram == 1)
	{
		std::cout << "Displaying all networking students: \n";
	}
	else if (degreeProgram == 2)
	{
		std::cout << "Displaying all software students: \n";
	}
	else
	{
		std::cout << "Error. Degree program not found.";
	}
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) 
		{
			classRosterArray[i]->print();
		}
	}
}


void roster::printTitleInfo()
{
	std::cout << "Scripting and Programming - Applications - C867\n" << "Programmed by Connor Timpe #000976484 in C++\n\n";
}

student * roster::getStudentAt(int index)
{
	return classRosterArray[index];
}



int main()
{
	int numStudents = 5;

	const std::string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Connor,Timpe,ctimpe4@wgu.edu,24,10,20,30,SOFTWARE" 
	};

	roster * classRoster = new roster(numStudents);

	//Print title information
	classRoster->printTitleInfo();

	//Add student data to roster
	std::cout << "Adding student data to roster...\n"; 
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseData(studentData[i]);
	}
	std::cout << "Finished.\n";
	std::cout << "Displaying all students:" << "\n";
	
	//Print all students
	classRoster->printAll();

	//Print invalid emails
	classRoster->printInvalidEmails();

	//Print Average days in course for all students
	for (int i = 0; i < numStudents; i++) 
	{
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->GetStudentID());
	}

	//Print students by degree program
	classRoster->printByDegreeProgram(SOFTWARE);

	//Remove student A3
	std::cout << "Removing student A3: \n";
	if (classRoster->remove("A3")) 
	{
		classRoster->printAll();
		numStudents--;
	}
	
	//Attempt to remove student A3 again to show error condition
	std::cout << "Removing student A3: \n";
	if (classRoster->remove("A3"))
	{
		classRoster->printAll();
		numStudents--;
	}
	

	//Call destructor 
	classRoster->~roster();
}

/*Data

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Connor,Timpe,ctimpe4@wgu.edu,24,10,20,30,SOFTWARE" }
*/

