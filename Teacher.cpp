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
	cout << "歡迎教師" << m_name << "登入!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.查看預約    \t|\n";
	cout << "\t|\t2.審核預約\t|\n";
	//cout << "\t|\t3.查看所有預約\t|\n";
	//cout << "\t|\t4.取消預約    \t|\n";
	cout << "\t|\t0.退出帳戶    \t|\n";
	cout << "\t-------------------------\n";
}

void Teacher::showAllOrder()
{
	OrderFile orderFile;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if (orderFile.m_orderData[i]["status"] != "0")
		{
			cout << " 預約日期: 周" << orderFile.m_orderData[i]["data"];
			cout << " 時段: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << " 學號:" << orderFile.m_orderData[i]["stuId"];
			cout << " 姓名: " << orderFile.m_orderData[i]["stuName"];
			cout << " 機房: " << orderFile.m_orderData[i]["room"];

			string status = " 狀態: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "審核中!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "審核不通過!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "審核通過!";
			//if (orderFile.m_orderData[i]["status"] == "0")
			//	status += "預約已取消!";
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
		cout << "無預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "請選擇要審核哪一條預約，如不審核請按 0 " << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["status"]) == "1")
		{
			v.push_back(i);
			cout << index + 1 << " 預約日期: 周" << orderFile.m_orderData[i]["data"];
			cout << " 時段: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << " 學號:" << orderFile.m_orderData[i]["stuId"];
			cout << " 姓名: " << orderFile.m_orderData[i]["stuName"];
			cout << " 機房: " << orderFile.m_orderData[i]["room"];

			string status = " 狀態: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "審核中!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "審核不通過!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "審核通過!";
			//if (orderFile.m_orderData[i]["status"] == "0")
			//	status += "預約已取消!";
			cout << " 狀態: " << status << endl;
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
		cout << "不存在此選項，請重新輸入" << endl;
	}
	system("pause");
	system("cls");
	int sel;
	cout << "請輸入審核結果" << endl;
	cout << "1.通過" << endl;
	cout << "2.不通過" << endl;
	cin >> sel;
	if (sel == 1)
		orderFile.m_orderData[v[select-1]]["status"] = "2";
	else if (sel == 2)
		orderFile.m_orderData[v[select - 1]]["status"] = "-1";
	orderFile.updateOrder();
	cout << "以成功審核!" << endl;
	system("pause");
	system("cls");
	return;
}