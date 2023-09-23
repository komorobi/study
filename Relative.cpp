#include<iostream>
#include"Relative.h"
using namespace std;
Relative::Relative(std::string name, std::string Type_name, int birthday, long int telephone, std::string email) {
	m_name = name;
	m_unknow = Type_name;
	m_Birthday = birthday;
	m_Telephone = telephone;
	m_email = email;
}


void Relative::ShowInformation() {
	std::cout << "\t联系人姓名：" << GetName()
		<< "\t联系人生日：" << GetBirthday()
		<< "\t联系人称呼：" << GetType()
		<< "\t联系人邮箱：" << GetEmail()
		<< "\t称呼：" << GetUnknow() << endl;
}

std::string Relative::GetType() {
	return std::string("亲戚");
}


