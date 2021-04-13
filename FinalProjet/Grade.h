#pragma once
class Grade
{
public:

	//Constructors

	Grade() = default;

	Grade(long, long, double);

	//GETTERS
	long getCourseNumber() const noexcept;
	long getStudentNumber() const noexcept;
	double getGrade() const noexcept;
	

	//SETTERS

	void setStudentNumber(long);
	void setCourseNumber(long);
	void setGrade(double);

	//Destructor

	virtual ~Grade();


private:
	long studentNumber;
	long courseNumber;
	double grade;
	
};

