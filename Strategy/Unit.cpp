#include "Unit.h"

int Unit::get_damage()// 데미지 리턴
{
	return offence;
}	
int Unit::get_defende() // 공격력 리턴
{
	return defense;
}
int Unit::get_healthPoint()//체력 리턴
{
	return healthPoint;
}
string Unit::get_name() // 이름 리턴
{
	return name;
}

int Unit::get_id()   //아이디 리턴
{
	return id;
}

//////////////////////////////////////////////////////////////////
void Unit::set_damage(int _damage) 
{
	offence=_damage;
}
void Unit::set_defende(int _defende) // 방어력 입력
{
	defense=_defende;
}
void Unit::set_healthPoint(int _healthPoint)   // 체력 입력
{
	healthPoint=_healthPoint;
}
void Unit::set_name(string _name)   // 이름 입력
{
	name=_name;
}
void Unit::set_id(int _id)   // 아이디 입력
{
	id=_id;
}
/////////////////////////////////////////////////////////////////////
