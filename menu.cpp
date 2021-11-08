#include "menu.h"
void menudouble(MyString<double> A, MyString<double> B)
{
	bool ex = true;
	int choise;
	while (ex)
	{
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		std::cout << "\n";
		std::cout << "Choise the menu item:" << std::endl;
		std::cout << "1)Changing an item by index" << std::endl;
		std::cout << "2)Equality check" << std::endl;
		std::cout << "3)Concotenation" << std::endl;
		std::cout << "4)Get the substring" << std::endl;
		std::cout << "5)Multiplying a string by number" << std::endl;
		std::cout << "6)Exit" << std::endl;
		std::cin >> choise;
		//system("cls");
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		switch (choise)
		{

		case 1://Changing an item by index
		{
			int number;
			std::cout << "Which line would you like to change:" << std::endl;
			std::cin >> number;
			int index;
			double character;
			std::cout << "Enter the element index:" << std::endl;
			std::cin >> index;
			std::cout << "Enter the element:" << std::endl;
			std::cin >> character;
			system("cls");
			if (number == 1)
			{
				try
				{
					A[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					B[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 2://Equality check
		{
			system("cls");
			if (A == B)
			{
				std::cout << "Strings are equal" << std::endl;
			}
			else
				std::cout << "Strings are not equal" << std::endl;
			break;
		}

		case 3://Concotenation
		{
			system("cls");
			MyString<double> Result = A + B;
			std::cout << Result << " - Result string" << std::endl;

			break;
		}

		case 4://Get the substring
		{
			int number;
			std::cout << "Number of string,which you want to get substring:" << std::endl;
			std::cin >> number;
			int index;
			int lenght;
			std::cout << "Enter the start index" << std::endl;
			std::cin >> index;
			std::cout << "Enter the lenght" << std::endl;
			std::cin >> lenght;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<double> D = A.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<double> D = B.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 5://Multiplying a string by number
		{
			int number;
			int count;
			std::cout << "Which line would you like to multiplying:" << std::endl;
			std::cin >> number;
			std::cout << "Number to multiply:" << std::endl;
			std::cin >> count;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<double> D = A * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<double> D = B * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 6://Exit
		{
			system("cls");
			ex = false;
		}
		}
	}
}
void menuint(MyString<int> A, MyString<int> B)
{
	bool ex = true;
	int choise;
	while (ex)
	{
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		std::cout << "\n";
		std::cout << "Choise the menu item:" << std::endl;
		std::cout << "1)Changing an item by index" << std::endl;
		std::cout << "2)Equality check" << std::endl;
		std::cout << "3)Concotenation" << std::endl;
		std::cout << "4)Get the substring" << std::endl;
		std::cout << "5)Multiplying a string by number" << std::endl;
		std::cout << "6)Exit" << std::endl;
		std::cin >> choise;
		//system("cls");
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		switch (choise)
		{

		case 1://Changing an item by index
		{
			int number;
			std::cout << "Which line would you like to change:" << std::endl;
			std::cin >> number;
			int index;
			int character;
			std::cout << "Enter the element index:" << std::endl;
			std::cin >> index;
			std::cout << "Enter the element:" << std::endl;
			std::cin >> character;
			system("cls");
			if (number == 1)
			{
				try
				{
					A[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					B[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 2://Equality check
		{
			system("cls");
			if (A == B)
			{
				std::cout << "Strings are equal" << std::endl;
			}
			else
				std::cout << "Strings are not equal" << std::endl;
			break;
		}

		case 3://Concotenation
		{
			system("cls");
			MyString<int> Result = A + B;
			std::cout << Result << " - Result string" << std::endl;
			break;
		}

		case 4://Get the substring
		{
			int number;
			std::cout << "Number of string,which you want to get substring:" << std::endl;
			std::cin >> number;
			int index;
			int lenght;
			std::cout << "Enter the start index" << std::endl;
			std::cin >> index;
			std::cout << "Enter the lenght" << std::endl;
			std::cin >> lenght;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<int> D = A.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<int> D = B.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 5://Multiplying a string by number
		{
			int number;
			int count;
			std::cout << "Which line would you like to multiplying:" << std::endl;
			std::cin >> number;
			std::cout << "Number to multiply:" << std::endl;
			std::cin >> count;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<int> D = A * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<int> D = B * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 6://Exit
		{
			system("cls");
			ex = false;
			break;
		}
		}
	}
}
void menuchar(MyString<char> A, MyString<char> B)
{
	bool ex = true;
	int choise;
	while (ex)
	{
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		std::cout << "\n";
		std::cout << "Choise the menu item:" << std::endl;
		std::cout << "1)Changing an item by index" << std::endl;
		std::cout << "2)Equality check" << std::endl;
		std::cout << "3)Concotenation" << std::endl;
		std::cout << "4)Get the substring" << std::endl;
		std::cout << "5)Multiplying a string by number" << std::endl;
		std::cout << "6)Exit" << std::endl;
		std::cin >> choise;
		//system("cls");
		std::cout << "1)" << A << std::endl;
		std::cout << "2)" << B << std::endl;
		switch (choise)
		{

		case 1://Changing an item by index
		{
			int number;
			std::cout << "Which line would you like to change:" << std::endl;
			std::cin >> number;
			int index;
			char character;
			std::cout << "Enter the element index:" << std::endl;
			std::cin >> index;
			std::cout << "Enter the element:" << std::endl;
			std::cin >> character;
			system("cls");
			if (number == 1)
			{
				try
				{
					A[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					B[index] = character;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 2://Equality check
		{
			system("cls");
			if (A == B)
			{
				std::cout << "Strings are equal" << std::endl;
			}
			else
				std::cout << "Strings are not equal" << std::endl;
			break;
		}

		case 3://Concotenation
		{
			system("cls");
			MyString<char> Result = A + B;
			std::cout << Result << " - Result string" << std::endl;

			break;
		}

		case 4://Get the substring
		{
			int number;
			std::cout << "Number of string,which you want to get substring:" << std::endl;
			std::cin >> number;
			int index;
			int lenght;
			std::cout << "Enter the start index" << std::endl;
			std::cin >> index;
			std::cout << "Enter the lenght" << std::endl;
			std::cin >> lenght;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<char> D = A.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<char> D = B.substring(index, lenght);
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 5://Multiplying a string by number
		{
			int number;
			int count;
			std::cout << "Which line would you like to multiplying:" << std::endl;
			std::cin >> number;
			std::cout << "Number to multiply:" << std::endl;
			std::cin >> count;
			system("cls");
			if (number == 1)
			{
				try
				{
					MyString<char> D = A * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			if (number == 2)
			{
				try
				{
					MyString<char> D = B * count;
					std::cout << D << " - Result string" << std::endl;
				}
				catch (const char* err)
				{
					std::cout << err << std::endl;
				}
			}
			break;
		}

		case 6://Exit
		{
			system("cls");
			ex = false;
		}
		}
	}
}