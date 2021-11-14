#pragma once
#include "PCH.hpp"

bool stringEqualsIgnoreCase(std::string_view a, std::string_view b);

std::string toLowerCase(std::string_view input);

bool stringEqualsOneOfTheFollowingIgnoreCase(std::string_view reference, std::vector<std::string_view> const &strings);

// template <class... Args>
// bool test(Args &&...args)
// {
//     auto arguments = std::make_tuple(std::forward<Args>(args)...);
//     auto begin = std::begin(arguments);
//     for (auto i = std::begin(arguments); i < std::end(arguments); i++)
//     {
//         std::cout << std::get<i>(arguments);
//         return true;
//     }
// }

template <typename T>
void cOutAndWait(std::string_view msg, std::chrono::duration<T> timeToWait)
{
    std::cout << msg << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds { timeToWait });
}

template <typename T = int>
requires std::integral<T>
    T cinInt()
{
    int input;
    std::cin >> input;
    while(std::cin.fail())
    {
        std::cout << "\nWoah there, please enter a number.\n:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    }
    return input;
}

// exact syntax may vary if your compiler isnt sufficently up to date
std::integral auto cinInt(std::integral auto lowerLimit, std::integral auto higherLimit)
{
    auto input = cinInt();
    while(input < lowerLimit || input > higherLimit)
    {
        std::cout << "\nWoah there, that's a strange number -- Please enter something between " << lowerLimit << " and " << higherLimit << ".\n:";
        input = cinInt();
    }
    return input;
}