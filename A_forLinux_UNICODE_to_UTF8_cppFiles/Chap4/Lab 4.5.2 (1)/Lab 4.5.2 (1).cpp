// Lab 4.5.2 (1).cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

string isIp(string str)
{
	int i;
	//cout << "<" << str << ">";
	for each (char c in str)
	{
		if (!isdigit(c)) 
			return  "Only digits and dots allowed";
	}
	if (str.length() > 3)
		return "Too many characters in a part";
	istringstream(str) >> i;
	if( i > 255)

		 return "Too big a value of a part";
	return "Correct IP";
	
}

int main()
{
	string str;
	cout << "Type string: \n";
	getline(cin, str);
	int j, l = 0;
	string out;
	for (int i = 0; i < 4; i++)
	{
		j = str.find(".");
		if (i == 3)
		{
			out = isIp(str.substr(l));
			break;
		}
		out = isIp(str.substr(l,j-l));
		if (out != "Correct IP")
		{
			break;
		}
		str.replace(j, 1, ",");
		l = j+1;
	}

	cout<< out <<endl;
	return 0;
}
