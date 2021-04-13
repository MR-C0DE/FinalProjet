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
	long getNumberStudent() const noexcept;
	std::string getFirstName() const noexcept;
	std::string getLastName() const noexcept;

	//SETTERS

	void setNumberStudent(long);
	void setFirstName(std::string);
	void setLastName(std::string);

	//Authors members functions

	void afficher();
	void confirmer(bool);

	//Destructor

	virtual ~Student();
private :
	long numberStudent;
	std::string firstName;
	std::string lastName;

	int getId();
};

