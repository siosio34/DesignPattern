
#include "BattleAlgorithm.h"

int BattleAlgorithm::EstimateDamage(Unit &Attaker,Unit &Defender)
{
	int _damage = Attaker.get_damage() - Defender.get_defende();
	return _damage;
	//���÷��� �κ� ���߿� ����.
}