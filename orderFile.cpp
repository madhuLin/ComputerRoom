#include"orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data, interval, stuId, name, room, status;
	string key, value;
	int pos;
	this->m_size = 0;
	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> name && ifs >> room && ifs >> status)
	{
		map<string, string> m;
		pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1);
			m.insert(make_pair(key, value));
		}
		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos);
			value = name.substr(pos + 1);
			m.insert(make_pair(key, value));
		}
		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(m_size, m));
		m_size++;
	}//end while
	ifs.close();

	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "±ø¼Æ¬°:" << it->first << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
	//	{
	//		cout << "key: " << mit->first << "  value: " << mit->second << endl;
	//	}
	//	cout << endl;
	//}
}//end OrderFile::OrderFile()

void OrderFile::updateOrder()
{
	if (m_size == 0)
		return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "data:" << m_orderData[i]["data"] << " ";
		ofs << "interval:"<< m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderData[i]["stuName"] << " ";
		ofs << "room:" << m_orderData[i]["room"] << " ";
		ofs << "status:" << m_orderData[i]["status"] << " " << endl;
	}
	ofs.close();
}