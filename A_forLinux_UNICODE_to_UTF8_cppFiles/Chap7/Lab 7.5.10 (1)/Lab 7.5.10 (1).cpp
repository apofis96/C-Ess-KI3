// Lab 7.5.10 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "string"
using namespace std;

class Exception {
public:
	string message;
	//Exception() { message = "Unknown Exception"; }
	Exception(string message) { this->message = message; }
};

class OutOfRangeException:public Exception {
public:
	OutOfRangeException() : Exception("Disk Number is out of range 1 - 3") { };
};

class IncorrectSizeException:public Exception {
public:

	IncorrectSizeException() : Exception("There are no space in the target tower") { };
};

class NoDisksException:public Exception {
public:;
	   NoDisksException() : Exception("There are no disks in the source tower") { };
};



class Tower
{
public: int* disks;
		int GetDiskCount()
		{
			int count = 0;
			for (int i = 0; i < 3; i++)
			{
				if (disks[i] != -1)
				{
					count++;
				}
			}
			return count;
		}
		string name;
		void Shift(int diskNum, Tower toTower)
		{
			if (GetDiskCount() == 0)
				throw NoDisksException();
			if (diskNum != 1 && diskNum != 2 && diskNum != 3)
				throw OutOfRangeException();
			if (toTower.GetDiskCount() == 3)
				throw IncorrectSizeException();
			for (int i = 0; i < 3; i++)
			{
				if (disks[i] == diskNum)
				{
					toTower.Add(diskNum);
					disks[i] = -1;
					break;
				}
			}
		}

		Tower(string _name)
		{
			name = _name;
			disks = new int[3];
			for (int i = 0; i < 3; i++)
			{
				disks[i] = -1;
			}
		}
		void Print()
		{
			cout << name << ": ";
			for (int i = 0; i < 3; i++)
			{
				if (disks[i] != -1)
					cout << disks[i] << " ";
			}
			cout << endl;
		}
		void Add(int diskNum)
		{
			if (diskNum != 1 && diskNum != 2 && diskNum != 3)
				throw OutOfRangeException();
			if (GetDiskCount() == 3)
				throw IncorrectSizeException();

			for (int i = 0; i < 3; i++)
			{
				if (disks[i] == -1)
				{
					disks[i] = diskNum;
					break;
				}
			}
		}
};



int main()
{
	try
	{
		Tower t1 = Tower("tower_1");
		t1.Add(3);
		t1.Add(2);
		t1.Add(1);
		Tower t2 = Tower("tower_2");
		Tower t3 = Tower("tower_3");
		t1.Shift(2, t3);
		t1.Shift(3, t2);
		t3.Shift(3, t2);
		t1.Shift(2, t3);
		t2.Shift(1, t1);
		t2.Shift(3, t3);
		t1.Shift(1, t3);
		t1.Print();
		t2.Print();
		t3.Print();
	}
	catch (IncorrectSizeException e)
	{
		cout << e.message << endl;
	}
	catch (OutOfRangeException e)
	{
		cout << e.message << endl;
	}
	catch (NoDisksException e)
	{
		cout << e.message << endl;
	}
	system("pause");
	return 0;
}