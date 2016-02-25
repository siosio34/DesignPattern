#include "UnitFactory.h"

Unit* UnitFactory::createUnit(int type)
{
	Unit *unit=new Unit();
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;
	count++;
	
	switch(type)
	{
	case 1: // 질럿
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Army;
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("질럿");
		unit->set_healthPoint(100);
		unit->set_damage(8);
		unit->set_defende(3);
		return unit;
		break;
	case 2:
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("해병");
		unit->set_healthPoint(40);
		unit->set_damage(6);
		unit->set_defende(1);
		return unit;
		break;
	case 3:
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("히드라");
		unit->set_healthPoint(80);
		unit->set_damage(10);
		unit->set_defende(1);
		return unit;
		break;
	case 4:
		vehicleType = new Ground();
		splashable = new Splash();
		attackbehavior = new Complex();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("아콘");
		unit->set_healthPoint(30);
		unit->set_damage(200);
		unit->set_defende(1);
		return unit;
		break;
	case 5:
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Complex();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("스카웃");
		unit->set_healthPoint(150);
		unit->set_damage(12);
		unit->set_defende(2);
		return unit;
		break;
	case 6:
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Army();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("가디언");
		unit->set_healthPoint(150);
		unit->set_damage(20);
		unit->set_defende(2);
		return unit;
		break;
	case 7:
		vehicleType = new Sky();
		splashable = new Splash();
		attackbehavior = new AirForce();
		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(count);
		unit->set_name("발키리");
		unit->set_healthPoint(200);
		unit->set_damage(10);
		unit->set_defende(2);
		return unit;
		break;
	default:
		cout<<"\n\t잘못 입력하셧습니다 ! "<<endl;
		return NULL;
		}
}






