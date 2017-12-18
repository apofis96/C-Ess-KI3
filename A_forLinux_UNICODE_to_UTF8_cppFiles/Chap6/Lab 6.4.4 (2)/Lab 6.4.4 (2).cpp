// Lab 6.4.4 (2).cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};


class MinLengthValidator : public StringValidator
{
private:
	int min;
public:
	MinLengthValidator(int min);
	bool isValid(std::string);
};

MinLengthValidator::MinLengthValidator(int min)
{
	this->min = min;
}

bool MinLengthValidator::isValid(std::string input)
{
	if (input.length() < this->min)
		return false;

	return true;
}


class MaxLengthValidator : public StringValidator
{
private:
	int max;
public:
	MaxLengthValidator(int max);
	bool isValid(std::string);
};

MaxLengthValidator::MaxLengthValidator(int max)
{
	this->max = max;
}

bool MaxLengthValidator::isValid(std::string input)
{
	if (input.length() > this->max)
		return false;

	return true;
}


class PatternValidator : public StringValidator
{
private:
	std::string pattern;
public:
	PatternValidator(std::string pattern);
	bool isValid(std::string input);
	bool Check(char c1, char c2);
	bool Reg(std::string str1, std::string str2);
};

PatternValidator::PatternValidator(std::string pattern)
{
	this->pattern = pattern;
}

bool PatternValidator::isValid(std::string input)
{
	return Reg(pattern, input);
}
bool PatternValidator::Check(char c1, char c2)
{
	if (c1 == ' ') return false;
	if (c1 == 'D')
	{
		if (c2 >= '0'&&c2 <= '9') return true;
		else return false;
	}
	if (c1 == 'A')
	{
		if (c2 >= 'A'&&c2 <= 'Z') return true;
		if (c2 >= 'a'&&c2 <= 'z') return true;
		return false;
	}
	if (c1 == '?') return true;
	if (c1 >= 'a' && c1 <= 'z')
	{
		if (c1 == c2 || c1 == (c2 - 'A' + 'a')) return true;
		return false;
	}
	if (c1 == c2) return true;
	return false;
}

bool PatternValidator::Reg(std::string str1, std::string str2)
{
	std::string str;
	int i = str1.length();
	int j = 0;
	int k = -1;
	for (; j < str2.length();)
	{
		for (int a = 0; a < i; )
		{
			if (j >= (str2.length())) return false;
			if (Check(str1.at(a), str2.at(j)))
			{
				a++;
				if (k == -1) k = j;
				j++;
			}
			else
			{
				j++;
				k = -1;
				a = 0;
			}
		}
		if (i == (j - k))
			return true;
		return false;
	}
	return false;
}

class ExactValidator : public StringValidator
{
private:
	std::string word;
public:
	ExactValidator(std::string word);
	bool isValid(std::string);
};

ExactValidator::ExactValidator(std::string word)
{
	if (word != "")
		this->word = word;
}

bool ExactValidator::isValid(std::string input)
{
	if (input == this->word)
		return true;

	return false;
}


void printValid(StringValidator &validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid");
}

int main()
{
	std::cout << "MinLengthValidator" << std::endl;
	MinLengthValidator min(6);

	printValid(min, "hello");
	std::cout << std::endl;
	printValid(min, "welcome");
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "MaxLengthValidator" << std::endl;
	MaxLengthValidator max(6);

	printValid(max, "hello");
	std::cout << std::endl;
	printValid(max, "welcome");
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "PatternValidator" << std::endl;
	PatternValidator digit("D");

	printValid(digit, "there are 2 types of sentences in the world");
	std::cout << std::endl;
	printValid(digit, "valid and invalid ones");
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
