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
	cout << "歡迎管理員" << m_name << "登入!" << endl;
	cout << "\t-------------------------\n";
	cout << "\t|\t1.添加帳號\t|\n";
	cout << "\t|\t2.顯示帳號\t|\n";
	cout << "\t|\t3.查看機房\t|\n";
	cout << "\t|\t4.清空預約\t|\n";
	cout << "\t|\t0.退出帳戶\t|\n";
	cout << "\t-------------------------\n";
}

void Manager::addPerson()
{
	string fileName, tip, errorTip;
	ofstream ofs;

	cout << "您要添加的帳號類型" << endl;
	cout << "1.添加學生\n";
	cout << "2.添加老師\n";
	int select = 0;
	while (select != 1 && select != 2)
	{
		cin >> select;
		if (select == 1)
		{
			tip = "請輸入學號";
			fileName = STUDENT_FILE;
			errorTip = "學生號重複!請重新輸入!";
		}
		else if (select == 2)
		{
			tip = "請輸入教師號";
			fileName = TEACHER_FILE;
			errorTip = "教師號重覆!請重新輸入!";
		}
		else
			cout << "輸入錯誤! 請重新選擇" << endl;
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
	cout << "請輸入密碼" << endl;
	cin >> pwd;
	cout << "請輸入姓名" << endl;
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
	cout << "請選擇查看內容" << endl;
	cout << "1.查看所有學生訊息!" << endl;
	cout << "2.查看所有老師訊息!" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "學生訊息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printvStu);
	}
	else if (select == 2)
	{
		cout << "老師訊息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printvTea);
	}
	else
		cout << "輸入錯誤! 請重新選擇" << endl;
	system("pause");
	system("cls");
	return;
}

void printComputer(computerRoom &c)
{
	cout << c.m_ComId << "號機房 電腦數:" << c.m_MaxNum << endl;
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
	cout << "成功清空預約紀錄!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVCom()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "檔案不存在" << endl;
		return;
	}
	computerRoom c;
	while (ifs>>c.m_ComId && ifs>>c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "當前機房數量" << vCom.size() << endl;
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
		cout << "文件讀取失敗!" << endl;
		ifs.close();
		return;
	}
	vStu.clear();
	Student s;
	while (ifs>>s.m_id && ifs>>s.m_password && ifs>>s.m_name)
	{
		vStu.push_back(s);
	}
	//cout << "學生數量:" << vStu.size() << endl;
	ifs.close();

	
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件讀取失敗!" << endl;
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
	//cout << "老師數量:" << vTea.size()<<endl;
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