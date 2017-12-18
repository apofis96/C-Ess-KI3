// Lab 6.4.4 (3).cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

class MinLengthValidator : public StringValidator
{
private:
	int minLenght;
public:
	MinLengthValidator(int lenght);
	bool isValid(string input);
};
MinLengthValidator::MinLengthValidator(int lenght)
{
	minLenght = lenght;
}
bool MinLengthValidator::isValid(string input)
{
	if (input.length() >= minLenght) return true;
	return false;
}

class MaxLengthValidator : public StringValidator
{
private:
	int maxLenght;
public:
	MaxLengthValidator(int lenght);
	bool isValid(string input);
};
MaxLengthValidator::MaxLengthValidator(int lenght)
{
	maxLenght = lenght;
}
bool MaxLengthValidator::isValid(string input)
{
	if (input.length() <= maxLenght) return true;
	return false;
}

class LengthValidator : public StringValidator
{
public:
	LengthValidator(int min, int max);
	bool isValid(std::string input);
private:
	MinLengthValidator min_validator;
	MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max) :
	min_validator(min), max_validator(max)
{
}
bool LengthValidator::isValid(std::string input)
{
	return (min_validator.isValid(input) && max_validator.isValid(input));
	
}

class PatternValidator : public StringValidator
{
private:
	string pattern;
	bool isUpper(string input);
	bool isLower(string input);
	bool isDigit(string input);
	bool isSpecial(string input);
public:
	PatternValidator();
	bool isValid(string input);
};

PatternValidator::PatternValidator()
{
}

bool PatternValidator::isValid(string input)
{
	return(isUpper(input) && isLower(input) && isDigit(input) && isSpecial(input));
}

bool PatternValidator::isUpper(string input)
{
	for (auto c : input)
	{
		if (c >= 'A' && c <= 'Z')
		{
			return true;
		}
	}
	return false;
}

bool PatternValidator::isLower(string input)
{
	for (auto c : input)
	{
		if (c >= 'a' && c <= 'z')
		{
			return true;
		}
	}
	return false;
}

bool PatternValidator::isDigit(string input)
{
	for (auto c : input)
	{
		if (c >= '0' && c <= '9')
		{
			return true;
		}
	}
	return false;
}

bool PatternValidator::isSpecial(string input)
{
	for (auto c : input)
	{
		if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '_' || c == '+' || c == '`' || c == '-' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == ':' || c == ';' || c == '<' || c == '>' || c == '.' || c == '/' || c == '\\')
		{
			return true;
		}
	}
	return false;
}


class ComposedValidator : public StringValidator
{
public:
	ComposedValidator(int min, int max);
	bool isValid(string input);
private:
	LengthValidator length_validator;
	PatternValidator pattern_validator;
};

ComposedValidator::ComposedValidator(int min, int max) :
	length_validator(min,max), pattern_validator()
{
}
bool ComposedValidator::isValid(string input)
{

	return (length_validator.isValid(input) && pattern_validator.isValid(input));
}

int main()
{
	cout << "Validator" << endl;
	ComposedValidator comp(8, 8);
	printValid(comp, "hello");
	printValid(comp, "hellohel");
	printValid(comp, "Hellohel");
	printValid(comp, "Hell0hel");
	printValid(comp, "Hell0#el");
	system("pause");
	return 0;
}