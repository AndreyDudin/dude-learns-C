#include "stdafx.h"
#include "Char_Array.h"
#include <string.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

Char_Array::Char_Array()
{
	amount_of_words = 0;
	ar = nullptr;
}


Char_Array::Char_Array(Char_Array && ob) :amount_of_words(ob.amount_of_words), ar(ob.ar)

{
	ob.ar = nullptr;
}


Char_Array& Char_Array::operator=(Char_Array && ob)
{
	int tamount_of_words = amount_of_words;
	amount_of_words = ob.amount_of_words;
	ob.amount_of_words = tamount_of_words;
	char** tar = ar;
	ar = ob.ar;
	ob.ar = tar;
	return *this;
}




Char_Array::Char_Array(const Char_Array &ob) :amount_of_words(ob.amount_of_words), ar(nullptr) ///???
{
	if (amount_of_words > 0)
	{
		ar = new char*[amount_of_words];

		for (int i = 0; i < amount_of_words; i++)
		{
			try
			{
				ar[i] = new char[strlen(ob.ar[i]) + 1];//catch(std::bad_alloc)
				strcpy(ar[i], ob.ar[i]);
			}

			catch (std::bad_alloc &t)
			{
				for (int i = 0; i < amount_of_words; i++)
				{
					delete[]ar[i];
				}
				delete[]ar;
				throw t;
			}


		}
	}
}

Char_Array& Char_Array::operator =(const Char_Array &ob)
{
	if (this != &ob)
	{

		for (int i = 0; i < amount_of_words; i++)
		{
			delete[]ar[i];
		}
		delete[]ar;
		ar = nullptr;
		try{
			if ((amount_of_words = ob.amount_of_words) != 0)
			{
				ar = new char*[ob.amount_of_words];
				for (int i = 0; i < amount_of_words; i++)
				{
					ar[i] = new char[strlen(ob.ar[i]) + 1];
					strcpy(ar[i], ob.ar[i]);

				}
			}
		}
		catch (std::bad_alloc &t)
		{
			for (int i = 0; i < amount_of_words; i++)
			{
				delete[]ar[i];
			}
			delete[]ar;
			throw t;
		}

	}
	return *this;
}

Char_Array::Char_Array(const char *s)
	:amount_of_words(1)

{
	ar = new char*[amount_of_words];

	try
	{
		ar[0] = new char[strlen(s) + 1];//catch(std::bad_alloc)
		strcpy(ar[0], s);
	}

	catch (std::bad_alloc &t)
	{
		for (int i = 0; i < amount_of_words; i++)
		{
			delete[]ar[i];
		}
		delete[]ar;
		throw t;
	}

}

Char_Array::Char_Array(const int n, const char** mas)

{
	amount_of_words = n;
	ar = new char*[amount_of_words];
	for (int i = 0; i < amount_of_words; i++)
	{
		try
		{
			ar[i] = new char[strlen(mas[i]) + 1];//catch(std::bad_alloc)
			strcpy(ar[i], mas[i]);
		}

		catch (std::bad_alloc &t)
		{
			for (int i = 0; i < amount_of_words; i++)
			{
				delete[]ar[i];
			}
			delete[]ar;
			throw t;
		}

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
	for (int i = 0; i < ch.amount_of_words; i++)
		delete[] ch.ar[i];
	delete[] ch.ar;
	ch.ar = nullptr;
	ch.amount_of_words = 0;
	do {
		is >> s;
		try
		{
			ch += s.c_str();
		}
		catch (std::bad_alloc &t)
		{
			is.setstate(std::ios::failbit);
			std::cerr << "failbit was set" << std::endl;
			return is;
		}

		c = is.get();
		if (c == '\n') break;
		if (c == ' ') continue;
		is.unget();
	} while (true);
	for (int i = 0; i < ch.amount_of_words - 1; i++)
	{
		for (int j = i + 1; j < ch.amount_of_words; j++)
		{
			if (strcmp(ch.ar[i], ch.ar[j]) == 0)
			{
				is.setstate(std::ios::failbit);
				std::cerr << "failbit was set" << std::endl;
				return is;
			}
		}
	}
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
				char *temp = new char[strlen(ar[i])];
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

	int n = amount_of_words;
	char **new_ar = new char*[amount_of_words + s.amount_of_words];
	try
	{
		for (int i = 0; i < amount_of_words; i++)
		{
			new_ar[i] = new char[strlen(ar[i]) + 1];
			strcpy(new_ar[i], ar[i]);
		}


		for (int i = 0; i < s.amount_of_words; i++)
		{
			new_ar[amount_of_words] = new char[strlen(s.ar[i]) + 1];
			strcpy(new_ar[amount_of_words++], s.ar[i]);
		}
	}
	catch (std::bad_alloc &t)
	{
		throw t;
	}
	if (ar)
	{
		for (int i = 0; i < n; i++)
			delete[] ar[i];
		delete[] ar;
	}
	
	ar = new_ar;
	return *this;
}


Char_Array& Char_Array::operator +=(const char *s)
{

	char **new_ar = new char*[amount_of_words + 1];
	try
	{
		for (int i = 0; i < amount_of_words; i++)
		{

			new_ar[i] = new char[strlen(ar[i])+1];
			strcpy(new_ar[i], ar[i]);
		}

		new_ar[amount_of_words] = new char[strlen(s) + 1];
		strcpy(new_ar[amount_of_words], s);
	}
	catch (std::bad_alloc &t)
	{
		throw t;
	}
	if (ar)
	{
		for (int i = 0; i < amount_of_words; i++)
			delete[] ar[i];
		delete[] ar;
	}

	amount_of_words++;
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

	for (int i = amount_of_words - 1; i>=0; i--)
	{
		delete[] ar[i];
	}
	delete[]ar;
	ar = nullptr;



}
