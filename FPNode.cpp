#include "FPNode.h"

FPNode::FPNode()	//constructor
{
	parent = NULL;
	next = NULL;
	frequency = 0;
}


FPNode::~FPNode()//destructor
{

}

FPNode* FPNode::getChildrenNode(string item) {
	map<string, FPNode*>::iterator iter = children.find(item);
	if (iter == children.end()) return NULL; 
	FPNode* findNode = iter->second;
	return findNode;
}


