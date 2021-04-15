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

	bool checkNumberStudent();
	bool checkNumberCourse();
	void saveGrade();

	//Destructor

	virtual ~Grade();


private:
	long studentNumber;
	long courseNumber;
	double grade;
	
};

