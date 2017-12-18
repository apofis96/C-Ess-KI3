// Lab 4.4.1 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

int* isPangram(string str)
{
	// Create a hash table to mark the characters
	// present in the string
	int * alphabet;
	alphabet = new int[27];

	for (int i = 0; i < 27; i++)
	{
	alphabet[i] = 0;
	}

	// For indexing in mark[]
	int index = -1;

	// Traverse all characters
	for (int i = 0; i<str.length(); i++)
	{
		index = -1;
		if ('A' <= str[i] && str[i] <= 'Z')
			index = str[i] - 'A';
		else if ('a' <= str[i] && str[i] <= 'z')
			index = str[i] - 'a';

		if(index!= -1)
		alphabet[index]++;
	}

	// Return false if any character is unmarked
	for (int i = 0; i <= 25; i++)
	{
		if (alphabet[i] == 0)
			alphabet[26] = -1;
	}



	// If all characters were present
	return alphabet;
}

int main()
{
	string str;// = "testo";
	int *arr;
	cout << "Type string: \n";
	getline(cin, str);
	arr = isPangram(str);


	if (arr[26] != -1) cout << "Pangram\n";
	else cout << "Not pangram\n";
	char a = 'a';
	for (int i = 0; i < 26; i++)
	{
		cout << a << " - " << arr[i]<<endl;
		a++;
	}

    return 0;
}

