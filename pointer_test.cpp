#include "std_lib_facilities.h"

int main()
{
	char c = 'a';
	int i = 4092;
	double d = 3.14;
	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	cout << "char c = " << c << endl;
	cout << "size of c is " << sizeof(c) << endl;
	cout << "int i = " << i << endl;
	cout << "size of i is " << sizeof(i) << endl;
	cout << "double d = " << d << endl;
	cout << "size of d  is " << sizeof(d) << endl <<endl;

	cout << "cp = " << cp << " and its value is : " << *cp << endl;
	cout << "size of cp is " << sizeof(cp) << endl;
	cout << "ip = " << ip << " and its value is : " << *ip << endl;
	cout << "size of ip is " << sizeof(ip) << endl;
	cout << "dp = " << dp << " and its value is : " << *dp << endl;
	cout << "size of dp is " << sizeof(dp) << endl;
	keep_window_open();
	return 0;
}
