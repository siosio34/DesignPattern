#pragma once
#include "User.h"
#include <fstream>
#include <sstream>

// �ܹ��� ����, ����, ����, �ð�, �����ID

class Order
{
public:
	Order();
	Order(User* _user, string _burgur_name, int _burger_count, int _price, string _message);

public:
	User* get_user();	// ���������� ����
	string get_burger_name();	// �ܹ��� �̸� ����
	int get_burger_count();		// �ܹ��� ���� ����
	int get_price();	// �ܹ��� ���� ����
	string get_message();	// �ܹ��� ��� �޼��� ����
	void set_user(User* _user);	// ���������� �Է�
	void set_burger_name(string _name);	// �ܹ��� �̸� �Է�
	void set_burger_count(int _count);	// �ֹ��� �ܹ��� ���� �Է�
	void set_price(int _price);	// �ֹ� ���� �Է�
	void set_message(string _message);	//	�ܹ��� ��� �޼��� �Է�
	int get_age();	// �ܹ��� ���� Ƚ�� ����
	void set_age(int _age);	// �ܹ��� ���� Ƚ�� �Է�
	void set_description(string _description);	// �ܹ��� ���
	string get_description();	// �ܹ��� ���
	int* get_topping();	//���� �Է�
	void set_topping(int ary[]);	//���� ����
	int get_burger_type();	//����Ÿ�� ����
	void set_burger_type(int _type);	// ����Ÿ�� �Է�

private:
	User* user;	// ����������
	string burgur_name;	// �ܹ��� �̸�
	string description;	// �ܹ��� ���
	int burger_count;	// �ֹ��� �ܹ��� ����
	int price;	// �ܹ��� ����
	int age;	// �ܹ��� ���� Ƚ��
	string message;	// �ܹ��� �޼���
	int topiing[5];	// ����
	int burger_type;	// ����Ÿ��
};

