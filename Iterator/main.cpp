#include <iostream>

#include "Vector.hpp"

int main()
{
	Vector<int> arr;

	arr.push_back(1);
	arr.push_back(3);

	for (const int& n : arr)
	{
		std::cout << n << " ";
	}

	for (auto it = arr.cbegin(); it != arr.cend(); it++)
	{
		std::cout << *it << " ";
	}

	return 0;
}