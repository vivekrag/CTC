#include <iostream>
using namespace std;

class Stack
{
	int MaxStack;
	int EmptyStack;
	char* item;
	int top;
public:
	Stack(int);
	~Stack();
	void push(char);
	char pop();
	int empty();
	int full();
};