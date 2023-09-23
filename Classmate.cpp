#include"Classmate.h"
#include<iostream>
using namespace std;

Classmate::Classmate(std::string name, std::string school, int birthday, long int telephone, std::string email) {
	m_name = name;
	m_unknow = school;
	m_Birthday = birthday;
	m_Telephone = telephone;
	m_email = email;

}

void Classmate::ShowInformation() {
	std::cout << "\t联系人姓名：" << GetName()
		<< "\t联系人生日：" << GetBirthday()
		<< "\t联系人称呼：" << GetType()
		<< "\t联系人邮箱：" << GetEmail()
		<< "\t所在学校：" << GetUnknow() << endl;
}

std::string Classmate::GetType() {
	return std::string("同学");
}