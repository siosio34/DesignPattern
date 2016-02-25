#pragma once

#include "ScreenSchedule.h"
#include "User.h"


struct MReserve
{
	string user_id;
	string screenNum;
	string movieTitle;
	string GoTime;
	int reserve_count;
};

class Theater
{
public:
	Theater(void)
	{
		reserveCount=0;
		load_user();
		load_movie();
		load_reserve();
		//load_screen();
		
	};
	~Theater(void)
	{	
	 save_movie();	// ��ȭ ����
	 save_reserve();
	 //save_screen();
	};

public:
	void load_user();	// ����� �ε�
	void load_movie();	// ��ȭ �ε�
	void load_reserve();// ���Ÿ�� �ε�
	//void load_screen();
	//void save_screen();	
	void save_movie();	// ��ȭ ����
	void save_reserve();	// ���� ����

public:
	User* login(string _user_id, string _pass_word);	// �α���
	void reserveScreen(string user_id, int movie_num);	// ��ȭ����
	void cancelScreen(string user_id, int movie_num);	// �������
	void addScreen();	// ��ũ�� �߰�
	void removeScreen();
	int get_reserveCount(){return ++reserveCount;};
	//int get_reserveCount2(){return 	reserveCount;};// ��ũ�� ����
	
public:
	bool print_searchSchedule(int type, string& m_name);	// ��ũ�� ���
	void print_movie();	// ��ȭ ���
	void print_reserve();	// ������ ��ü���
	void print_userReserve(string user_id);	// �α��� ����� ������ ���
	

private:
	ScreenSchedule sc;
	list<MovieScreen>::iterator movieScreen;  // ������ ��ȭ
	int user_count;	// ȸ�� ���
	User* userAry[10];	// ����� ����
	list<MReserve> reserveAry;	// ��ȭ������
	list<Movie> movieAry;	// ��ȭ ����
	int reserveCount;
	
	
};

