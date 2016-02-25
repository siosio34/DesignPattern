#include "Strategy.h"

void Attackbehavior::attack_damage(Unit &Attacker,Unit &Defender)
{
	int damage = BattleAlgorithm::EstimateDamage(Attacker,Defender);
	Defender.receiveDamage(damage);
}

void Attackbehavior::splash_damage(Unit &Attacker, vector<Unit>& Defender, int pos)
{
	int damage=0;
	 
		if(pos != 0 && pos != Defender.size()-1)
		{
			damage = BattleAlgorithm::EstimateDamage(Attacker,Defender.at(pos-1));
			Defender.at(pos-1).receiveDamage(damage/2);
			damage = BattleAlgorithm::EstimateDamage(Attacker,Defender.at(pos+1));
			Defender.at(pos+1).receiveDamage(damage/2);
		}
		else if(pos == 0 )
		{
			damage = BattleAlgorithm::EstimateDamage(Attacker,Defender.at(1));
			Defender.at(1).receiveDamage(damage/2);
		}
		else if(pos == Defender.size()-1)
		{
			damage = BattleAlgorithm::EstimateDamage(Attacker,Defender.at(Defender.size()-2));
			Defender.at(Defender.size()-2).receiveDamage(damage/2);
		}
}
