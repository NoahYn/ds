#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
//
//using namespace std;
//
//int main() {
//	ifstream result("result.txt"); 
//	int key;
//	string temp;
//	set<int> a;
//	set<int>::iterator iter;
//	pair<set<int>::iterator, bool> p;
//	
//	while (!result.eof()) // extract data from market.txt to itemsets, 
//	{
//		getline(result, temp);
//		stringstream ssrs(temp);
//		getline(ssrs, temp, '\t');
//		if (temp[0] < '0' || temp[0] > '9') { // exception for first word in a line is not a key
//			continue;
//		}
//		key = stoi(temp);
//		p = a.insert(key);
//		if (p.second == true) 
//			cout << key << "\t" << endl;
//
//	}	
//
////	set<int>::iterator iter;
////	for (iter = a.begin(); iter != a.end(); iter++)
////		cout << *iter << " ";
//
//}