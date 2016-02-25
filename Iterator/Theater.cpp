#include "Theater.h"

void Theater::load_user()
{
	user_count=0;
	string _id,_password,_name;
	int _age;

	ifstream fin("user.txt");
	string record;

	while(getline(fin,record))
	{
		User *user = new User;
		stringstream spacing(record);
		spacing >> _id >> _password >> _name >> _age;
		user->set_userId(_id);
		user->set_userPw(_password);
		user->set_userName(_name);
		user->set_userAge(_age);
		userAry[user_count]=user;
		user_count++;
	}
}

void Theater::load_movie()
{
	int m_id,m_age;
	string m_title,m_running,m_actor;

	ifstream fin("movie.txt");
	string record;
	while(getline(fin,record))
	{
		stringstream spacing(record);
		spacing>>m_id>>m_title>>m_running>>m_age>>m_actor;
		Movie movie(m_id,m_title,m_running,m_age,m_actor);
		movieAry.push_back(movie);
	}
}
void Theater::load_reserve()
{
	int count;
	string sc_Num;
	string u_id;
	string mv_Title;
	string run_time;

	ifstream fin("reserve.txt");
	string record;
	while(getline(fin,record))
	{
		stringstream spacing(record);
		spacing>>u_id>>sc_Num>>mv_Title>>run_time>>count;
		MReserve mreserve;
		mreserve.screenNum=sc_Num;
		mreserve.user_id=u_id;
		mreserve.movieTitle=mv_Title;
		mreserve.GoTime=run_time;
		mreserve.reserve_count=count;
		reserveAry.push_back(mreserve);
		reserveCount++;
	}

}

void Theater::save_movie()//영화저장
{
	ofstream inf3;
	inf3.open("movie.txt");

	while(movieAry.size()!=0)
	{
		Movie m;
		m=movieAry.front();
		movieAry.pop_front();
		inf3<<m.get_movieId()<<" "<<m.get_movieTitle()<<" "<<m.get_runningTime()<<" "<<m.get_ageRequire()<<" "<<m.get_mainActor();
		if(movieAry.size() != 0)
			inf3<<endl;
	}

	inf3.close();
}

void Theater::save_reserve()//예약저장
{
	ofstream inf3;
	inf3.open("reserve.txt");

	while(reserveAry.size()!=0)
	{
		MReserve r;
		r=reserveAry.front();
		reserveAry.pop_front();
		inf3<<r.user_id<<" "<<r.screenNum<<" "<<r.movieTitle<<" "<<r.GoTime<<" "<<r.reserve_count;
		if(reserveAry.size() != 0)
			inf3<<endl;
	}

	inf3.close();
}

User* Theater::login(string _user_id,string _pass_word)
{
	for(int i= 0 ;i<user_count ; i++)
	{
		if(userAry[i]->get_userId() ==_user_id && userAry[i]->get_userPw() == _pass_word)
		{
			size_t pos=userAry[i]->get_userName().find("영제");
			if(pos != std::string::npos)
			{
				userAry[i]->set_userleader(1);
				return userAry[i];
			}
			else
			{
				userAry[i]->set_userleader(0);
				return userAry[i];
			}
		}
	}
			
			return NULL;
}

void Theater::reserveScreen(string user_id,int movie_num)
{
	User *u;
	for(int i=0 ; i<user_count; i++)
	{
		if(userAry[i]->get_userId()==user_id)
		{
			u=userAry[i];
		}
	}
	movieScreen =sc.reserveSchedule(movie_num);
	MovieScreen M_S = *movieScreen;

	if(M_S.get_mAge() <= u->get_userAge())
	{
	cout<<"\t\t "<<M_S.get_screenId()<<" "<<M_S.get_screenNum()<<" "<<M_S.get_seatCount()<<" "<<M_S.get_mTitle()<<" "<<M_S.get_mRunning()<<" "<<M_S.get_mAge()<<" "<<M_S.get_mActor()<<endl;
	cout<<"\t\t 예 매 완 료 "<<endl;
	MReserve m_reserve;
	m_reserve.reserve_count=get_reserveCount();
	m_reserve.user_id=user_id;
	
	m_reserve.screenNum=M_S.get_screenNum();
	m_reserve.movieTitle=M_S.get_mTitle();
	m_reserve.GoTime=M_S.get_startTime();
	
	reserveAry.push_back(m_reserve);
	}
	else
	{
		movieScreen->cancel_count();
		cout<<"\t\t 해당 회원은 관람이 불가능한 영화입니다 \n ";
	}
	cout<<endl;
	
}
void Theater::cancelScreen(string user_id,int reserve_count)
{
	list<MReserve>::iterator it;
	
	for(it=reserveAry.begin();it!=reserveAry.end();it++)
	{
		if(it->user_id == user_id && it->reserve_count==reserve_count)
		{
				reserveAry.erase(it);
				break;
		}
	}
}
void Theater::addScreen()
{
	int m_age;
	int check_num=0;
	int mv_id;
	string m_title;
	string m_runningTime;
	string m_Actor;

	cout<<"\t\t 추가할 스크린의 정보를 입력해 주세요 "<<endl;
	
	cout<<"\t\t 영화 이름 : "; cin>>m_title;
	list <Movie>:: iterator it; 
	for(it=movieAry.begin() ; it != movieAry.end(); it++)
	{
		if(it->get_movieTitle()  != m_title)
		{
			
			mv_id=movieAry.size()+1;
		}
		else
		{
			mv_id=it->get_movieId();
			break;
		}
	}
	
		
	

	cout<<"\t\t 상영 시간 : "; cin>>m_runningTime;
	cout<<"\t\t 관람 가능 나이 : "; cin>>m_age;
	cout<<"\t\t 주 연 : "; cin>>m_Actor;
	Movie movie(mv_id,m_title,m_runningTime,m_age,m_Actor);
	movieAry.push_back(movie);

	cout<<endl<<endl;

	cout<<"\t\t 상영관의 정보를 입력해주세요 "<<endl;
	string sc_num;
	string GoTime;
	int seat_Count;
	int screenId;
	
	screenId= sc.get_back() +1 ;
	cout<<"\t\t 상영관 : "; cin>>sc_num;
	cout<<"\t\t 시작시간 : "; cin>>GoTime;
	cout<<"\t\t 좌석 갯수 : "; cin>>seat_Count;
	

	MovieScreen moviescreen(screenId,sc_num,GoTime,seat_Count,mv_id,movie);
	sc.addScreen(moviescreen);
}

void Theater::removeScreen()
{
	int sc_id;
	sc.print_searchSchedule();
	cout<<"\t\t 삭제하고 싶은 스크린 ID를 입력하세요 : "; cin>>sc_id;
	sc.removeScreen(sc_id);
}
bool Theater::print_searchSchedule(int type,string &m_name)
{
	if(type == 1)
		{if(sc.print_searchSchedule(m_name)==true)
			return true;
		else
			return false;
	}

	else if(type == 2){
		if(sc.print_searchSchedule()==true)
			return true;
		else
			return false;
	}
}
void Theater::print_movie()
{
	list<Movie>::iterator it;
	for(it = movieAry.begin() ; it != movieAry.end() ; it++)
	{
		cout<<"\t\t "<<it->get_movieId()<<" "<<it->get_movieTitle()<<" "<<it->get_runningTime()<<" "<<it->get_mainActor()<<endl;
	}
}
void Theater::print_reserve()
{
	list<MReserve>::iterator it;
	for(it= reserveAry.begin() ; it != reserveAry.end() ; it++)
	{
		cout<<"\t\t "<<it->reserve_count<<" "<<it->screenNum<<" "<<it->user_id <<" "<<" "<<it->movieTitle<<" "<<it->GoTime<<endl;
	}

}
void Theater::print_userReserve(string user_id)
{
	int a=0;
	list <MReserve>::iterator it;
	for(it=reserveAry.begin(); it != reserveAry.end() ; it++)
	{
		if(it->user_id.compare(user_id)==0)
		{
			a++;
			cout<<"\t\t "<<it->reserve_count <<" "<<it->user_id<<" "<<it->screenNum<<" "<<it->GoTime<<" "<<it->movieTitle<<endl;
		}

	}
	
}



	




