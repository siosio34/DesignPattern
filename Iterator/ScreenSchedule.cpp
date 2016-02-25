#include "ScreenSchedule.h"

void ScreenSchedule::load_screen()
{
	ifstream fis("screen.txt");
	string s_num;
	string s_time;
	int index,s_seat,s_id,m_id,m_age;
	string m_title,m_running,m_actor;
	
	string record;


	while(getline(fis,record))
	{
		stringstream spacing(record);
		spacing>>index>>s_num>>s_time>>s_seat>>s_id;
		ifstream fim("movie.txt");
			string m_record;
			while(getline(fim,m_record))
			{
				stringstream spacing(m_record);
				spacing>>m_id>>m_title>>m_running>>m_age>>m_actor;
				if(s_id==m_id)
				{
					Movie movie(m_id,m_title,m_running,m_age,m_actor);
					MovieScreen m_screen(index,s_num,s_time,s_seat,s_id,movie);
					aryScreen.push_back(m_screen);
				}
			}
		
	}
	fis.close();
}

bool ScreenSchedule::print_searchSchedule(string &m_name)
{
	list<MovieScreen>::iterator it;
	string time_s;
	string time_l;
	int a=0;

	time_s = calculateTime();

	for(it=aryScreen.begin() ; it!=aryScreen.end() ; it++)
	{
		if(it->get_mTitle() == m_name)
		{
			if(it->get_startTime() > time_s)
			{a++;
		cout<<"\t\t "<<it->get_screenId()<<" "<<it->get_screenNum()<<" "<<it->get_startTime()<<" "<<it->get_seatCount()<<" "<<it->get_mTitle()<<" "<<it->get_mRunning()<<" "<<it->get_mAge()<<" "<<it->get_mActor()<<endl;
			}
		}
	}

	if(a == 0)
		return false;
	else
		return true;
}

bool ScreenSchedule::print_searchSchedule()
{
	
	list<MovieScreen>::iterator it;
	for(it=aryScreen.begin() ; it!=aryScreen.end() ; it++)
	{
		cout<<"\t\t "<<it->get_screenId()<<" "<<it->get_mTitle()<<" "<<it->get_mRunning()<<" "<<it->get_mAge()<<" "<<it->get_mActor()<<endl;
	}
	return true;

}

void ScreenSchedule::addScreen(MovieScreen& ms)
{
	//if(checkScreen(ms.get_mTitle())==1)
	aryScreen.push_back(ms);
}

list<MovieScreen>::iterator ScreenSchedule::reserveSchedule(int m_index)
{
	list<MovieScreen>::iterator it;
	for(it=aryScreen.begin() ; it !=aryScreen.end() ; it++)
	{
		if(it->get_screenId()==m_index)
		{
			it->set_seatCount();
			return it;
		}
	}
	return aryScreen.end();
}

list<MovieScreen>::iterator ScreenSchedule::cancleSchedule(int sc_id)
{
	list<MovieScreen>::iterator it;

	for(it=aryScreen.begin() ; it!=aryScreen.end() ; it++)
	{
		if(it->get_screenId() == sc_id)
			it->cancel_count();
			return it;
	}
	return aryScreen.end();
}

void ScreenSchedule::removeScreen(int id)
{
	list<MovieScreen>::iterator it;
	for(it=aryScreen.begin() ; it !=aryScreen.end() ; it++)
	{
		if(it->get_screenId()==id)
		{
			aryScreen.erase(it);
			break;
		}
	}
}


void ScreenSchedule::save_screen()
{
	ofstream inf3;
	inf3.open("screen.txt");

	while(aryScreen.size()!=0)
	{
		MovieScreen s;
		s=aryScreen.front();
		aryScreen.pop_front();
		inf3<<s.get_screenId()<<" "<<s.get_screenNum()<<" "<<s.get_startTime()<<" "<<s.get_seatCount()<<" "<<s.get_movieId();
		if(aryScreen.size() != 0)
			inf3<<endl;
	}

	inf3.close();
}

string ScreenSchedule::calculateTime()
{
	time_t timer;
	timer=time(NULL);
	struct tm t;
	localtime_s(&t,&timer);
	

	string currentTime;
	int buf;
	char target[10];

	buf=t.tm_year + 1900;
	itoa(buf,target,10);
	currentTime.append(target);

	buf=t.tm_mon+1;
	if(buf<10)
	{
		currentTime.push_back('O');
		itoa(buf,target,10);
		currentTime.append(target);

	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	buf=t.tm_mday;
	if(buf<10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	buf=t.tm_hour;
	if(buf<10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	buf=t.tm_min;
	if(buf<10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}
	else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	return currentTime;
}



/*
bool ScreenSchedule::checkScreen(string &m_name)
{
	list <MovieScreen>::iterator it;
	
	for(it=aryScreen.begin(); it!=aryScreen.end() ; it++)
	{
		if(it->get_mTitle()== m_name)
			return true;
	}
	return false;
}
		*/

		




	

	