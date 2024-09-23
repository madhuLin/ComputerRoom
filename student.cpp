#include"student.h"

Student::Student()
{

}

Student::Student(string id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_password = pwd;
	this->initComputer();
}

void Student::openMenu()
{
	cout << "�w��ǥͥN��" << m_name << "�n�J!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.�ӽйw��    \t|\n";
	cout << "\t|\t2.�d�ݧڪ��w��\t|\n";
	cout << "\t|\t3.�d�ݩҦ��w��\t|\n";
	cout << "\t|\t4.�����w��    \t|\n";
	cout << "\t|\t0.�h�X�b��    \t|\n";
	cout << "\t-------------------------\n";
}

void printvCom(computerRoom &c)
{
	cout << c.m_ComId << "������ �q����:" << c.m_MaxNum << endl;
}

void Student::applyOrder()
{
	int data, interval, room;
	cout << "�q���ЫǶ}��ɶ����P�@�ܩP��!" << endl;
	cout << "�п�J�ӽйw�����ɶ�:" << endl;
	cout << "1.�P�@" << endl;
	cout << "2.�g�G" << endl;
	cout << "3.�g�T" << endl;
	cout << "4.�g�|" << endl;
	cout << "5.�g��" << endl;
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
			break;
		cout << "��J���~�Э��s��J!" << endl;
	}
	cout << "�п�J���w���ɬq" << endl;
	cout << "1.�W��" << endl;
	cout << "2.�U��" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		cout << "��J���~�Э��s��J!" << endl;
	}

	cout << "�п�ܾ���" << endl;
	for_each(vCom.begin(), vCom.end(), printvCom);
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= (int)vCom.size())
			break;
		cout << "��J���~�Э��s��J!" << endl;
	}
	cout << "�w�����\!�f�֤�" << endl;
	system("cls");

	//write file
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	//ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " ";
	ofs << "stuId:" << m_id << " " << "stuName:" << m_name << " ";
	ofs << "room:" << room <<" "<<"status:"<<1<< endl;
	ofs.close();
	cout << "�z�w���F�P��" << data << (interval == 1 ? "�W��" : "�U��") << room << "������" << endl;

	system("pause");
	system("cls");
	return;
}

void Student::showMyOrder()
{
	OrderFile orderFile;
	if (orderFile.m_size == 0)
	{
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["stuId"]) == m_id)
		{
			cout << "�ǥ�"<<m_name <<"�z�n!" << " �w�����: �P" << orderFile.m_orderData[i]["data"];
			cout << " �ɬq: " << ((orderFile.m_orderData[i]["interval"] == "1")?"�W��" : "�U��");
			cout << " ����: " << orderFile.m_orderData[i]["room"];

			string status = " ���A: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "�f�֤�!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "�f�֤��q�L!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "�f�ֳq�L!";
			if (orderFile.m_orderData[i]["status"] == "0")
				status += "�w���w����!";
			cout << status << endl;

		}
	}
	system("pause");
	system("cls");
	return;
}

void Student::showAllOrder()
{
	OrderFile orderFile;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		/*if (orderFile.m_orderData[i]["status"] != "0")
		{*/
			cout << i + 1 << " �w�����: �P" << orderFile.m_orderData[i]["data"];
			cout << " �ɬq: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "�W��" : "�U��");
			cout << " ����: " << orderFile.m_orderData[i]["room"];

			string status = " ���A: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "�f�֤�!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "�f�֤��q�L!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "�f�ֳq�L!";
			if (orderFile.m_orderData[i]["status"] == "0")
				status += "�w���w����!";
			cout <<status << endl;
		//}
	}
	system("pause");
	system("cls");
	return;
}

void Student::cancelOrder()
{
	OrderFile orderFile;
	if (orderFile.m_size == 0)
	{
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�п�ܭn�������@���w���A�p�������Ы� 0 " << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["stuId"]) == m_id)
		{
			if ((orderFile.m_orderData[i]["status"]) == "1" || (orderFile.m_orderData[i]["status"]) == "2")
			{
				v.push_back(i);
				cout << index + 1 << " �w�����: �P" << orderFile.m_orderData[i]["data"];
				cout << " �ɬq: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "�W��" : "�U��");
				cout << " ����: " << orderFile.m_orderData[i]["room"];

				string status = " ���A: ";
				if (orderFile.m_orderData[i]["status"] == "1")
					status += "�f�֤�!";
				if (orderFile.m_orderData[i]["status"] == "-1")
					status += "�f�֤��q�L!";
				if (orderFile.m_orderData[i]["status"] == "2")
					status += "�f�ֳq�L!";
				if (orderFile.m_orderData[i]["status"] == "0")
					status += "�w���w����!";
				cout << " ���A: " << status << endl;
				index++;
			}
		}
	}
	int select;
	while (true)
	{
		cin >> select;
		if (select >= 1 && select <= (int)v.size())
			break;
		if (select == 0)
		{
			system("pause");
			system("cls");
			return;
		}
		cout << "���s�b���ﶵ�A�Э��s��J" << endl;
	}
	orderFile.m_orderData[v[select - 1]]["status"] = "0";
	orderFile.updateOrder();
	cout << "�H���\����!" << endl;
	system("pause");
	system("cls");
	return;

}

void Student::initComputer()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ɮפ��s�b" << endl;
		return;
	}
	computerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "��e���мƶq" << vCom.size() << endl;
	ifs.close();
}

