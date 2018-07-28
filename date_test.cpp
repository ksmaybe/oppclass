#include "std_lib_facilities.h"
#include "date.h"

Date f();
ostream& operator <<(ostream& os, Date d);

int main()
{
	
	Date today= f();
	cout << "Today is: " << today << endl;
	int d1;
	int m1;
	int y1;
	cout << "Number of days to add: ";
	cin >> d1;
	today.add_day(d1);
	cout << "After adding, the date is: " << today << endl;
	cout << "Number of months to add: ";
	cin >> m1;
	today.add_month(m1);
	cout << "After adding, the date is: " << today << endl;
	cout << "Number of years to add: ";
	cin >> y1;
	for (int x = 0; x < y1; x++)
		today.add_year();
	cout << "After adding, the date is: " << today << endl;
	keep_window_open();
	return 0;
}