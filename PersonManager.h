#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include"Person.h"
#include"Friend.h"
#include"Classmate.h"
#include"Colleague.h"
#include"Relative.h"

constexpr auto ClassmateFile = "Book1.txt",
ColleagueFile = "Book2.txt",
FriendFile = "Book3.txt",
RelativeFile = "Book4.txt";

class PersonManager
{


public:
	//std::fstream fs1, fs2, fs3, fs4;
	PersonManager();

	~PersonManager();

	void Show_Menu();

	void Exit_system();

	//Friend number
	int m_PersonNum;

	//Friend array
	Person** m_PersonArray;
	bool m_FileIsEmpty;
	void AddPerson();

	//SaveInformation data to file
	void SaveInformation();
	//count number
	int Get_person_num();

	//initialize the number 
	void Initial_Person();

	void Show_CurrentPerson();

	void Delete_Person();
	//Friend is exsist,return number
	void Send_Greetings();
	void sort_person_bymonth();
	void Modify_person();

	void Find_person();

	void Sort_person();

	void Clean_File();

	bool Dateiscorrect(int year, int month, int day);
};
