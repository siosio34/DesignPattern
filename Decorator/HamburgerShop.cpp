#include "HamburgerShop.h"

HamburgerShop::HamburgerShop()
{
	user_count=0;
	count=0;
	load_user();
}
void HamburgerShop::load_user()
{
	ifstream ifn;
	ifn.open("user.txt");

	User * user;

	int U_id;
	int U_mileage;

	string U_grade;

	while(!ifn.eof())
	{
		user=new User;
		ifn>> U_id >> U_mileage >> U_grade;
		user->set_id(U_id);
		user->set_mileage(U_mileage);
		user->set_grade(U_grade);
		array_user[user_count]=user;
		user_count ++;
	}
}

void HamburgerShop::save_user()
{
	ofstream of;
	of.open("user.txt");

	for(int i=0 ; i<user_count ; i++)
	{
		of << array_user[i]->get_id() <<" "<< array_user[i]->get_mileage()<<" " << array_user[i]->get_grade();
		if(i != user_count-1)
			of<<endl;
	}
}

User* HamburgerShop::search_user(int _id)
{
	for(int i=0 ; i<user_count ; i++)
	{
		if(array_user[i]->get_id() == _id)
			return array_user[i];
	}
	return NULL;
}

void HamburgerShop::print_start()
{
	int input;
	cout<<"\n\t 영제's 맥도리아 \n\n";

	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│  고용된 종업원의 수를 입력하세요       │\n";
	cout<<"\t└────────────────────┘\n";

	cout<<"\n\t menuNum : ";
	cin>>employee;

	while(1)
	{
		system("cls");

		cout<<"\n\t 영제's 맥도리아 \n\n";
		cout<<"\t┌────────────────────┐\n";
		cout<<"\t│  메뉴                                  │\n";
		cout<<"\t│                                        │\n";
		cout<<"\t│  1. 햄버거 주문                        │\n";
		cout<<"\t│  2. 주문 내역                          │\n";
		cout<<"\t│  3. 햄버거 만들기                      │\n";
		cout<<"\t│  4. 종 료                              │\n";
		cout<<"\t└────────────────────┘\n";

		cout<<"\n\t 메뉴 선택 : ";
		cin>>input;

		if(input == 1)
		{
			print_menu();
		}

		else if(input == 2)
		{
			print_order();

		}
		else if(input == 3)
		{
			priority_makelist();
			print_hamburger();

		}
		else if(input ==4)
		{
			return  ;
		}
		else
		{
			cout<<"\n\t 잘못된 입력입니다 \n";
			system("pause");
			continue;
		}
	}
}

void HamburgerShop::print_menu()
{
	int u_id;
	int burger_type;
	int check_toping;
	int select_toping;
	int count;
	int num=0;
	int toping[5];

	system("cls");
	cout<<"\n\t 영제's 맥도리아 \n\n";
	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│ 햄버거 메뉴                            │\n";
	cout<<"\t│                                        │\n";
	cout<<"\t│  1. 불고기 버거                        │\n";
	cout<<"\t│  2. 치킨 버거                          │\n";
	cout<<"\t│  3. 치즈 버거                          │\n";
	cout<<"\t│  4. 종 료                              │\n";
	cout<<"\t└────────────────────┘\n";

	cout<<"\n\t [ 아이디 입력 ] : ";
	cin>>u_id;

	current_user =search_user(u_id);

	cout<<"\n\t [ 햄버거 종류 선택 ] : ";
	cin>>burger_type;

	cout<<"\n\t [ 햄버거 개수 입력 ] : ";
	cin>>count;

	cout<<"\n\t [ 사용 가능한 마일리지 ] : ";
	cout<<current_user->get_mileage()<<endl;

	cout<<"\n\t [ 토핑을 추가하시겠습니까? <Yes 1, No 2> ] ";
	cin>>check_toping;

	if(check_toping ==1)
	{
		while(1)
		{

			system("cls");
			cout<<"\n\t 영제's 맥도리아 \n\n";
			cout<<"\t┌────────────────────┐\n";
			cout<<"\t│  토핑 메뉴                             │\n";
			cout<<"\t│                                        │\n";
			cout<<"\t│  1. 토마토                             │\n";
			cout<<"\t│  2. 베이컨                             │\n";
			cout<<"\t│  3. 치즈                               │\n";
			cout<<"\t│  4. 양상추                             │\n";
			cout<<"\t│  5. 종 료                              │\n";
			cout<<"\t└────────────────────┘\n";

			if(num ==5 )
			{
				cout<<"\n\t 더 이상의 토핑추가는 불가합니다 \n";
				break;
			}

			cout<<"\t < 추가할 토핑 입력 > : ";
			cin>>select_toping;

			if(select_toping==5)
			{
				break;
			}

			cout<<"\n\t [ 토핑이 추가되었습니다 ] \n";
			toping[num]=select_toping;
			num++;

		}


	}
	else if(check_toping == 2)
	{
		cout<<"\n\t 아무런 토핑이 추가되지 않앗습니다. \n";
	}

	for(int i=num ; i<5 ; i++)
	{
		toping[i]=NULL;
	}

	make_order(burger_type,count,toping);
	system("pause");
}

void HamburgerShop::make_order(int burger_type, int burger_count, int topiing[])
{
	while(1)
	{
		if(burger_type == 1)
		{
			current_order.set_burger_name("불고기 버거");
			break;
		}
		else if(burger_type == 2)
		{
			current_order.set_burger_name("치킨 버거");
			break;
		}
		else if(burger_type == 3)
		{
			current_order.set_burger_name("치즈 버거");
			break;
		}
		else if(burger_type ==4)
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

	current_order.set_user(current_user);
	current_order.set_burger_type(burger_type);
	current_order.set_burger_count(burger_count);
	current_order.set_topping(topiing);
	current_order.set_age(0);
	priority_sortedlist();

}

void HamburgerShop::priority_sortedlist()
{
	list<Order>::iterator it;
	list<Order>::iterator temp=order_list.end();
	if(current_order.get_burger_count() >=20)
	{
		order_list.push_back(current_order);
		return ;
	}

	for(it = order_list.begin() ; it != order_list.end(); it++)
	{
		if(/*it->get_burger_count() >=20 && */it->get_age() >=5)
		{
			temp=it;
		}
	}

	if(temp != order_list.end()) // age가 5이고 햄버거 주문개수가 20개 이상 남았을때
	{
		if(current_order.get_user()->get_grade().compare("Guest") == 0) //게스트 등급일대
		{
			order_list.push_back(current_order);
		}
		else // vip 등급일때
		{
			while(temp != order_list.end())
			{
				temp++;
				if(temp != order_list.end())
				{
					if(temp->get_user()->get_grade().compare("Vip")==0)
					{
						continue;
					}
					else if(temp->get_user()->get_grade().compare("Guest")==0)
					{
						order_list.insert(temp,current_order);
					}
				}
				else
				{
					order_list.push_back(current_order);
					break;
				}
			}

		}
	}

	if(current_order.get_user()->get_grade().compare("Vip")==0) //age==5가 존재하지않을때
	{
		for( it=order_list.begin() ; it!=order_list.end() ; it++)
		{
			if(it->get_user()->get_grade().compare("Guest")==0 || it->get_burger_count() >=20)
			{
				order_list.insert(it,current_order);
				return ;
			}
		}
	}

	else
	{
		for( it=order_list.begin() ; it!=order_list.end() ; it++)
		{
			if(it->get_burger_count() >= 20)
			{
				order_list.insert(it,current_order);
				return ;
			}
		}
	}
	order_list.push_back(current_order);
}

void HamburgerShop::print_order()
{
	list<Order> :: iterator it;

	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│  주문 내역 보기                        │\n";
	cout<<"\t└────────────────────┘\n";

	for(it = order_list.begin() ; it != order_list.end() ; it++)
	{
		cout<<"\n\t ID : "<<
			it->get_user()->get_id();
		cout<<" , 등급 : "<<
			it->get_user()->get_grade();
		cout<<"\n\t 햄버거 이름 : "<<
			it->get_burger_name();
		cout<<"\n\t 햄버거 개수 : "<<
			it->get_burger_count();
		cout<<"\n\t 누적된 마일리지 : "<<
			it->get_user()->get_mileage();
		cout<<"\n\n--------------------------------------------------";
	}

	system("pause");
}

void HamburgerShop::print_hamburger()
{
	list<Order> :: iterator it;

	cout<<"\t┌────────────────────┐\n";
	cout<<"\t│  햄버거 만들기 완료                    │\n";
	cout<<"\t└────────────────────┘\n";

	for(it = make_burger_list.begin() ; it != make_burger_list.end() ; it++)
	{
		cout<<"\n\t ID : "<<
			it->get_user()->get_id();
		cout<<" , 등급 : "<<
			it->get_user()->get_grade();
		cout<<"\n\t 햄버거 이름 : "<<
			it->get_burger_name();
		cout<<"\n\t 햄버거 재료 : "<<
			it->get_description();
		cout<<"\n\t 햄버거 가격 : "<<
			it->get_price();
		cout<<"\n\t 햄버거 개수 : "<<
			it->get_burger_count();
		cout<<"\n\t 누적된 마일리지 : "<<
			it->get_user()->get_mileage();
		cout<<"\n\n--------------------------------------------------";
	}
	system("pause");
}

Order* HamburgerShop::make_hamburger(Order &order)
{

	if(count == employee) 
	{
		count=0;
		return NULL;
	}

	Order* temp = new Order(order);
	if(order.get_burger_count() >= 3 )
	{
		if(employee-count >= 3)
		{
			temp->set_burger_count(order.get_burger_count()-3);
			order.set_burger_count(3);
			count+=3;
		}
		else if(employee-count < 3)
		{
			temp->set_burger_count(order.get_burger_count()-(employee-count));
			order.set_burger_count(employee-count);
			count+=employee-count;
		}

	}
	else //버거의 개수가 0개 또는 1개 또는 2개일때
	{
		if(employee-count>=order.get_burger_count())
		{
			count+=order.get_burger_count();
			temp->set_burger_count(0);
			order.set_burger_count(order.get_burger_count());
		}

		else
		{
			count+= employee-count;
			order.set_burger_count(employee-count);
			temp->set_burger_count(order.get_burger_count()-(employee-count));
		}
	}

	hm = hf.create_hamburger(order.get_burger_type());
	for(int i=0 ; *(order.get_topping()+i) != NULL ; i++)
		hm = hf.add_topping(hm,*order.get_topping());

	order.set_price(hm->get_cost()*order.get_burger_count());
	order.set_description(hm->get_description());

	make_burger_list.push_back(order);

	temp->get_user()->set_mileage(order.get_user()->get_mileage()+order.get_price()*0.2);

	//order.get_user()->set_mileage(order.get_user()->get_mileage()+order.get_price()*0.2);


	return temp;

}

void HamburgerShop::priority_makelist()
{

	make_burger_list.clear();

	list<Order>::iterator it = order_list.begin();

	while(it!=order_list.end()) 
	{
		Order order = *it;
		Order* temp = make_hamburger(order);

		if(temp == NULL)
		{
			break;
		}

		it = order_list.erase(it);
		order_list.insert(it, *temp);
		--it;
		delete temp;

		if(it->get_burger_count() == 0)
		{
			it = order_list.erase(it);
		}
		else
		++it;
	}

	for(it = order_list.begin(); it != order_list.end(); it++)
		it->set_age(it->get_age()+1);
}











