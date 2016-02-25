#include "StarCraft.h"
#include <Windows.h>

int main()
{
	system("mode con:cols=100 lines=80");
	StarCraft st;
	st.printStart();
	
	return 0;
}