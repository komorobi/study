#include"Colleague.h"
#include<iostream>
using namespace std;

Colleague::Colleague(std::string name, std::string firm, int birthday, long int telephone, std::string email) {
	m_name = name;
	m_Birthday = birthday;
	m_Telephone = telephone;
	m_unknow = firm;
	m_email = email;

}

void Colleague::ShowInformation() {
	std::cout << "\t联系人姓名：" << GetName()
		<< "\t联系人生日：" << GetBirthday()
		<< "\t联系人称呼：" << GetType()
		<< "\t联系人邮箱：" << GetEmail()
		<< "\t所在单位：" << GetUnknow() << endl;
}

std::string Colleague::GetType() {
	return std::string("同事");
}