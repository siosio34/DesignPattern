#include "User.h"

User::User()
{
	id=0;
	mileage=0;
	grade="";
}

int User::get_id()
{
	return id;
}

void User::set_id(int _id)
{
	id=_id;
}

int User::get_mileage()
{
	return mileage;
}

void User::set_mileage(int _mileage)
{
	mileage=_mileage;
}

string User::get_grade()
{
	return grade;
}

void User::set_grade(string _grade)
{
	grade=_grade;
}


