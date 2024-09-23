#include<iostream>
#pragma once
using namespace std;

class Identity {
public:
	virtual void openMenu() = 0;
	string m_name;
	string m_password;
};