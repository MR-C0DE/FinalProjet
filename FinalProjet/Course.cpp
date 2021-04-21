#include <fstream>
#include <iostream>
#include "Course.h"
#include <string>


using namespace std;

//La difition d'un constructeur  

Course::Course(long CourseNumber, string code, string title) 
{

	this->CourseNumber = CourseNumber;
	this->code = code;
	this->title = title;
}

//La definition de GETTERS
long Course::getCourseNumber() const noexcept 
{
	return this->CourseNumber;
}
string Course::getCode() const noexcept 
{
	return this->code;
}
string Course::getTitle() const noexcept 
{
	return this->title;
}

//La definition de SETTERS

void Course::setCourseNumber(long CourseNumber) 
{
	this->CourseNumber = CourseNumber;
}

void Course::setCode(string code) {
	this->code = code;
}

void Course::setTitle(string title) {
	this->title = title;
}
/*
La fonction checkCoursNumber() verifie si le numero du cours existe 
et génère un nouveau  si celui-ci existe  ou est deja utilisé
 */
void Course::checkCoursNumber() 
{
	srand(time(0));
	string cheminAcces{ "administration/cours/numeroCours.txt" };
	ifstream fichier(cheminAcces.c_str());

	if (fichier) 
	{
		string line; // capture de la ligne 
		while (getline(fichier, line)) 
		{
			if (to_string(this->CourseNumber) == line) 
			{
				this->CourseNumber = 1000 + rand() % 5000; // La generation du numero du cours 
				this->checkCoursNumber();
			}
		}
	}
	
}

//	La fonction countCours() compte les cours disponible
 
int Course::countCourse() 
{

	string cheminAcces = "administration/cours/numeroCours.txt";
	ifstream fichier(cheminAcces.c_str());

	int compteur = 0;

	if (fichier) 
	{
		string line;// capture de la ligne

		while (getline(fichier, line)) 
		{

			compteur++;
		}
	}

	return compteur;
}
/*
La fonction saveCourse() sauvegarde le cours apres sa creation
 */
void Course::saveCourse(bool correct) 
{
	if (correct) {

		string cheminAcces = "administration/cours/coursList.txt";
		string cheminAcces2 = "administration/cours/numeroCours.txt";
		ofstream fichier(cheminAcces.c_str(), ios::app);
		ofstream fichier2(cheminAcces2.c_str(), ios::app);

		if (fichier2) 
		{
			fichier2 << this->getCourseNumber() << endl;
		}
		fichier2.close();
		if (fichier)
		 {
			fichier << this->CourseNumber << " " << this->code << " " << this->title << endl;
		}

		fichier.close();
	}
}
//La fonction afficherCours() permet d'afficher la totalités des cours disponible
void Course::afficherCours() 
{
	if (this->countCourse() != 0) 
	{
		int compteur = 0;
		string cheminAcces = "administration/cours/coursList.txt";
		ifstream fichier(cheminAcces.c_str());
		if (fichier) 
		{
			string line;
			while (getline(fichier, line)) 
			{
				compteur++;
				cout <<compteur<< ". " << line << endl;
			}
		}

		fichier.close();
	}
	else {
		cout << "Pas des cours existants" << endl;
	}
}

Course::~Course() {};