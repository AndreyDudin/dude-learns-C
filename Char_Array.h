#pragma once
#define  MAXLENGTH 80
#define  MAXAMOUNT 80
#include <iostream>
using namespace std;
class Char_Array
{
	private:
	char ar[MAXAMOUNT][MAXLENGTH];
	int amount_of_words;


public:
	int search(const char* word);
	Char_Array();
	Char_Array(const char *s);
	Char_Array(const int n, char** mas);
	friend std::ostream& operator<<(std::ostream& os, const Char_Array& ch);
	friend std::istream& operator>>(std::istream& is,  Char_Array& ch);
	Char_Array& operator +=(const char *s);
	~Char_Array();
	Char_Array& operator () (const char c);
	const char* operator [](int) const;
	Char_Array sort(Char_Array ch);
};
