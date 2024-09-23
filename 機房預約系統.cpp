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
		cout << "�п�ܥ\��:" << endl;
		int select;
		cin >> select;
		if (type == 1)
		{
			Student* stu = (Student*)person;
			switch (select)
			{
			case 1:
				//�ӽйw��
				stu->applyOrder();
				break;
			case 2:
				//�d�ݧڪ��w��
				stu->showMyOrder();
				break;
			case 3:
				//�d�ݩҦ��w��
				stu->showAllOrder();
				break;
			case 4:
				//�����w��
				stu->cancelOrder();
				break;
			case 0:
				//�h�X�n�J
				delete stu;
				cout << "���P���\" << endl;
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
				//�ӽйw��
				tea->showAllOrder();
				break;
			case 2:
				//
				tea->validOrder();
				break;
			case 0:
				//�h�X�n�J
				delete tea;
				cout << "���P���\" << endl;
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
				//�K�[�b��
				man->addPerson();
				break;
			case 2:
				//�d�ݱb��
				man->showPerson();
				break;
			case 3:
				//�d�ݹq��
				man->showComputer();
				break;
			case 4:
				//�M�Źw��
				man->cleanFile();
				break;
			case 0:
				//�h�X�n�J
				delete man;
				cout << "���P���\" << endl;
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
		cout << "�䤣�즹�ɮ�" << endl;
		ifs.close();
		return;
	}

	string id, name, pwd;
	if (type == 1)
	{
		cout << "�п�J�z���Ǹ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "�п�J�z���Юv��" << endl;
		cin >> id;
	}
	else if (type == 3)
	{
		cout << "�п�J�b��W��" << endl;
		cin >> id;
	}
	//cout << "�п�J�Τ�W" << endl;
	//cin >> name;
	cout << "�п�J�K�X" << endl;
	cin >> pwd;

	//determine login
	string fId, fName, fPwd;
	if (type == 1)
	{
		while (ifs>>fId && ifs>>fPwd && ifs>>name)
		{
			if (fId == id && fPwd == pwd)
			{
				cout << "�n�J���\" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//�i�J�l���
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
				cout << "�n�J���\" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�i�J�l���
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
				cout << "�n�J���\" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�i�J�l���
				openMenu(person, type);
				return;
			}
		}
	}
	cout << "�n�J����" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
		cout << "�w��ϥξ��к޲z�t��!" << endl;
		cout << "�п�J�z������" << endl;
		cout << "\t-------------------------" << endl;
		cout << "\t|\t1.�ǥ�  \t|\n";
		cout << "\t|\t2.�Ѯv  \t|\n";
		cout << "\t|\t3.�޲z��\t|\n";
		cout << "\t|\t0.�h�X  \t|\n";
		cout << "\t-------------------------" << endl;
		cout << "�п�J�z�����" << endl;
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
			cout << "��J���~�Э��s���" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}