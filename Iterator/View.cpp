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
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t��\t �޴� \t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. �α���\t\t��\n";
	cout<<"\t\t��2. �α׾ƿ�\t\t��\n";
	cout<<"\t\t��3. ����\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	//���θ޴�
void View::print_pmenu()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t��\t����� �޴� \t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ��ȭ����\t\t��\n";
	cout<<"\t\t��2. �������\t\t��\n";
	cout<<"\t\t��3. ���Ÿ��\t\t��\n";
	cout<<"\t\t��4. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	//����� ��ȭ���� �޴� 
void View::print_login()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t��\t�α��� �޴� \t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ������ �α���\t��\n";
	cout<<"\t\t��2. ����� �α���\t��\n";
	cout<<"\t\t��3. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";


}	// �α���
void View::print_logout()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. �α׾ƿ��ϱ�\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// �α׾ƿ�
void View::print_close()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. �����ϱ�\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	//���α׷� ����
void View::print_reserve()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ���� �ϱ�\t\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}// ��ȭ����
void View::print_cancelReserve()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ���� ���\t\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// ���� ���
void View::print_adminMenu()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t��\t������ �޴� \t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ��ũ�� �߰�\t��\n";
	cout<<"\t\t��2. ��ũ�� ����\t��\n";
	cout<<"\t\t��3. ������Ȳ ����\t��\n";
	cout<<"\t\t��4. ��ũ����Ȳ ����\t��\n";
	cout<<"\t\t��5. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// ������ �޴�
void View::print_addScreen()
{
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ��ũ�� �߰��ϱ�\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}// ��ũ�� �߰�
void View::print_removeScreen()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ��ũ�� �����ϱ�\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// ��ũ�� ����
void View::print_reserveList()
{
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ���� ��Ȳ����\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// ������Ȳ���� 
void View::print_screenSchedule()
{
	cout<<"\t\t\n\n\n\n";
	cout<<"\t\t��������������������������\n";
    cout<<"\t\t���޴� \t\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��1. ��ũ�� ��Ȳ����\t��\n";
	cout<<"\t\t��2. �ڷΰ���\t\t��\n";
	cout<<"\t\t��\t\t\t��\n";
	cout<<"\t\t��������������������������\n";
}	// ��ũ����Ȳ����

