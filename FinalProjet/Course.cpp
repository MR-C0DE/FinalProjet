#include <fstream>

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

void Course::checkCoursNumber() {
	srand(time(0));
	string file{ "administration/cours/numeroCours.txt" };
	ifstream fichier(file.c_str());

	if (fichier) {
		string line;
		while (getline(fichier, line)) {
			if (to_string(this->CourseNumber) == line) {
				this->CourseNumber = 1000 + rand() % 5000;
				this->checkCoursNumber();
			}
		}
	}
	
}

int Course::countCourse() {

	string file = "administration/cours/numeroCours.txt";
	ifstream fichier(file.c_str());

	int somme = 0;

	if (fichier) {
		string line;

		while (getline(fichier, line)) {

			somme++;
		}
	}

	return somme;
}

void Course::saveCourse(bool correct) {
	if (correct) {

		string file = "administration/cours/coursList.txt";
		string file2 = "administration/cours/numeroCours.txt";
		ofstream fichier(file.c_str(), ios::app);
		ofstream fichier2(file2.c_str(), ios::app);

		if (fichier2) {
			fichier2 << this->getCourseNumber() << endl;
		}
		fichier2.close();
		if (fichier) {
			fichier << this->CourseNumber << " " << this->code << " " << this->title << endl;
		}

		fichier.close();
	}
}

Course::~Course() {};