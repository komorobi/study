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
	std::cout << "\t��ϵ��������" << GetName()
		<< "\t��ϵ�����գ�" << GetBirthday()
		<< "\t��ϵ�˳ƺ���" << GetType()
		<< "\t��ϵ�����䣺" << GetEmail()
		<< "\t���ڵ�λ��" << GetUnknow() << endl;
}

std::string Colleague::GetType() {
	return std::string("ͬ��");
}