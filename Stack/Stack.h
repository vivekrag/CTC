
//stack.h: header file
#include <iostream>
using namespace std;

class Stack
{
	int MaxStack;
	int EmptyStack;
	char* items;
	int top;
public:
	Stack(int);
	~Stack();
	void push(char);
	char pop();
	int empty();
	int full();
};

Stack::Stack(int size){
	MaxStack = size;
	EmptyStack = -1;
	top = EmptyStack;
	items = new char[MaxStack]; 
}

Stack::~Stack() {delete [] items;}

void Stack::push(char c) {
	if(top != MaxStack-1)
	items[++top] = c;
	else {
		cout << "stack overflow";
		return;
	}
}

char Stack::pop() {
	if(top != EmptyStack)
	return items[top--];
	else {
		cout << "stack underflow";
		return -1;
	}
}

int Stack::full(){
	return (top+1 == MaxStack);
}

int Stack::empty(){
	return (top == EmptyStack);
}
