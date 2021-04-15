#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;
//Constructor

Student::Student(long numberStudent, string firstName, string lastName) {
	this->numberStudent = numberStudent;
	this->setFirstName(firstName);
	this->setLastName(lastName);
}

//GETTERS
long Student::getNumberStudent() const noexcept {
	return this->numberStudent;
}
string Student:: getFirstName() const noexcept {
	return this->firstName;
}
string Student::getLastName() const noexcept {
	return this->lastName;
}

//SETTERS

void Student::setNumberStudent(long numberStudent) {
	if (numberStudent > 10000 && numberStudent < 90000) {
		this->numberStudent = numberStudent;
	}
	else
	{
		this->numberStudent = 0;
	}
	
}
void Student::setFirstName(string firstName) {
	if (firstName.size() >= 3) {
		this->firstName = firstName;
	}
	else
	{
		this->firstName = "inconnu";
	}
	
}
void Student::setLastName(string lastName) {
	if (lastName.size() >= 3) {
		this->lastName = lastName;
	}
	else {
		this->lastName = "inconnu";
	}
	
	
}


void Student::afficher() {
	cout << "\nNumero Etudiant : " << getNumberStudent() << "\n"
		 << "Nom             : "	 << getFirstName() << "\n"
		 << "Prenom          : "  << getLastName() << endl;
}

void Student::confirmer(bool autoriser) {
	string file = "administration/Etudiant.txt";
	string saveStudentsNumber = "administration/ListeNumeroEtudiant.txt";
	string fileStudent = "administration/dossierAcademique/";
	if (autoriser == true) {

		ofstream fichier(file.c_str(), ios::app);
		ofstream fichierSauvegarderEtudiantNumero(saveStudentsNumber.c_str(),ios::app);

		if (fichier) {
			fichier 
				<<"id              : "  << this->getId() << "\n"
				<<"Numero Etudiant : " << this->numberStudent << "\n"
				<<"Nom             : " << this->firstName << "\n"
				<<"Prenom          : " << this->lastName << "\n\n";

			string concat = to_string(this->numberStudent) + ".txt";
			string fileStudent = "administration/dossierAcademique/" + concat;
			ofstream createFile(fileStudent.c_str());
			if (createFile) {
				createFile 
					<< "Numero Etudiant : " << this->numberStudent << "\n"
					<< "Nom             : " << this->firstName << "\n"
					<< "Prenom          : " << this->lastName << "\n\n";
			}
		}

		if (fichierSauvegarderEtudiantNumero) {
			fichierSauvegarderEtudiantNumero << this->numberStudent << endl;
		}

		fichier.close();
		fichierSauvegarderEtudiantNumero.close();
	}
}
int Student::getId() {
	int somme = 0;
	ifstream fichier("administration/ListeNumeroEtudiant.txt");
	if (fichier) {
		string line;
		while (getline(fichier, line))
		{
			somme++;
		}
	}

	fichier.close();

	return (somme + 1);
}
void Student::afficherLesEtudiant() {
	
	if (this->getId() != 0) {
		string file = "administration/Etudiant.txt";
		ifstream fichier(file.c_str());

		if (fichier) {
			string line;
			while (getline(fichier, line)) {
				cout << line << endl;
			}
		}
	}
	else {
		cout << "Pas d'etudiant inscrit" << endl;
	}
}

void Student::rechercheEtudiant(long numero) const {

	string chaine = "administration/dossierAcademique/" + to_string(numero) + ".txt";

	try {

		ifstream stream(chaine);

		if (stream) {
			string ligne;
			cout << "\n" << endl;
			while (getline(stream, ligne)) {
				cout << ligne << endl;
			}
		}
		else {
			throw std::runtime_error("Etudiant introuvable.");
		}
	}
	catch (std::runtime_error const& exception) {
		std::cout << "Erreur : " << exception.what() << std::endl;
	}


}
Student::~Student() {};