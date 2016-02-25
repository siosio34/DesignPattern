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
	string performVehicleType(){};  // 이동 "지상""공중"
	string performAttackBehavior(){};  // 공격가능한 형태 "지상""공중""지상&공중"
	string performSplashable(){};	// 스플래쉬 있음,없음
	string performSizeType();
	void receiveDamage(int _damage)
	{
		this->healthPoint=this->healthPoint - _damage;
	}// 받는 데미지

public:
	int get_damage();	// 데미지 리턴
	int get_defende();   // 공격력 리턴
	int get_healthPoint();   //체력 리턴
	string get_name();   // 이름 리턴
	void set_damage(int _damage);   // 데미지 입력
	void set_defende(int _defende);   // 방어력 입력
	void set_healthPoint(int _healthPoint);   // 체력 입력
	void set_name(string _name);   // 이름 입력
	void set_id(int _id);   // 아이디 입력
	int get_id();   //아이디 리턴

public:// 스트레티지 패턴
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
	int offence; // 공격력
	int defense;  // 방어력
	int healthPoint;  // 체력
	string name;  // 이름
	int id;// 아이디
};

