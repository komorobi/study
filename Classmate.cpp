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
	std::cout << "\t��ϵ��������" << GetName()
		<< "\t��ϵ�����գ�" << GetBirthday()
		<< "\t��ϵ�˳ƺ���" << GetType()
		<< "\t��ϵ�����䣺" << GetEmail()
		<< "\t����ѧУ��" << GetUnknow() << endl;
}

std::string Classmate::GetType() {
	return std::string("ͬѧ");
}