#pragma once
#include "HeaderTable.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

class FPGrowth
{
private:
	int threshold;
	FPNode* fpTree;
	HeaderTable* table;
	map<set<string>,int> frequenctPatterns;
	ofstream fout;
	ofstream* flog;
public:
	FPGrowth(ofstream *flog, int threshold) {
		this->threshold = threshold;
		fout.open("result.txt", ios::app);
		fout.setf(ios::fixed);
		fpTree = new FPNode;  table = new HeaderTable;
		this->flog = flog;
	}

	~FPGrowth();
	void createTable(string item, int frequency) { table->insertTable(item, frequency); }
	void createFPtree(FPNode* root, HeaderTable* table, list<pair<int,string>> item_array, int frequency);
	void connectNode(HeaderTable* table, string item, FPNode* node);
	
	void frequenctPatternSetting() {
		table->ascendingIndexTable();
		frequenctPatterns = getFrequentPatterns(table, fpTree);
	}

	map<set<string>, int> getFrequentPatterns(HeaderTable* pTable, FPNode* pTree);
	void powerSet(map<set<string>, int>* FrequentPattern, vector<string> data, string item, int frequency, int* flag, int depth);
	bool contains_single_path(FPNode* pNode);
	int item_frequency(string item) {return table->find_frequency(item);}

	FPNode* getTree() { return fpTree; }
	HeaderTable* getHeaderTable() { return table; }

	bool printList();
	bool descendingList() {	table->descendingIndexTable(); } 
	bool printTree();
	void saveFrequentPatterns();

	};

