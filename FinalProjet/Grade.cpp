#include "Grade.h"
#include <string>

using namespace std;

Grade::Grade(long studentNumber, long courseNumber, double grade) {
	this->studentNumber = studentNumber;
	this->courseNumber = courseNumber;
	this->grade = grade;
}

//GETTERS

long Grade::getStudentNumber() const noexcept {
	return this->studentNumber;
}

long Grade::getCourseNumber() const noexcept {
	return this->courseNumber;
}

double Grade::getGrade() const noexcept {
	return this->grade;
}

//SETTERS

void Grade::setStudentNumber(long studentNumber) {
	this->studentNumber = studentNumber;
}

void Grade::setCourseNumber(long courseNumber) {
	this->courseNumber;
}

void Grade::setGrade(double grade) {
	this->grade;
}
Grade::~Grade() {};