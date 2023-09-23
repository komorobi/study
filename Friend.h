#pragma once
#include<iostream>
#include"Person.h"
class Friend : public Person {

public:
	Friend(std::string name, std::string position, int birthday, long int telephone, std::string email);
	virtual void ShowInformation();
	virtual std::string GetType();

};

