
//stack.h: header file
#include <iostream>
using namespace std;
const int MAX_INT = ~(1<<31);
class Stack
{
	int MaxStack;
	int* items;
	int top;
	int* stackMin;
public:
	Stack(int);
	~Stack();
	void push(int);
	int pop();
	int empty();
	int full();
	int stackMinimim();
};

Stack::Stack(int size){
	MaxStack = size;
	top = -1;
	items = new int[MaxStack];
	stackMin = new int[MaxStack];
	stackMin[0] = MAX_INT;
}

Stack::~Stack() {delete [] items; delete [] stackMin;}

void Stack::push(int val) {
	if(top != MaxStack-1)
	items[++top] = val;
	else {
		cout << "stack overflow";
		return;
	}
	if(val <= stackMin[top-1] || top == 0)
		stackMin[top] = val;
	else
		stackMin[top] = stackMin[top-1];
}

int Stack::pop() {
	if(top != -1)
		return items[top--];
	else{
		cout << "stack underflow";
		return -1;
	}
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
	Stack s(8);
	s.push(3);
	s.push(7);
	s.push(8);
	s.push(2);
	s.push(9);
	s.push(8);
	cout << "min stack value is 2:" << s.stackMinimim();
	s.pop();
	s.pop();
	cout << "min stack value is 2:" << s.stackMinimim();
	s.pop();
	cout << "min stack value is 3:" << s.stackMinimim();
	return 0;
}

// 5 3 7 8 2 9 8