#ifndef STRING_H
#define STRING_H
class String
{
	char* data;
	int size;
	int getLength(const char* str)const;
	void copyString(char* dest, const char* src)const;
	bool isValidIndex(const int index)const;
	bool isSameString(const char*, const char*);
	void swap(char& p, char& q);
	void concatenate(char* dest, const char* src)const;
	bool isWideSpaceCharacter(char ch)const;
	float getDecimalPart()const;
public:
	String(const String&);//tested
	String();//tested
	String(const char c);//tested
	String(const char* str);//tested
	String concatenate(const String& s2)const;
	void input();//tested
	~String();
	void makeLower();//tested
	void shrink();//tested
	float convertToFloat()const;
	void insert(const int index, const String& subStr);
	int compare(const String& s2)const;//tested
	int getSize()const;//tested
	void reSize(const int);
	int getLength()const;
	void display()const;
	void reverse();//tested
	bool isEmpty()const;//tested
	void makeUpper();//tested
	int find(const String subStr, const int start = 0);//tested
	char& at(const int index);//tested
	const char& at(const int index)const;
	int replace(const String& old, const String& newSubStr);
	void remove(const int index, const int count = 1);//tested
	void trimLeft();
	void trimRight();
	void trim();
	String left(const int count);
	String right(const int count);
	void setNumber(const long long int num);
	long long int convertToInteger()const;
	void concatEqual(const String& s2);
};
#endif 
