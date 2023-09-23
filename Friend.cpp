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
	std::cout << "\t联系人姓名：" << GetName()
		<< "\t联系人生日：" << GetBirthday()
		<< "\t联系人称呼：" << GetType()
		<< "\t联系人邮箱：" << GetEmail()
		<< "\t相遇地点：" << GetUnknow() << endl;
}

std::string Friend::GetType() {
	return "朋友";
}