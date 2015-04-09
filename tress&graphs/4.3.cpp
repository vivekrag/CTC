#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 100;
int cnt;
struct Node
{
	int key;
	Node* parent;
	Node* rchild;
	Node* lchild;
};
Node* p;
Node* head;
Node node[maxn];

void init(){
	p = NULL;
	memset(node, '\0', sizeof(node));
	cnt = 0;
}
// Time complexity O(log N)
void minHeightTree(int arr[], Node* &head, Node* parent, int start, int end){
	if(start <= end){
		int mid = (start+end)/2;
		node[cnt].key = arr[mid];
		node[cnt].parent = parent;
		head = &node[cnt++];
		minHeightTree(arr, head->lchild, head, start, mid-1);
		minHeightTree(arr, head->rchild, head, mid+1, end);
	}	
}

int height(Node* head){
	if(head == NULL)
		return 0;
	else 
		return (max(height(head->lchild), height(head->rchild)) + 1);
}

int main(){
	init();
	Node* head = NULL;
	int a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,17,18,19,20.21,21,22,23,24,26,27,28,29,31,32,33,34,35,36,37,38,39};
	minHeightTree(a, head, p, 0, 40);
	cout << height(head) << endl;
	return 0;
}