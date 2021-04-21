#include "Fonction.h"

using namespace std;

//Gestion de menu
void menu() {
    

    int votreChoix = 0;

    cout << "1. Nouveau\n" <<
            "2. Ajouter Notes\n" <<
            "3. Afficher\n" <<
            "4. Recherche\n" <<
            "5. Quitter\n" <<
            ">>> ";


    cin >> votreChoix;

    if (votreChoix == 1) 
    {
        cout << "1. Creer un etudiant\n" <<
            "2. Creer un Cours\n" <<
            ">>> ";

        cin >> votreChoix;

        if (votreChoix == 1)
        {
            inscrire();
        }
        else if (votreChoix == 2) 
        {
            nouveauCours();
        }
        else 
        {
            cout << "Option invalide!" << endl;
        }

    }
    else if (votreChoix == 2) 
    {
        ajouterNote();
    }
    else if (votreChoix == 3) 
    {
        cout << "1. Afficher les etudiant\n" <<
            "2. afficher les cours\n" <<
            ">>> ";

        cin >> votreChoix;

        if (votreChoix == 1) 
        {
            Student().afficherLesEtudiant();
        }
        else if (votreChoix == 2) 
        {
            Course().afficherCours();
        }
        else
        {
            cout << "Option invalide!" << endl;
        }
    }
    else if (votreChoix == 4)
    {
        recherche();
    }
    else if (votreChoix == 5)
    {
        system("exit");
    }
    else 
    {
        cout << "Option invalide!" << endl;
    }
   
}

//Fonction permettant à l'utilisateur de creer un etudiant
void inscrire()
{

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

    cout << endl << "1. Confirmer.\n" <<
            "2. Recommencer.\n" <<
            "3. Sortir.\n" <<
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

//Fonction permettant de rechercher un etudiant
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


//Fonction  permettant de creer un nouveau cours
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

//Fonction permettant d'ajouter la note
void ajouterNote() {

   
 long numeroEtudiant = 0;
    long numeroCours = 0;
    double note = 0.0;
   
    cin.clear();
    cin.ignore();

    cout << "Saisissez le numero de l'etudiant : ";
    cin >> numeroEtudiant;
    
    cout << "Saisissez le numero du cours : ";
    cin >> numeroCours;

    cout << "Saisissez la note : ";
    cin >> note;

    Grade grade(numeroEtudiant, numeroCours, note);

    grade.saveGrade(); 
}
