
#include "BattleAlgorithm.h"

int BattleAlgorithm::EstimateDamage(Unit &Attaker,Unit &Defender)
{
	int _damage = Attaker.get_damage() - Defender.get_defende();
	return _damage;
	//스플래쉬 부분 나중에 구현.
}