#include <iostream>
#include <cstring>
#ifndef _STRINGS_
#define _STRINGS_
class String{
	char* str_buffer;
	unsigned int length;
public:
	String(){			//default constructor string 
		length = 1;
		str_buffer = new char[length];
		str_buffer[0] = '\0'; // setting 1st element as null
	}

	String(const char* str){	// for constructor for char* argument 
		length = strlen(str);
		str_buffer = new char[length + 1]; // since, last char is null
		memcpy(str_buffer, str, length);
		str_buffer[length] = '\0';	// adding null char at last
	}

	String(const String& another_str){	//(copy constructor) to copy strings, else would have called destructor multiple times
		length = another_str.length;
		str_buffer = new char[length + 1];
		memcpy(str_buffer, another_str.str_buffer, length + 1);
	}

	int len(){
		return length;
	}

	int find(char someChar){	//for finding character in string
		for(unsigned int i = 0; i < length; i++){
			if(str_buffer[i] == someChar)
				return (i+1);
		}
		return 0;
	}
	void push(char ch){ //add element to the last
		char tempStr[length + 2];
		strcpy(tempStr, str_buffer);
		tempStr[length] = ch;
		tempStr[length + 1] = '\0';
		length ++;
		str_buffer = new char[length + 1];
		strcpy(str_buffer, tempStr);
	}
	void pop(){		// delets last element
		char tempStr[length + 1];
		strcpy(tempStr, str_buffer);
		
		length --;
		str_buffer = new char[length + 1];
		for(int i = 0; i < length; i++){
			str_buffer[i] = tempStr[i];
		}
		str_buffer[length] = '\0';
	}
	char& operator [](const int& charNumber){	// for edithing (n-1)th element os string
		return str_buffer[charNumber];
	}
	void operator =(const String& another_str){ //overloading = operator
		length = another_str.length;
		str_buffer = new char[length + 1];
		memcpy(str_buffer, another_str.str_buffer, length + 1);
	}

	String operator +(const String& another_str){ // overloading + operator
		String temp;
		temp.length = length + another_str.length + 1;
		temp.str_buffer = new char[temp.length];
		strcpy(temp.str_buffer, str_buffer);
		strcat(temp.str_buffer, another_str.str_buffer);
		return temp;
	}

	bool operator ==(const String& another_str){
		if( strcmp(str_buffer, another_str.str_buffer) == 0)
			return 1;
		else
			return 0;
	}

	bool operator !=(const String& another_str){
		if( strcmp(str_buffer, another_str.str_buffer) == 0)
			return 0;
		else
			return 1;
	}

	bool operator >(const String& another_str){
		if( strcmp(str_buffer, another_str.str_buffer) > 0)
			return 1;
		else
			return 0;
	}

	bool operator <(const String& another_str){
		if( strcmp(str_buffer, another_str.str_buffer) < 0)
			return 1;
		else
			return 0;
	}
	~String(){
		delete[] str_buffer;
	}
	friend std::ostream& operator <<(std::ostream& out, String& str); //operator << overloading
	friend std::istream& operator >>(std::istream& in, String& str);	//operator >> overloading
};
std::ostream& operator <<(std::ostream& out, String& str){
	out << str.str_buffer;
	return out;
}
std::istream& operator >>(std::istream& in, String& str){
	in >> str.str_buffer;
	return in;
}
#endif