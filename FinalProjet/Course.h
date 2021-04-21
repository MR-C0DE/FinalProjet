#pragma once
#include <string>
class Course
{
public:
	//Constructeur

	Course() = default;

	Course(long, std::string, std::string);

	//Declaration du prototype GETTERS
	long getCourseNumber() const noexcept;
	std::string getCode() const noexcept;
	std::string getTitle() const noexcept;

	//Declaration du prototype SETTERS
	void setCourseNumber(long);
	void setCode(std::string);
	void setTitle(std::string);

	//Les autres fonctions membres de la classe
	void checkCoursNumber();
	void saveCourse(bool);
	void afficherCours();

	//Destructeur
	virtual ~Course();
private :

	long CourseNumber;
	std::string code;
	std::string title;


	int countCourse();

};

