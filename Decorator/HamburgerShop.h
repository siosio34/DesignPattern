#pragma once
#include "HamburgerFactory.h"
#include "Order.h"
#include <queue>
#include <list>

class HamburgerShop
{
// �ܹ��� �Լ�
//------------------------------------------------------------------------------------------
public:
	HamburgerShop();	// ������
	void priority_sortedlist(); // �켱���� �������ǿ� ���缭 list_order�� ����
	void make_order(int burger_type, int burger_count, int topiing[]);// ������ �����
	void priority_makelist();	// order_list�� �ܹ��Ÿ� ���� make_burger_list�� ����
	Order* make_hamburger(Order& order);// �ܹ��Ÿ� �����

// ��� �Լ�
//------------------------------------------------------------------------------------------
public:
	void print_start();	// ����
	void print_menu();	// �޴� ���
	void print_order();	//	list_order ����� ���� ���
	void print_hamburger();	// �ϼ��� �ܹ��� ���

// ���� �Լ�
//------------------------------------------------------------------------------------------
public:
	void save_user();	// ���� ����
	void load_user();	// ���� �ε�
	User* search_user(int _id);	// �Է¹��� ID�� array_user[10]���� Ž��

// �ܹ��� ��� ����
//------------------------------------------------------------------------------------------
private:
	HamburgerFactory hf;// HamburgerFactory ��ü
	Hamburger* hm;	// ���� �ֹ��� �ܹ���
	Order current_order;		//ť�� �ֹ��� ���� �� ���Ǵ� �ӽ� �ֹ���ü
	list<Order> make_burger_list;	// ���� ���
	list<Order> order_list;	// �� �ֹ� ���
	int employee;	// ������ ��

// ���� ��� ����
//------------------------------------------------------------------------------------------
private:
	User* array_user[10];	// ���� �迭
	User* current_user;	// ���� ���̵�
	int user_count;	// �� ���� ��
	int count; 
};

