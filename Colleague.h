#pragma once
#include<iostream>
#include"Person.h"
class Colleague :public Person {
public:


	Colleague(std::string name, std::string firm, int birthday, long int telephone, std::string email);
	virtual void ShowInformation();
	virtual std::string GetType();
};