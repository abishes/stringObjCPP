#include <iostream>
#include <cstring>
#ifndef _strings_
#define _strings_
class String{
	char* str_buffer;
	unsigned int length;
public:
	String();

	String(const char* str);

	String(const String& another_str);

	int len();

	int find(char someChar);

	void push(char ch);

	void pop();

	char at(int);
	//operators overloading
	char& operator [](const int& charNumber);

	void operator =(const String& another_str);

	void operator =(const char* another_str);

	String operator +(const String& another_str);

	void operator +=(const String& another_str);

	bool operator ==(const String& another_str);

	bool operator !=(const String& another_str);

	bool operator >(const String& another_str);

	bool operator <(const String& another_str);

	~String();
	
	friend std::ostream& operator <<(std::ostream& out, String& str); //operator << overloading
	
	friend std::istream& operator >>(std::istream& in, String& str);	//operator >> overloading
};
#endif