#pragma once
#include <string>
class Student
{
	
public:
	friend std::ostream& operator<< (std::ostream&, const Student&);
	//Constructor

	Student() = default;

	Student(long, std::string, std::string);
	//GETTERS
	long getNumberStudent() const ;
	std::string getFirstName() const ;
	std::string getLastName() const ;

	//SETTERS

	void setNumberStudent(long);
	void setFirstName(std::string);
	void setLastName(std::string);

	//Authors members functions

	void confirmer(bool);
	void afficherLesEtudiant();
	void rechercheEtudiant(long) const;
	void afficher();

	//Destructor

	virtual ~Student();
private :
	long numberStudent;
	std::string firstName;
	std::string lastName;

	int getId();
};

