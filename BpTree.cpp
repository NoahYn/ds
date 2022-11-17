#include "BpTree.h"

bool BpTree::Insert(int key, set<string> set) {
	
	FrequentPatternNode* fpNode;

	if (root == NULL) { // first routine
		root = new BpTreeNode;
		fpNode = new FrequentPatternNode;
		fpNode->InsertList(set);
		root->insertDataMap(key, fpNode);
		return true;
	}

	BpTreeNode* search = searchDataNode(key);
	map<int,FrequentPatternNode*> *mapData = search->getDataMap();
	map<int,FrequentPatternNode*>::iterator iter = mapData->find(key);
	if (iter != mapData->end()) { // find same key
		fpNode = iter->second; // take node with same key
		fpNode->InsertList(set); // put in the same list
		return true;
	}

	// make new node
	fpNode = new FrequentPatternNode;
	fpNode->InsertList(set);
	search->insertDataMap(key, fpNode);

	if (excessDataNode(search)) {
		splitDataNode(search);
	}
	return true;
}

BpTreeNode* BpTree::searchDataNode(int key) {
	BpTreeNode* pCur = root;
	map<int,BpTreeNode*> *mapIndex = pCur->getIndexMap();
	map<int,BpTreeNode*>::iterator iter;
	int mostLeft;

	while (!mapIndex->empty()) {
		
		mostLeft = 1;
		for (iter = mapIndex->begin(); iter != mapIndex->end(); iter++) {
			if (key < iter->first) {
				break;
			}
			mostLeft = 0;
		}
		if (mostLeft == 1) {
			pCur = pCur->getMostLeftChild();
			mapIndex = pCur->getIndexMap();
		}
		else {
			iter--;
			pCur = iter->second;
			mapIndex = pCur->getIndexMap();
		}
	}

	return pCur;
}

void BpTree::splitDataNode(BpTreeNode* pDataNode) {
	if (excessIndexNode(pDataNode)) {
//		splitIndexNode();
	}
//	pDataNode->setMostLeftChild();
}
void BpTree::splitIndexNode(BpTreeNode* pIndexNode) {
	
}

bool BpTree::excessDataNode(BpTreeNode* pDataNode) {
	if (pDataNode->getDataMap()->size() > order - 1) return true;//order is equal to the number of elements 
	else return false;
}
bool BpTree::excessIndexNode(BpTreeNode* pIndexNode) {
	if (pIndexNode->getIndexMap()->size() > order - 1)return true;//order is equal to the number of elements 
	else return false;
}


bool BpTree::printConfidence(string item, double item_frequency, double min_confidence)
{

	return true;
}
bool BpTree::printFrequency(string item, int min_frequency)//print winratio in ascending order
{

	return true;
}
bool BpTree::printRange(string item, int min, int max) {

	return true;
}
void BpTree::printFrequentPatterns(set<string> pFrequentPattern) {
	*flog << "{";
	set<string> curPattern = pFrequentPattern;
	for (set<string>::iterator it = curPattern.begin(); it != curPattern.end();) {
		string temp = *it++;
		*flog << temp;
		if (it == curPattern.end()) {
			*flog << "} ";
			break;
		}
		*flog << ", ";
	}
}
