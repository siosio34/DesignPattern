#pragma once
#include <iostream>
#include <string>
#include "Strategy.h"
using namespace std;

class VehicleType;
class Ground;
class Sky;

class Splashable;
class Splash;
class Nosplash;

class Attackbehavior;
class Army;
class AirForce;
class Complex;

class SizeType;
class Small;
class Medium;
class Large;


class Unit
{
public:
	Unit(){};

public:
	string performVehicleType(){};  // �̵� "����""����"
	string performAttackBehavior(){};  // ���ݰ����� ���� "����""����""����&����"
	string performSplashable(){};	// ���÷��� ����,����
	string performSizeType();
	void receiveDamage(int _damage)
	{
		this->healthPoint=this->healthPoint - _damage;
	}// �޴� ������

public:
	int get_damage();	// ������ ����
	int get_defende();   // ���ݷ� ����
	int get_healthPoint();   //ü�� ����
	string get_name();   // �̸� ����
	void set_damage(int _damage);   // ������ �Է�
	void set_defende(int _defende);   // ���� �Է�
	void set_healthPoint(int _healthPoint);   // ü�� �Է�
	void set_name(string _name);   // �̸� �Է�
	void set_id(int _id);   // ���̵� �Է�
	int get_id();   //���̵� ����

public:// ��Ʈ��Ƽ�� ����
	void set_vehicleType(VehicleType &_vehicleType){vehicleType=&_vehicleType;}; 
	void set_splashable(Splashable &_splashable){splashable= &_splashable;};
	void set_attackbehavior(Attackbehavior &_attackbehavior){attackbehavior=&_attackbehavior;};
	void set_sizetype(SizeType &_sizetype){sizetype=&_sizetype;};

	Attackbehavior* get_attackbehavior()
	{
		return attackbehavior;
	}
	VehicleType *get_vehicleType()
	{
		return vehicleType;
	}
	Splashable *get_splashable()
	{
		return splashable;
	}

private:
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;
	SizeType *sizetype;
	int offence; // ���ݷ�
	int defense;  // ����
	int healthPoint;  // ü��
	string name;  // �̸�
	int id;// ���̵�
};

