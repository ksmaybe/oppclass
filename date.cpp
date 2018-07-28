#include "std_lib_facilities.h"
#include "date.h"

vector<int> non_leap_day{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
vector<int> leap_day{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
vector<int> last_day;
vector<string> mons{ "haha","January","Feburary","March","April","May","June","July","August","September","October","November","December" };

Month operator++(Month & m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}
void Date::add_year()
{
	y+=1;
}

bool leap_year(int y)
{
	return y % 4 == 0;
}

Date::Date(int yy, int mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (leap_year(y)) last_day = leap_day;
	else
		last_day = non_leap_day;
	if (!isvalid())
		throw Invalid{};
	else
		cout << "Valid date inputted.\n";
}



void Date::add_day(int n)
{
	if (n > 10)
	{
		add_day(10);
		add_day(n - 10);
	}
	else
	{
		d += n;
		if(d>last_day[m])
		{
			d -= last_day[m];
			m++;
			if (m == 13) {
				m = 1;
				add_year();
			}
		}
	}
}
void Date::add_month(int n)
{
	while(n>=12)
	{
		n -= 12;
		add_year();
	}
	for (int x = 0; x < n; x++)
	{
		m++;
		if(m==13)
		{
			m = 1;
			add_year();
		}
	}
}

bool Date::isvalid()
{
	int x = 0;
	if (int(y) < 0)
	{
		cout << "Invalid year" << endl;
		x += 1;
	}
	if (int(m) < 1 || int(m) > 12)
	{
		cout << "Invalid month" << endl;
		x += 1;
	}
	else
	{if (int(d) < 1||int(d)>last_day[m])
		{
			cout << "Invalid day" << endl;
			x += 1;
		}
	}


	return x == 0;
}
const int& Date::year()
{
	return y;
}
const int& Date::month()
{
	return m;
}
const int& Date::day()
{
	return d;
}

ostream& operator <<(ostream& os, Date d)
{
	return os << '(' << mons[d.month()] << " " << d.day() << "," << d.year() << ")" << endl;
}
Date f()
try
{
	int xx;
	int yy;
	int zz;
	string input;
	cout << "Enter a date in format (YYYY,MM,DD): ";
	cin >> input;
	istringstream ss(input);
	string token_y;
	string token_m;
	string token_d;
	getline(ss, token_y, ',');
	stringstream y(token_y);
	y >> xx;
	getline(ss, token_m, ',');
	stringstream m(token_m);
	m >> yy;
	getline(ss, token_d, ',');
	stringstream d(token_d);
	d >> zz;
	Date dxy{ xx,yy,zz };
	return dxy;
}
catch (Date::Invalid)
{
	return f();
}

