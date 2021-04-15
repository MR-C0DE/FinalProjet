#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "Fonction.h"
#include "Student.h"
#include "Course.h"
#include "Grade.h"

using namespace std;
void menu() {
    

    int votreChoix = 0;

    cout << "1. Nouveau Etudiant\n" <<
            "2. Nouveau Cours\n" <<
            "3. Ajouter des notes\n" <<
            "4. Rechercher Etudiant\n" <<
            "5. afficher etudiant \n" << 
            "6. afficher Cours \n" <<
            "7. Quitter\n\n" <<
            ">>> ";

    while (!(cin >> votreChoix)) {
        cout << "Entrez la bonne option : ";
        cin.clear();
        cin.ignore(255, '\n');

    }

   
    switch (votreChoix)
    {
    case 1:
        inscrire();
        break;
    case 2 :
        nouveauCours();
        break;
    case 3:
        ajouterNote();
        break;
    case 4:
        recherche();
        break;
    case 5:
        Student().afficherLesEtudiant();
        break;
    case 6:
        Course().afficherCours();
        break;
    case 7:
        system("exit");
        break;
    default:
        cout << "Entrée invalide!" << endl;
        break;
    }


}

void inscrire() {

    srand(time(0));

    int votreChoix = 0;
    string nom = "";
    string prenom = "";
    bool correct = true;


    long numeroEtudiant = 10000 + rand() % 90000;

    verifierNumero(numeroEtudiant);

    cin.ignore();

    cout << "Nom Etudiant : ";
    getline(cin, nom);

    cout << "Prenom Etudiant : ";
    getline(cin, prenom);

    Student student(numeroEtudiant, nom, prenom);


    student.afficher();

    cout << "1. Confirmer\n" <<
        "2. Recommencer\n" <<
        "3. Sortir\n\n" <<
        ">>> ";
    cin >> votreChoix;



    switch (votreChoix)
    {
    case 1:

        if (student.getFirstName() == "inconnu" || student.getLastName() == "inconnu" || student.getNumberStudent() == 0) {
            correct = false;
        }
        student.confirmer(correct);

        if (correct == false) {
            cout << "Une erreur est survenue!" << endl;
        }
        break;
    case 2:
        inscrire();
        break;
    case 3:
        menu();
        break;
    default:
        cout << endl;
        break;
    }

}

void verifierNumero(long& numero) {


    vector <string> listNumeroEtudiant;
    string link = "administration/ListeNumeroEtudiant.txt";

    ifstream file(link);

    if (file) {

        string numeroFormString;
        while (getline(file, numeroFormString))
        {
            listNumeroEtudiant.push_back(numeroFormString);
        }
    }

    for (int i = 0; i < listNumeroEtudiant.size(); i++)
    {
        if (to_string(numero) == listNumeroEtudiant[i]) {

            numero = 10000 + rand() % 90000;

            verifierNumero(numero);


        }
    }


    file.close();

}

void recherche() {
    long numeroEtudiant = 0;
  
     cout << "Taper un numero d'etudiant : ";

     while (!(cin >> numeroEtudiant)) {

         cout << "Erreur survenue, Ressayer : ";
         cin.clear();
         cin.ignore(255, '\n');
         
       }
    
     Student().rechercheEtudiant(numeroEtudiant);
    

}

void nouveauCours() {
   srand(time(0));
    
   
    string code = ""; 
    string titre = "";
    long numero = 1000 + rand() % 5000;
    cin.clear();
    cin.ignore();
    cout << "Taper le code du cours : ";
    getline(cin, code);
    cout << "Taper le titre du cours : ";
    getline(cin, titre);

    Course cours(numero, code, titre);
    cours.checkCoursNumber();
    cours.saveCourse(true);
    

}

void ajouterNote() {

   
 long numeroEtudiant = 0;
    long numeroCours = 0;
    double note = 0.0;
   
    cin.clear();
    cin.ignore();
    cout << "Taper le numero de l'etudiant : ";
    cin >> numeroEtudiant;
    
    cout << "Taper le numero du cours : ";
    cin >> numeroCours;

    cout << "Taper la note : ";
    cin >> note;

    Grade grade(numeroEtudiant, numeroCours, note);

    grade.saveGrade();
   
   
   
   
}
