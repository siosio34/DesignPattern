#pragma once
#include "UnitFactory.h"
#include <iomanip>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

class StarCraft
{
public:
	StarCraft(){};
	
public: // turnBattle ���� �Լ� ����
	void turnBattle();	// �Ʊ� vs ���� �ο�
	void createAlly(int type);  // �Ʊ����� ��ü ����
	void createEnemy();	// �������� ��ü ����
	Unit* randomAlly();	// �������� �Ʊ� Unit ��ü ����
	Unit* randomEnemy();  // �������� ���� Unit ��ü ����
	void eraseAlly(Unit &_unit);  // healthPoint(ü��)�� 0�� �Ʊ� Unit��ü ����
	void eraseEnemy(Unit &_unit);  // healthPoint(ü��)�� 0�� ���� Unit��ü ����
	
public :
	void printStart();	// ����ȭ��
	void print_make();  //���� ���� ȭ��
	void allyUnitPrint();  // �Ʊ����� vector<Unit> list_ally_unit ���
	void enemyUnitPrint();  // �������� vector<Unit> list_enemy_unit ���

private:
	UnitFactory uf;  // �������丮 ��ü
	Unit* unit;  // ���� ��ü
	vector<Unit> list_ally_unit;  // �Ʊ����� ����
	vector<Unit> list_enemy_unit;  // �������� ����
	vector<Unit> list_defender; // ���÷����� ���ϴ� ���� ����
	int splash_pos; // ���÷��� ���ϴ� list_defender�� ��ġ ����
};


