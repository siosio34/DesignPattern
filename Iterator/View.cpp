#include "View.h"

View::View()
{
}
View::~View()
{
}

void View::print_menu()
{

	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│\t 메뉴 \t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 로그인\t\t│\n";
	cout<<"\t\t│2. 로그아웃\t\t│\n";
	cout<<"\t\t│3. 종료\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	//메인메뉴
void View::print_pmenu()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│\t사용자 메뉴 \t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 영화예매\t\t│\n";
	cout<<"\t\t│2. 예매취소\t\t│\n";
	cout<<"\t\t│3. 예매목록\t\t│\n";
	cout<<"\t\t│4. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	//사용자 영화예매 메뉴 
void View::print_login()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│\t로그인 메뉴 \t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 관리자 로그인\t│\n";
	cout<<"\t\t│2. 사용자 로그인\t│\n";
	cout<<"\t\t│3. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";


}	// 로그인
void View::print_logout()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 로그아웃하기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 로그아웃
void View::print_close()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 종료하기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	//프로그램 종료
void View::print_reserve()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 예매 하기\t\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}// 영화예약
void View::print_cancelReserve()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 예매 취소\t\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 예매 취소
void View::print_adminMenu()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│\t관리자 메뉴 \t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 스크린 추가\t│\n";
	cout<<"\t\t│2. 스크린 삭제\t│\n";
	cout<<"\t\t│3. 예매현황 보기\t│\n";
	cout<<"\t\t│4. 스크린현황 보기\t│\n";
	cout<<"\t\t│5. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 관리자 메뉴
void View::print_addScreen()
{
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 스크린 추가하기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}// 스크린 추가
void View::print_removeScreen()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 스크린 제거하기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 스크린 제거
void View::print_reserveList()
{
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 예매 현황보기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 예매현황보기 
void View::print_screenSchedule()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t┌───────────┐\n";
    cout<<"\t\t│메뉴 \t\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t│1. 스크린 현황보기\t│\n";
	cout<<"\t\t│2. 뒤로가기\t\t│\n";
	cout<<"\t\t│\t\t\t│\n";
	cout<<"\t\t└───────────┘\n";
}	// 스크린현황보기

