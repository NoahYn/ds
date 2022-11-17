#pragma once
#include "FPGrowth.h"
#include "BpTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;


class Manager
{
private:
	int threshold;
	int bpOrder;
	string cmd;
	vector<string> option;
	FPGrowth* fpgrowth;
	BpTree* bptree;
public:
	Manager(int threshold, int bpOrder)	//constructor
	{
		this->threshold = threshold;
		this->bpOrder = bpOrder;
		fpgrowth = NULL;
		bptree = NULL;
	}

	~Manager()//destructor
	{
		/* You must fill here */
	}

	ifstream fin;
	ofstream flog;

	void run(const char* cmd_txt);
	bool LOAD();
	bool BTLOAD();
	
	bool PRINT_ITEMLIST();
	bool PRINT_FPTREE();

	bool PRINT_RANGE(string item, int start, int end);
	bool PRINT_CONFIDENCE(string item, double rate);
	bool PRINT_BPTREE(string item, int min_frequency);


	void printErrorCode(int n);
	void printSuccessCode();
	
};

