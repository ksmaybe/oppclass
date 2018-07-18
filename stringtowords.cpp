#include "std_lib_facilities.h"

int main()
{
	cout << "Enter some words: \n";
	vector<string> wording;
	for (string words; cin >> words;) {
		if (words == "stop") { //type "stop" to stop entering words
			break;
		}
		wording.push_back(words);
	}
	sort(wording);
	int count = 1;      

	for (int i=0;i < wording.size(); ++i) // for length of vector
	{
		if (i == wording.size() - 1) {          
			if (wording[i] == wording[i - 1])  //for last word in vector, compare to word before it
			{
				cout << wording[i] << ": " << count << endl;
			}
			else
			{
				cout << wording[i] << ": " << 1 << endl;
			}
		}
		else 
		{
			if (wording[i] == wording[i + 1])  //if the next word is the same, count up. Else, print the word and word count.
				count += 1;
			else 
			{
				cout << wording[i] << ": " << count << endl;
				count = 1;
			}
		}
			

	}

	keep_window_open();
	return 0;
}
