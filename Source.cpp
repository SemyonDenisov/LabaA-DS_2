#include <iostream>
#include <string>
#include <windows.h>
#include "MyString.h"
#include "menu.h"
int main()
{
	int n = 0;
	char* string_1 = new char[100];
	std::cout << "Enter the first string:";
	std::cin  >> string_1;
	int len1 = strlen(string_1);
	char* string_2 = new char[100];
	std::cout << "Enter the second string:";
	std::cin  >> string_2;
	int len2 = strlen(string_2);
	int choise = 0;
	std::cout << "Choise a type of strings:" <<std::endl;
	std::cout << "1)Int" << std::endl;
	std::cout << "2)Double" << std::endl;
	std::cout << "3)Char" << std::endl;
	std::cin >> choise;
	if (choise == 1)
	{
		int* arr1 = new int[len1*sizeof(char)];
		for (int i = 0; i < len1; i++)
		{
			arr1[i] = string_1[i] - '0';
		}
		MyString<int> A(arr1, len1);
		int* arr2 = new int[len2 * sizeof(char)];
		for (int i = 0; i < len2; i++)
		{
			arr2[i] = string_2[i] - '0';
		}
		MyString<int> B(arr2, len2);
		menuint(A,B);
	}
	else if (choise == 2)
	{
		double len_double_1 = 0;
		double len_double_2 = 0;
		char* tmp = string_1;
		int size=0;
		while (*tmp)
		{
			size++;
			tmp++;
		}
		double* arr1 = new double[size*sizeof(char)];
		tmp = string_2;
		size = 0;
		while (*tmp)
		{
			size++;
			tmp++;
		}
		double* arr2 = new double[size * sizeof(char)];
		int i = 0;
		int e = 0;
		while (i < len1)
		{
			int len = 0;
			char* temp = string_1;
			while ((*temp != ',')&&(*temp != '\0'))
			{
				len++;
				temp++;
			}
			char* part = new char[len * sizeof(char)+1];
			for (int k = 0; k < len; k++)
			{
				part[k] = *string_1;
				string_1++;
				i++;
			}
			double result = std::stod(part);
			arr1[e] = result;
			string_1++;
			len_double_1 ++;
			i++;
			e++;
		}
		MyString <double> A(arr1,len_double_1);
		i = 0;
		e = 0;
		while (i < len2)
		{
			int len = 0;
			char* temp = string_2;
			while ((*temp != ',') && (*temp != '\0'))
			{
				len++;
				temp++;
			}
			char* part = new char[len * sizeof(char) + 1];
			for (int k = 0; k < len; k++)
			{
				part[k] = *string_2;
				string_2++;
				i++;
			}
			double result = std::stod(part);
			arr2[e] = result;
			string_2++;
			len_double_2++;
			i++;
			e++;
		}
		MyString < double > B(arr2, len_double_2);
		menudouble(A,B);
	}
	else if (choise == 3)
	{
		MyString < char > A(string_1, len1);
		MyString < char > B(string_2, len2);
		menuchar(A, B);
	}
	return 0;
};