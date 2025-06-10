#include<iostream>
#include "String.h"
using namespace std;
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c)
{
	size = 2;
	data = new char[size] {c, '\0'};
}
String::String(const char* str) :String()
{
	int strLength = getLength(str);
	if (strLength == 0)
	{
		return;
	}
	size = strLength + 1;
	data = new char[size];
	copyString(data, str);
}
String::String(const String& ref) :String()
{
	if (ref.data == nullptr)
	{
		return;
	}
	size = ref.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = ref.data[i];
	}
}
int String::getLength(const char* str)const
{
	int i = 0;
	if (str == nullptr)
	{
		return i;
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void String::copyString(char* dest, const char* src)const
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
int String::getSize()const
{
	return size;
}
String::~String()
{
	delete[]data;
	data = nullptr;
	size = 0;
}
void String::input()
{
	int count = 0;
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		data[count] = ch;
		if (count + 1 == size)
		{
			reSize(size * 2);
		}
		count++;
	}
	data[count] = '\0';
}
void String::reSize(const int newSize)
{
	if (newSize <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[newSize];
	int i = 0;
	while (i < newSize - 1 && i < getLength())
	{
		temp[i] = data[i] >= 0 ? data[i] : 0;
		i++;
	}
	temp[i] = '\0';
	this->~String();
	size = newSize;
	data = temp;
}
int String::getLength()const
{
	return getLength(data);
}
void String::display()const
{
	if (!isEmpty())
		cout << data;
}
bool String::isEmpty()const
{
	return data == nullptr || data[0] == '\0';
}
char& String::at(const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
const char& String::at(const int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << isValidIndex(0);
	exit(0);
}
bool String::isValidIndex(const int index)const
{
	return index >= 0 && index < getSize() ? true : false;
}
int String::compare(const String& s2)const
{
	if (getLength() >= s2.getLength())
	{
		if (data == "\0\0" && data == s2.data)
		{
			return 0;
		}
		for (int i = 0; data[i] != '\0'; i++)
		{
			if (data[i] < s2.data[i])
			{
				return -1;
			}
			else if (data[i] > s2.data[i])
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; s2.data[i] != '\0'; i++)
		{
			if (s2.data[i] < data[i])
			{
				return 1;
			}
			else if (s2.data[i] > data[i])
			{
				return -1;
			}
		}
		return 0;

	}
}
void String::shrink()
{
	reSize(getLength() + 1);
}
bool String::isSameString(const char* firstStr, const char* secondStr)
{
	if (firstStr[0] != '\0')
	{
		for (int i = 0; firstStr[i] != '\0'; i++)
		{
			if (firstStr[i] != secondStr[i])
			{
				return false;
			}
		}
		return true;
	}
	return firstStr[0] == secondStr[0];
}
int String::find(const String subStr, const int start)
{
	for (int i = start; i < getLength(); i++)
	{
		if (isSameString(subStr.data, &data[i]))
		{
			return i;
		}
	}
	return -1;
}
void String::reverse()
{
	if (getLength() != 0)
	{
		for (int j = getLength() - 1, i = 0; i < j; j--, i++)
		{
			swap(data[i], data[j]);
		}
	}
}
void String::swap(char& p, char& q)
{
	int temp = p;
	p = q;
	q = temp;
}
void String::makeUpper()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			int a = data[i] - 97;
			data[i] = a + 'A';
		}
	}
}
void String::makeLower()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			int a = data[i] - 65;
			data[i] = a + 97;
		}
	}
}
void String::insert(const int index, const String& subStr)
{
	if (isValidIndex(index))
	{
		int sizeOfNewString = getLength() + subStr.getLength() + 1;
		char* temp = new char[sizeOfNewString];
		for (int i = 0, j = 0; i < sizeOfNewString; i++)
		{
			if (i != index)
			{
				temp[i] = data[j];
				j++;
			}
			else
			{
				copyString(&temp[i], subStr.data);
				i = getLength(subStr.data) + i - 1;
			}
		}
		this->~String();
		data = temp;
		size = sizeOfNewString;
	}
}
void String::remove(const int index, const int count)
{
	if (isValidIndex(index) && getLength() != 0 && count > 0)
	{
		char* temp = new char[getLength() + 2] {'\0'};
		int i, j;
		for (i = 0, j = 0; i < getLength(); i++)
		{
			if (i<index || i>(index + count - 1))
			{
				temp[j] = data[i];
				temp[j + 1] = '\0';
				j++;
			}
		}
		this->~String();
		data = temp;
		size = getLength() + 1;
	}
}
int String::replace(const String& old, const  String& newSubStr)
{
	int count = 0;
	if (!isEmpty())
	{
		int sizeOfNewString = (find(old) * getLength(newSubStr.data) + getLength()) - (find(old) * getLength(old.data)) + 1;
		char* temp = new char[sizeOfNewString] {'\0'};
		for (int j = 0, i = 0; i < getLength(); i++)
		{
			if (isSameString(old.data, &data[i]))
			{
				concatenate(temp, newSubStr.data);
				i = getLength(old.data) + i - 1;
			}
			else
			{
				int j = getLength(temp);
				temp[j] = data[i];
				temp[j + 1] = '\0';
			}
		}
		this->~String();
		data = temp;
		size = sizeOfNewString;
	}
	return count;
}
void String::concatenate(char* dest, const char* src)const
{
	int i = getLength(dest);
	copyString(&dest[i], src);
}
String String::concatenate(const String& s2)const
{
	if (data == nullptr && s2.data == nullptr)
	{
		String s;
		return s;
	}
	else if (s2.data == nullptr || data == nullptr)
	{
		String s{ data == nullptr ? s2.data : data };
		return s;
	}
	int i = getLength();
	int j = getLength(s2.data);
	String str;
	char* temp = new char[i + j + 2];
	copyString(temp, data);
	concatenate(temp, s2.data);
	str.data = temp;
	str.size = i + j + 1;
	return str;
}
void String::trimLeft()
{
	if (!isEmpty())
	{
		int i = 0;
		while (i < getLength() && isWideSpaceCharacter(data[i]))
		{
			i++;
		}
		if (!isWideSpaceCharacter(data[i]))
		{
			char* temp = new char[getSize() - i + 1];
			copyString(temp, &data[i]);
			this->~String();
			data = temp;
			size = getSize() - i;
		}
	}
}
bool String::isWideSpaceCharacter(char ch)const
{
	return ch == ' ' || ch == '\t' || ch == '\n';
}
void String::trimRight()
{
	if (!isEmpty())
	{
		int i = getLength() - 1;
		while (i >= 0 && isWideSpaceCharacter(data[i]))
		{
			data[i] = '\0';
			i--;
		}
	}
}
void String::trim()
{
	if (!isEmpty())
	{
		trimLeft();
		trimRight();
	}
}

String String::left(const int count)
{
	String str;
	char* ch;
	if (count <= 0 || isEmpty())
	{
		this->~String();
		return str;
	}
	else if (count >= getSize())
	{
		ch = new char[getSize()];
		copyString(ch, data);
		str.data = ch;
		str.size = this->size;
		this->~String();
	}
	else
	{
		int j = getLength();
		ch = new char[count + 1];
		char temp = data[count];
		data[count] = '\0';
		copyString(ch, data);
		str.data = ch;
		str.size = count + 1;
		for (int i = 1; i <= (j - count); i++)
		{
			swap(data[i], data[i + count]);
		}
		data[0] = temp;
	}
	return str;
}
String String::right(const int count)
{
	String str;
	if (data != nullptr && count > getLength())
	{
		int j = count;
		char* temp = new char[count + 1];
		int i = getLength();
		while (i > 0 && j != 0)
		{
			j--;
			i--;
		}
		copyString(temp, &data[i]);
		str.data = temp;
		str.size = count + 1;
		data[i] = '\0';
		return str;
	}
	return str;
}
long long int String::convertToInteger()const
{
	int i = 0;
	long long int  number = 0;
	if (!isEmpty())
	{
		while (data[i] != '\0' && data[i] != '.')
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				int digit = (int)data[i] - '0';
				number = number * 10 + digit;
			}
			i++;
		}
	}
	return number;
}
float String::convertToFloat()const
{
	float number = 0;
	if (!isEmpty())
	{
		number = getDecimalPart() + convertToInteger();
	}
	return number;
}
float String::getDecimalPart()const
{
	float decimalPart = 0, p = 10.0;
	int i = 0;
	while (data[i] != '.' && data[i] != '\0')
	{
		i++;
	}
	if (data[i] == '.')
	{
		i++;
		while (data[i] >= '0' && data[i] <= '9')
		{
			decimalPart = (data[i] - '0') / p + decimalPart;
			p = p * 10.0;
			i++;
		}
	}
	return decimalPart;
}
void String::setNumber(const long long int num)
{
	size = 0;
	long long int temp = num;
	while (temp != 0)
	{
		temp = temp / 10;
		size++;
	}
	long long int tempNum = num;
	char* ch;
	if (num != 0)
	{
		ch = new char[size + 2];
		for (int i = size; i >= 1; i--)
		{
			ch[i] = ((num < 0 ? -1 : 1) * (tempNum % 10)) + '0';
			tempNum = tempNum / 10;
		}
		num < 0 ? ch[0] = '-' : ch[0] = ' ';
		ch[size + 1] = '\0';
	}
	else
	{
		ch = new char[2] {'0', '\0'};
	}
	size = size + 2;
	delete[]data;
	data = ch;
}
void String::concatEqual(const String& s2)
{
	if (!s2.isEmpty())
	{
		reSize(getLength() + s2.getLength() + 1);
		copyString(&data[getLength()], s2.data);
	}
}