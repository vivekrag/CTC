
//stack.h: header file
#include <iostream>
using namespace std;
const int MAX_INT = ~(1<<31);
class Stack
{
	int MaxStack;
	int* items;
	int top;
public:
	Stack(int);
	~Stack();
	void push(int);
	int pop();
	int empty();
	int full();
};

Stack::Stack(int size){
	MaxStack = size;
	top = -1;
	items = new int[MaxStack];
}

Stack::~Stack() {delete [] items;}

void Stack::push(int val) {
	if(top != MaxStack-1)
		items[++top1] = val;
	else {
		cout << "stack overflow";
		return;
	}
}

int Stack::pop() {
	if(top1 != -1){
		return items[top1--];
	}
	else{
		cout << "stack underflow";
		return -1;
	}
	if(top)
}

int Stack::full(){
	return (top+1 == MaxStack);
}

int Stack::empty(){
	return (top == -1);
}

int Stack::stackMinimim(){
	return stackMin[top];
}

int main(){
	Stack s(5);
	s.push(2);
	s.push(4);
	s.push(9);
	s.push(1);
	s.push(6);
	s.pop();
	s.pop();
	s.pop();
	cout << "min stack value is " << s.stackMinimim();
	return 0;
}