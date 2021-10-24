#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <locale>
#include <string>
#include<windows.h>
template <class T>
class MyString
{
private:
	T* data;
	size_t size;
public:
	MyString<T>()
	{
		T* data = NULL;
		size = 0;
	}
	MyString<T>(const T* str, int  len)
	{
		size = 0;
		const T* temp = str;
		while (len != 0)
		{
			size++;
			temp++;
			len--;
		}
		data = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			data[i] = str[i];
		}
		data[size] = '\0';
	}
	MyString(const MyString& other)
	{
		this->size = other.size;
		data = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		if (data)
		{
			data[size] = '\0';
		}
	}
	~MyString()
	{
		if (data)
		{
			delete data;
		}
	}

	T& operator [] (int index)
	{
		if (index < 0 || index >= size)
		{
			throw "Invalid index";
		}
		return data[index];
	}

	friend MyString operator + (const MyString& str_1, const MyString& str_2)
	{
		MyString result;
		result.size = str_1.size + str_2.size;
		result.data = new T[result.size + 1];
		for (int i = 0; i < str_1.size; i++)
		{
			result.data[i] = str_1.data[i];
		}
		for (int i = 0; i < str_2.size; i++)
		{
			result.data[str_1.size + i] = str_2.data[i];
		}
		return result;
	}

	friend MyString operator * (MyString& str, int count)
	{
		if (count < 0)
		{
			throw "Multiplying a string by negative number";
		}
		MyString result;
		result.size = count * str.size;
		result.data = new T[count * str.size + 2];
		for (int k = 0; k < result.size; k++)
		{
			result.data[k] = str.data[k % str.size];
		}
		result.data[result.size] = '\0';
		return result;
	}

	friend MyString operator * (int count, MyString& str)
	{
		return operator * (str, count);
	}

	MyString substring(int index, int lenght)
	{
		if (index < 0 || index > size)
		{
			throw "Invalid index";
		}
		if (index + lenght > size)
		{
			throw "Incorrect substring parameters";
		}
		MyString str;
		str.data = new T[lenght + 1];
		for (int i = index; i < lenght + index; i++)
		{
			str.data[str.size] = data[i];
			str.size++;
		}
		//str.data[str.size] = '\0';
		return str;
	}

	bool operator == (MyString& str)
	{
		if (size != str.size)
		{
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			if (data[i] != str.data[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(MyString& str)
	{
		return !(operator ==(str));
	}

	friend std::ostream& operator << (std::ostream& out, const MyString& str)
	{
		out << "MyString:  ";
		for (int i = 0; i < str.size; i++)
		{
			out << "(";
			out << str.data[i];
			out << ")";
		}
		return out;
	}
};
int main()
{
	double n[] = { 1.3,2.4,3.5 };
	double* ptr = n;
	bool ex = true;
	char* string_2 = new char;
	std::cout << "Enter the first string:";
	MyString<double> A(ptr, 3);
	//std::cout << "Enter the second string:";
	//std::cin >> string_2;
	MyString<double> B(ptr, 3);
	std::cout << B << std::endl;
	MyString<double> C = A + B;
	std::cout << C << std::endl;
	if (A == B)
	{
		std::cout << "yeah" << std::endl;
	}
	MyString<double> D = A.substring(0,2);
	std::cout << D << std::endl;
	MyString<double> X = A*3;
	std::cout << X << std::endl;
	//while (ex)
	//{
	//	std::cout << "1)" << A << std::endl;
	//	std::cout << "2)" << B << std::endl;
	//	std::cout << "\n";
	//	std::cout << "Choise the menu item:" << std::endl;
	//	std::cout << "1)Changing an item by index" << std::endl;
	//	std::cout << "2)Equality check" << std::endl;
	//	std::cout << "3)Concotenation" << std::endl;
	//	std::cout << "4)Get the substring" << std::endl;
	//	std::cout << "5)Multiplying a string by number" << std::endl;
	//	std::cout << "6)Exit" << std::endl;
	//	std::cin >> n;
	//	system("cls");
	//	std::cout << "1)" << A << std::endl;
	//	std::cout << "2)" << B << std::endl;
	//	switch (n)
	//	{

	//	case 1://Changing an item by index
	//	{
	//		int number;
	//		std::cout << "Which line would you like to change:" << std::endl;
	//		std::cin >> number;
	//		int index;
	//		char character;
	//		std::cout << "Enter the element index:" << std::endl;
	//		std::cin >> index;
	//		std::cout << "Enter the element:" << std::endl;
	//		std::cin >> character;
	//		system("cls");
	//		if (number == 1)
	//		{
	//			try
	//			{
	//				A[index] = character;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		if (number == 2)
	//		{
	//			try
	//			{
	//				B[index] = character;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		break;
	//	}

	//	case 2://Equality check
	//	{
	//		system("cls");
	//		if (A == B)
	//		{
	//			std::cout << "Strings are equal" << std::endl;
	//		}
	//		else
	//			std::cout << "Strings are not equal" << std::endl;
	//		break;
	//	}

	//	case 3://Concotenation
	//	{
	//		system("cls");
	//		MyString Result = A + B;
	//		std::cout << Result << " - Result string" << std::endl;
	//		break;
	//	}

	//	case 4://Get the substring
	//	{
	//		int number;
	//		std::cout << "Number of string,which you want to get substring:" << std::endl;
	//		std::cin >> number;
	//		int index;
	//		int lenght;
	//		std::cout << "Enter the start index" << std::endl;
	//		std::cin >> index;
	//		std::cout << "Enter the lenght" << std::endl;
	//		std::cin >> lenght;
	//		system("cls");
	//		if (number == 1)
	//		{
	//			try
	//			{
	//				MyString D = A.substring(index, lenght);
	//				std::cout << D << " - Result string" << std::endl;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		if (number == 2)
	//		{
	//			try
	//			{
	//				MyString D = B.substring(index, lenght);
	//				std::cout << D << " - Result string" << std::endl;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		break;
	//	}

	//	case 5://Multiplying a string by number
	//	{
	//		int number;
	//		int count;
	//		std::cout << "Which line would you like to multiplying:" << std::endl;
	//		std::cin >> number;
	//		std::cout << "Number to multiply:" << std::endl;
	//		std::cin >> count;
	//		system("cls");
	//		if (number == 1)
	//		{
	//			try
	//			{
	//				MyString D = A * count;
	//				std::cout << D << " - Result string" << std::endl;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		if (number == 2)
	//		{
	//			try
	//			{
	//				MyString D = B * count;
	//				std::cout << D << " - Result string" << std::endl;
	//			}
	//			catch (const char* err)
	//			{
	//				std::cout << err << std::endl;
	//			}
	//		}
	//		break;
	//	}

	//	case 6://Exit
	//	{
	//		system("cls");
	//		ex = false;
	//	}
	//	}
	//}
	return 0;
};