#include "strings.hpp"


String::String(){			//default constructor string 
	length = 0;
	str_buffer = new char[1];
	str_buffer[0] = '\0'; // setting 1st element as null
}

String::String(const char* str){	// for constructor for char* argument 
	length = strlen(str);
	str_buffer = new char[length + 1]; // since, last char is null
	memcpy(str_buffer, str, length);
	str_buffer[length] = '\0';	// adding null char at last
}

String::String(const String& another_str){	//(copy constructor) to copy strings, else would have called destructor multiple times
	length = another_str.length;
	delete[] str_buffer;
	str_buffer = new char[length + 1];
	memcpy(str_buffer, another_str.str_buffer, length + 1);
}

String::~String(){
	delete[] str_buffer;
}

int String::len(){
	return length;
}

int String::find(char someChar){	//for finding character in string
	for(unsigned int i = 0; i < length; i++){
		if(str_buffer[i] == someChar)
			return (i+1);
	}
	return 0;
}

void String::push(char ch){ //add element to the last
	char tempStr[length + 2];
	strcpy(tempStr, str_buffer);
	tempStr[length] = ch;
	tempStr[length + 1] = '\0';
	length ++;
	delete[] str_buffer;
	str_buffer = new char[length + 1];
	strcpy(str_buffer, tempStr);
}

void String::pop(){		// delets last element
	char tempStr[length + 1];
	strcpy(tempStr, str_buffer);
		
	length --;
	delete[] str_buffer;
	str_buffer = new char[length + 1];
	for(int i = 0; i < length; i++){
		str_buffer[i] = tempStr[i];
	}
	str_buffer[length] = '\0';
}

char String::at(int index){ //returns nth element of string
	return operator[](index - 1);
}

//operators overloading
char& String::operator [](const int& charNumber){	// for edithing (n-1)th element os string
	return str_buffer[charNumber];
}
void String::operator =(const String& another_str){ //overloading = operator
	length = another_str.length;
	delete[] str_buffer;
	str_buffer = new char[length + 1];
	memcpy(str_buffer, another_str.str_buffer, length + 1);
}
void String::operator =(const char* str){
	length = strlen(str);
	delete[] str_buffer;
	str_buffer = new char[length + 1]; // since, last char is null
	memcpy(str_buffer, str, length);
	str_buffer[length] = '\0';
}

String String::operator +(const String& another_str){ // overloading + operator
	String temp;
	temp.length = length + another_str.length + 1;
	temp.str_buffer = new char[temp.length];
	strcpy(temp.str_buffer, str_buffer);
	strcat(temp.str_buffer, another_str.str_buffer);
	return temp;
}

void String::operator +=(const String& another_str){
	char temp[length + 1];
	strcpy(temp, str_buffer);
	length += another_str.length +1;
	delete[] str_buffer;
	str_buffer = new char[length];
	strcpy(str_buffer, temp);
	strcat(str_buffer, another_str.str_buffer);
}

bool String::operator ==(const String& another_str){
	if( strcmp(str_buffer, another_str.str_buffer) == 0)
		return 1;
	else
		return 0;
}

bool String::operator !=(const String& another_str){
	if( strcmp(str_buffer, another_str.str_buffer) == 0)
		return 0;
	else
		return 1;
}

bool String::operator >(const String& another_str){
	if( strcmp(str_buffer, another_str.str_buffer) > 0)
		return 1;
	else
		return 0;
}

bool String::operator <(const String& another_str){
	if( strcmp(str_buffer, another_str.str_buffer) < 0)
		return 1;
	else
		return 0;
}

std::ostream& operator <<(std::ostream& out, String& str){ //for displaying in console
	out << str.str_buffer;
	return out;
}

std::istream& operator >>(std::istream& in, String& str){ //for input from console
	char ch;
	str = String();
	while(1){
		ch = in.get();
		if(ch == ' ' || ch == '\n')
			break;
		str.push(ch);
	}
	return in;
}