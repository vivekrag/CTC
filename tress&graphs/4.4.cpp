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
Node* p;
Node node[maxn];

void init(){
	cnt = 0;
	p = NULL;
	memset(node, '\0', sizeof(node));
}

void createMinHeightTree(Node* &head, Node* parent, int arr[], int start, int end){
	if(start<=end){
	int mid = (start+end)/2;
	node[cnt].key = arr[mid];
	node[cnt].parent = parent;
	head = &node[cnt++];
	createMinHeightTree(head->lchild, head, arr, start, mid-1);
	createMinHeightTree(head->rchild, head, arr, mid+1, end);
	}
	return;
}

int height(Node* head){
	if(head == NULL)
		return 0;
	else
	 	return(1+max(height(head->lchild), height(head->rchild)));
}

bool findPathSum(Node* head, int sum){
	if(head == NULL && sum != 0)
		return false;
	if(sum == 0)
		return true;
	else{
		int subSum = sum - head->key;
		return(findPathSum(head->lchild, subSum) || findPathSum(head->rchild, subSum));
	}
}
void printPath1(Node* head, int level){
	vector<int> v;
	for(int i=0; i<level; i++){
		v.push_back(head->key);
		head = head->parent;
	}
	while(!v.empty()){
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << endl;
}

void pathSumAny1(Node* head, int sum){
	if(head == NULL)
		return;
	Node* no = head;
	int temp=0;
	for(int i=0; no!=NULL; i++){
		temp+=no->key;
		if(temp == sum){
			printPath1(head, i+1);
		}
		no = no->parent;	
	}
	pathSumAny1(head->lchild, sum);
	pathSumAny1(head->rchild, sum);
}

void printPath(vector<int> v, int level){
	for(int i=level; i<v.size(); i++){
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void pathSumAny(Node* head, int sum, int level, vector<int> v){
	if(head == NULL)
		return;
	v.push_back(head->key);
	int t = 0;
	for(int i=level; i>-1; --i){
		t+=v.at(i);
		if(t==sum)
			printPath(v, i);
	}
	vector<int> v1(v), v2(v);
	pathSumAny(head->lchild,sum,level+1, v1);
	pathSumAny(head->rchild,sum,level+1, v2);
}

int main(){
	Node* head = NULL;
	init();
	int arr[]= {4, 3, 8, 5, 2, 1, 6};
	createMinHeightTree(head, NULL, arr, 0, 6);
	findPathSum(head, 8)?cout << "yes": cout << "no";
	cout << endl;
	int h=height(head);
	int *levelSum = new int[h];
	vector<int> v;
	pathSumAny(head, 8, 0, v);
	pathSumAny1(head, 8);	
	return 0;
}