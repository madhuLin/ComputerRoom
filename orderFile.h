#pragma once
#include<iostream>
#include<map>
using namespace std;
#include<fstream>
#include"globaFile.h"

class OrderFile {
public:
	OrderFile();

	void updateOrder();

	map<int, map<string, string>> m_orderData;

	int m_size;
};
