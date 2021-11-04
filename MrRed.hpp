#pragma once
#include <iostream>
#include <chrono>
#include <thread>
//#include <string_view>


inline bool stringEqualsIgnoreCase(std::string_view a, std::string_view b)
{
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}

inline bool stringEqualsIgnoreCase(std::string_view a, std::string_view b, std::string_view orC)
{
	return stringEqualsIgnoreCase(a, b) || stringEqualsIgnoreCase(a, orC);
}

inline void cOutAndWait(std::string_view msg, const int& timeToWait)
{
	std::cout << msg << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds{ timeToWait });
}

inline int cinInt()
{
	int input;
	std::cin >> input;
	while (std::cin.fail())
	{
		std::cout << "\nWoah there, please enter a number.\n:";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	return input;
}

inline int cinInt(int lowerLimit, int higherLimit)
{
	int input = cinInt();
	while (input < lowerLimit || input > higherLimit) {
		std::cout << "\nWoah there, that's a strange number -- Please enter something between " << lowerLimit << " and " << higherLimit << ".\n:";
		input = cinInt();
	}
	return input;
}
