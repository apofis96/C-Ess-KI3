// Lab 7.5.9 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "string"
#include "regex"
using namespace std;

class Exception {
public:
	string message;
	Exception() { message = "Unknown Exception\n"; }
	Exception(string message) { this->message = message; }
};

class IPAddress
{
public:
	string ip;
	IPAddress(string _ip);
	IPAddress()
	{
		ip = "0.0.0.0";
	}


};
IPAddress::IPAddress(string _ip)
{
	ip = _ip;
}

bool IsCorrect(IPAddress _ip)
{
	string ip = _ip.ip;
	regex isDigit("[1-9]");

	bool correctIp = false, manyParts = false,
		onlyDigitsAndDots = true, BigPartValue = false;
	int lastDotPosition = 0, dotCount = 0, dotPosition;

	string dotIp = ip;
	for (int i = 0; i < ip.length(); i++)
	{
		if (ip.substr(i, 1) == ".") dotCount++;
		if ((ip.substr(i, 1) != ".") && (!regex_match(ip.substr(i, 1), isDigit))) onlyDigitsAndDots = false;
	}

	if (dotCount > 3) manyParts = true;

	if (!manyParts && onlyDigitsAndDots)
	{
		string tempIp = ip;
		int firstOctet = atoi(tempIp.c_str());
		int i;
		for (i = 0; tempIp[i] != '.'; i++);
		tempIp = &tempIp[i + 1];
		int secondOctet = atoi(tempIp.c_str());
		for (i = 0; tempIp[i] != '.'; i++);
		tempIp = &tempIp[i + 1];
		int thirdOctet = atoi(tempIp.c_str());
		for (i = 0; tempIp[i] != '.'; i++);
		tempIp = &tempIp[i + 1];
		int fourthOctet = atoi(tempIp.c_str());
		if (firstOctet > 255 || secondOctet > 255 || thirdOctet > 255 || fourthOctet > 255) BigPartValue = true;
	}
	bool isCorrect = (!manyParts && !BigPartValue && onlyDigitsAndDots);
	return isCorrect;
}


class IPHeader {
private: IPAddress srcIp;
		 IPAddress destIp;
public: IPHeader(IPAddress _srcIp, IPAddress _destIp)
{
	if (!IsCorrect(_srcIp))
		throw Exception("Invalid IP Header - Source IP Address is invalid.");
	if (!IsCorrect(_destIp))
		throw Exception("Invalid IP Header - Destination IP Address is invalid.");
	srcIp = _srcIp;
	destIp = _destIp;
	cout << "Valid IP Header" << endl;
}
};

int main()
{
	string input;
	cout << "Input:\n";
	try
	{
		cin >> input;
		IPAddress sIp = IPAddress(input);
		cin >> input;
		IPAddress dIp = IPAddress(input);
		IPHeader header = IPHeader(sIp, dIp);
		cout << endl;
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}
	try
	{
		cin >> input;
		IPAddress sIp = IPAddress(input);
		cin >> input;
		IPAddress dIp = IPAddress(input);
		IPHeader header = IPHeader(sIp, dIp);
		cout << endl;
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}

	system("pause");
	return 0;
}