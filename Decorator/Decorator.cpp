#include "Decorator.h"

Tomato::Tomato(Hamburger* _hamburger)
{
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

Bacon::Bacon(Hamburger* _hamburger)
{
	
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

Cheese::Cheese(Hamburger* _hamburger)
{
	
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

Lettuce::Lettuce(Hamburger* _hamburger)
{
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

Bulgogi::Bulgogi(Hamburger* _hamburger)
{
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

Chicken::Chicken(Hamburger* _hamburger)
{
	hamburger=_hamburger;
	cost=get_cost();
	description = get_description();
}

int Tomato::get_cost()
{
	return 500+hamburger->get_cost();
}

int Bacon::get_cost()
{
	return 300+hamburger->get_cost();
}

int Lettuce::get_cost()
{
	return 500+hamburger->get_cost();
}

int Cheese::get_cost()
{
	return 200+hamburger->get_cost();
}

int Bulgogi::get_cost()
{
	return 1000+hamburger->get_cost();
}

int Chicken::get_cost()
{
	return 1500+hamburger->get_cost();
}

string Tomato::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", �丶�� ";

	return Toping;
}


string Bacon::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", ������ ";

	return Toping;
}

string Lettuce::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", ����� ";

	return Toping;
}

string Cheese::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", ġ�� ";

	return Toping;
}

string Bulgogi::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", �Ұ�� ��Ƽ ";

	return Toping;
}

string Chicken::get_description()
{
	string Toping = hamburger->get_description();
	Toping += ", ġŲ ��Ƽ ";

	return Toping;
}





    
