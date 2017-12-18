// Lab 5.3.13 (3).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

Node::~Node() {}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int& value);
	int size();
private:
	Node* head;
};

List::List() : head(nullptr) {}

List::~List()
{
	Node* new_head;

	while (this->head != nullptr)
	{
		new_head = head->next;
		delete head;
		this->head = new_head;
	}
}

void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
}

bool List::pop_front(int& value)
{
	if (head == nullptr)
		return false;

	Node* new_head = head->next;
	value = head->value;
	delete head;
	head = new_head;

	return true;
}

int List::size()
{
	Node* firstElement = head;
	int size = 0;

	while (head != nullptr)
	{
		size++;
		head = head->next;
	}

	head = firstElement;

	return size;
}

int main()
{
	List list;
	int value;

	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		list.pop_front(value);
		cout << "popped " << value << ", size: " << list.size() << endl;
	}

	return 0;
}
