#pragma once

#include <iostream>
#include <string>
#include <list>
using namespace std;

class User
{
public:
	User(void){bool leader=0;};
	~User(void){};
	User(string _id, string _pw, string _name, int _age){};

public:
	string get_userId(){return id;}	// ID ����
	string get_userPw(){return password;}	// ��й�ȣ ����
	string get_userName(){return name;}	// �̸� ����
	int get_userAge(){return age;}
	int get_leader(){return leader;};	// ���� ����

	void set_userId(string _id){id=_id;};	// ID �Է�
	void set_userPw(string _password){password=_password;};	// PW �Է�
	void set_userName(string _name){name=_name;};	// �̸� �Է�
	void set_userAge(int _age){age = _age;};	//���� �Է�
	void set_userleader(int _leader){leader=_leader;};

private:
	int leader; // ������ Ȯ�ο���
	string id;	// ���̵�
	string password;	// ��й�ȣ
	string name;	// �̸�
	int age;	// ����

};

