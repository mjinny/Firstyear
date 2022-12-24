#include <iostream>
using namespace std;

class Date
{
	private:
		int day,
			month,
			year;

	public:
		Date()
		{
			month = 1;
			day = 1;
			year = 2001;
		}
		Date(int m, int d, int y)
		{
			if (m < 1 || m > 12)
			{
				month = 1;
			}
			else
				month = m;

			if (d < 1 || d > 31)
			{
				day = 1;
			}
			else
				day = d;

			if (y < 0)
			{
				year = 2001;
			}
			else
				year = y;
		}
		void print1()
		{
			cout << month << "/" << day << "/" << year << endl;
		}
		

		void print2()
		{
			switch (month)
			{
			case 1:
				cout << "January " << day << ", " << year << endl;
				break;
			case 2:
				cout << "February " << day << ", " << year << endl;
				break;
			case 3:
				cout << "March " << day << ", " << year << endl;
				break;
			case 4:
				cout << "April " << day << ", " << year << endl;
				break;
			case 5:
				cout << "May " << day << ", " << year << endl;
				break;
			case 6:
				cout << "June " << day << ", " << year << endl;
				break;
			case 7:
				cout << "July " << day << ", " << year << endl;
				break;
			case 8:
				cout << "August " << day << ", " << year << endl;
				break;
			case 9:
				cout << "September " << day << ", " << year << endl;
				break;
			case 10:
				cout << "October " << day << ", " << year << endl;
				break;
			case 11:
				cout << "November " << day << ", " << year << endl;
				break;
			case 12:
				cout << "December " << day << ", " << year << endl;
				break;
			}
		}

		void print3()
		{
			switch (month)
			{
			case 1:
				cout << day << " January " << year << endl;
				break;
			case 2:
				cout << day << " February " << year << endl;
				break;
			case 3:
				cout << day << " March " << year << endl;
				break;
			case 4:
				cout << day << " April " << year << endl;
				break;
			case 5:
				cout << day << " May " << year << endl;
				break;
			case 6:
				cout << day << " June " << year << endl;
				break;
			case 7:
				cout << day << " July " << year << endl;
				break;
			case 8:
				cout << day << " August " << year << endl;
				break;
			case 9:
				cout << day << " September " << year << endl;
				break;
			case 10:
				cout << day << " October " << year << endl;
				break;
			case 11:
				cout << day << " November " << year << endl;
				break;
			case 12:
				cout << day << " December " << year << endl;
				break;
			}
		}
};




int main()
{
	int day, month, year;

	cout << "Enter a year ";
	cin >> year;
	while (year < 1)
	{
		cout << "Invalid year number, enter another: ";
		cin >> year;
	}

	cout << "Enter a month ";
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "Invalid month number, enter another: ";
		cin >> month;
	}


	cout << "Enter a day ";
	cin >> day;
	while (day < 1 || day > 31)
	{
		cout << "Invalid day number, enter another: ";
		cin >> month;
	}


	Date date1, date2(9, 12, 2004), date3(month, day, year);

	date1.print1();
	date1.print2();
	date1.print3();

	date2.print1();
	date2.print2();
	date2.print3();

	date3.print1();
	date3.print2();
	date3.print3();


	return 0;
}
