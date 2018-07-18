#include "std_lib_facilities.h"


class Token
{
public:
	char kind;
	double value;

};
class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer:");
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	//cout << "lslslsl";
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'q':
	case '(': case ')': case'+': case '-': case'*': case'/':
		return Token{ ch };
	
	case'.': case'0': case'1': case'2': case'3': case'4': case'5':
	case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };

	}
	default:
		return Token{ 'i',ch };
	}
}

Token_stream ts;
Token get_token()
{
	//cout << "lol";
	return ts.get();

}


int main()
{
	vector<Token> tok;
	for (Token t = get_token(); t.kind != 'q'; t = get_token())
	{
		//cout << "haha";
		tok.push_back(t);
	}
	for (Token t:tok)
	{
		if (t.kind == '8')
			cout << "A number token with val= " << t.value << endl;
		else if (t.kind == 'i')
		{

			char r = t.value;
			cout << "We received an invalid token of value " <<r << endl;
		}
		else
			cout << "A token of kind " << t.kind << endl;
	}
	keep_window_open();
	return 0;
}