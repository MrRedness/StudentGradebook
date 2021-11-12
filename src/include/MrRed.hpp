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

void cOutAndWait(std::string_view msg, int const &timeToWait);

int cinInt();

int cinInt(int lowerLimit, int higherLimit);