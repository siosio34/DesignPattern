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
	cout<<"\n\t ����'s �Ƶ����� \n\n";

	cout<<"\t��������������������������������������������\n";
	cout<<"\t��  ���� �������� ���� �Է��ϼ���       ��\n";
	cout<<"\t��������������������������������������������\n";

	cout<<"\n\t menuNum : ";
	cin>>employee;

	while(1)
	{
		system("cls");

		cout<<"\n\t ����'s �Ƶ����� \n\n";
		cout<<"\t��������������������������������������������\n";
		cout<<"\t��  �޴�                                  ��\n";
		cout<<"\t��                                        ��\n";
		cout<<"\t��  1. �ܹ��� �ֹ�                        ��\n";
		cout<<"\t��  2. �ֹ� ����                          ��\n";
		cout<<"\t��  3. �ܹ��� �����                      ��\n";
		cout<<"\t��  4. �� ��                              ��\n";
		cout<<"\t��������������������������������������������\n";

		cout<<"\n\t �޴� ���� : ";
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
			cout<<"\n\t �߸��� �Է��Դϴ� \n";
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
	cout<<"\n\t ����'s �Ƶ����� \n\n";
	cout<<"\t��������������������������������������������\n";
	cout<<"\t�� �ܹ��� �޴�                            ��\n";
	cout<<"\t��                                        ��\n";
	cout<<"\t��  1. �Ұ�� ����                        ��\n";
	cout<<"\t��  2. ġŲ ����                          ��\n";
	cout<<"\t��  3. ġ�� ����                          ��\n";
	cout<<"\t��  4. �� ��                              ��\n";
	cout<<"\t��������������������������������������������\n";

	cout<<"\n\t [ ���̵� �Է� ] : ";
	cin>>u_id;

	current_user =search_user(u_id);

	cout<<"\n\t [ �ܹ��� ���� ���� ] : ";
	cin>>burger_type;

	cout<<"\n\t [ �ܹ��� ���� �Է� ] : ";
	cin>>count;

	cout<<"\n\t [ ��� ������ ���ϸ��� ] : ";
	cout<<current_user->get_mileage()<<endl;

	cout<<"\n\t [ ������ �߰��Ͻðڽ��ϱ�? <Yes 1, No 2> ] ";
	cin>>check_toping;

	if(check_toping ==1)
	{
		while(1)
		{

			system("cls");
			cout<<"\n\t ����'s �Ƶ����� \n\n";
			cout<<"\t��������������������������������������������\n";
			cout<<"\t��  ���� �޴�                             ��\n";
			cout<<"\t��                                        ��\n";
			cout<<"\t��  1. �丶��                             ��\n";
			cout<<"\t��  2. ������                             ��\n";
			cout<<"\t��  3. ġ��                               ��\n";
			cout<<"\t��  4. �����                             ��\n";
			cout<<"\t��  5. �� ��                              ��\n";
			cout<<"\t��������������������������������������������\n";

			if(num ==5 )
			{
				cout<<"\n\t �� �̻��� �����߰��� �Ұ��մϴ� \n";
				break;
			}

			cout<<"\t < �߰��� ���� �Է� > : ";
			cin>>select_toping;

			if(select_toping==5)
			{
				break;
			}

			cout<<"\n\t [ ������ �߰��Ǿ����ϴ� ] \n";
			toping[num]=select_toping;
			num++;

		}


	}
	else if(check_toping == 2)
	{
		cout<<"\n\t �ƹ��� ������ �߰����� �ʾѽ��ϴ�. \n";
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
			current_order.set_burger_name("�Ұ�� ����");
			break;
		}
		else if(burger_type == 2)
		{
			current_order.set_burger_name("ġŲ ����");
			break;
		}
		else if(burger_type == 3)
		{
			current_order.set_burger_name("ġ�� ����");
			break;
		}
		else if(burger_type ==4)
		{
			return ;
		}
		else
		{
			cout<<"\n\t �߸��� �Է��Դϴ� \n";
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

	if(temp != order_list.end()) // age�� 5�̰� �ܹ��� �ֹ������� 20�� �̻� ��������
	{
		if(current_order.get_user()->get_grade().compare("Guest") == 0) //�Խ�Ʈ ����ϴ�
		{
			order_list.push_back(current_order);
		}
		else // vip ����϶�
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

	if(current_order.get_user()->get_grade().compare("Vip")==0) //age==5�� ��������������
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

	cout<<"\t��������������������������������������������\n";
	cout<<"\t��  �ֹ� ���� ����                        ��\n";
	cout<<"\t��������������������������������������������\n";

	for(it = order_list.begin() ; it != order_list.end() ; it++)
	{
		cout<<"\n\t ID : "<<
			it->get_user()->get_id();
		cout<<" , ��� : "<<
			it->get_user()->get_grade();
		cout<<"\n\t �ܹ��� �̸� : "<<
			it->get_burger_name();
		cout<<"\n\t �ܹ��� ���� : "<<
			it->get_burger_count();
		cout<<"\n\t ������ ���ϸ��� : "<<
			it->get_user()->get_mileage();
		cout<<"\n\n--------------------------------------------------";
	}

	system("pause");
}

void HamburgerShop::print_hamburger()
{
	list<Order> :: iterator it;

	cout<<"\t��������������������������������������������\n";
	cout<<"\t��  �ܹ��� ����� �Ϸ�                    ��\n";
	cout<<"\t��������������������������������������������\n";

	for(it = make_burger_list.begin() ; it != make_burger_list.end() ; it++)
	{
		cout<<"\n\t ID : "<<
			it->get_user()->get_id();
		cout<<" , ��� : "<<
			it->get_user()->get_grade();
		cout<<"\n\t �ܹ��� �̸� : "<<
			it->get_burger_name();
		cout<<"\n\t �ܹ��� ��� : "<<
			it->get_description();
		cout<<"\n\t �ܹ��� ���� : "<<
			it->get_price();
		cout<<"\n\t �ܹ��� ���� : "<<
			it->get_burger_count();
		cout<<"\n\t ������ ���ϸ��� : "<<
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
	else //������ ������ 0�� �Ǵ� 1�� �Ǵ� 2���϶�
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











