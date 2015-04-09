#include <iostream>
#include <cstring>
#include <list>
#include <cmath>
#include <vector>
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

bool matchTree(Node* s, Node* t){
	if(s==NULL && t== NULL)
		return true;
	if(s==NULL || t==NULL)
		return false;
	if(s->key!=t->key)
		return false;
	return(matchTree(s->lchild,t->lchild) && matchTree(s->rchild,t->rchild));
}

bool subTreeUtil(Node* s, Node* t){
	if(s==NULL)
		return false;
	if(s->key == t->key)
		return(matchTree(s,t));
	return (subTreeUtil(s->lchild, t)||subTreeUtil(s->rchild, t));
}
	
bool subTree(Node* s, Node* t){
	if(t==NULL)
		return true;
	subTreeUtil(s,t);
}

int main(){
	init();
	Node* head1=NULL;
	Node* head2=NULL;
	int a[]={1,2,3,4,5,6,7,8,9};
	int b[]={1,2,3,4,5,6};
	createMinTree(head1, NULL, a, 0, 8);
	createMinTree(head2, NULL, b, 0, 3);
	subTree(head1, head2)? cout << "yes": cout << "no";
	return 0;
}