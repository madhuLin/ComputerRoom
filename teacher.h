#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;
#include"orderFile.h"
#include<vector>

class Teacher:public Identity{
public:
	Teacher();

	Teacher(string empId, string name, string pwd);

	virtual void openMenu();

	void showAllOrder();

	void validOrder();

	string m_id;

};