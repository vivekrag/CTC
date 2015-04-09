#include "tree.h"
#include <iostream>
#include <cmath>
using namespace std;

//O(N) time comlexity and O(H) space complexity
int checkHeight(Node* node){
	int lh;
	int rh;
	if(node == NULL)
		return 0;
	lh = checkHeight(node->lchild);
	if(lh == -1)
		return -1;
	rh = checkHeight(node->rchild);
	if(rh == -1)
		return -1;
	int diff = lh-rh;
	if(abs(diff) > 1)
		return -1;
	return (max(lh,rh) + 1);
}

bool isTreeBalance(Node* head){
	if(checkHeight(head) == -1)
		return false;
	else
		return true;
}

int main(){
	init();
	int n[]={5, 3, 8, 1, 4, 7, 10, 2, 5, 9, 11, 12};
	for(int i = 0; i<12; i++)
		insert(head, n[i]);
	cout << isTreeBalance(head);
	return 0;
}