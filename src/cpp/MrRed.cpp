#include "MrRed.hpp"
#include <chrono>
#include <concepts>

bool stringEqualsIgnoreCase(std::string_view a, std::string_view b)
{
    if(b.size() != a.size())
        return false;
    for(unsigned int i = 0; i < a.size(); ++i)
        if(tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

std::string toLowerCase(std::string_view input)
{
    std::string lowerCased;
    for(char const& c : input)
        lowerCased += std::tolower(c);
    return lowerCased;
}

// bool stringEqualsOneOfTheFollowingIgnoreCase(std::string_view reference, std::vector<std::string_view> const &strings)
// {
//     const std::string referenceLowerCase = toLowerCase(reference);
//     return (std::any_of(strings.begin(), strings.end(), [&referenceLowerCase](std::string_view view) { return referenceLowerCase == toLowerCase(view); }));

//     // for(std::string_view string : strings)
//     // {
//     //     if(referenceLowerCase == toLowerCase(string))
//     //     {
//     //         // delete &strings; // does this not crash for you?
//     //         return true;
//     //     }
//     // }
//     // return false;
// }
