#include"manager.h"
#include"globaFile.h"

Manager::Manager()
{
	
}
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_password = pwd;
	this->initVector();
	this->initVCom();
}

void Manager::openMenu()
{
	cout << "�w��޲z��" << m_name << "�n�J!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.�K�[�b��\t|\n";
	cout << "\t|\t2.��ܱb��\t|\n";
	cout << "\t|\t3.�d�ݾ���\t|\n";
	cout << "\t|\t4.�M�Źw��\t|\n";
	cout << "\t|\t0.�h�X�b��\t|\n";
	cout << "\t-------------------------\n";
}

void Manager::addPerson()
{
	string fileName, tip, errorTip;
	ofstream ofs;

	cout << "�z�n�K�[���b������" << endl;
	cout << "1.�K�[�ǥ�\n";
	cout << "2.�K�[�Ѯv\n";
	int select = 0;
	while (select != 1 && select != 2)
	{
		cin >> select;
		if (select == 1)
		{
			tip = "�п�J�Ǹ�";
			fileName = STUDENT_FILE;
			errorTip = "�ǥ͸�����!�Э��s��J!";
		}
		else if (select == 2)
		{
			tip = "�п�J�Юv��";
			fileName = TEACHER_FILE;
			errorTip = "�Юv������!�Э��s��J!";
		}
		else
			cout << "��J���~! �Э��s���" << endl;
	}

	ofs.open(fileName, ios::out | ios::app);
	string id, pwd, name;
	while (true)
	{
		cout << tip << endl;
		cin >> id;
		if (!checkRepeat(id, select))
			break;
		cout << errorTip << endl;
	}
	cout << "�п�J�K�X" << endl;
	cin >> pwd;
	cout << "�п�J�m�W" << endl;
	cin >> name;

	ofs << id << " " << pwd << " " << name << endl;
	ofs.close();
	this->initVector();
	system("pause");
	system("cls");
}

void printvStu(Student &s)
{
	cout << "Id:" << s.m_id << "  Password:" << s.m_password << "  Name:" << s.m_name << endl;
}
void printvTea(Teacher &t)
{
	cout << "Id:" << t.m_id << "  Password:" << t.m_password << "  Name:" << t.m_name << endl;
}

void Manager::showPerson()
{
	cout << "�п�ܬd�ݤ��e" << endl;
	cout << "1.�d�ݩҦ��ǥͰT��!" << endl;
	cout << "2.�d�ݩҦ��Ѯv�T��!" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "�ǥͰT���p�U" << endl;
		for_each(vStu.begin(), vStu.end(), printvStu);
	}
	else if (select == 2)
	{
		cout << "�Ѯv�T���p�U" << endl;
		for_each(vTea.begin(), vTea.end(), printvTea);
	}
	else
		cout << "��J���~! �Э��s���" << endl;
	system("pause");
	system("cls");
	return;
}

void printComputer(computerRoom &c)
{
	cout << c.m_ComId << "������ �q����:" << c.m_MaxNum << endl;
}

void Manager::showComputer()
{
	for_each(vCom.begin(), vCom.end(), printComputer);
	system("pause");
	system("cls");
	return;
}

void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "���\�M�Źw������!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVCom()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ɮפ��s�b" << endl;
		return;
	}
	computerRoom c;
	while (ifs>>c.m_ComId && ifs>>c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "��e���мƶq" << vCom.size() << endl;
	ifs.close();
	/*system("pause");
	system("cls");
	return;*/
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "���Ū������!" << endl;
		ifs.close();
		return;
	}
	vStu.clear();
	Student s;
	while (ifs>>s.m_id && ifs>>s.m_password && ifs>>s.m_name)
	{
		vStu.push_back(s);
	}
	//cout << "�ǥͼƶq:" << vStu.size() << endl;
	ifs.close();

	
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "���Ū������!" << endl;
		ifs.close();
		return;
	}
	vTea.clear();
	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_password && ifs >> t.m_name)
	{
		vTea.push_back(t);
	}
	ifs.close();
	//cout << "�Ѯv�ƶq:" << vTea.size()<<endl;
}//end initVector()

bool Manager::checkRepeat(string id, int type)
{
	if (type == 1)
	{
		for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_id == id)
				return true;
		}
	}
	else
	{
		for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_id == id)
				return true;
		}
	}
		return false;
}