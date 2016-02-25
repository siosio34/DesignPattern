#include "MovieScreen.h"

MovieScreen::MovieScreen()
{
	int screenId=0;	// ��ũ�� ���̵�
	string screenNum="";	// �󿵰� ��ȣ
	string startTime="";	// ���۽ð�
	int seatCount=0;	// �¼� ����
	int movieId=0;  //��ȭ ID
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