#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 100; // size of tree nodes
int cnt;              // index of tree nodes
struct Node{
	int key;
	Node* parent;
	Node* lchild;
	Node* rchild;
};
Node* p;
Node* head; 
Node node[maxn];

void init(){
	p = NULL;
	head = NULL;
	memset(node, '\0', sizeof(node));
	cnt = 0;
}

void insert(Node* &head, int val){
	if(head == NULL){
		node[cnt].key = val;
		node[cnt].parent = p;
		head = &node[cnt++];
		return;
	}
	p = head;
	if(val < head->key)
		insert(head->lchild, val);
	else
		insert(head->rchild, val);
}