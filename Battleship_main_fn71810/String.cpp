#include "stdafx.h"
#include "String.h"


void String::copy(const String& other)                       //helper copy function
{
	int otherValueLen = strlen(other.value) + 1;
	this->value = new char[otherValueLen];
	strcpy_s(this->value, otherValueLen, other.value);
}

void String::destroy()										//helper destruct function
{
	delete[] value;
}

String::String()											//default constructor
{
	this->value = new char[1];
	strcpy_s(this->value, 1, "");
}

String::String(const char* value)							//constructor
{
	int OtherValueLen = strlen(value) + 1;
	this->value = new char[OtherValueLen];
	strcpy_s(this->value, OtherValueLen, value);
}

String::String(const String& other)							//copy constructor
{
	this->copy(other);
}
String& String::operator=(const String& other)				//operator =
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}
	return *this;
}

String& String::operator+(const String& other)				//concat strings operator +
{
	int len = strlen(this->value) + strlen(other.value) + 1;
	char* newValue = new char[len];
	strcpy_s(newValue, len ,this->value);
	strcat(newValue, other.value);
	delete[] this->value;
	this->value = newValue;
	return *this;
}

String::~String()											//destructor
{
	this->destroy();
}

void String::print() const									//print function
{
	std::cout << this->value << std::endl;
}

char* String::convertToPointer()						    //convert String to char*
{
	return this->value;
}


std::ostream& operator<<(std::ostream& output, const String& other)			//operator<< for ostream
{
	output << other.value << std::endl;
	return output;
}

std::istream& operator>>(std::istream& input, String& other)				//operator>> for istream
{
	char buffer[1024];
	input.getline(buffer, 1024);
	other.operator+(buffer);
	return input;
}
char String::operator [] (const size_t index)const							//operator[] get element from index
{
	return (index <= strlen(this->value)) ? this->value[index] : '\0';
}