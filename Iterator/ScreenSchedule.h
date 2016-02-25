#pragma once
#include "MovieScreen.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <string>

class ScreenSchedule
{
public:
	ScreenSchedule(void){load_screen();};
	~ScreenSchedule(void){save_screen();};

public:
	void load_screen();	// ���Ϸε�
	void save_screen();  //��ũ������
	bool print_searchSchedule(string& m_name); // ��ȭ�̸����� ������ �˻�
	bool print_searchSchedule();	// aryScreen ���
	void addScreen(MovieScreen& ms);	// ��ũ�� �߰�
	list<MovieScreen>::iterator reserveSchedule(int m_index);// ��ȭ ����
	list<MovieScreen>::iterator cancleSchedule(int mv_id);
	void removeScreen(int id);// ��ũ�� ����
	int get_back(){return aryScreen.back().get_screenId();};
	//bool checkScreen(string &m_name);
	
	string calculateTime();//�ð� ���ϱ�

private:
	string currentTime; // ����ð�
	list<MovieScreen> aryScreen;	// ��ũ�� ����
};

