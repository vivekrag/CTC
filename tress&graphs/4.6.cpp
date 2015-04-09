#include <iostream>
#include <cstring>
#include <list>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int maxn = 100;
int cnt;
struct Node{
	int key;
	Node* lchild;
	Node* rchild;
	Node* parent;
};
Node node[maxn];

void init(){
	cnt = 0;
	memset(node, '\0', sizeof(node));
}

void createMinTree(Node* &head, Node* parent, int arr[], int start, int end){
	if(start <= end){
		int mid = (start+end)/2;
		node[cnt].key = arr[mid];
		node[cnt].parent = parent;
		head = &node[cnt++];
		createMinTree(head->lchild, head, arr, start, mid-1);
		createMinTree(head->rchild, head, arr, mid+1, end);
	}
}

Node* searchNode(int val, Node* head){
	if(head == NULL)
		return NULL;
	if(head->key == val)
		return head;
	if(val<head->key)
		searchNode(val, head->lchild);
	else
		searchNode(val, head->rchild);
}

Node* minRight(Node* n){
	while(n->lchild!=NULL)
		n=n->lchild;
	return n;
}

Node* inOrderSuccessor(Node* n){
	if(n==NULL)
		return NULL;
	if(n->rchild!=NULL)
		minRight(n->rchild);
	else{
		Node* q=n;
		Node* p=q->parent;
		while(p!=NULL && (q!=p->lchild)){
			q=p;
			p=p->parent;
		}
		if(p==NULL){
			cout << "no ancestor found";
			return NULL;
		}
		return p;
	}
}

int main(){
	Node* head = NULL;
	init();
	int arr[]= {0,1,2,3,4,5,6,7,8,9};
	createMinTree(head, NULL, arr, 0, 9);
	Node* n = searchNode(9, head);
	Node* s = inOrderSuccessor(n);
	cout << "InOrderSuccessor of " << n->key << " is " << s->key;
	return 0;
}