#include <iostream>
#include <fstream>
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

bool Grade::checkNumberStudent() {
	bool correct = false;

	string file = "administration/ListeNumeroEtudiant.txt";
	ifstream fichier(file.c_str());

	if (fichier) {
		string line;
		while (getline(fichier, line)) {
			if (to_string(this->studentNumber) == line) {
				correct = true;
			}
		}
	}

	return correct;
}


bool Grade::checkNumberCourse() {
	bool correct = false;

	
	string file = "administration/cours/numeroCours.txt";
	ifstream fichier(file.c_str());

	if (fichier) {
		string line;
		while (getline(fichier, line)) {
			if (to_string(this->courseNumber) == line) {
				correct = true;
			}
		}
	}

	return correct;
}

void Grade::saveGrade() {
	std::cout << "Etape 1 ok" << endl;
	if (this->checkNumberCourse() && this->checkNumberStudent()) {
		std::cout << "Etape 2 ok" << endl;
		int numberline = 0;
		int cpt = 0;
		string cours = "";

		string file1 = "administration/cours/numeroCours.txt";
		ifstream fichier1(file1.c_str());

		std::cout << "Etape 3 ok" << endl;

		if (fichier1) {
			std::cout << "Etape 4 ok" << endl;
			string line1;

			while (getline(fichier1, line1)) {
				cpt++;
				if (to_string(this->courseNumber) == line1) {
					numberline = cpt;
				}
			}
		}

		fichier1.close();
		cpt = 0;

		string file2 = "administration/cours/coursList.txt";
		ifstream fichier2(file2.c_str());
		std::cout << "Etape 5 ok" << endl;
		if (fichier2) {
			std::cout << "Etape 6 ok" << endl;
			string line2;

			while (getline(fichier2, line2)) {
				cpt++;
				if (cpt == numberline) {
					cours = line2;
				}
			}
		}

		fichier2.close();

		string file3 = "administration/dossierAcademique/" + to_string(this->studentNumber) + ".txt";
		ofstream fichier3(file3.c_str(), ios::app);
		std::cout << "Etape 7 ok" << endl;
		if (fichier3) {
			std::cout << "Etape 8 ok" << endl;
			fichier3 <<"\n" <<cours << "  note = " << this->grade <<endl;
		}
		fichier3.close();



	}
}
Grade::~Grade() {};