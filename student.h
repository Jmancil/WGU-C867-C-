#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "degree.h"
using namespace std;

class Student
{
private:
	string studentID;
	string fName;
	string lName;
	string eAddress;
	string sAge;
	int* courseDays;
	DegreeType dType;

public:
	const static int courseDaysSize = 3;
	Student(); //empty con
	//Full con
	Student(string studentID, string fName, string lName, string eAddress, string sAge, int courseDays[], DegreeType Type);

	string getStudentID(); //Getter
	void setStudentID(string studentID);   //Setter

	string getFName(); //Getter
	void setFName(string fName); //Setter

	string getLName(); //Getter
	void setLname(string lName);   //Setter

	string getEAddress(); //Getter
	void setEAddress(string eAddress); //Setter

	string getSAGE(); //Getter
	void setSAGE(string sAge); // Setter

	int* getCourseDays(); //Getter
	void setCourseDays(int courseDays[]); //Setter

	DegreeType getDegreeType(); //Getter
	void setDegreeType(DegreeType d); //setter

	void print();

	~Student();

};