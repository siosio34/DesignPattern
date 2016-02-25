#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "Unit.h"
#include "BattleAlgorithm.h"
class Unit;
class BattleAlgorithm;
//-----------------------------------------����, ����
class VehicleType
{
public:
	VehicleType(){};
	virtual void vehicle() = 0;
	string get_vehicle()
	{
		return m_vehicle;
	};
protected:
	string m_vehicle;
};

class Ground : public VehicleType
{
public:
	Ground(){vehicle();};
	void vehicle()
	{
		m_vehicle="����";
	}

};

class Sky : public VehicleType
{
public:
	Sky(){vehicle();};
	void vehicle()
	{
		m_vehicle="����";
	}
};

//-----------------------------------------���÷��� ������

class Splashable
{
public:
	Splashable(){};
	virtual void splash() = 0;
	string get_splashable()
	{
		return m_splashable;
	}
protected:
	string m_splashable;
};

class Splash:public Splashable
{
public:
	Splash(){splash();};
	void splash()
	{
		m_splashable="����";
	}
};

class Nosplash :public Splashable
{
public:
	Nosplash(){splash();};
	void splash()
	{
		m_splashable="����";
	}
};

//-----------------------------------------����


class Attackbehavior
{
public:
	Attackbehavior(){};
	virtual void attack() = 0;
	string get_attack()
	{
		return m_attack;
	}
	void attack_damage(Unit &Attacker, Unit &Defender);

	void splash_damage(Unit &Attacker, vector<Unit>& Defender, int pos);

protected:
	string m_attack;

};

class Army :public Attackbehavior
{
public:
	Army(){attack();};
	void attack()
	{
		m_attack="����";
	}
};

class AirForce :public Attackbehavior
{
public:
	AirForce(){attack();};
	void attack()
	{
		m_attack="����";
	}
};

class Complex :public Attackbehavior
{
public:
	Complex(){attack();};
	void attack()
	{
		m_attack="����&����";
	}
};

//-----------------------------------------������

class SizeType
{
public:
	SizeType(){};
	virtual void size() = 0;
	string get_size()
	{
		return m_size;
	};
protected:
	string m_size;
};

class Small : public SizeType
{
public:
	Small(){};
	void size();
};

class Medium : public SizeType
{
public:
	Medium(){};
	void size();
};

class Large : public SizeType
{
public:
	Large(){};
	void size();
};