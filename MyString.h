#pragma once
#include <iostream>
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
		out << "MyString: {";
		for (int i = 0; i < str.size; i++)
		{
			out << "'";
			out << str.data[i];
			out << "'";
			if (i != str.size - 1)
			{
				out << ", ";
			}
		}
		out << "} ";
		return out;
	}
};