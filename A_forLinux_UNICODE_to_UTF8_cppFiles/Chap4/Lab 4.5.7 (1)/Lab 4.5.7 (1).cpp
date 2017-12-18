// Lab 4.5.7 (1).cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
using namespace std;
int main()
{
	string sentence;// = "qwe*asd*asd*zxc*qaz*qaz";
	//cout << sentence << endl;
	getline(cin, sentence);
	// manipulate the sentence here
	int a = 0, b = 0, c, d;
	while ((sentence.substr(a)).find(" ") != string::npos)
	{
		b = (sentence.substr(a)).find(" ");
		if (((sentence.substr(a)).substr(b + 1)).find(" ") != string::npos)
		{
			c = ((sentence.substr(a)).substr(b + 1)).find(" ");
		}
		else { c = ((sentence.substr(a)).substr(b + 1)).length(); }
		//cout <<"a"<<a<< " b" << b << " c" << c;
		/*cout << "1sub " << sentence.substr(a) << "| \n";
		cout << "2sub " << ((sentence.substr(a)).substr(b + 1)) << "| \n";
		cout << "1 " << sentence.substr(a, b) << "| \n";
		cout << "2 " << ((sentence.substr(a)).substr(b + 1)).substr(0, c) << "| \n";*/
		if (sentence.substr(a, b) == ((sentence.substr(a)).substr(b + 1)).substr(0, c))
		{
			sentence.erase(a, b+1);
			a = 0;
			c = 0;
			b = 0;
			//cout << "exit: " << sentence << endl;
		}
		else
		{
			a += b + 1;
			c = 0;
			b = 0;
		}
	}
	cout << sentence << "\n";
}