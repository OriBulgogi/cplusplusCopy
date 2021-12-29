#include <cstring>
#include "Text.h"
#include <iostream>
using namespace std;

Text::Text() 
{
	String();
	find_end();
}
Text::Text(const char* str)
{
	assign(str);
	find_end();
}
Text::Text(const String& str)
{
	assign(str);
	find_end();
}
Text::Text(const Text& txt)
{
	String s = txt;
	assign(txt);
	find_end();
}
Text::~Text()
{

}
void Text::find_end()
{
	char fin = '\n';
	string s = this->str_;
	
	if (s[size()] != fin){
		String :: append("\n");
	}
}
ostream& operator<<(ostream& os, const Text& txt)
{
	String str = txt;
	str.print(true);
	return os;
}


int Text::lines()
{
	int count = 0;
	char fin = '\n';
	string s = this->str_;
	for (int i = 0; i < strlen(this->str_); i++)
	{
		if (s[i] == fin)
		{
			count++;
		}
	}
	return count;
}



Text& Text::append(const char* s) {

	String :: append(s);
	find_end();
	return *this;
}

Text& Text::append(const String& str)
{
	String ::append(str);
	find_end();
	return *this;
}
Text& Text::append(const Text& txt)
{
	String str = txt;
	String::append(str);

	find_end();
	return *this;
}

