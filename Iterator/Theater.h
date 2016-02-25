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
	 save_movie();	// 영화 저장
	 save_reserve();
	 //save_screen();
	};

public:
	void load_user();	// 사용자 로드
	void load_movie();	// 영화 로드
	void load_reserve();// 예매목록 로드
	//void load_screen();
	//void save_screen();	
	void save_movie();	// 영화 저장
	void save_reserve();	// 예약 저장

public:
	User* login(string _user_id, string _pass_word);	// 로그인
	void reserveScreen(string user_id, int movie_num);	// 영화예약
	void cancelScreen(string user_id, int movie_num);	// 예약취소
	void addScreen();	// 스크린 추가
	void removeScreen();
	int get_reserveCount(){return ++reserveCount;};
	//int get_reserveCount2(){return 	reserveCount;};// 스크린 삭제
	
public:
	bool print_searchSchedule(int type, string& m_name);	// 스크린 출력
	void print_movie();	// 영화 출력
	void print_reserve();	// 예약목록 전체출력
	void print_userReserve(string user_id);	// 로그인 사용자 예약목록 출력
	

private:
	ScreenSchedule sc;
	list<MovieScreen>::iterator movieScreen;  // 예매할 영화
	int user_count;	// 회원 명수
	User* userAry[10];	// 사용자 저장
	list<MReserve> reserveAry;	// 영화예약목록
	list<Movie> movieAry;	// 영화 저장
	int reserveCount;
	
	
};

