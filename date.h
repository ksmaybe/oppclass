#pragma once

class Date
{
public:
	class Invalid {};
	Date(int y, int m, int d);
	void add_day(int n);
	void add_month(int n);
	void add_year();
	const int& year();
	const int& month();
	const int& day();
private:
	int y, m, d;
	bool isvalid();
};
enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
