#pragma once
#include "Strategy.h"
#include "Unit.h"

class UnitFactory
{
public:
	UnitFactory(){count=-1;};
	Unit* createUnit(int type); // ���� ����

private:
	int count;

};

