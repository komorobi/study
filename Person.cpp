#include<iostream>
#include"Person.h"
int Person::GetbirtMonth() {
	int month = m_Birthday % 10000 / 100;
	return month;
}
int Person::Getbirthdayday() {
	int day = m_Birthday % 100;
	return day;
}