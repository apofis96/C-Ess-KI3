// Lab 6.3.5 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

class Tree
{
public:
	virtual void Draw()
	{
		cout << " /\\\n";
	}
};

class Tree1 : public Tree
{
	void Draw()
	{
		Tree::Draw();
		cout << "//\\\\\n" << endl;
	}
};

class Tree2 : public Tree
{
	void Draw()
	{
		Tree::Draw();
		cout << "/++\\\n";
	}
};

class Tree3 : public Tree
{
	void Draw()
	{
		Tree::Draw();
		cout << "/**\\\n";
	}
};

int main()
{
	Tree** Trees = new Tree*[3];

	Trees[0] = new Tree1();
	Trees[2] = new Tree2();
	Trees[1] = new Tree3();

	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i + 1 << ":\n" ;
		Trees[i]->Draw();
	}

	return 0;
}
