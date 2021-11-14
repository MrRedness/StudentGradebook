#include "MrRed.hpp"

bool stringEqualsIgnoreCase(std::string_view a, std::string_view b)
{
	if (b.size() != a.size())
		return false;
	for (unsigned int i = 0; i < a.size(); ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}

std::string toLowerCase(std::string_view input)
{
	std::string lowerCased;
	for (char c : input)
		lowerCased += tolower(c);
	return lowerCased;
}

bool stringEqualsOneOfTheFollowingIgnoreCase(std::string_view reference, std::vector<std::string_view> const &strings)
{
	const std::string referenceLowerCase = toLowerCase(reference);
	// auto lowerCaseFunc = toLowerCase;
	// return (std::any_of(strings.front(), strings.back(), [&lowerCaseFunc, &referenceLowerCase](std::string_view view)
	// 					{ return referenceLowerCase == toLowerCase(view); }));

	for (std::string_view string : strings)
	{
		if (referenceLowerCase == toLowerCase(string))
		{
			delete &strings;
			return true;
		}
	}
	return false;
}

void cOutAndWait(std::string_view msg, int const &timeToWait)
{
	std::cout << msg << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds{timeToWait});
}

int cinInt()
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

int cinInt(int lowerLimit, int higherLimit)
{
	int input = cinInt();
	while (input < lowerLimit || input > higherLimit)
	{
		std::cout << "\nWoah there, that's a strange number -- Please enter something between " << lowerLimit << " and " << higherLimit << ".\n:";
		input = cinInt();
	}
	return input;
}