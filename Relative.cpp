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
	std::cout << "\t��ϵ��������" << GetName()
		<< "\t��ϵ�����գ�" << GetBirthday()
		<< "\t��ϵ�˳ƺ���" << GetType()
		<< "\t��ϵ�����䣺" << GetEmail()
		<< "\t�ƺ���" << GetUnknow() << endl;
}

std::string Relative::GetType() {
	return std::string("����");
}


