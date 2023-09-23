#pragma once
#include<iostream>
#include<string>
class Person {
protected:
	std::string m_name;
	int m_Birthday;
	long int m_Telephone;
	std::string m_email;
	std::string m_unknow;
public:
	virtual void ShowInformation() = 0;
	virtual std::string GetType() = 0;
	int GetbirtMonth();
	int Getbirthdayday();

	std::string GetName() {
		return m_name;
	}

	int GetBirthday() {
		return m_Birthday;
	}
	long int GetTelephone() {
		return m_Telephone;
	}

	std::string GetEmail() {
		return m_email;
	}

	std::string GetUnknow() {
		return m_unknow;
	}
};