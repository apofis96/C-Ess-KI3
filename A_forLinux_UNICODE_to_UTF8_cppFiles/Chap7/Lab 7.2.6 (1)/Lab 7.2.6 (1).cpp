// Lab 7.2.6 (1).cpp: определяет точку входа для консольного приложения.
//

#include <string>
#include <iostream>

using namespace std;


class Exception {
public:
	string message;
	Exception() { message = "Value could exceed limit.\n"; }
	Exception(string message) { this->message = message; }
};


class ValueHolder
{
private:
	int value;
	int max;
	int min;

public:
	ValueHolder(int value, int min, int max);
	void Add(int value);
	void Substract(int value);
	int GetValue();
};

ValueHolder::ValueHolder(int value, int min, int max)
{
	this->value = value;
	this->max = max;
	this->min = min;
}

void ValueHolder::Add(int value)
{
	if (this->value + value > this->max)
		throw Exception();

	this->value += value;
}

void ValueHolder::Substract(int value)
{
	if (this->value - value < this->min)
		throw Exception();

	this->value -= value;
}

int ValueHolder::GetValue()
{
	return this->value;
}


int main()
{
	int val, min, max;
	ValueHolder *holder1, *holder2;

	cout << "Enter A value and limits\n";
	cin >> val >> min >> max;
	holder1 = new ValueHolder(val, min, max);

	cout << "Enter B value and limits\n";
	cin >> val >> min >> max;
	holder2 = new ValueHolder(val, min, max);

	cout << "Add to A :\n";


	
	try
	{
		while (true) {
			cin >> val;
			holder1->Add(val);
		}
	}
	catch (Exception exception)
	{
		cout << exception.message;
	}

	cout << "Add to B :\n";
	try
	{
		while (true) {
			cin >> val;
			holder2->Add(val);
		}
	}

	catch (Exception exception)
	{
		cout << exception.message;
	}

	cout << "Result: \n";
	cout <<"A "<< holder1->GetValue() << endl;
	cout <<"B "<< holder2->GetValue() << endl;

	return 0;
}