#include<iostream>
using namespace std;
#include<fstream>
#include"Identity.h"
#include"globaFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"


void openMenu(Identity* &person, int type)
{
	while (true)
	{
		person->openMenu();
		cout << "請選擇功能:" << endl;
		int select;
		cin >> select;
		if (type == 1)
		{
			Student* stu = (Student*)person;
			switch (select)
			{
			case 1:
				//申請預約
				stu->applyOrder();
				break;
			case 2:
				//查看我的預約
				stu->showMyOrder();
				break;
			case 3:
				//查看所有預約
				stu->showAllOrder();
				break;
			case 4:
				//取消預約
				stu->cancelOrder();
				break;
			case 0:
				//退出登入
				delete stu;
				cout << "註銷成功" << endl;
				system("pause");
				system("cls");
				return;
			default:
				break;
			}
		}
		else if (type == 2)
		{
			Teacher* tea = (Teacher*)person;
			switch (select)
			{
			case 1:
				//申請預約
				tea->showAllOrder();
				break;
			case 2:
				//
				tea->validOrder();
				break;
			case 0:
				//退出登入
				delete tea;
				cout << "註銷成功" << endl;
				system("pause");
				system("cls");
				return;
			default:
				break;
			}
		}
		else
		{
			Manager* man = (Manager*)person;
			switch (select)
			{
			case 1:
				//添加帳號
				man->addPerson();
				break;
			case 2:
				//查看帳號
				man->showPerson();
				break;
			case 3:
				//查看電腦
				man->showComputer();
				break;
			case 4:
				//清空預約
				man->cleanFile();
				break;
			case 0:
				//退出登入
				delete man;
				cout << "註銷成功" << endl;
				system("pause");
				system("cls");
				return;
			default:
				break;
			}//end switch
		}
	}//end while (true)	
	return;
}

void LoingIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "找不到此檔案" << endl;
		ifs.close();
		return;
	}

	string id, name, pwd;
	if (type == 1)
	{
		cout << "請輸入您的學號" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "請輸入您的教師號" << endl;
		cin >> id;
	}
	else if (type == 3)
	{
		cout << "請輸入帳戶名稱" << endl;
		cin >> id;
	}
	//cout << "請輸入用戶名" << endl;
	//cin >> name;
	cout << "請輸入密碼" << endl;
	cin >> pwd;

	//determine login
	string fId, fName, fPwd;
	if (type == 1)
	{
		while (ifs>>fId && ifs>>fPwd && ifs>>name)
		{
			if (fId == id && fPwd == pwd)
			{
				cout << "登入成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//進入子菜單
				openMenu(person, type);

				return;
			}
		}
	}
	if (type == 2)
	{
		while (ifs >> fId && ifs >> fPwd && ifs >> name)
		{
			if (fId == id && fPwd == pwd)
			{
				cout << "登入成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//進入子菜單
				openMenu(person, type);
			}
		}
	}
	if (type == 3)
	{
		while (ifs >> fId && ifs >> fPwd && ifs >> name)
		{
			if (fId == id && fPwd == pwd)
			{
				cout << "登入成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//進入子菜單
				openMenu(person, type);
				return;
			}
		}
	}
	cout << "登入失敗" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
		cout << "歡迎使用機房管理系統!" << endl;
		cout << "請輸入您的身分" << endl;
		cout << "\t-------------------------" << endl;
		cout << "\t|\t1.學生  \t|\n";
		cout << "\t|\t2.老師  \t|\n";
		cout << "\t|\t3.管理員\t|\n";
		cout << "\t|\t0.退出  \t|\n";
		cout << "\t-------------------------" << endl;
		cout << "請輸入您的選擇" << endl;
		cin >> select;
		switch (select)
		{
		case 1://student login
			LoingIn(STUDENT_FILE, select);
			break;
		case 2:// teacher login
			LoingIn(TEACHER_FILE, select);
			break;
		case 3://administrator login
			LoingIn(ADMIN_FILE, select);
			break;
		case 0:

			break;
		default:
			cout << "輸入錯誤請重新選擇" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}