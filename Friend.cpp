#include"Friend.h"
using namespace std;
Friend::Friend(std::string name, std::string position, int birthday, long int telephone, std::string email) {
	m_Telephone = telephone;
	m_Birthday = birthday;
	m_name = name;
	m_unknow = position;
	m_email = email;
}

void Friend::ShowInformation() {
	std::cout << "\t��ϵ��������" << GetName()
		<< "\t��ϵ�����գ�" << GetBirthday()
		<< "\t��ϵ�˳ƺ���" << GetType()
		<< "\t��ϵ�����䣺" << GetEmail()
		<< "\t�����ص㣺" << GetUnknow() << endl;
}

std::string Friend::GetType() {
	return "����";
}