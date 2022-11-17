#pragma once
#include "FPNode.h"
#include <list>
#include <algorithm>

using namespace std;

class HeaderTable
{
private:
	list<pair<int, string>> indexTable;
	map<string, FPNode*> dataTable;
public:
	HeaderTable() {}
	~HeaderTable();
	void insertTable(string item, int frequency);
	list<pair<int, string>>* getindexTable() { return &indexTable; }
	map<string, FPNode*>* getdataTable() { return &dataTable; }
	FPNode* getNode(string item) { return dataTable.find(item)->second; }
	void descendingIndexTable() { indexTable.sort(greater<pair<int, string>>()); }
	void ascendingIndexTable() { indexTable.sort(less<pair<int, string>>()); }
	int find_frequency(string item);
};

