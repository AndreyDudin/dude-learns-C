#include "stdafx.h"
#include "Char_Array.h"
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

Char_Array::Char_Array()
{
	amount_of_words = 0;
}

Char_Array::Char_Array(const Char_Array &ob) :amount_of_words(ob.amount_of_words), ar(NULL)
{
	if (amount_of_words > 0)
	{
		ar = new char*[amount_of_words];
		for (int i = 0; i < amount_of_words; i++)
		{
			ar[i] = new char[strlen(ob.ar[i]) + 1];
			strcpy(ar[i], ob.ar[i]);

		}
	}
}
Char_Array::Char_Array(const char *s)
	:amount_of_words(1)
	
{
	
	if (strlen(s) > MAXLENGTH)
	{
		throw std::exception("Too long word");
	}
	ar = new char*[amount_of_words];
	ar[0] = new char[strlen(s) + 1];
	strcpy(ar[0], s);

}

Char_Array::Char_Array(const int n, const char** mas)

{
	/*if (n > MAXAMOUNT)
	{
		throw std::exception("Too much words\n");
	}

	for (int i = 0; i < n; i++)
	{
		if (strlen(mas[i])>MAXLENGTH)
		{
			throw std::exception("Incorrect length of word\n");
		}
	}
	*/
	amount_of_words = n;
	ar = new char*[amount_of_words];
	for (int i = 0; i < n; i++)
	{
		ar[i] = new char[strlen(mas[i]) + 1];
		strcpy(ar[i], mas[i]);

	}
}


std::ostream& operator<<(std::ostream& os, const Char_Array& ch)
{
	for (int i = 0; i < ch.amount_of_words; i++)
	{
		os << ch.ar[i] << " ";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Char_Array& ch)
{
	char c;
	std::string s;
	//char *str;
	ch.amount_of_words = 0;
	do {
		is >> s;
		

		ch +=s.c_str();
		


	/*	if (ch.amount_of_words + 1>MAXAMOUNT)
		{
			is.setstate(std::ios::failbit);
			std::cerr << "failbit was set" << std::endl; ///??? no exception -> is.setstate(std::ios_base::failbit)
			return is;
		}
		if (strlen(ch.ar[ch.amount_of_words]) > MAXLENGTH)
		{
			is.setstate(std::ios::failbit);
			std::cerr << "failbit was set" << std::endl;
			return is;

		}
		*/
		ch.amount_of_words++;

		c = is.get();
		if (c == '\n') break;
		if (c == ' ') continue;
		is.unget();
	} while (true);
	return is;
}

int Char_Array::search(const char* word) const
{

	for (int i = 0; i < amount_of_words; i++)
	{
		if (strcmp(ar[i], word) == 0)
		{
			return i;
		}
	}

	return -1;
}


void Char_Array::sort()
{
	for (int i = 0; i < amount_of_words - 1; i++)
	{
		for (int j = i + 1; j < amount_of_words; j++)
		{
			if (strcmp(ar[i], ar[j]) > 0)
			{
				char temp[MAXLENGTH];
				strcpy(temp, ar[i]);
				strcpy(ar[i], ar[j]);
				strcpy(ar[j], temp);

			}

		}
	}
	return;
}


Char_Array& Char_Array::operator +=(const Char_Array &s)
{
	
	/*if (amount_of_words + s.amount_of_words>MAXAMOUNT)
	{
		throw std::exception("Too much words\n");
	}
	*/
	char **new_ar = new char*[amount_of_words + s.amount_of_words];

	for (int i = 0; i <amount_of_words; i++)
	{
		new_ar[i] = new char[strlen(ar[i])];
		strcpy(new_ar[i], ar[i]);
	}

	for (int i = 0; i < s.amount_of_words; i++)
	{

		new_ar[amount_of_words] = new char[strlen(s.ar[i])];
		strcpy(new_ar[amount_of_words++], s.ar[i]);
	}
	ar = new_ar;
	return *this;
}

Char_Array& Char_Array::operator +=(const char *s)
{

	//	int qu = amount_of_words;
	char **new_ar = new char*[amount_of_words + 1];
	for (int i = 0; i <amount_of_words; i++)
	{
		new_ar[i] = new char[strlen(ar[i])];
		strcpy(new_ar[i], ar[i]);
	}

	new_ar[amount_of_words] = new char[strlen(s)];

	strcpy(new_ar[amount_of_words++], s);
	ar = new_ar;
	return *this;

}

const char* Char_Array::operator[](int w) const
{
	if (w < 0 || w >= amount_of_words)
	{
		throw::exception("illegal index\n");

	}
	return ar[w];
}

Char_Array Char_Array::operator () (const char c)
{
	Char_Array ch;


	for (int i = 0; i < amount_of_words; i++)
	{
		if (tolower(ar[i][0]) == tolower(c))
		{
			ch += ar[i];

		}
	}

	return ch;
}

Char_Array::~Char_Array()
{
}
