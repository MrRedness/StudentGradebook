#pragma once
#include <iostream>
#include <vector>
//#include <string_view>


bool stringEqualsIgnoreCase(std::string_view a, std::string_view b);

std::string toLowerCase(std::string_view input);

bool stringEqualsOneOfTheFollowingIgnoreCase(std::string_view reference, std::vector<std::string_view> const& strings);

void cOutAndWait(std::string_view msg, int const& timeToWait);

int cinInt();

int cinInt(int lowerLimit, int higherLimit);
