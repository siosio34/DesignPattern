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
	void load_screen();	// 파일로드
	void save_screen();  //스크린저장
	bool print_searchSchedule(string& m_name); // 영화이름으로 스케쥴 검색
	bool print_searchSchedule();	// aryScreen 출력
	void addScreen(MovieScreen& ms);	// 스크린 추가
	list<MovieScreen>::iterator reserveSchedule(int m_index);// 영화 예약
	list<MovieScreen>::iterator cancleSchedule(int mv_id);
	void removeScreen(int id);// 스크린 삭제
	int get_back(){return aryScreen.back().get_screenId();};
	//bool checkScreen(string &m_name);
	
	string calculateTime();//시간 구하기

private:
	string currentTime; // 현재시간
	list<MovieScreen> aryScreen;	// 스크린 저장
};

