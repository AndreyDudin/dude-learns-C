
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Char_Array
{
private:
	char** ar;
	int amount_of_words;
public:
	Char_Array();
	Char_Array(const char *s);
	Char_Array(const int n, const char** mas);
	Char_Array(const Char_Array &ob);
	Char_Array(Char_Array&& ob);
	//move constr
	virtual ~Char_Array();

	friend std::ostream& operator<<(std::ostream& os, const Char_Array& ch);
	friend std::istream& operator>>(std::istream& is, Char_Array& ch);

	Char_Array& operator +=(const char *s);
	Char_Array& operator +=(const Char_Array &s);
	Char_Array Char_Array::operator () (const char c);
	Char_Array& operator =(const Char_Array &ob);
	Char_Array& operator =( Char_Array &&ob);
	const char* operator [](int) const;

	void sort();
	int search(const char* word) const;


};

