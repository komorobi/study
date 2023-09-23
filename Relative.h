#pragma once
#pragma once
#include<iostream>
#include"Person.h"

class Relative :public Person {
public:

	Relative(std::string name, std::string Type_name, int birthday, long int telephone, std::string email);
	virtual void ShowInformation();
	virtual std::string GetType();

};