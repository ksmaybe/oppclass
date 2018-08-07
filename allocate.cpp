#include "std_lib_facilities.h"
int main()
{
	int i = 0;
	while(true)
	{
		double* dpler = new double[10000];
		cout << "Loop " << i << endl;
		i++;
	}
	keep_window_open();
	return 0;
}
