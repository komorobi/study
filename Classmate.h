#pragma once
#pragma once
#include<iostream>
#include"Person.h"
class Classmate :public Person {

public:
	Classmate(std::string name, std::string school, int birthday, long int telephone, std::string email);
	virtual void ShowInformation();
	virtual std::string GetType();
};
