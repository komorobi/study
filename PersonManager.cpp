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
//初始化
//void PersonManager::Initial_Person() {
//	std::ifstream fs1(ClassmateFile);
//	std::ifstream fs2(ColleagueFile);
//	std::ifstream fs3(FriendFile);
//	std::ifstream fs4(RelativeFile);
//
//	if (!fs1 || !fs2 || !fs3 || !fs4) {
//		std::cout << "打开文件失败" << std::endl;
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
		std::cout << "文件为空" << std::endl;
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
	std::cout << "***** 欢迎使用职工管理系统 *****" << endl
		<< "******* 0.退出系统 *************" << endl
		<< "******* 1.增加联系人信息 *******" << endl
		<< "******* 2.显示联系人信息 *******" << endl
		<< "******* 3.删除联系人 ***********" << endl
		<< "******* 4.修改联系人信息 *******" << endl
		<< "******* 5.查找联系人信息 *******" << endl
		<< "******* 6.排序联系人 ***********" << endl
		<< "******* 7.清空所有文档 *********" << endl
		<< "******* 8.查早并发送贺卡 *******" << endl;
}

void PersonManager::Exit_system()
{
	std::cout << "欢迎下次使用" << endl;
	std::system("pause");
	exit(0);
}

void PersonManager::AddPerson() {
	std::cout << "请输入添加联系人的数量：" << std::endl;
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
			std::cout << "请输入第" << i + 1 << "个新联系人的姓名：" << std::endl;
			std::cin >> name;
			std::cout << "请输入第" << i + 1 << "个新联系人的生日：" << std::endl;
			std::cin >> birthday;
			int cy = birthday / 10000;
			int cm = birthday % 10000 / 100;
			int cd = birthday % 100;
			while (!Dateiscorrect(cy, cm, cd)) {
				std::cout << "输入不合法，请重新输入：" << endl;
				std::cin >> birthday;
				cy = birthday / 10000;
				cm = birthday % 10000 / 100;
				cd = birthday % 100;
			}
			std::cout << "请输入第" << i + 1 << "个新联系人的电话：" << std::endl;
			std::cin >> telephone;
			std::cout << "请输入第" << i + 1 << "个新联系人的邮箱：" << std::endl;
			std::cin >> email;
			std::cout << "请选择第" << i + 1 << "个新联系人的类型：" << std::endl
				<< "1.同学" << std::endl
				<< "2.同事" << std::endl
				<< "3.朋友" << std::endl
				<< "4.亲戚" << std::endl;
			std::cin >> did;
			std::cout << "请输入与其相关的其他信息：" << std::endl;
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
		std::cout << "成功添加" << addnum << "名新联系人" << std::endl;
	}
	else {
		std::cout << "输入数据有误" << std::endl;
	}

	std::system("pause");
	std::system("cls");
}
//void PersonManager::AddPerson() {
//	std::cout << "请输入添加联系人的数量：" << endl;
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
//			std::cout << "请输入第" << i + 1 << "个新联系人的姓名" << endl;
//			std::cin >> name;
//			std::cout << "请输入第" << i + 1 << "个新联系人的生日" << endl;
//			std::cin >> birthday;
//			std::cout << "请输入第" << i + 1 << "个新联系人的电话" << endl;
//			std::cin >> telephone;
//			std::cout << "请输入第" << i + 1 << "个新联系人的邮箱" << endl;
//			std::cin >> email;
//			std::cout << "请选择第" << i + 1 << "个新联系人的类型" << endl
//				<< "1.同学" << endl
//				<< "2.同事" << endl
//				<< "3.朋友" << endl
//				<< "4.亲戚" << endl;
//			std::cin >> did;
//			std::cout << "与其相关的其他信息" << endl;
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
//		std::cout << "成功添加" << addnum << "名新联系人" << endl;
//	}
//	else {
//		std::cout << "输入数据有误" << endl;
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
//		if (m_PersonArray[i]->GetType() == "同学") {
//			fs1 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow()<<" "
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "同事") {
//			fs2 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow() << " "
//
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "朋友") {
//			fs3 << m_PersonArray[i]->GetName() << " "
//				<< m_PersonArray[i]->GetUnknow() << " "
//
//				<< m_PersonArray[i]->GetBirthday() << " "
//				<< m_PersonArray[i]->GetTelephone() << " "
//				<< m_PersonArray[i]->GetEmail() << endl;
//		}
//		else if (m_PersonArray[i]->GetType() == "亲戚") {
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

		if (type == "同学") {
			ofs = &fs1;
		}
		else if (type == "同事") {
			ofs = &fs2;
		}
		else if (type == "朋友") {
			ofs = &fs3;
		}
		else if (type == "亲戚") {
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
		std::cout << "文件不存在或记录为空" << endl;
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
		std::cout << "文件不存在或记录为空" << endl;
	}

	else if (!m_FileIsEmpty) {
		std::cout << "请输入想要删除的联系人姓名" << endl;
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
			cout << "共找到" << signal << "个联系人" << endl;
			cout << "请输入想要删除的联系人编号" << endl;

			int choice, current = 0;

			std::cin >> choice;
			while (choice < 1 || choice > signal) {
				std::cout << "输入不合法，请重新输入：" << endl;
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
			cout << "删除成功" << endl;
		}
		else {
			std::cout << "删除失败，未找到该联系人" << endl;
		}
	}


	std::system("pause");
	std::system("cls");
}

//void PersonManager::PerIsExsist(std::string name) {
//
//	for (int i = 0;i < m_PersonNum;i++) {
//		if (m_PersonArray[i]->GetName() == name) {
//			std::cout << "已找到该员工，信息如下：" << endl;
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
			daysUntilBirthday = (birthdayTime - now) / (60 * 60 * 24);//秒数
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
			// 将 tm 结构体转换为本地时间
			tm* birthdayThisYearLocalTime = localtime(&birthdayThisYeartime);
			std::string weekday;
			switch (birthdayThisYearLocalTime->tm_wday)
			{
			case 1:
				weekday = "星期一";
				break;
			case 2:
				weekday = "星期二";
				break;
			case 3:
				weekday = "星期三";
				break;
			case 4:
				weekday = "星期四";
				break;
			case 5:
				weekday = "星期五";
				break;
			case 6:
				weekday = "星期六";
				break;
			case 0:
				weekday = "星期日";
				break;
			default:
				break;
			}
			cout << "近五天有联系人生日:" << endl;
			cout << m_PersonArray[i]->GetName() << ":" << m_PersonArray[i]->GetbirtMonth() << "月" << m_PersonArray[i]->Getbirthdayday() << "日" << "(" << weekday << ")";
			//m_PersonArray[i]->ShowInformation();

			fstream fs;
			string cname;
			cout << "请输入贺信的落款姓名" << endl;
			cin >> cname;
			fs.open("Greeting.txt", ios::out);
			fs << m_PersonArray[i]->GetName() << "：" << endl;
			fs << "\t\t祝生日快乐，健康幸福。" << endl;
			fs << "\t\t\t\t\t\t\t\t"<<cname;
			fs.close();
			cout << "贺信已成功生成,请前往查看" << endl;
		}

	}
	if (signal == 0) {
		cout << "当前没有联系人生日" << endl;
	}
	system("pause");
	system("cls");
}
void PersonManager::Modify_person() {
	if (m_FileIsEmpty) {
		std::cout << "文件不存在或为空" << std::endl;
		return;
	}

	std::cout << "请输入想要修改的联系人姓名：" << std::endl;
	std::string name;
	std::cin >> name;

	int count = 0;
	for (int i = 0; i < m_PersonNum; i++) {
		if (m_PersonArray[i]->GetName() == name) {
			std::cout << "查到联系人：" << std::endl;
			std::cout << "序号：" << i << std::endl;
			m_PersonArray[i]->ShowInformation();
			count++;
		}
	}

	if (count == 0) {
		std::cout << "修改失败，查无此人" << std::endl;
		return;
	}

	std::cout << "请输入想要修改的联系人序号：" << std::endl;
	int choice;
	std::cin >> choice;

	if (choice < 0 || choice >= m_PersonNum) {
		std::cout << "输入的序号无效" << std::endl;
		return;
	}

	int newdid;
	std::string newname;
	int newbirthday;
	long int newtelephone;
	std::string newemail;
	std::string newunknow;

	std::cout << "请输入新的姓名：" << std::endl;
	std::cin >> newname;
	std::cout << "请输入新的生日：" << std::endl;
	std::cin >> newbirthday;

	int cy = newbirthday / 10000;
	int cm = newbirthday % 10000 / 100;
	int cd =newbirthday % 100;
	while (!Dateiscorrect(cy, cm, cd)) {
		std::cout << "输入不合法，请重新输入：" << endl;
		std::cin >> newbirthday;
		cy = newbirthday / 10000;
		cm = newbirthday % 10000 / 100;
		cd = newbirthday % 100;
	}

	std::cout << "请输入新的电话：" << std::endl;
	std::cin >> newtelephone;
	std::cout << "请输入新的邮箱：" << std::endl;
	std::cin >> newemail;
	std::cout << "请输入新的类型：" << std::endl
		<< "1.朋友" << std::endl
		<< "2.同事" << std::endl
		<< "3.同学" << std::endl
		<< "4.亲戚" << std::endl;
	std::cin >> newdid;
	std::cout << "请输入与其有关的其他信息：" << std::endl;
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
		std::cout << "输入的类型无效" << std::endl;
		return;
	}

	this->SaveInformation();
	std::cout << "修改成功" << std::endl;

	std::system("pause");
	std::system("cls");
}

//void PersonManager::Find_person() {
//	if (m_FileIsEmpty) {
//		std::cout << "文件不存在或记录为空" << endl;
//
//	}
//	else {
//		std::cout << "请输入查找的方式：" << endl
//			<< "1.按照生日查找" << endl
//			<< "2.按照姓名查找" << endl
//			<< "3.按照生日月份查找" << endl;
//
//
//		int select = 0;
//		std::cin >> select;
//
//		switch (select) {
//		case 1: {
//			int birthday = 0;
//			std::cout << "请输入想要查找的联系人生日：" << endl;
//			std::cin >> birthday;
//			bool index = false;
//			for (int i = 0;i < m_PersonNum;i++) {
//				if (m_PersonArray[i]->GetBirthday() == birthday) {	
//					std::cout << "已找到该联系人，信息如下：" << endl;
//					m_PersonArray[i]->ShowInformation();
//					index = true;
//				}
//				
//			}
//			if(index == false) {
//				std::cout << "查找失败，查无此人" << endl;
//				}
//			std::system("pause");
//			std::system("cls");
//			break;
//		}
//		case 2: {
//			std::string inname = "";
//			std::cout << "请输入查找的姓名：" << endl;
//			std::cin >> inname;
//			bool signal = false;
//			for (int i = 0;i < m_PersonNum;i++) {
//				if (m_PersonArray[i]->GetName() == inname) {
//					std::cout << "已找到该联系人，信息如下：" << endl;
//					m_PersonArray[i]->ShowInformation();
//					signal = true;
//				}
//
//			}
//			if (signal == false) {
//				std::cout << "查找失败，查无此人" << endl;
//			}
//			std::system("pause");
//			std::system("cls");
//			break;
//		}
//		case 3:
//			sort_person_bymonth();break;
//		default:
//			std::cout << "输入有误" << endl;
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
		std::cout << "记录为空" << std::endl;
		return;
	}

	std::cout << "请输入查找的方式：" << std::endl
		<< "1.按照生日查找" << std::endl
		<< "2.按照姓名查找" << std::endl
		<< "3.按照生日月份查找" << std::endl;

	int select = 0;
	std::cin >> select;

	switch (select) {
	case 1: {
		int birthday = 0;
		std::cout << "请输入想要查找的联系人生日：" << std::endl;
		std::cin >> birthday;
		int cy = birthday / 10000;
		int cm = birthday % 10000 / 100;
		int cd = birthday % 100;
		while (!Dateiscorrect(cy, cm, cd)) {
			std::cout << "输入不合法，请重新输入：" << endl;
			std::cin >> birthday;
			cy = birthday / 10000;
			cm = birthday % 10000 / 100;
			cd = birthday % 100;
		}
		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetBirthday() == birthday) {
				std::cout << "已找到该联系人，信息如下：" << std::endl;
				m_PersonArray[i]->ShowInformation();
				found = true;
			}
		}

		if (!found) {
			std::cout << "查找失败，查无此人" << std::endl;
		}
		break;
	}
	case 2: {
		std::string inname = "";
		std::cout << "请输入查找的姓名：" << std::endl;
		std::cin >> inname;

		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetName() == inname) {
				std::cout << "已找到该联系人，信息如下：" << std::endl;
				m_PersonArray[i]->ShowInformation();
				found = true;
			}
		}

		if (!found) {
			std::cout << "查找失败，查无此人" << std::endl;
		}
		break;
	}
	case 3: {
		sort_person_bymonth();break;
		/*std::cout << "请输入想要查找的生日月份：" << std::endl;
		int month = 0;
		std::cin >> month;

		bool found = false;
		for (int i = 0; i < m_PersonNum; i++) {
			if (m_PersonArray[i]->GetBirthday() % 10000 / 100 == month) {
				if (!found) {
					std::cout << "已找到生日在" << month << "月份的联系人，信息如下：" << std::endl;
					found = true;
				}
				m_PersonArray[i]->ShowInformation();
			}
		}

		if (!found) {
			std::cout << "查找失败，查无此人" << std::endl;
		}
		break;*/
	}
	default:
		std::cout << "输入有误" << std::endl;
		break;
	}

	std::system("pause");
	std::system("cls");
}

void PersonManager::Sort_person() {
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在后文件为空" << endl;
		std::system("pause");
		std::system("cls");
		return;
	}

	else {
		std::cout << "请选择排序方式" << endl;
		std::cout << "1.按姓名" << endl;
		std::cout << "2.按生日" << endl;
		std::cout << "3.按类别" << endl;

		int select = 0;
		std::cin >> select;
		if (select == 3) {
			std::cout << "排序成功，结果为：" << endl;
			/*for (int i = 0;i < m_PersonNum;i++) {
				if(m_PersonArray[i]->GetType() == "同学") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "同事") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "朋友") {
					m_PersonArray[i]->ShowInformation();
				}
			}
			for (int i = 0;i < m_PersonNum;i++) {
				if (m_PersonArray[i]->GetType() == "亲戚") {
					m_PersonArray[i]->ShowInformation();
				}
			}*/
			/*const auto& type 是一个循环变量，它的类型是 const char* 的常量引用，表示一个指向字符常量的指针。\
			在这个程序中，它被用来遍历一个字符串数组，其中包含了联系人的类别：同学、同事、朋友、亲戚。
			使用 const auto& 可以让编译器自动推导循环变量的类型，而不需要显式地指定类型。
			同时，使用常量引用可以避免在循环中创建临时变量，提高代码的效率。*/
			for (const auto& type : { "同学", "同事", "朋友", "亲戚" }) {
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
			std::cout << "排序成功，结果为：" << endl;
			this->SaveInformation();
			this->Show_CurrentPerson();
		}
		
	}
}
//统计在给定月份出生的人数，并显示输出
//void PersonManager::sort_person_bymonth() {
//	cout << "请输入生日月份" << endl;
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
//			cout << "没有在" << month << "月出生的联系人" << endl;
//
//		}
//		else {
//			cout << "在" << month << "月出生的联系人共有" << signal << "个" << endl;
//		}
//	}
//	else {
//		cout << "输入月份有误" << endl;
//	}
//	std::system("pause");
//	std::system("cls");
//}
void PersonManager::sort_person_bymonth() {
	std::cout << "请输入生日月份：" << std::endl;
	int month = 0;
	std::cin >> month;

	if (month < 1 || month > 12) {
		std::cout << "输入月份有误" << std::endl;
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
		std::cout << "没有在" << month << "月出生的联系人" << std::endl;
	}
	else {
		std::cout << "在" << month << "月出生的联系人共有" << count << "个" << std::endl;
	}
}

//void PersonManager::Clean_File() {
//	std::cout << "确认清空？" << endl;
//	std::cout << "1.是" << endl;
//	std::cout << "2.否" << endl;
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
//		std::cout << "清空完成" << endl;
//		std::system("pause");
//		std::system("cls");
//	}
//}
void PersonManager::Clean_File() {
	std::cout << "确认清空？" << std::endl;
	std::cout << "1.是" << std::endl;
	std::cout << "2.否" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select != 1) {
		std::cout << "取消清空" << std::endl;
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

	std::cout << "清空完成" << std::endl;
	std::system("pause");
	std::system("cls");
}

bool PersonManager::Dateiscorrect(int year,int month, int day) {
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {//如果是闰年
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





