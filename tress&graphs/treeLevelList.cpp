
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

vector<list <Node*> > createLevelList(Node* head){
	list<Node*> cur;
	vector<list<Node*> > res;
	if(head!=NULL)
		cur.push_back(head);
	while(cur.size()>0){
		res.push_back(cur);
		list<Node*> p = cur;
		list<Node*> cur1;
		list<Node*>::iterator i;
		for(i=p.begin(); i!=p.end(); i++){
			Node* n=*i;
			if(n->lchild!=NULL)
				cur.push_back(n->lchild);
			if(n->rchild!=NULL)
				cur.push_back(n->rchild);
		}
	}
	return res;
}

void print(vector<list<Node*> > res){
    vector<list<Node*> >::iterator vit;
    for(vit=res.begin(); vit!=res.end(); ++vit){
        list<Node*> li = *vit;
        list<Node*>::iterator lit;
        for(lit=li.begin(); lit!=li.end(); ++lit){
            Node *n = *lit;
            cout<<n->key<<" ";
        }
        cout<<endl;
    }
}

int main(){
	init();
	Node* head=NULL;
	int a[]={0,1,2,3,4,5,6,7,8,9};
	createMinTree(head, NULL, a, 0, 9);
	vector<list<Node*> > result = createLevelList(head);
	print(result);
	return 0;
}