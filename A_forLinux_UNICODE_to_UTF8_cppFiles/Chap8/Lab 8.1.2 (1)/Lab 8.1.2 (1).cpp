// Lab 8.1.2 (1).cpp: определяет точку входа для консольного приложения.
//

#include <string>
#include <iostream>

using namespace std;


class Stack {
private:
	int *stackstore;
	int stacksize;
	int emount;
public:
	Stack(int size) {
		if (size <= 0)
			throw string("size must be >= 0\n");
		try {
			stackstore = new int[size];
		}
		catch (bad_alloc ba) {
			throw string("stack_bad_alloc\n");
		}
		stacksize = size;
		emount = 0;
	}
	~Stack() {
		delete stackstore;
	}
	void push(int value) {
		if (emount == stacksize)
			throw string("stack size exceeded\n");
		stackstore[emount++] = value;
	}
	int pop() {
		if (emount == 0)
			throw string("stack is empty\n");
		return stackstore[--emount];
	}
	int top()  {
		if (emount == 0)
			throw string("stack is empty\n");
		return stackstore[emount];
	}
	Stack& operator<< (int v) {
		push(v);
		return *this;
	}
	Stack& operator >> (int &v) {
		v = pop();
		return *this;
	}
};

int main(void) {
	int n;

	cout << "Stack size: \n";
	cin >> n;
	try
	{
		Stack stk(n);


		int j;
		cout << "Enter elements: \n";
		for (int i = 0; i < n; i++)
		{
			cin >> j;
			stk << j;
		}

		cout << "Print elements: \n";
		cin >> n;
		cout << "Printing:\n";
		for (int i = 0; i < n; i++)
		{
			stk >> j;
			cout << j << endl;
		}
	}

	catch (string e)
	{
		cout <<"Exception:"<< e;
	}
	return 0;
}

