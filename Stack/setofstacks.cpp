#include <iostream>
using namespace std;
const int STACK_NUM = 10;
const int STACK_SIZE = 100;

class Stacks
{
private:
	int top;
	int MaxStack;
	int* items;

public:
	Stacks(int size = STACK_SIZE){
		 top = -1;
		 MaxStack = size;
		 items = new int[MaxStack];
	}
	~Stacks(){
		delete [] items;
	}
	void push(int val){
		if(top != MaxStack-1)
			items[++top] = val;
		else {
			cout << "satck overflow";
			return;
		}
	}
	int pop(){
		if(top != -1)
		return items[top--];
	else{
		cout << "stack underflow";
		return -1;
	}
	}
	int peek(){
		return items[top];
	}

	bool empty(){
		return top == -1;
	}

	bool full(){
		return top == MaxStack-1;
	}
};
class setofstacks
{
private:
	Stacks* st;
	int top;
	int MaxStack;
public:
	setofstacks(int size = STACK_NUM){
		MaxStack = size;
		top = 0;
		st = new Stacks[MaxStack];
	}
	~setofstacks(){
		delete [] st;
	}

	void push(int val){
		if(st[top].full())
			top++;
		st[top].push(val);
	}

	int pop(){
		if(st[top].empty())
			top--;
		st[top].pop();
	}

	int peek(){
		if(st[top].empty())
			top--;
		return st[top].peek();
	}
	
	bool empty(){
		if(top == 0)
			return st[top].empty();
		else
			return false;
	}

	bool full(){
		if(top = MaxStack-1)
			return st[top].full();
		else
			return false;
	}
};

int main(){
	setofstacks ss;
	for(int j=0; j<STACK_NUM+1; j++){
		ss.push(j);
	}
	while(!ss.empty()){
		cout << ss.peek();
		ss.pop();
	}

	return 0;
}