#include <iostream>
#include "String.h"
using namespace std;


class Text : public String
{
public:
	Text();
	Text(const char* str);
	Text(const String& str);
	Text(const Text& txt);
	~Text();
	int lines();
	Text& append(const char* s);
	Text& append(const String& str);
	Text& append(const Text& text);
	void find_end();
};

ostream& operator<<(ostream& os, const Text& txt);
