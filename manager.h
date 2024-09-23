#pragma once
#include"Identity.h"
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager : public Identity
{
public:
	Manager();
	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	vector<Student> vStu;

	vector<Teacher> vTea;

	bool checkRepeat(string id, int type);

	vector<computerRoom> vCom;

	void initVCom();

private:

};


