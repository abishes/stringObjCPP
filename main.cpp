#include <iostream>
#include "strings.hpp"
int main(){
	String str1;
	str1 = "This is String.";
	std::cout << str1	<< std::endl;
	String str2 = str1;
	std::cout << str2	<< std::endl;
	String str3 = " And this is another.";
	String str4;
	str4 = str2 + str3;
	std::cout << str4	<<std::endl;
	std::cout << (str1 == str2)	<<std::endl;
	std::cout << (str1 == str3)	<<std::endl;
	str3.push('0');
	str3.push('0');
	std::cout << str3.len()	<<std::endl;
	std::cout << str3	<<std::endl;
	str3.pop();
	str3.pop();
	std::cout << str3	<<std::endl;
}