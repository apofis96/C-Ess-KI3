// Lab 8.2.3 (1).cpp: определяет точку входа для консольного приложения.
//

#include "string"
#include "iostream"
using namespace std;
class date {


public:
	int day, month, year;
	enum weekday { THURSDAY, FRIDAY, SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY };
	enum month { january, february, march, april, may, june, july, august, september, oktober, november, december };
	string DayWeek(int da) {

		switch (da) {
		case THURSDAY:  return "THURSDAY";
		case FRIDAY:    return "FRIDAY";
		case SATURDAY:  return"SATURDAY";
		case SUNDAY:   return "SUNDAY";
		case MONDAY:   return"MONDAY";
		case TUESDAY: return "TUESDAY";
		case WEDNESDAY: return "WEDNESDAY";
		
		default:        return "Idonnolol";
		}
		return "";
	}
	string Month(int da) {

		switch (da-1) {
		case january:   return "january";
		case february:   return"february";
		case march: return "march";
		case april: return "april";
		case may:  return "may";
		case june:    return "june";
		case july:  return"july";
		case august:  return"august";
		case september:  return"september";
		case oktober:  return"oktober";
		case november:  return"november";
		case december:  return"december";
		default:        return "Idonnolol";
		}
		return "";
	}
	date(int d = 1, int m = 1, int y = 1970) {
		if (y < 1970)
			throw string("data must be more 1.1.1970");
		if (m<1 || m>12)
			throw string("month in range [1....12]");
		if (d<1 || d>31)
			throw string("day in range [1....31]");
		day = d;
		month = m;
		year = y;

	}
	bool isLeap(int year)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return true;
		}
		else if (year % 400 == 0)
		{
			return true;
		}
		else return false;
	}
	int monthLength(int year, int month)
	{
		if (month == 2)
		{
			if (isLeap(year)) return 29;
			else return 28;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
		if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
		return 0;
	}
	int dayOfYear(date d)
	{
		int i = 0;
		for (int j = 1; j < d.month; j++)
		{
			i += monthLength(d.year, j);
		}
		i += d.day;
		return i;
	}

	int operator-(date w) {

		int dif = dayOfYear(*this) - dayOfYear(w);
		if (dif<0)
			return -1;
		for (int i = 0; i < (this->year - w.year); ++i) {
			if (isLeap(w.year + i))
				dif += 366;
			else
				dif += 365;
		}
		return dif;
	}
};
int main()
{
	cout << "Ender Y M D \n";
	int y, m, d;
	cin >> y;
	cin >> m;
	cin >> d;

	date q(d, m, y);
	date w(1, 1, 1970);

	int qq = q - w;
	cout << q.day << " " << q.Month(q.month) << " " << q.year << " - " << q.DayWeek(qq % 7) << " - " << qq << " days since 1st January 1970" << endl;
	return 0;
}