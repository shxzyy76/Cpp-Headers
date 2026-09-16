#pragma once

#include <string>
#include <type_traits>
#include <charconv>
#include <cctype>
#include <sstream>
#include <stdexcept>

using std::string;

enum class ConvertType {
    Binary
};

inline constexpr ConvertType binary = ConvertType::Binary;

template<typename T>
T Convert(const string& value, T)
{
    if constexpr (std::is_same_v<T, string>)
    {
        return value;
    }
    else if constexpr (std::is_same_v<T, char>        ||
                       std::is_same_v<T, signed char>  ||
                       std::is_same_v<T, unsigned char>)
    {
        if (value.empty())
            throw std::invalid_argument("Cannot convert empty string to char");
        return static_cast<T>(value[0]);
    }
    else if constexpr (std::is_same_v<T, bool>)
    {
        if (value == "true"  || value == "1") return true;
        if (value == "false" || value == "0") return false;
        throw std::invalid_argument("Cannot convert string to bool");
    }
    else if constexpr (std::is_integral_v<T>)
    {
        string numbers;
        for (char c : value)
        {
            if (std::isdigit(static_cast<unsigned char>(c)) ||
                (c == '-' && numbers.empty()))
                numbers += c;
        }
        if (numbers.empty())
            throw std::invalid_argument("No number found");

        T result{};
        auto [ptr, ec] = std::from_chars(
            numbers.data(),
            numbers.data() + numbers.size(),
            result
        );
        if (ec != std::errc{} || ptr != numbers.data() + numbers.size())
            throw std::invalid_argument("Invalid integer conversion");
        return result;
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        string numbers;
        for (char c : value)
        {
            if (std::isdigit(static_cast<unsigned char>(c)) ||
                c == '.' ||
                (c == '-' && numbers.empty()))
                numbers += c;
        }
        if (numbers.empty())
            throw std::invalid_argument("No number found");

        std::stringstream ss(numbers);
        T result{};
        ss >> result;
        if (ss.fail())
            throw std::invalid_argument("Invalid decimal conversion");
        return result;
    }
    else
    {
        throw std::invalid_argument("Unsupported type for Convert");
    }
}

inline char Convert(const string& value, std::size_t position)
{
    if (position >= value.size())
        throw std::out_of_range("Character position is out of range");
    return value[position];
}

inline string Convert(const string& value, ConvertType type)
{
    if (type != ConvertType::Binary)
        throw std::invalid_argument("Unknown conversion type");

    string result;
    for (unsigned char c : value)
    {
        for (int bit = 7; bit >= 0; --bit)
            result += ((c >> bit) & 1) ? '1' : '0';
        result += ' ';
    }
    if (!result.empty())
        result.pop_back();
    return result;
}
