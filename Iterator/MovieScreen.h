#pragma once

#include "Movie.h"
#include <list>

class MovieScreen
{
public:
	MovieScreen(void);
	MovieScreen(int id, string num, string time, int count, int m_id, Movie& m_movie);
	~MovieScreen(void){};

public:	// MovieScreenŬ���� �������
	void set_screenId(int id){screenId = id;}	// ��ũ��ID �Է�
	int get_screenId(){return screenId;}	// ��ũ��ID ����
	string get_screenNum(){return screenNum;}	// �󿵰���ȣ ����
	string get_startTime(){return startTime;}	// ���۽ð� ����
	int get_seatCount(){return seatCount;}	//	�����¼��� ����
	int get_movieId(){return movieId;}	// ��ȭ ���̵� ����
	void set_seatCount(){seatCount--;}	// �¼��� �Է�
	void cancel_count(){seatCount++;}  //�¼��� ����

public:	// MovieŬ���� �������
	int get_mId(){return movie.get_movieId();}	// ��ȭ ���̵� 
	string get_mTitle(){return movie.get_movieTitle();}	//	��ȭ���� ����
	string get_mRunning(){return movie.get_runningTime();}	// ��ȭ�󿵽ð� ����
	int get_mAge(){return movie.get_ageRequire();}	// �������� ����
	string get_mActor(){return movie.get_mainActor();}	// �ֿ� ����
	
private:
	Movie movie;
	int screenId;	// ��ũ�� ���̵�
	string screenNum;	// �󿵰� ��ȣ
	string startTime;	// ���۽ð�
	int seatCount;	// �¼� ����
	int movieId;	// ��ȭ ���̵�
};

