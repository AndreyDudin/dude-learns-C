// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include "..\Dynamic_Char_Library\Char_Array.h"



using namespace std;
const char* MENU = "1.Create new array\n2.Write the array\n3.Add words\n4.Search the word\n5.Allocation the word\n6.Form a new array\n7.Sort the array\n";
int _tmain(int argc, _TCHAR* argv[])
{
	const char* numbers[] = { "zero", "one", "two","zeroq" };
	Char_Array sy;
	Char_Array q;
	Char_Array add;
	//Char_Array ob;
	Char_Array ob(4, numbers);
	char *str = new char[81];
	char* s;
	const char *wrd;
	char c, sym;
	int n, k;
	for (;;)
	{
		std::cout << MENU << std::endl;
		c = _getch();
		
			switch (c)
			{
			case '1':

				std::cout << "Enter new array" << std::endl;
			
					std::cin >> ob;
				
				break;
			case '2':
				std::cout << ob << std::endl;
				break;
			case '3':
				std::cout << "Enter the words for add" << std::endl;
				std::cin >> add;
				ob += add;
				break;
			case '4':

				std::cout << "Enter the word" << std::endl;
				std::cin >> str;
				k = ob.search(str);
				if (k == -1)
				{
					std::cout << "No" << std::endl;
				}
				else
				{
					std::cout << "Position= " << k << std::endl;
				}
				break;

			case '5':

				std::cout << "Enter the number" << std::endl;
				n = 0;
				std::cin >> n;
				wrd = ob[n];
				std::cout << "Word is " << wrd << std::endl;
				break;
			case '6':
				std::cout << "Enter the symbol" << std::endl;
				std::cin >> sym;
				sy = ob(sym);
				std::cout << "New array:" << std::endl;
				std::cout << sy << std::endl;
				break;


			case '7':
				ob.sort();
				break;



			}
		
		
		if (c == '0')
		{

			break;
		}
	}


	return 0;
}

