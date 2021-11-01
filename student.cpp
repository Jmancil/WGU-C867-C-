#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include <iomanip>
using namespace std;

Student::Student() //Empty Con
{
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->eAddress = "";
	this->sAge = "";
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < courseDaysSize; ++i) this->courseDays[i];
	this->dType = DegreeType::UNDECIDED;
};

//full con
Student::Student(string studentID, string fName, string lName, string eAddress, string sAge, int courseDays[], DegreeType type)
{
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->eAddress = eAddress;
	this->sAge = sAge;
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < 3; ++i)this->courseDays[i] = courseDays[i];
	this->dType = type;
}

//Getters + Setters for each var

string Student::getStudentID() //Getter
{
	return studentID;
}

void Student::setStudentID(string studentID) //Setter
{
	this->studentID = studentID;
}

string Student::getFName() //Getter
{
	return fName;
}

void Student::setFName(string fName) //Setter
{
	this->fName = fName;
}

string Student::getLName() //Getter
{
	return lName;
}

void Student::setLname(string lName) //Setter
{
	this->lName = lName;
}

string Student::getEAddress() // Getter
{
	return eAddress;
}
void Student::setEAddress(string eAddress) //Setter
{
	this->eAddress = eAddress;
}

string Student::getSAGE() //Getter
{
	return sAge;
}
void Student::setSAGE(string sAge) //Setter
{
	this->sAge = sAge;
}

int* Student::getCourseDays() //Getter
{
	return courseDays;
}

void Student::setCourseDays(int courseDays[]) //Setter
{
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < 3; i++) this->courseDays[i] = courseDays[i];
}

DegreeType Student::getDegreeType() //Getter
{
	return dType;
}

void Student::setDegreeType(DegreeType d) //Setter
{
	this->dType = d;
}


Student::~Student() // Decon
{
	if (courseDays != nullptr)
	{
		delete[] courseDays;
		courseDays = nullptr;
	}
}

void Student::print() //Student info print
{
	cout << "Student ID: " << studentID << " Student first name: " << fName;
	cout << " student last name: " << lName << " student email: " << eAddress;
	cout << " student age: " << sAge << " Average Course Days: " << (courseDays[0] + courseDays[1] + courseDays[2]) / 3;
	cout << " Degree type " << dType << endl;

	
}

