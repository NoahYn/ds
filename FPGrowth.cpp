#include "FPGrowth.h"


FPGrowth::~FPGrowth() {

}

void FPGrowth::createFPtree(FPNode* root, HeaderTable* table, list<pair<int,string>> item_array, int frequency) {
	FPNode* curr = root;
	FPNode* find_child;
	list<pair<int,string>>::iterator iter;
	for (iter = item_array.begin(); iter != item_array.end(); iter++) {
		if (iter->first < threshold)
			continue;
		else {
			if (find_child = curr->getChildrenNode(iter->second)) { // find child with same item
				find_child->updateFrequency(1);
				curr = find_child;
				continue;
			}
			FPNode* fpChild = new FPNode; // add a new child
			fpChild->setParent(curr);
			fpChild->setNext(NULL);
			fpChild->updateFrequency(1);
			connectNode(table, iter->second, fpChild);
			curr->pushchildren(iter->second, fpChild);
			curr = fpChild;
		}
	}
}

void FPGrowth::connectNode(HeaderTable* table, string item, FPNode* node) {
	map<string, FPNode*> *dataTable = table->getdataTable();
	map<string, FPNode*>::iterator iter = dataTable->find(item);
	if (iter != dataTable->end()) { // find item!
		FPNode* curr = iter->second;
		while (curr->getNext()) {
			curr = curr->getNext();
		}
		curr->setNext(node);
	}
	else { // fail to find item
		dataTable->insert(pair<string, FPNode*>(item, node));
	}
	
}

bool FPGrowth::contains_single_path(FPNode* pNode) {
	if (pNode->getChildren().size() == 0) return true;
	else if (pNode->getChildren().size() > 1) return false;
	return contains_single_path(pNode->getChildren().begin()->second);
}

map<set<string>, int> FPGrowth::getFrequentPatterns(HeaderTable* pTable, FPNode* pTree) {

	return {};
}


void FPGrowth::powerSet(map<set<string>, int>* FrequentPattern, vector<string> data, string item, int frequency, int* ptr, int depth) {
	if (data.size() == depth) {
		set<string> set; set.insert(item);
		for (int i = 0; i < data.size(); i++) { if (ptr[i] == 1) set.insert(data[i]); }
		FrequentPattern->insert(make_pair(set, frequency)); return;
	}
	ptr[depth] = 1;
	powerSet(FrequentPattern, data, item, frequency, ptr, depth + 1);
	ptr[depth] = 0;
	powerSet(FrequentPattern, data, item, frequency, ptr, depth + 1);
}

bool FPGrowth::printList() {
	table->descendingIndexTable();
	list<pair<int,string>> *idx_table = table->getindexTable();
	list<pair<int,string>>::iterator iter;
	for (iter = idx_table->begin(); iter != idx_table->end(); iter++) {
		cout << iter->second << " " << iter->first << endl;
		*flog << iter->second << " " << iter->first << endl;
	}
	return true;
}

bool FPGrowth::printTree() {
	table->ascendingIndexTable();

	list<pair<int,string>> *idx = table->getindexTable();	
	list<pair<int,string>>::iterator iter;
	FPNode* curr;
	FPNode* curr_p;
	FPNode* parent;
	map<string, FPNode*> children;
	map<string, FPNode*>::iterator iter_item;
	string item;

	for (iter = idx->begin(); iter != idx->end(); iter++) {
		if (iter->first < threshold)
			continue;
		cout << "{" << iter->second << ", " << iter->first << "}\n";
		item = iter->second;
		curr = table->getNode(item);
		while (curr) { // move to next
			curr_p  = curr;
			while (curr_p != fpTree) { // move to parent
				parent = curr_p->getParent();
				children = parent->getChildren();
				iter_item = children.begin();
				if (iter_item->second == curr_p) {
					item = iter_item->first;
				}
				else {
					while (iter_item++ != children.end()) {
						if (iter_item->second == curr_p) {
							item = iter_item->first;
							break;
						}
					}
				}
				cout << "(" << item << ", " << curr_p->getFrequency() << ") ";	
				curr_p = parent;
			}
			cout << "\n";
			curr = curr->getNext();
		}
	}
	return true;
}

void FPGrowth::saveFrequentPatterns(){

}
