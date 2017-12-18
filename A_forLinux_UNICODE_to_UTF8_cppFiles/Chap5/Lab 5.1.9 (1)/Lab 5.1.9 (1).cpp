// Lab 5.1.9 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	string name;
	int age;
	// Your code here
	string test;

	string Print()
	{
		string str;
		str += name + " | " + test +"\n";
		return str;
	}
};
void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
}
int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.test = "testo";
	cout << "Meet " << person.name<<endl;
	print(&person);
	// Your code here
	cout << person.Print();
	return 0;
}

