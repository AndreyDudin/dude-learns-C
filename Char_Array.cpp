#include "stdafx.h"
#include "Char_Array.h"
#include <string.h>
#include <stdlib.h>
#define  maxlength 80;
#define  maxamount 80;
#define _CRT_SECURE_NO_WARNINGS


Char_Array::Char_Array()
{
	amount_of_words = 0;
}
Char_Array::Char_Array(const char *s)
{
	strcpy_s(ar[0], s);
	amount_of_words = 1;
}

Char_Array::Char_Array(const int n, char **mas)
{
	amount_of_words = n;
	for (int i = 0; i < n; i++)
	{
		strcpy_s(ar[i], mas[i]);

	}
	 

	
}
Char_Array& Char_Array::operator()(const char c)
{
	Char_Array ch;
	ch.amount_of_words = 0;
	int n = 0;
	for (int i = 0; i < amount_of_words; i++)
	{
		if (ar[i][0]==c)

		{
			ch.amount_of_words++;
			strcpy_s(ch.ar[n++],ar[i]);

		}
	}
	return ch;
}







Char_Array::~Char_Array()
{
}
std::ostream& operator<<(std::ostream& os, const Char_Array& ch)
{
	for (int i = 0; i < ch.amount_of_words; i++)
	{
		os << ch.ar[i] << " ";
	}
}

std::istream& operator>>(std::istream& is,  Char_Array& ch)
{
	char c;
	ch.amount_of_words = 0;
	do {
		is >> ch.ar[ch.amount_of_words++];
		c = is.get();
		if (c == '\n') break;
		if (c == ' ') continue;
		is.unget();
	} while (true);
}

int Char_Array::search(const char* word)
{

	for (int i = 0; i < amount_of_words; i++)
	{
		if (ar[i] == word)
		{
			cout << "Position in array= " << i << endl;
			return i;
		}
	}

	return 100;
}



Char_Array& Char_Array::operator +=(const char *s)
{

	int qu = amount_of_words;
	if ((amount_of_words + 1) > MAXAMOUNT)
	{
		throw std::exception("Too much words");		
	}
	strcpy_s(ar[++amount_of_words],s);
	return *this;
		
}


const char* Char_Array::operator[](int w) const
{
	if (w < 0 || w >= amount_of_words)
	{
		throw::exception("illegal index");

	}
	return ar[w];
}




/*Char_Array Char_Array::sort(Char_Array ch)
{
	for (int i = 0; i < amount_of_words; i++)
	{
		for (int j = i+1; j < amount_of_words-1; j++)
		{
			if (strcmp(ar[i], ar[j]) > 0)
			{
				char *temp = new char[MAXLENGTH];
				strcpy(temp, ar[j]);
				strcpy(ar[i], ar[j]);
				strcpy(ar[j], temp);

			}
			
		}
	}
	return *this;
}
*/