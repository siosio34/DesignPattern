#include "StarCraft.h"

void StarCraft::printStart()
{
	int input;

	while(1)
	{
		system("cls");

		cout<<"\n\t StarCraft \n\n";
		cout<<"\t┌────────────────────┐\n";
		cout<<"\t│  메뉴                                  │\n";
		cout<<"\t│                                        │\n";
		cout<<"\t│  1. 아군 유닛 생산                     │\n";
		cout<<"\t│  2. 아군 유닛 확인                     │\n";
		cout<<"\t│  3. 적군 유닛 생산                     │\n";
		cout<<"\t│  4. 적군 유닛 확인                     │\n";
		cout<<"\t│  5. 배 틀                              │\n";
		cout<<"\t│  6. 종 료                              │\n";
		cout<<"\t└────────────────────┘\n";

		cout<<"\n\t 메뉴 선택 : ";
		cin>>input;

		if(input == 1)
		{
			print_make();
		}

		else if(input == 2)
		{
			allyUnitPrint();
		}
		else if(input == 3)
		{
			createEnemy();
		}
		else if(input ==4)
		{
			enemyUnitPrint();
		}
		else if(input ==5)
		{
			turnBattle();
		}
		else if(input == 6)
		{
			return ;
		}
		else
		{
			cout<<"\n\t 잘못된 입력입니다 \n";
			system("pause");
			continue;
		}
	}
}

void StarCraft::print_make()
{
	int _type;
	_type=1;

	while(_type != 0)
	{
		system("cls");
		cout<<"\n\t StarCraft \n\n";
		cout<<"\t┌────────────────────┐\n";
		cout<<"\t│  메뉴                                  │\n";
		cout<<"\t│                                        │\n";
		cout<<"\t│  1. 질럿                               │\n";
		cout<<"\t│  2. 해병                               │\n";
		cout<<"\t│  3. 히드라                             │\n";
		cout<<"\t│  4. 아콘                               │\n";
		cout<<"\t│  5. 스카우트                           │\n";
		cout<<"\t│  6. 가디언                             │\n";
		cout<<"\t│  7. 발키리                             │\n";
		cout<<"\t│  0. 유닛 그만 사기                     │\n";
		cout<<"\t└────────────────────┘\n";

		cout<<"\n\t 메뉴 선택 : ";

		cin>>_type;
		createAlly(_type);

	}
}

void StarCraft::createAlly(int type)
{
	unit=uf.createUnit(type);
	if(unit != NULL)
		list_ally_unit.push_back(*unit);
}

void StarCraft::allyUnitPrint()
{

	system("cls");
	cout<<"\n\t StarCraft \n\n";
	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│             아 군 유 닛                │\n";
	cout<<"\t└────────────────────┘\n\n\n";


	vector<Unit>::iterator it;

	cout<<"\t "<<setw(10)<<"이름"<<setw(10)<<"체력"<<setw(10)<<"공격력"<<setw(10)<<"방어력"<<setw(15)<<"이동형태"<<setw(15)<<"공격가능"<<setw(15)<<"스플래시"<<"\n\n";
	for(it = list_ally_unit.begin() ; it != list_ally_unit.end() ; it++)
	{
		
		cout<<"\t "<<setw(10)<<it->get_name();
		cout<<setw(10)<<it->get_healthPoint();
		cout<<setw(10)<<it->get_damage();
		cout<<setw(10)<<it->get_defende();
		cout<<setw(15)<<it->get_vehicleType()->get_vehicle();
		cout<<setw(15)<<it->get_attackbehavior()->get_attack();
		cout<<setw(15)<<it->get_splashable()->get_splashable();

		cout<<endl;
	}
	system("pause");
}

void StarCraft::createEnemy()
{

	system("cls");
	cout<<"\n\t StarCraft \n\n";
	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│          적군 유닛 생산 완료           │\n";
	cout<<"\t└────────────────────┘\n\n\n";

	int a = rand()%7 +1;
	unit=uf.createUnit(a);
	list_enemy_unit.push_back(*unit);

	system("pause");
}

void StarCraft::enemyUnitPrint()
{
	system("cls");
	cout<<"\n\t StarCraft \n\n";
	cout<<"\t "<<setw(45)<<"┌────────────────────┐\n";
	cout<<"\t "<<setw(45)<<"│             적 군 유 닛                │\n";
	cout<<"\t "<<setw(45)<<"└────────────────────┘\n\n\n";


	vector<Unit>::iterator it;

	cout<<"\t "<<setw(10)<<"이름"<<setw(10)<<"체력"<<setw(10)<<"공격력"<<setw(10)<<"방어력"<<setw(15)<<"이동형태"<<setw(15)<<"공격가능"<<setw(15)<<"스플래시"<<"\n\n";
	for(it = list_enemy_unit.begin() ; it != list_enemy_unit.end() ; it++)
	{
		cout<<"\t "<<setw(10)<<it->get_name();
		cout<<setw(10)<<it->get_healthPoint();
		cout<<setw(10)<<it->get_damage();
		cout<<setw(10)<<it->get_defende();
		cout<<setw(15)<<it->get_vehicleType()->get_vehicle();
		cout<<setw(15)<<it->get_attackbehavior()->get_attack();
		cout<<setw(15)<<it->get_splashable()->get_splashable();

		cout<<endl;
	}
	system("pause");
}

void StarCraft::turnBattle()
{
	Unit *Ally;
	Unit *enemy;
	bool check = true;
	int attack_count = 0;
	int count=0;
	int hurt;


	while(list_ally_unit.size() !=0 && list_enemy_unit.size()!=0)
	{
		if(check)
		{
			system("cls");
			cout<<"\t "<< " < 아 군 차 례 > "<<"\n\n";
			count++;
			Ally = randomAlly(); // 구현필요
			
			cout<<"\t "<<" 공 격 유 닛 : "<<Ally->get_name()<<"\n";
			cout<<"\t "<<" 공 격 력 : "<<Ally->get_damage()<<"\n\n";

			check=false;
			if(list_defender.size() != 0)
			{
				splash_pos=rand()%list_defender.size();
				enemy = &list_defender.at(splash_pos);
				Ally ->get_attackbehavior()->attack_damage(*Ally,*enemy);

				if(list_defender.size() != 1)
				{
					if(Ally->get_splashable()->get_splashable() == "있음")
						Ally->get_attackbehavior()->splash_damage(*Ally,list_defender,splash_pos); // 구현필요

					vector <Unit> ::iterator it;
					vector <Unit> ::iterator it2;
					
					for( it=list_enemy_unit.begin() ; it!= list_enemy_unit.end() ; it++)
					{
						for( it2=list_defender.begin() ; it2!=list_defender.end() ; it2++)
						{
							if(it->get_healthPoint() != it2->get_healthPoint() && it->get_id() == it2->get_id() && it->get_id() != enemy->get_id())
							{
								 hurt = it->get_healthPoint() - it2->get_healthPoint();
								it->set_healthPoint(it2->get_healthPoint());
						
								if(it->get_healthPoint() <= 0)
								{
										cout<<"\t "<<it->get_id()<<" "<<it->get_name()<<"이 전사 하였습니다 "<<"\n";
										eraseEnemy(*it);
										it=list_enemy_unit.begin();
								}
								else
									cout<<"\t "<<it->get_id()<<" "<<it->get_name()<<" 가 "<<hurt<<"의 피해를 입었습니다. "<<"\n";

								break;
							}
						}
					}
				}

				if(enemy ->get_healthPoint() <= 0)
				{
					cout<<"\t "<<enemy->get_id()<<" "<<enemy->get_name()<<"이 전사 하였습니다 "<<"\n";
					eraseEnemy(*enemy);
				}

				else
				{
					vector<Unit> ::iterator it=list_enemy_unit.begin();
					{
						for( it ; it != list_enemy_unit.end() ; it++)
						{
							if( it->get_id() == enemy->get_id() )
							{
								hurt = it->get_healthPoint() - enemy->get_healthPoint();
								cout<<"\t "<<enemy->get_id()<<" "<<enemy->get_name()<< " 가 "<<hurt<<"의 피해를 입었습니다. "<<"\n";
								it->set_healthPoint(enemy->get_healthPoint());
								
							}
						}
					}
				}

			}
			else 
			{
				cout<<"\t 공격 가능 대상이 없음 \n\n";
				vector <Unit> ::iterator it = list_ally_unit.begin();
					if(Ally->get_attackbehavior()->get_attack()=="지상")
					{
						for( it ; it !=list_ally_unit.end() ;it++)
						{
							if(it->get_attackbehavior()->get_attack() == "공중" || it->get_attackbehavior()->get_attack() == "지상&공중")
							{
								break;
							}
							else
							{
								attack_count++;
								break;
							}
						}
					}
					else if(Ally->get_attackbehavior()->get_attack()=="공중")
					{
						for( it ; it !=list_ally_unit.end() ;it++)
						{
							if(it->get_attackbehavior()->get_attack() == "지상" || it->get_attackbehavior()->get_attack() == "지상&공중")
							{
								break;
							}
							else
							{
								attack_count++;
								break;
							}
						}
						
					}
					
				}
				system("pause");
				
		}

		else
		{
			cout<<"\t "<< " < 적 군 차 례 > "<<"\n\n";
			check = true;
			count++;
			if(check)
			{
				Ally = randomEnemy(); // 구현필요
				cout<<"\t "<< " 공 격 유 닛 : "<<Ally->get_name()<<"\n";
				cout<<"\t "<< " 공 격 력 : "<<Ally->get_damage()<<"\n\n";

				if(list_defender.size() != 0)
				{
					splash_pos=rand()%list_defender.size();
					enemy = &list_defender.at(splash_pos);
					Ally ->get_attackbehavior()->attack_damage(*Ally,*enemy);

					if(list_defender.size() != 1)
					{
						if(Ally->get_splashable()->get_splashable() == "있음")
							Ally->get_attackbehavior()->splash_damage(*Ally,list_defender,splash_pos); // 구현필요

						vector <Unit> ::iterator it;
						vector <Unit> ::iterator it2;

						for( it=list_ally_unit.begin() ; it!= list_ally_unit.end() ; it++)
						{
							for( it2=list_defender.begin() ; it2!=list_defender.end() ; it2++)
							{
								if(it->get_healthPoint() != it2->get_healthPoint() && it->get_id() == it2->get_id() && it->get_id() != enemy->get_id() )
								{
									hurt = it->get_healthPoint() - it2->get_healthPoint();
									it->set_healthPoint(it2->get_healthPoint());

									if(it->get_healthPoint() <= 0)
									{
										cout<<"\t "<<it->get_id()<<" "<<it->get_name()<<"가  전사 하였습니다 \n";
										eraseAlly(*it);
										it=list_ally_unit.begin();
									}
									else
									{
										 
										cout<<"\t "<<it->get_id()<<" "<<it->get_name()<<" 가 "<<hurt<<"의 피해를 입었습니다 \n";
									}
									break;
								}
							}
						}
					}


					if(enemy ->get_healthPoint() <= 0)
					{
						cout<<"\t "<<enemy->get_id()<<" "<<enemy->get_name()<<"가 전사 하였습니다. \n";
						eraseAlly(*enemy);
					}

					else
					{
						vector<Unit> ::iterator it=list_ally_unit.begin();
						{
							for( it ; it != list_ally_unit.end() ; it++)
							{
								if( it->get_id() == enemy->get_id() )
								{
									hurt = it->get_healthPoint() - enemy->get_healthPoint();
									it->set_healthPoint(enemy->get_healthPoint());
									cout<<"\t "<<enemy->get_id()<<" "<<enemy->get_name()<<"가 "<<hurt<<"의 피해를 입었습니다 \n";
								}
							}
						}
					}

				}
				else 
				{
					cout<<"\t 공격 가능 대상이 없음 \n\n";
					vector <Unit> ::iterator it = list_ally_unit.begin();
					if(Ally->get_attackbehavior()->get_attack()=="지상")
					{
						for( it ; it !=list_ally_unit.end() ;it++)
						{
							if(it->get_attackbehavior()->get_attack() == "공중" || it->get_attackbehavior()->get_attack() == "지상&공중")
							{
								break;
							}
							else
							{
								attack_count++;
								break;
							}
						}
					}
					else if(Ally->get_attackbehavior()->get_attack()=="공중")
					{
						for( it ; it !=list_ally_unit.end() ;it++)
						{
							if(it->get_attackbehavior()->get_attack() == "지상" || it->get_attackbehavior()->get_attack() == "지상&공중")
							{
								break;
							}
							else
							{
								attack_count++;
								break;
							}
						}
						
					}
					
				}
			}
			system("pause");
			
		}

		if(count == 2)
		{
			if(check==true && attack_count == 2)
				break;
			else
			{
				count=0;
				attack_count=0;
			}
		}


	}
	system("cls");
	cout<<"\n\t StarCraft \n\n";
	cout<<"\t "<<setw(45)<<"┌────────────────────┐\n";
	cout<<"\t "<<setw(45)<<"│             전 투 종 료                │\n";
	cout<<"\t "<<setw(45)<<"└────────────────────┘\n\n\n";


	if(attack_count == 2 || (list_ally_unit.size()==0 && list_enemy_unit.size()==0))
	{
		system("pause");
		cout<<"\t ┌────────────┐ \n";
		cout<<"\t │       무 승 부         │ \n";
		cout<<"\t └────────────┘ \n";
		
	}

	else if(list_ally_unit.size() ==0)
	{
		
		cout<<"\t ┌────────────┐ \n";
		cout<<"\t │       적 군 승 리      │ \n";
		cout<<"\t └────────────┘ \n";
		system("pause");
		enemyUnitPrint();
		system("pause");
	}
	else if(list_enemy_unit.size()==0)
	{	
		system("pause");
		cout<<"\t ┌────────────┐ \n";
		cout<<"\t │       아 군 승 리      │ \n";
		cout<<"\t └────────────┘ \n";
		system("pause");
		allyUnitPrint();
		system("pause");
	}


}

Unit *StarCraft::randomAlly()
{
	Unit *unit2;
	unit2=&list_ally_unit.at(rand()%list_ally_unit.size());
	string available = unit2->get_attackbehavior()->get_attack();
	vector<Unit>::iterator start = list_enemy_unit.begin();
	vector<Unit>::iterator end = list_enemy_unit.end();
	list_defender.clear();
	int count=0;

	if(available == "지상")
	{
		for( start ; start != end ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "지상")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;

	}

	else if(available == "공중")
	{
		for( start ; start != end ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "공중")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;
	}

	else
	{
		for( start ; start != end ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "지상" || start->get_vehicleType()->get_vehicle() == "공중")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;
	}
	return NULL;
}

Unit *StarCraft::randomEnemy()
{
	Unit *unit2;
	unit2=&list_enemy_unit.at(rand()%list_enemy_unit.size());
	string available = unit2->get_attackbehavior()->get_attack();
	vector<Unit>::iterator start = list_ally_unit.begin();
	vector<Unit>::iterator end = list_ally_unit.end();
	list_defender.clear();
	int count=0;

	if(available == "지상")
	{
		for( start ; start != list_ally_unit.end() ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "지상")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;

	}

	else if(available == "공중")
	{
		for( start ; start != list_ally_unit.end() ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "공중")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;
	}

	else
	{
		for( start ; start != list_ally_unit.end() ; start++ )
		{
			if(start->get_vehicleType()->get_vehicle() == "지상" || start->get_vehicleType()->get_vehicle() == "공중")
			{
				list_defender.push_back(*start);

			}
		}
		return unit2;
	}
	return NULL;
}


void StarCraft::eraseAlly(Unit &_unit)  // healthPoint(체력)이 0인 아군 Unit객체 삭제
{
	if(_unit.get_healthPoint() <= 0 )
	{
		vector<Unit> :: iterator it;
		for(it =list_ally_unit.begin() ; it != list_ally_unit.end() ; it++)
		{
			if(it->get_id() == _unit.get_id())
			{
				list_ally_unit.erase(it);
				break;
			}
		}
	}
}
void StarCraft::eraseEnemy(Unit &_unit)  // healthPoint(체력)이 0인 적군 Unit객체 삭제
{
	if(_unit.get_healthPoint() <= 0 )
	{
		vector<Unit> :: iterator it;
		for(it =list_enemy_unit.begin() ; it != list_enemy_unit.end() ; it++)
		{
			if(it->get_id() == _unit.get_id())
			{
				list_enemy_unit.erase(it);
				break;
			}
		}
	}
}








