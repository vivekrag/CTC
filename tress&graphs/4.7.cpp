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
Node* searchNode(int key, Node* head){
	if(head == NULL)
		return NULL;
	if(head->key == key)
		return head;
	if(head->key <= key)
		searchNode(key, head->rchild);
	else
		searchNode(key, head->lchild);		
}
// time complexity is O(N) on a balanced tree

Node* commonAncestor(Node* head, int key1, int key2){
    Node* n1 = searchNode(key1, head);
    Node* n2 = searchNode(key2, head);
    map<Node*, bool> m;
    while(n1){
    	m[n1]=true;
    	n1=n1->parent;
    }
    while(m[n2]==false && n2!=NULL){
    	n2=n2->parent;
    }
    return n2;
}

bool Ancestor(Node* p, Node*q){
	if(p==NULL)
		return false;
	if(p==q)
		return true;
	return(Ancestor(p->lchild, q)||Ancestor(p->rchild, q));
}

void commonAncestor1Util(Node* head, Node* s, Node* t, Node* &ans){
	if(head==NULL || s==NULL || t==NULL)
		return;
	ans = head;
	if(Ancestor(head->lchild, s) && Ancestor(head->lchild,t))
		commonAncestor1Util(head->lchild, s, t, ans);
	if(Ancestor(head->rchild, s))
		commonAncestor1Util(head->rchild, s, t, ans);
}

void commonAncestor1(Node* head, Node* s, Node* t, Node* &ans){
	if(head==NULL)
		return;
	if(s==head||t==head){
		ans = head;
		return;
	}
	commonAncestor1Util(head, s, t, ans);
}

int main(){
	init();
	Node* head=NULL;
	Node* ans = NULL;
	int a[]={0,1,2,3,4,5,6,7,8,9};
	createMinTree(head, NULL, a, 9, 9);
	Node* ca=commonAncestor(head, 9,9);
	Node* s = searchNode(0, head);
    Node* t = searchNode(9, head);
    commonAncestor1(head, s, t, ans);
	cout << "commonAncestor is " << ca->key << endl;
	cout << "commonAncestor is " << ans->key;
	return 0;
}