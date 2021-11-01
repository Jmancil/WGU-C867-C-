#pragma once
#include "student.h"
using namespace std;

class Roster
{
public:
	int lastIndex; // last student index
	int capacity; // Roster size
	Student** classRosterArray; // student pointer array
	Roster(); // Empty Con
	Roster(int capacity);  // full con
	void pAdd(string datarow); //parsing and adding data
	void pAll(); //prints
	void remove(string studentID); // Remove based on Student ID
	void printInvalidEmails(); //Prints by invalid email
	void printByDegreetype(DegreeType d); //Prints by DegreeType
	void printAverageDays(string studentID); //prints courseDays based on student ID

	~Roster(); //Decon 
};