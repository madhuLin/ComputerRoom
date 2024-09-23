#pragma once
#include<iostream>
#include"Identity.h"
#include<vector>
using namespace std;
#include"computerRoom.h"
#include<fstream>
#include"globaFile.h"
#include<algorithm>
#include"orderFile.h"

class Student : public Identity{
public:
	Student();

	Student(string id, string name, string pwd);

	virtual void openMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	vector<computerRoom> vCom;

	void initComputer();

	string m_id;

};
