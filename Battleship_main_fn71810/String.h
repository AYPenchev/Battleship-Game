#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable : 4996)

class String
{
public:
	String();									//default constructor
	String(const char* value);					//constructor
	String(const String& other);				//copy constructor
	String& operator= (const String& other);	//operator =
	String& operator+ (const String& other);	//concat strings operator +
	~String();									//destructor
	void print() const;							//print function
	friend std::ostream& operator<< (std::ostream& output, const String& other);	//operator<< for ostream
	char* convertToPointer();					//convert String to char*
	friend std::istream& operator>> (std::istream& input, String& other);			//operator>> for istream
	char operator[](size_t index) const;		//operator[] get element from index
private:
	char* value;
	void copy(const String& other);				//helper copy function
	void destroy();								//helper destruct function
};