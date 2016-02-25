#include "HamburgerFactory.h"

Hamburger* HamburgerFactory::create_hamburger(int _type)
{
	Hamburger *Hb;

	while(1)
	{

	if(_type == 1)
	{
		Hb = new Wheat();
		Hb = new Bulgogi(Hb);
		Hb = new Tomato(Hb);
		Hb = new Lettuce(Hb);
		Hb = new Cheese(Hb);
		break;
	}
	else if(_type == 2)
	{
		Hb = new Wheat();
		Hb = new Chicken(Hb);
		Hb = new Tomato(Hb);
		Hb = new Lettuce(Hb);
		Hb = new Bacon(Hb);
		break;
	}
	else if(_type == 3)
	{
		Hb = new Rye();
		Hb = new Cheese(Hb);
		Hb = new Tomato(Hb);
		Hb = new Lettuce(Hb);
		Hb = new Bacon(Hb);
		break;
	}
	else
	{
		cout<<"\n\t < 입력하신 항목과 일치하는 버거가 존재하지 않습니다 > \n";
		system("pause");
		continue;
	}
	}
	return Hb;
		
}

Hamburger* HamburgerFactory::add_topping(Hamburger* _hm, int _type)
{
	while(1)
	{
		if(_type == 1)
		{
			_hm=new Tomato(_hm);
			break;
		}
		else if(_type == 2)
		{
			_hm=new Bacon(_hm);
			break;
		}
		else if(_type == 3)
		{
			_hm=new Cheese(_hm);
			break;
		}
		else if(_type == 4)
		{
			_hm=new Lettuce(_hm);
			break;
		}
	}
	return _hm;
}