#include "Unit.h"

int Unit::get_damage()// ������ ����
{
	return offence;
}	
int Unit::get_defende() // ���ݷ� ����
{
	return defense;
}
int Unit::get_healthPoint()//ü�� ����
{
	return healthPoint;
}
string Unit::get_name() // �̸� ����
{
	return name;
}

int Unit::get_id()   //���̵� ����
{
	return id;
}

//////////////////////////////////////////////////////////////////
void Unit::set_damage(int _damage) 
{
	offence=_damage;
}
void Unit::set_defende(int _defende) // ���� �Է�
{
	defense=_defende;
}
void Unit::set_healthPoint(int _healthPoint)   // ü�� �Է�
{
	healthPoint=_healthPoint;
}
void Unit::set_name(string _name)   // �̸� �Է�
{
	name=_name;
}
void Unit::set_id(int _id)   // ���̵� �Է�
{
	id=_id;
}
/////////////////////////////////////////////////////////////////////
