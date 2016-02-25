#include "Movie.h"

Movie::Movie()
{
	movieId=0;
	movieTitle="";
	runningTime="";
	ageRequire=0;
	mainActor="";
}

Movie::Movie(int id, string title, string time, int age, string actor)
{
	movieId=id;
	movieTitle=title;
	runningTime=time;
	ageRequire=age;
	mainActor=actor;
}
Movie::~Movie()
{
}

