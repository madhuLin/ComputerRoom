#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(string empId, string name, string pwd)
{
	this->m_id = empId;
	this->m_name = name;
	this->m_password = pwd;
}

void Teacher::openMenu()
{
	cout << "�w��Юv" << m_name << "�n�J!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.�d�ݹw��    \t|\n";
	cout << "\t|\t2.�f�ֹw��\t|\n";
	//cout << "\t|\t3.�d�ݩҦ��w��\t|\n";
	//cout << "\t|\t4.�����w��    \t|\n";
	cout << "\t|\t0.�h�X�b��    \t|\n";
	cout << "\t-------------------------\n";
}

void Teacher::showAllOrder()
{
	OrderFile orderFile;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if (orderFile.m_orderData[i]["status"] != "0")
		{
			cout << " �w�����: �P" << orderFile.m_orderData[i]["data"];
			cout << " �ɬq: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "�W��" : "�U��");
			cout << " �Ǹ�:" << orderFile.m_orderData[i]["stuId"];
			cout << " �m�W: " << orderFile.m_orderData[i]["stuName"];
			cout << " ����: " << orderFile.m_orderData[i]["room"];

			string status = " ���A: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "�f�֤�!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "�f�֤��q�L!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "�f�ֳq�L!";
			//if (orderFile.m_orderData[i]["status"] == "0")
			//	status += "�w���w����!";
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
	return;
	
}

void Teacher::validOrder()
{
	OrderFile orderFile;
	if (orderFile.m_size == 0)
	{
		cout << "�L�w������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�п�ܭn�f�֭��@���w���A�p���f�ֽЫ� 0 " << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["status"]) == "1")
		{
			v.push_back(i);
			cout << index + 1 << " �w�����: �P" << orderFile.m_orderData[i]["data"];
			cout << " �ɬq: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "�W��" : "�U��");
			cout << " �Ǹ�:" << orderFile.m_orderData[i]["stuId"];
			cout << " �m�W: " << orderFile.m_orderData[i]["stuName"];
			cout << " ����: " << orderFile.m_orderData[i]["room"];

			string status = " ���A: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "�f�֤�!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "�f�֤��q�L!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "�f�ֳq�L!";
			//if (orderFile.m_orderData[i]["status"] == "0")
			//	status += "�w���w����!";
			cout << " ���A: " << status << endl;
			index++;
		}
	}
	int select;
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			system("pause");
			system("cls");
			return;
		}
		if (select >= 1 && select <= orderFile.m_size)
			break;
		cout << "���s�b���ﶵ�A�Э��s��J" << endl;
	}
	system("pause");
	system("cls");
	int sel;
	cout << "�п�J�f�ֵ��G" << endl;
	cout << "1.�q�L" << endl;
	cout << "2.���q�L" << endl;
	cin >> sel;
	if (sel == 1)
		orderFile.m_orderData[v[select-1]]["status"] = "2";
	else if (sel == 2)
		orderFile.m_orderData[v[select - 1]]["status"] = "-1";
	orderFile.updateOrder();
	cout << "�H���\�f��!" << endl;
	system("pause");
	system("cls");
	return;
}