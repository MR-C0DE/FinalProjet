#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;

//Constructeur
Student::Student(long numberStudent, string firstName, string lastName) 
{
	this->numberStudent = numberStudent;
	this->setFirstName(firstName);
	this->setLastName(lastName);
}

// La definition des GETTERS
long Student::getNumberStudent() const 
{
	return this->numberStudent;
}
string Student:: getFirstName() const 
{
	return this->firstName;
}
string Student::getLastName() const 
{
	return this->lastName;
}

// La definition des SETTERS

void Student::setNumberStudent(long numberStudent) 
{
	if (numberStudent > 10000 && numberStudent < 90000) 
	{
		this->numberStudent = numberStudent;
	}
	else
	{
		this->numberStudent = 0;
	}
	
}

// La condition qui vérifie si la longueur du nom est de trois caractères ou plus
void Student::setFirstName(string firstName) 
{
	if (firstName.size() >= 3) 
	{
		this->firstName = firstName;
	}
	else
	{
		this->firstName = "inconnu";
	}
	
}

// La condition qui vérifie si la longueur du prénom est de trois caractères ou plus
void Student::setLastName(string lastName) 
{
	if (lastName.size() >= 3) 
	{
		this->lastName = lastName;
	}
	else 
	{
		this->lastName = "inconnu";
	}	
}

// Fonction qui affiche les coordonnés d'un etudiant
void Student::afficher() 
{
	cout << "\nNumero Etudiant : " << this->numberStudent << "\n"
		 << "Nom             : "	 << this->firstName << "\n"
		 << "Prenom          : "  << this->lastName << endl;
}

// Enregistrement des données dans un fichier texte par étudiant
void Student::confirmer(bool autoriser) 
{
	string cheminRepertoire = "administration/Etudiant.txt";
	string saveStudentsNumber = "administration/ListeNumeroEtudiant.txt";
	string cheminRepertoireStudent = "administration/dossierAcademique/";

	if (autoriser == true) 
	{
		ofstream fichier(cheminRepertoire.c_str(), ios::app);
		ofstream fichierSauvegarderEtudiantNumero(saveStudentsNumber.c_str(),ios::app);

		if (fichier) 
		{
			fichier 
				<<"id              : "  << this->getId() << "\n"
				<<"Numero Etudiant : " << this->numberStudent << "\n"
				<<"Nom             : " << this->firstName << "\n"
				<<"Prenom          : " << this->lastName << "\n\n";

			string concat = to_string(this->numberStudent) + ".txt";
			string cheminRepertoireStudent = "administration/dossierAcademique/" + concat;
			ofstream createcheminRepertoire(cheminRepertoireStudent.c_str());

			if (createcheminRepertoire) 
			{
				createcheminRepertoire 
					<< "Numero Etudiant : " << this->numberStudent << "\n"
					<< "Nom             : " << this->firstName << "\n"
					<< "Prenom          : " << this->lastName << "\n\n";
			}
		}

		if (fichierSauvegarderEtudiantNumero) 
		{
			fichierSauvegarderEtudiantNumero << this->numberStudent << endl;
		}

		fichier.close();
		fichierSauvegarderEtudiantNumero.close();
	}
}
// la fonction renvoie le nombre d'etudiants
int Student::getId() 
{
	int compteur = 0;
	ifstream fichier("administration/ListeNumeroEtudiant.txt");

	if (fichier) 
	{
		string lineCapture;   

		while (getline(fichier, lineCapture))
		{
			compteur++;
		}
	}

	fichier.close();

	return (compteur + 1);
}

// La fonction affiche les etudiants enregistres
void Student::afficherLesEtudiant() 
{
	
	if (this->getId() != 0) 
	{
		string cheminRepertoire = "administration/Etudiant.txt";
		ifstream fichier(cheminRepertoire.c_str());

		if (fichier) 
		{
			string lineCapture;

			while (getline(fichier, lineCapture)) 
			{
				cout << lineCapture << endl;
			}
		}
	}

	else 
	{
		cout << "Aucun étudiant enregistré" << endl;
	}
}

//la finction permet de recherche l'etudiant par son numero
void Student::rechercheEtudiant(long numero) const 
{

	string cheminRepertoire = "administration/dossierAcademique/" + to_string(numero) + ".txt";

	try 
	{
		ifstream stream(cheminRepertoire);

		if (stream) 
		{
			string lineCapture;
			cout << "\n" << endl;

			while (getline(stream, lineCapture)) 
			{
				cout << lineCapture << endl;
			}
		}

		else 
		{
			throw std::runtime_error("Etudiant introuvable.");
		}
	}
	
	catch (std::runtime_error const& exception) 
	{
		std::cout << "Erreur : " << exception.what() << std::endl;
	}
}

//destructeur virtuel
Student::~Student() {};