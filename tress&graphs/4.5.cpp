#include <iostream>
#include <cstring>
using namespace std;
const int maxn=100;
const int MINVAL = -1;
const int MAXVAL = 100;
int lastValue = -1;
struct Node{
	int key;
	Node* lchild;
	Node* rchild;
	Node* parent;
};
Node node[maxn];
int cnt;

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

bool isBST(Node* head){
	if(head==NULL)
		return true;
	if(!isBST(head->lchild))
		return false;
	if(head->key <= lastValue)
		return false;
	lastValue = head->key;
	if(!isBST(head->rchild))
		return false;
	return true;
}

bool isBST1(Node* head,int MINVAL, int MAXVAL){
	if(head == NULL)
		return true;
	if(head->key<MINVAL || head->key>MAXVAL)
		return false;
	if(!isBST1(head->lchild, MINVAL, head->key-1)||!isBST1(head->rchild, head->key+1, MAXVAL))
		return false;
	return true;
}

int main(){
	init();
	Node* head=NULL;
	int arr[]={0,1,2,3,4,5,6,7,7,8,9};
	createMinTree(head, NULL, arr, 0, 9);
	isBST1(head, MINVAL, MAXVAL)?cout << "yes":cout << "no";
	cout << endl;
	isBST(head)?cout << "yes":cout << "no";;
}	