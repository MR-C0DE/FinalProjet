#pragma once
#include <string>
class Course
{
public:
	//Constructor

	Course() = default;

	Course(long, std::string, std::string);

	//GETTERS
	long getCourseNumber() const noexcept;
	std::string getCode() const noexcept;
	std::string getTitle() const noexcept;

	//SETTERS

	void setCourseNumber(long);
	void setCode(std::string);
	void setTitle(std::string);

	//Destructor
	virtual ~Course();
private :

	long CourseNumber;
	std::string code;
	std::string title;

};

