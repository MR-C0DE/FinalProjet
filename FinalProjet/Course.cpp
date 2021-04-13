#include "Course.h"
#include <string>

using namespace std;

Course::Course(long CourseNumber, string code, string title) {

	this->CourseNumber = CourseNumber;
	this->code = code;
	this->title = title;
}

//GETTERS
long Course::getCourseNumber() const noexcept {
	return this->CourseNumber;
}
string Course::getCode() const noexcept {
	return this->code;
}
string Course::getTitle() const noexcept {
	return this->title;
}

//SETTERS

void Course::setCourseNumber(long CourseNumber) {
	this->CourseNumber = CourseNumber;
}

void Course::setCode(string code) {
	this->code = code;
}

void Course::setTitle(string title) {
	this->title = title;
}

Course::~Course() {};