#include "MovieScreen.h"

MovieScreen::MovieScreen()
{
	int screenId=0;	// 스크린 아이디
	string screenNum="";	// 상영관 번호
	string startTime="";	// 시작시간
	int seatCount=0;	// 좌석 개수
	int movieId=0;  //영화 ID
}

MovieScreen::MovieScreen(int id, string num, string time, int count, int m_id, Movie& m_movie)
{
	screenId=id;
	screenNum=num;
	startTime=time;
	seatCount=count;
	movieId=m_id;
	movie=m_movie;
}