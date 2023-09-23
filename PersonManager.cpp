#include"PersonManager.h"
#include<iostream>
#include<ctime>
using namespace std;

PersonManager::PersonManager()
{

	int num = Get_person_num();
	if (num == 0) {
		m_FileIsEmpty = true;
	}
	m_PersonNum = num;
	m_PersonArray = new Person * [num];
	this->Initial_Person();
}
//��ʼ��
//void PersonManager::Initial_Person() {
//	std::ifstream fs1(ClassmateFile);
//	std::ifstream fs2(ColleagueFile);
//	std::ifstream fs3(FriendFile);
//	std::ifstream fs4(RelativeFile);
//
//	if (!fs1 || !fs2 || !fs3 || !fs4) {
//		std::cout << "���ļ�ʧ��" << std::endl;
//		return;
//	}
//
//	std::string name, unknow, email;
//	int birthday;
//	long int telephone;
//	int index = 0;
//
//	while (fs1 >> name >> unknow >> birthday >> telephone >> email) {
//		Person* person = new Classmate(name, unknow, birthday, telephone, email);
//		m_PersonArray[index++] = person;
//	}
//
//	while (fs2 >> name >> unknow >> birthday >> telephone >> email) {
//		Person* person = new Colleague(name, unknow, birthday, telephone, email);
//		m_PersonArray[index++] = person;
//	}
//
//	while (fs3 >> name >> unknow >> birthday >> telephone >> email) {
//		Person* person = new Friend(name, unknow, birthday, telephone, email);
//		m_PersonArray[index++] = person;
//	}
//
//	while (fs4 >> name >> unknow >> birthday >> telephone >> email) {
//		Person* person = new Relative(name, unknow, birthday, telephone, email);
//		m_PersonArray[index++] = person;
//	}
//
//	m_PersonNum = index;
//
//	fs1.close();
//	fs2.close();
//	fs3.close();
//	fs4.close();
//}
void PersonManager::Initial_Person() {
	std::ifstream fs1(ClassmateFile);
	std::ifstream fs2(ColleagueFile);
	std::ifstream fs3(FriendFile);
	std::ifstream fs4(RelativeFile);

	if (!fs1 || !fs2 || !fs3 || !fs4) {
		std::cout << "�ļ�Ϊ��" << std::endl;
		return;
	}

	std::string name, unknow, email;
	int birthday;
	long int telephone;
	int index = 0;

	while (fs1 >> name >> unknow >> birthday >> telephone >> email) {
		Person* person = new Classmate(name, unknow, birthday, telephone, email);
		m_PersonArray[index++] = person;
	}

	while (fs2 >> name >> unknow >> birthday >> telephone >> email) {
		Person* person = new Colleague(name, unknow, birthday, telephone, email);
		m_PersonArray[index++] = person;
	}

	while (fs3 >> name >> unknow >> birthday >> telephone >> email) {
		Person* person = new Friend(name, unknow, birthday, telephone, email);
		m_PersonArray[index++] = person;
	}

	while (fs4 >> name >> unknow >> birthday >> telephone >> email) {
		Person* person = new Relative(name, unknow, birthday, telephone, email);
		m_PersonArray[index++] = person;
	}

	m_PersonNum = index;

	fs1.close();
	fs2.close();
	fs3.close();
	fs4.close();
}

//1.name
//2.unknow
//3.birthday
//4.telephone
//5.email

PersonManager::~PersonManager()
{
	if (m_PersonArray != NULL) {
		for (int i = 0;i < m_PersonNum;i++) {
			delete m_PersonArray[i];
		}
		delete[]m_PersonArray;
		m_PersonArray = NULL;
	}
}

void PersonManager::Show_Menu()
{
	std::cout << "***** ��ӭʹ��ְ������ϵͳ *****" << endl
		<< "******* 0.�˳�ϵͳ *************" << endl
		<< "******* 1.������ϵ����Ϣ *******" << endl
		<< "******* 2.��ʾ��ϵ����Ϣ *******" << endl
		<< "******* 3.ɾ����ϵ�� ***********" << endl
		<< "******* 4.�޸���ϵ����Ϣ *******" << endl
		<< "******* 5.������ϵ����Ϣ *******" << endl
		<< "******* 6.������ϵ�� ***********" << endl
		<< "******* 7.��������ĵ� *********" << endl
		<< "******* 8.���粢���ͺؿ� *******" << endl;
}

void PersonManager::Exit_system()
{
	std::cout << "��ӭ�´�ʹ��" << endl;
	std::system("pause");
	exit(0);
}

void PersonManager::AddPerson() {
	std::cout << "�����������ϵ�˵�������" << std::endl;
	int addnum = 0;
	std::cin >> addnum;

	if (addnum > 0) {
		int newsize = m_PersonNum + addnum;
		Person** newspace = new Person * [newsize];

		if (m_PersonArray != NULL) {
			for (int i = 0; i < m_PersonNum; i++) {
				newspace[i] = m_PersonArray[i];
			}
		}

		for (int i = 0; i < addnum; i++) {
			long int telephone;
			std::string name, unknow;
			int birthday;
			std::string email;
			int did;
			std::cout << "�������" << i + 1 << "������ϵ�˵�������" << std::endl;
			std::cin >> name;
			std::cout << "�������" << i + 1 << "������ϵ�˵����գ�" << std::endl;
			std::cin >> birthday;
			int cy = birthday / 10000;
			int cm = birthday % 10000 / 100;
			int cd = birthday % 100;
			while (!Dateiscorrect(cy, cm, cd)) {
				std::cout << "���벻�Ϸ������������룺" << endl;
				std::cin >> birthday;
				cy = birthday / 10000;
				cm = birthday % 10000 / 100;
				cd = birthday % 100;
			}
			std::cout << "�������" << i + 1 << "������ϵ�˵ĵ绰��" << std::endl;
			std::cin >> telephone;
			std::cout << "�������" << i + 1 << "������ϵ�˵����䣺" << std::endl;
			std::cin >> email;
			std::cout << "��ѡ���" << i + 1 << "������ϵ�˵����ͣ�" << std::endl
				<< "1.ͬѧ" << std::endl
				<< "2.ͬ��" << std::endl
				<< "3.����" << std::endl
				<< "4.����" << std::endl;
			std::cin >> did;
			std::cout << "������������ص�������Ϣ��" << std::endl;
			std::cin >> unknow;

			Person* newPerson = NULL;
			switch (did) {
			case 1:
				newPerson = new Classmate(name, unknow, birthday, telephone, email);
				break;
			case 2:
				newPerson = new Colleague(name, unknow, birthday, telephone, email);
				break;
			case 3:
				newPerson = new Friend(name, unknow, birthday, telephone, email);
				break;
			case 4:
				newPerson = new Relative(name, unknow, birthday, telephone, email);
				break;
			default:
				break;
			}
			newspace[m_PersonNum + i] = newPerson;
		}

		delete[] m_PersonArray;
		m_PersonArray = newspace;
		m_PersonNum = newsize;
		m_FileIsEmpty = false;

		SaveInformation();
		std::cout << "�ɹ����" << addnum << "������ϵ��" << std::endl;
	}
	else {
		std::cout << "������������" << std::endl;
	}

	std::system("pause");
	std::system("cls");
}
//void PersonManager::AddPerson() {
//	std::cout << "�����������ϵ�˵�������" << endl;
//	//innput number
//	int addnum = 0;
//	std::cin >> addnum;
//	if (addnum > 0) {
//		int newsize = m_PersonNum + addnum;
//		Person** newspace = new Person * [newsize];
//		//put original data into newspace
//		if (m_PersonArray != NULL) {
//			for (int i = 0;i < m_PersonNum;i++) {
//				newspace[i] = m_PersonArray[i];
//			}
//		}
//
//		//add new Friend
//		for (int i = 0;i < addnum;i++) {
//			long int telephone;
//			std::string name, unknow;
//			int birthday;
//			std::string email;
//			int did;
//			std::cout << "�������" << i + 1 << "������ϵ�˵�����" << endl;
//			std::cin >> name;
//			std::cout << "�������" << i + 1 << "������ϵ�˵�����" << endl;
//			std::cin >> birthday;
//			std::cout << "�������" << i + 1 << "������ϵ�˵ĵ绰" << endl;
//			std::cin >> telephone;
//			std::cout << "�������" << i + 1 << "������ϵ�˵�����" << endl;
//			std::cin >> email;
//			std::cout << "��ѡ���" << i + 1 << "������ϵ�˵�����" << endl
//				<< "1.ͬѧ" << endl
//				<< "2.ͬ��" << endl
//				<< "3.����" << endl
//				<< "4.����" << endl;
//			std::cin >> did;
//			std::cout << "������ص�������Ϣ" << endl;
//			std::cin >> unknow;
//			Person* newPerson = NULL;
//			switch (did) {
//			case 1:
//				newPerson = new Friend(name, unknow, birthday, telephone, email);
//				break;
//			case 2:
//				newPerson = new Colleague(name, unknow, birthday, telephone, email);
//				break;
//			case 3:
//				newPerson = new Classmate(name, unknow, birthday, telephone, email);
//				break;
//			case 4:
//				newPerson = new Relative(name, unknow, birthday, telephone, email);
//				break;
//			default:
//				break;
//			}
//			newspace[m_PersonNum + i] = newPerson;
//		}
//		//delete original space
//		delete[] m_PersonArray;
//		m_PersonArray = newspace;
//		m_PersonNum = newsize;
//		m_FileIsEmpty = false;
//
//		SaveInformation();
//		std::cout << "�ɹ����" << addnum << "������ϵ��" << endl;
//	}
//	else {
//		std::cout << "������������" << endl;
//	}
//	std::system("pause");
//	std::system("cls");
//}

//void PersonManager::SaveInformation() {
//	fs1.open(ClassmateFile, ios::out);
//	fs2.open(ColleagueFile, ios::out);
//	fs3.open(FriendFile, ios::out);
//	fs4.open(RelativeFile, ios::out);
//	for (int i = 0;i < m_PersonNum;i++) {
//		if (m_PersonArray[i]->GetType() == "ͬѧ") {
//			fs1 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow()<<" "
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "ͬ��") {
//			fs2 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow() << " "
//
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "����") {
//			fs3 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow() << " "
//
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "����") {
//			fs4 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow() << " "
//
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//
//	}
//	fs1.close();
//	fs2.close();
//	fs3.close();
//	fs4.close();
//}
void PersonManager::SaveInformation() {
	std::ofstream fs1(ClassmateFile, std::ios::out);
	std::ofstream fs2(ColleagueFile, std::ios::out);
	std::ofstream fs3(FriendFile, std::ios::out);
	std::ofstream fs4(RelativeFile, std::ios::out);

	for (int i = 0; i < m_PersonNum; i++) {
		std::string type = m_PersonArray[i]->GetType();
		std::ofstream* ofs = NULL;

		if (type == "ͬѧ") {
			ofs = &fs1;
		}
		else if (type == "ͬ��") {
			ofs = &fs2;
		}
		else if (type == "����") {
			ofs = &fs3;
		}
		else if (type == "����") {
			ofs = &fs4;
		}

		if (ofs != NULL) {
			*ofs << m_PersonArray[i]->GetName() << " "
				<< m_PersonArray[i]->GetUnknow() << " "
				<< m_PersonArray[i]->GetBirthday() << " "
				<< m_PersonArray[i]->GetTelephone() << " "
				<< m_PersonArray[i]->GetEmail() << std::endl;
		}
	}

	fs1.close();
	fs2.close();
	fs3.close();
	fs4.close();
}

//int PersonManager::Get_person_num() {
//		int num = 0;
//		fs1.open(ClassmateFile,ios::in);
//		fs2.open(ColleagueFile,ios::in);
//		fs3.open(FriendFile,ios::in);
//		fs4.open(RelativeFile,ios::in);
//		long int telephone;
//		std::string name, unknow;
//		int birthday;
//		std::string email;
//
//		while (fs1 >> name && fs1 >> unknow && fs1 >> birthday && fs1 >> telephone && fs1 >> email) {
//			num++;
//		}
//
//		while (fs2 >> name && fs2 >> unknow && fs2 >> birthday && fs2 >> telephone && fs2 >> email) {
//			num++;
//		}
//
//		while (fs3 >> name && fs3 >> unknow && fs3 >> birthday && fs3 >> telephone && fs3 >> email) {
//			num++;
//		}
//
//		while (fs4 >> name && fs4 >> unknow && fs4 >> birthday && fs4 >> telephone && fs4 >> email) {
//			num++;
//		}
//		fs1.close();
//		fs2.close();
//		fs3.close();
//		fs4.close();
//				
//		return num;
//
//	}
int PersonManager::Get_person_num() {
	int num = 0;
	std::ifstream fs1(ClassmateFile, std::ios::in);
	std::ifstream fs2(ColleagueFile, std::ios::in);
	std::ifstream fs3(FriendFile, std::ios::in);
	std::ifstream fs4(RelativeFile, std::ios::in);

	std::string name, unknow, email;
	int birthday;
	long int telephone;

	while (fs1 >> name >> unknow >> birthday >> telephone >> email) {
		num++;
	}

	while (fs2 >> name >> unknow >> birthday >> telephone >> email) {
		num++;
	}

	while (fs3 >> name >> unknow >> birthday >> telephone >> email) {
		num++;
	}

	while (fs4 >> name >> unknow >> birthday >> telephone >> email) {
		num++;
	}

	fs1.close();
	fs2.close();
	fs3.close();
	fs4.close();

	return num;
}

void PersonManager::Show_CurrentPerson() {
	if (m_FileIsEmpty) {
		std::cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0;i < m_PersonNum;i++) {
			m_PersonArray[i]->ShowInformation();
		}
	}
	std::cout << endl;
	std::system("pause");
	std::system("cls");

}

void PersonManager::Delete_Person() {
	if (m_FileIsEmpty) {
		std::cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	else if (!m_FileIsEmpty) {
		std::cout << "��������Ҫɾ������ϵ������" << endl;
		std::string name;
		std::cin.ignore();
		std::getline(std::cin, name);
		int signal = 0;
		for (int i = 0;i < m_PersonNum;i++) {
			if (m_PersonArray[i]->GetName() == name) {
				std::cout << ++signal << '\t';
				m_PersonArray[i]->ShowInformation();
			}
		}
		if (signal > 0) {
			cout << "���ҵ�" << signal << "����ϵ��" << endl;
			cout << "��������Ҫɾ������ϵ�˱��" << endl;

			int choice, current = 0;

			std::cin >> choice;
			while (choice < 1 || choice > signal) {
				std::cout << "���벻�Ϸ������������룺" << endl;
				std::cin >> choice;
			}

			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetName() == name) {
					current++;
					if (current == choice) {
						delete m_PersonArray[i];
						for (int j = i + 1; j < m_PersonNum; j++) {
							m_PersonArray[j - 1] = m_PersonArray[j];
						}
						m_PersonNum--;
						break;
					}
				}
			}
			//updata in file
			this->SaveInformation();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			std::cout << "ɾ��ʧ�ܣ�δ�ҵ�����ϵ��" << endl;
		}
	}


	std::system("pause");
	std::system("cls");
}

//void PersonManager::PerIsExsist(std::string name) {
//
//	for (int i = 0;i < m_PersonNum;i++) {
//		if (m_PersonArray[i]->GetName() == name) {
//			std::cout << "���ҵ���Ա������Ϣ���£�" << endl;
//			m_PersonArray[i]->ShowInformation();
//		}
//	}
//}
void PersonManager::Send_Greetings() {
	int signal = 0;
	time_t now = time(0);
	tm* ltime = localtime(&now);
	int lmonth = 1 + ltime->tm_mon;
	int lday = ltime->tm_mday;
	for (int i = 0;i < m_PersonNum;i++) {
		int daysUntilBirthday = 0;
		if (lmonth < m_PersonArray[i]->GetbirtMonth() || (lmonth == m_PersonArray[i]->GetbirtMonth() && lday <= m_PersonArray[i]->Getbirthdayday())) {
			// birthday hasn't happened yet this year
			tm birthday = { 0, 0, 0, m_PersonArray[i]->Getbirthdayday(),m_PersonArray[i]->GetbirtMonth() - 1, ltime->tm_year };
			time_t birthdayTime = mktime(&birthday);
			daysUntilBirthday = (birthdayTime - now) / (60 * 60 * 24);//����
		}
		else {
			// birthday has already happened this year
			tm nextBirthday = { 0, 0, 0, m_PersonArray[i]->Getbirthdayday(), m_PersonArray[i]->GetbirtMonth() - 1, ltime->tm_year + 1 };
			time_t nextBirthdayTime = mktime(&nextBirthday);
			daysUntilBirthday = (nextBirthdayTime - now) / (60 * 60 * 24);
		}

		if (daysUntilBirthday <= 5) {
			signal++;
			tm birthdayThisYear = { 0,0,0,m_PersonArray[i]->Getbirthdayday(),m_PersonArray[i]->GetbirtMonth() - 1,ltime->tm_year };
			time_t birthdayThisYeartime = mktime(&birthdayThisYear);
			// �� tm �ṹ��ת��Ϊ����ʱ��
			tm* birthdayThisYearLocalTime = localtime(&birthdayThisYeartime);
			std::string weekday;
			switch (birthdayThisYearLocalTime->tm_wday)
			{
			case 1:
				weekday = "����һ";
				break;
			case 2:
				weekday = "���ڶ�";
				break;
			case 3:
				weekday = "������";
				break;
			case 4:
				weekday = "������";
				break;
			case 5:
				weekday = "������";
				break;
			case 6:
				weekday = "������";
				break;
			case 0:
				weekday = "������";
				break;
			default:
				break;
			}
			cout << "����������ϵ������:" << endl;
			cout << m_PersonArray[i]->GetName() << ":" << m_PersonArray[i]->GetbirtMonth() << "��" << m_PersonArray[i]->Getbirthdayday() << "��" << "(" << weekday << ")";
			//m_PersonArray[i]->ShowInformation();

			fstream fs;
			string cname;
			cout << "��������ŵ��������" << endl;
			cin >> cname;
			fs.open("Greeting.txt", ios::out);
			fs << m_PersonArray[i]->GetName() << "��" << endl;
			fs << "\t\tף���տ��֣������Ҹ���" << endl;
			fs << "\t\t\t\t\t\t\t\t"<<cname;
			fs.close();
			cout << "�����ѳɹ�����,��ǰ���鿴" << endl;
		}

	}
	if (signal == 0) {
		cout << "��ǰû����ϵ������" << endl;
	}
	system("pause");
	system("cls");
}
void PersonManager::Modify_person() {
	if (m_FileIsEmpty) {
		std::cout << "�ļ������ڻ�Ϊ��" << std::endl;
		return;
	}

	std::cout << "��������Ҫ�޸ĵ���ϵ��������" << std::endl;
	std::string name;
	std::cin >> name;

	int count = 0;
	for (int i = 0; i < m_PersonNum; i++) {
		if (m_PersonArray[i]->GetName() == name) {
			std::cout << "�鵽��ϵ�ˣ�" << std::endl;
			std::cout << "��ţ�" << i << std::endl;
			m_PersonArray[i]->ShowInformation();
			count++;
		}
	}

	if (count == 0) {
		std::cout << "�޸�ʧ�ܣ����޴���" << std::endl;
		return;
	}

	std::cout << "��������Ҫ�޸ĵ���ϵ����ţ�" << std::endl;
	int choice;
	std::cin >> choice;

	if (choice < 0 || choice >= m_PersonNum) {
		std::cout << "����������Ч" << std::endl;
		return;
	}

	int newdid;
	std::string newname;
	int newbirthday;
	long int newtelephone;
	std::string newemail;
	std::string newunknow;

	std::cout << "�������µ�������" << std::endl;
	std::cin >> newname;
	std::cout << "�������µ����գ�" << std::endl;
	std::cin >> newbirthday;

	int cy = newbirthday / 10000;
	int cm = newbirthday % 10000 / 100;
	int cd =newbirthday % 100;
	while (!Dateiscorrect(cy, cm, cd)) {
		std::cout << "���벻�Ϸ������������룺" << endl;
		std::cin >> newbirthday;
		cy = newbirthday / 10000;
		cm = newbirthday % 10000 / 100;
		cd = newbirthday % 100;
	}

	std::cout << "�������µĵ绰��" << std::endl;
	std::cin >> newtelephone;
	std::cout << "�������µ����䣺" << std::endl;
	std::cin >> newemail;
	std::cout << "�������µ����ͣ�" << std::endl
		<< "1.����" << std::endl
		<< "2.ͬ��" << std::endl
		<< "3.ͬѧ" << std::endl
		<< "4.����" << std::endl;
	std::cin >> newdid;
	std::cout << "�����������йص�������Ϣ��" << std::endl;
	std::cin >> newunknow;

	switch (newdid) {
	case 1:
		m_PersonArray[choice] = new Friend(newname, newunknow, newbirthday, newtelephone, newemail);
		break;
	case 2:
		m_PersonArray[choice] = new Colleague(newname, newunknow, newbirthday, newtelephone, newemail);
		break;
	case 3:
		m_PersonArray[choice] = new Classmate(newname, newunknow, newbirthday, newtelephone, newemail);
		break;
	case 4:
		m_PersonArray[choice] = new Relative(newname, newunknow, newbirthday, newtelephone, newemail);
		break;
	default:
		std::cout << "�����������Ч" << std::endl;
		return;
	}

	this->SaveInformation();
	std::cout << "�޸ĳɹ�" << std::endl;

	std::system("pause");
	std::system("cls");
}

//void PersonManager::Find_person() {
//	if (m_FileIsEmpty) {
//		std::cout << "�ļ������ڻ��¼Ϊ��" << endl;
//
//	}
//	else {
//		std::cout << "��������ҵķ�ʽ��" << endl
//			<< "1.�������ղ���" << endl
//			<< "2.������������" << endl
//			<< "3.���������·ݲ���" << endl;
//
//
//		int select = 0;
//		std::cin >> select;
//
//		switch (select) {
//		case 1: {
//			int birthday = 0;
//			std::cout << "��������Ҫ���ҵ���ϵ�����գ�" << endl;
//			std::cin >> birthday;
//			bool index = false;
//			for (int i = 0;i < m_PersonNum;i++) {
//				if (m_PersonArray[i]->GetBirthday() == birthday) {	
//					std::cout << "���ҵ�����ϵ�ˣ���Ϣ���£�" << endl;
//					m_PersonArray[i]->ShowInformation();
//					index = true;
//				}
//				
//			}
//			if(index == false) {
//				std::cout << "����ʧ�ܣ����޴���" << endl;
//				}
//			std::system("pause");
//			std::system("cls");
//			break;
//		}
//		case 2: {
//			std::string inname = "";
//			std::cout << "��������ҵ�������" << endl;
//			std::cin >> inname;
//			bool signal = false;
//			for (int i = 0;i < m_PersonNum;i++) {
//				if (m_PersonArray[i]->GetName() == inname) {
//					std::cout << "���ҵ�����ϵ�ˣ���Ϣ���£�" << endl;
//					m_PersonArray[i]->ShowInformation();
//					signal = true;
//				}
//
//			}
//			if (signal == false) {
//				std::cout << "����ʧ�ܣ����޴���" << endl;
//			}
//			std::system("pause");
//			std::system("cls");
//			break;
//		}
//		case 3:
//			sort_person_bymonth();break;
//		default:
//			std::cout << "��������" << endl;
//			std::system("pause");
//			std::system("cls");
//			break;
//
//		}
//
//	}
//
//}
void PersonManager::Find_person() {
	if (m_PersonNum == 0) {
		std::cout << "��¼Ϊ��" << std::endl;
		return;
	}

	std::cout << "��������ҵķ�ʽ��" << std::endl
		<< "1.�������ղ���" << std::endl
		<< "2.������������" << std::endl
		<< "3.���������·ݲ���" << std::endl;

	int select = 0;
	std::cin >> select;

	switch (select) {
	case 1: {
		int birthday = 0;
		std::cout << "��������Ҫ���ҵ���ϵ�����գ�" << std::endl;
		std::cin >> birthday;
		int cy = birthday / 10000;
		int cm = birthday % 10000 / 100;
		int cd = birthday % 100;
		while (!Dateiscorrect(cy, cm, cd)) {
			std::cout << "���벻�Ϸ������������룺" << endl;
			std::cin >> birthday;
			cy = birthday / 10000;
			cm = birthday % 10000 / 100;
			cd = birthday % 100;
		}
		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetBirthday() == birthday) {
				std::cout << "���ҵ�����ϵ�ˣ���Ϣ���£�" << std::endl;
				m_PersonArray[i]->ShowInformation();
				found = true;
			}
		}

		if (!found) {
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
		break;
	}
	case 2: {
		std::string inname = "";
		std::cout << "��������ҵ�������" << std::endl;
		std::cin >> inname;

		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetName() == inname) {
				std::cout << "���ҵ�����ϵ�ˣ���Ϣ���£�" << std::endl;
				m_PersonArray[i]->ShowInformation();
				found = true;
			}
		}

		if (!found) {
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
		break;
	}
	case 3: {
		sort_person_bymonth();break;
		/*std::cout << "��������Ҫ���ҵ������·ݣ�" << std::endl;
		int month = 0;
		std::cin >> month;

		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetBirthday() % 10000 / 100 == month) {
				if (!found) {
					std::cout << "���ҵ�������" << month << "�·ݵ���ϵ�ˣ���Ϣ���£�" << std::endl;
					found = true;
				}
				m_PersonArray[i]->ShowInformation();
			}
		}

		if (!found) {
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
		break;*/
	}
	default:
		std::cout << "��������" << std::endl;
		break;
	}

	std::system("pause");
	std::system("cls");
}

void PersonManager::Sort_person() {
	if (this->m_FileIsEmpty) {
		std::cout << "�ļ������ں��ļ�Ϊ��" << endl;
		std::system("pause");
		std::system("cls");
		return;
	}

	else {
		std::cout << "��ѡ������ʽ" << endl;
		std::cout << "1.������" << endl;
		std::cout << "2.������" << endl;
		std::cout << "3.�����" << endl;

		int select = 0;
		std::cin >> select;
		if (select == 3) {
			std::cout << "����ɹ������Ϊ��" << endl;
			/*for (int i = 0;i < m_PersonNum;i++) {
				if(m_PersonArray[i]->GetType() == "ͬѧ") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "ͬ��") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "����") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "����") {
					m_PersonArray[i]->ShowInformation();
				}
			}*/
			/*const auto& type ��һ��ѭ������������������ const char* �ĳ������ã���ʾһ��ָ���ַ�������ָ�롣\
			����������У�������������һ���ַ������飬���а�������ϵ�˵����ͬѧ��ͬ�¡����ѡ����ݡ�
			ʹ�� const auto& �����ñ������Զ��Ƶ�ѭ�����������ͣ�������Ҫ��ʽ��ָ�����͡�
			ͬʱ��ʹ�ó������ÿ��Ա�����ѭ���д�����ʱ��������ߴ����Ч�ʡ�*/
			for (const auto& type : { "ͬѧ", "ͬ��", "����", "����" }) {
				for (int i = 0; i < m_PersonNum; i++) {
					if (m_PersonArray[i]->GetType() == type) {
						m_PersonArray[i]->ShowInformation();
					}
				}
			}
			system("pause");
			system("cls");

		}
		else {
			for (int i = 0;i < m_PersonNum;i++) {
				int maxmin = i;
				for (int j = i + 1;j < m_PersonNum;j++) {
					if (select == 2) {
						if (m_PersonArray[maxmin]->GetBirthday() > m_PersonArray[j]->GetBirthday()) {
							maxmin = j;
						}
					}
					else if (select == 1) {
						if (m_PersonArray[maxmin]->GetName() > m_PersonArray[j]->GetName()) {
							maxmin = j;
						}
					}
				}
				if (i != maxmin) {
					std::swap(m_PersonArray[i], m_PersonArray[maxmin]);
				}

			}
			std::cout << "����ɹ������Ϊ��" << endl;
			this->SaveInformation();
			this->Show_CurrentPerson();
		}
		
	}
}
//ͳ���ڸ����·ݳ���������������ʾ���
//void PersonManager::sort_person_bymonth() {
//	cout << "�����������·�" << endl;
//	int month;
//	cin >> month;
//	if (month > 0 && month < 13) {
//		int signal = 0;
//		for (int i = 0;i < m_PersonNum;i++) {
//			if (m_PersonArray[i]->GetbirtMonth() == month) {
//				signal++;
//				m_PersonArray[i]->ShowInformation();
//			}
//		}
//		if (signal == 0) {
//			cout << "û����" << month << "�³�������ϵ��" << endl;
//
//		}
//		else {
//			cout << "��" << month << "�³�������ϵ�˹���" << signal << "��" << endl;
//		}
//	}
//	else {
//		cout << "�����·�����" << endl;
//	}
//	std::system("pause");
//	std::system("cls");
//}
void PersonManager::sort_person_bymonth() {
	std::cout << "�����������·ݣ�" << std::endl;
	int month = 0;
	std::cin >> month;

	if (month < 1 || month > 12) {
		std::cout << "�����·�����" << std::endl;
		return;
	}

	int count = 0;
	for (int i = 0; i < m_PersonNum; i++) {
		if (m_PersonArray[i]->GetbirtMonth() == month) {
			m_PersonArray[i]->ShowInformation();
			count++;
		}
	}

	if (count == 0) {
		std::cout << "û����" << month << "�³�������ϵ��" << std::endl;
	}
	else {
		std::cout << "��" << month << "�³�������ϵ�˹���" << count << "��" << std::endl;
	}
}

//void PersonManager::Clean_File() {
//	std::cout << "ȷ����գ�" << endl;
//	std::cout << "1.��" << endl;
//	std::cout << "2.��" << endl;
//
//	int select = 0;
//	std::cin >> select;
//	if (select == 1) {
//		ofstream ofs1(ClassmateFile, ios::trunc);
//		ofstream ofs2(ColleagueFile, ios::trunc);
//		ofstream ofs3(RelativeFile, ios::trunc);
//		ofstream ofs4(FriendFile, ios::trunc);
//		ofs1.close();
//		ofs2.close();
//		ofs3.close();
//		ofs4.close();
//
//		if (this->m_PersonArray != NULL) {
//			for (int i = 0;i < m_PersonNum;i++) {
//				if (m_PersonArray[i] != NULL) {
//					delete m_PersonArray[i];
//
//				}
//			}
//			m_PersonNum = NULL;
//			delete[]m_PersonArray;
//			m_PersonArray = NULL;
//			m_FileIsEmpty = true;
//		}
//
//		std::cout << "������" << endl;
//		std::system("pause");
//		std::system("cls");
//	}
//}
void PersonManager::Clean_File() {
	std::cout << "ȷ����գ�" << std::endl;
	std::cout << "1.��" << std::endl;
	std::cout << "2.��" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select != 1) {
		std::cout << "ȡ�����" << std::endl;
		return;
	}

	std::ofstream ofs1(ClassmateFile, std::ios::trunc);
	std::ofstream ofs2(ColleagueFile, std::ios::trunc);
	std::ofstream ofs3(RelativeFile, std::ios::trunc);
	std::ofstream ofs4(FriendFile, std::ios::trunc);
	ofs1.close();
	ofs2.close();
	ofs3.close();
	ofs4.close();

	for (int i = 0; i < m_PersonNum; i++) {
		delete m_PersonArray[i];
	}
	delete[] m_PersonArray;
	m_PersonArray = nullptr;
	m_PersonNum = 0;
	m_FileIsEmpty = true;

	std::cout << "������" << std::endl;
	std::system("pause");
	std::system("cls");
}

bool PersonManager::Dateiscorrect(int year,int month, int day) {
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {//���������
		a[1] = 29;
		if (0 < day && day <= a[month - 1] && month > 0 && month <= 12) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (0 < day && day <= a[month - 1] && 0 < month && 12 >= month) {
			return true;
		}
		else {
			return false;
		}
	}

}





