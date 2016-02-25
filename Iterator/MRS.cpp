#include "MRS.h"


CGV::CGV()
{
	current_user=NULL;
}
CGV::~CGV()
{
}

void CGV::login(string _user_id,string _password)
{
	//th.login(_user_id,_password);
	current_user=th.login(_user_id,_password);
}

void CGV::print_start()
{
	bool loop=1;
	int input=0;
	string id,pw;

	while(loop)
	{
		switch(input)
		{
		case 0:
			{
				system("cls");
				vw.print_menu();
				cout<<"\t\t < 메뉴 선택 > : ";
				cin>>input;
				pro.push_back(input);
				break;
			}
		case 1:
			{
				system("cls");
				string _Id;
				string _Pw;
				vw.print_login();
				cout<<"\t\t < 메뉴 선택 > : ";

				cin>>input;
				pro.push_back(input);
				if(input==1) 
				{
					cout<<endl;
					cout<<"\t\t ★관리자 로그인★"<<endl<<endl;

					cout<<"\t\t <아이디를 입력해주세요> : ";
					cin>>_Id;
					cout<<"\t\t <비밀번호를 입력해주세요> : ";
					cin>>_Pw;
					
					login(_Id,_Pw);
					if(current_user != NULL)
					{
				
					if(current_user->get_leader() ==1)
					{
						cout<<endl;
						cout<<"\t\t <관리자 계정 접속 완료> "<<endl;
						system("pause");
					while(input !=5)
					{
						system("cls");
						vw.print_adminMenu();
						cout<<"\t\t < 메뉴 선택 > : ";
						cin>>input;
						if(input == 1)
						{
							system("cls");
							vw.print_addScreen();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1) {
								
								th.addScreen();
							}
							if(input==2)
							{
								pro.pop_back();
								input=pro.back();
								//break;
							}
							system("pause");
						}
						else if(input ==2)
						{
							system("cls");
							vw.print_removeScreen();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1) th.removeScreen();
							else if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}
						else if(input ==3)
						{
							system("cls");
							vw.print_reserveList();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1) th.print_reserve();
							else if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}
						else if(input ==4)
						{
							system("cls");
							vw.print_screenSchedule();
							string a=" ";
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1) th.print_searchSchedule(2,a);
							else if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}
						else if(input==5)
						{
							system("cls");
							input=1;
							system("pause");
							break;
						}
						else
						{
							cout<<"\t\t <잘못된 번호를 입력하셧습니다> "<<endl;
							input=1;
							system("pause");
							
						}

					}
					break;
				}
					
				}
					else
					{
						cout<<"\n\n";
						cout<<"\t\t <해당 계정은 관리자 계정이 아닙니다> "<<endl;
						pro.pop_back();
						input=pro.back();
						system("pause");
						break;
					}
				}

				else if(input==2)
				{
					string title;
					int screen_num;
					cout<<endl;
					cout<<"\t\t ★사용자 로그인★"<<endl;
					cout<<"\t\t <아이디를 입력해주세요> : ";
					cin>>_Id;
					cout<<"\t\t <비밀번호를 입력해주세요> : ";
					cin>>_Pw;
					login(_Id,_Pw);
					if(current_user != NULL)
					{
						
					if(current_user->get_leader() ==0)
					{
						cout<<endl;
						cout<<"\t\t <사용자 계정 접속 완료> "<<endl;
						system("pause");
					while(input != 4)
					{
						system("cls");
						cout<<"\t\t \n";
						cout<<"\t\t "<<current_user->get_userName() << " "<<current_user->get_userAge()<<endl;
						vw.print_pmenu();
						cout<<"\t\t < 메뉴 선택 > : ";
						cin>>input;
						
						if(input ==1)
						{
							system("cls");
							cout<<"\t\t \n";
							cout<<"\t\t "<<current_user->get_userName() << " "<<current_user->get_userAge()<<endl;
							vw.print_reserve();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							th.print_movie();

							cout<<endl<<endl;

							cout<<"\t\t <예약할 영화의 이름을 입력하세요> : ";
							cin>>title;
							//th.print_searchSchedule(1,title);

							if(th.print_searchSchedule(1,title) == false )
							{
								cout<<"\t\t 현재 < " << title << " > 는 상영이 불가능 합니다 "<<endl;
								
								pro.pop_back();
								input=pro.back();
								
							}
							else
							{

							cout<<endl<<endl;

							cout<<"\t\t <영화 예매 시간의 인덱스번호를 입력해 주세요> "<<endl;
							cout<<"\t\t num : ";
							cin>>screen_num;
							
							th.reserveScreen(current_user->get_userId(),screen_num);
							}

							if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}

						else if(input==2)
						{
							system("cls");
							cout<<"\t\t \n";
							cout<<"\t\t "<<current_user->get_userName() << " "<<current_user->get_userAge()<<endl<<endl;
							vw.print_cancelReserve();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1)
							{
								print_userReserve(current_user->get_userId());
								cout<<endl;
								cout<<"\t\t <취소할 영화 번호를 입력하세요 >"<<endl;
								cin>>screen_num;
								th.cancelScreen(current_user->get_userId(),screen_num);
							}
							else if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}

						else if(input==3)
						{
							system("cls");
							cout<<"\t\t \n";
							cout<<"\t\t "<<current_user->get_userName() << " "<<current_user->get_userAge()<<endl;
							vw.print_reserveList();
							cout<<"\t\t < 메뉴 선택 > : ";
							cin>>input;
							pro.push_back(input);
							if(input==1) print_userReserve(current_user->get_userId());
							if(input==2)
							{
								pro.pop_back();
								input=pro.back();
							}
							system("pause");
						}

						else if(input==4)
						{
							system("cls");
							cout<<"\t\t \n";
							cout<<"\t\t "<<current_user->get_userName() << " "<<current_user->get_userAge()<<endl;
							input=1;
							break;
						}

						else
						{
							cout<<"\n\n";
							cout<<"\t\t <잘못된 번호를 입력하셧습니다> "<<endl;
							input=2;
							system("pause");
						}

					}
					break;
				}
					
					}
					else
					{
						system("cls");
						cout<<"\t\t 해당 계정은 관리자 계정이 아닙니다 "<<endl;
						pro.pop_back();
						input=pro.back();
						system("pause");
						break;
					}
				
			}
				else if(input==3)
				{
					system("cls");
					input=0;
					break;
				}
			}
		case 2:
			{
				system("cls");
			vw.print_logout();
			cout<<"\t\t < 메뉴 선택 > : ";
			cin>>input;
			if(input==1)
			{
				system("cls");
				cout<<"\t\t <로그 아웃 되셨습니다> " <<endl;
				input=1;
				break;
			}
				
			else if(input==2)
			{
				system("cls");
				pro.pop_back();
				input=pro.back();
				break;
			}
			system("pause");
			}
		case 3:
			{
			system("cls");
			vw.print_close();
			cout<<"\t\t < 메뉴 선택 > : ";
			cin>>input;
			if(input==2)
			{
				pro.pop_back();
				input=pro.back();
				break;
			}
			cout<<"\t\t <프로그램을 종료합니다> "<<endl;
			return ;
		
			}
		}
	}
}



void CGV::print_userReserve(string user_id)
{
	th.print_userReserve(user_id);
}
