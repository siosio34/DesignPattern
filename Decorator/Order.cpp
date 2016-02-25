#include "Order.h"

Order::Order()
{
	user=NULL;
	burgur_name="";	
	description="";	
	burger_count=0;	
	price=0;	// ÇÜ¹ö°Å
	age=0;	// ÇÜ¹ö°Å
	message="";	// ÇÜ
	burger_type=0;	
}

Order::Order(User* _user,string _burgur_name,int _burger_count,int _price,string _message)
{
	user=_user;
	burgur_name=_burgur_name;
	burger_count=_burger_count;
	price=_price;
	message=_message;
}

User* Order::get_user()
{
	return user;
}

string Order::get_burger_name()
{
	return burgur_name;
}

int Order::get_burger_count()
{
	return burger_count;
}

int Order::get_price()
{
	return price;
}

string Order::get_message()
{
	return message;
}

void Order::set_user(User* _user)
{
	user=_user;
}

void Order::set_burger_name(string _name)
{
	burgur_name=_name;
}

void Order::set_burger_count(int _count)
{
	burger_count=_count;
}

void Order::set_price(int _price)
{
	price=_price;
}

void Order::set_message(string _message)
{
	message=_message;
}

int Order::get_age()
{
	return age;
}

void Order::set_age(int _age)
{
	age=_age;
}

void Order::set_description(string _description)
{
	description=_description;
}

string Order::get_description()
{
	return description;
}

int* Order::get_topping()
{
	return topiing;
}

void Order::set_topping(int ary[])
{
	for(int i=0 ; i < 5 ; i++)
	{
		topiing[i]=ary[i];
	}
}

int Order::get_burger_type()
{
	return burger_type;
}

void Order::set_burger_type(int _type)
{
	burger_type=_type;
}







