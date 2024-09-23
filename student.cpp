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
	cout << "歡迎學生代表" << m_name << "登入!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.申請預約    \t|\n";
	cout << "\t|\t2.查看我的預約\t|\n";
	cout << "\t|\t3.查看所有預約\t|\n";
	cout << "\t|\t4.取消預約    \t|\n";
	cout << "\t|\t0.退出帳戶    \t|\n";
	cout << "\t-------------------------\n";
}

void printvCom(computerRoom &c)
{
	cout << c.m_ComId << "號機房 電腦數:" << c.m_MaxNum << endl;
}

void Student::applyOrder()
{
	int data, interval, room;
	cout << "電腦教室開放時間為周一至周五!" << endl;
	cout << "請輸入申請預約的時間:" << endl;
	cout << "1.周一" << endl;
	cout << "2.週二" << endl;
	cout << "3.週三" << endl;
	cout << "4.週四" << endl;
	cout << "5.週五" << endl;
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
			break;
		cout << "輸入錯誤請重新輸入!" << endl;
	}
	cout << "請輸入欲預約時段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		cout << "輸入錯誤請重新輸入!" << endl;
	}

	cout << "請選擇機房" << endl;
	for_each(vCom.begin(), vCom.end(), printvCom);
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= (int)vCom.size())
			break;
		cout << "輸入錯誤請重新輸入!" << endl;
	}
	cout << "預約成功!審核中" << endl;
	system("cls");

	//write file
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	//ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " ";
	ofs << "stuId:" << m_id << " " << "stuName:" << m_name << " ";
	ofs << "room:" << room <<" "<<"status:"<<1<< endl;
	ofs.close();
	cout << "您預約了星期" << data << (interval == 1 ? "上午" : "下午") << room << "號機房" << endl;

	system("pause");
	system("cls");
	return;
}

void Student::showMyOrder()
{
	OrderFile orderFile;
	if (orderFile.m_size == 0)
	{
		cout << "無預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["stuId"]) == m_id)
		{
			cout << "學生"<<m_name <<"您好!" << " 預約日期: 周" << orderFile.m_orderData[i]["data"];
			cout << " 時段: " << ((orderFile.m_orderData[i]["interval"] == "1")?"上午" : "下午");
			cout << " 機房: " << orderFile.m_orderData[i]["room"];

			string status = " 狀態: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "審核中!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "審核不通過!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "審核通過!";
			if (orderFile.m_orderData[i]["status"] == "0")
				status += "預約已取消!";
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
			cout << i + 1 << " 預約日期: 周" << orderFile.m_orderData[i]["data"];
			cout << " 時段: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << " 機房: " << orderFile.m_orderData[i]["room"];

			string status = " 狀態: ";
			if (orderFile.m_orderData[i]["status"] == "1")
				status += "審核中!";
			if (orderFile.m_orderData[i]["status"] == "-1")
				status += "審核不通過!";
			if (orderFile.m_orderData[i]["status"] == "2")
				status += "審核通過!";
			if (orderFile.m_orderData[i]["status"] == "0")
				status += "預約已取消!";
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
		cout << "無預約紀錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "請選擇要取消哪一條預約，如不取消請按 0 " << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < orderFile.m_size; i++)
	{
		if ((orderFile.m_orderData[i]["stuId"]) == m_id)
		{
			if ((orderFile.m_orderData[i]["status"]) == "1" || (orderFile.m_orderData[i]["status"]) == "2")
			{
				v.push_back(i);
				cout << index + 1 << " 預約日期: 周" << orderFile.m_orderData[i]["data"];
				cout << " 時段: " << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
				cout << " 機房: " << orderFile.m_orderData[i]["room"];

				string status = " 狀態: ";
				if (orderFile.m_orderData[i]["status"] == "1")
					status += "審核中!";
				if (orderFile.m_orderData[i]["status"] == "-1")
					status += "審核不通過!";
				if (orderFile.m_orderData[i]["status"] == "2")
					status += "審核通過!";
				if (orderFile.m_orderData[i]["status"] == "0")
					status += "預約已取消!";
				cout << " 狀態: " << status << endl;
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
		cout << "不存在此選項，請重新輸入" << endl;
	}
	orderFile.m_orderData[v[select - 1]]["status"] = "0";
	orderFile.updateOrder();
	cout << "以成功取消!" << endl;
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
		cout << "檔案不存在" << endl;
		return;
	}
	computerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "當前機房數量" << vCom.size() << endl;
	ifs.close();
}

