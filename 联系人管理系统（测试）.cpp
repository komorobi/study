#include<iostream>
#include"PersonManager.h"
#include"Friend.h"
#include"Person.h"
#include"Classmate.h"
#include"Colleague.h"
using namespace std;
int main()
{
	PersonManager wm;
	int choice = 0;
	while (true)
	{

		//show menu
		cout << "������" << wm.Get_person_num() << "����ϵ��" << endl;
		wm.Show_Menu();
		std::cout << "���������ѡ��" << endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0://logout
			wm.Exit_system();
			break;

		case 1://add Friends
			wm.AddPerson();
			break;

		case 2://display
			wm.Show_CurrentPerson();
			break;

		case 3://delete
			wm.Delete_Person();
			break;

		case 4://modify
			wm.Modify_person();
			break;
		case 5://search
			wm.Find_person();
			break;

		case 6://sort
			wm.Sort_person();
			break;

		case 7://clean
			wm.Clean_File();
			break;

		case 8:
			wm.Send_Greetings();
			break;

		default:
			std::system("cls");//����
			break;

		}

	}


	std::system("pause");
	return 0;
}