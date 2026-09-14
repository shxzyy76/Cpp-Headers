#ifndef IOP_HPP
#define IOP_HPP
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
namespace iop {
inline void flush() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
template <typename T>
bool _scan(T& value) {
    if constexpr (std::is_same_v<T, bool>)
        std::cin >> std::boolalpha;
    if (std::cin >> value) {
        if constexpr (!std::is_same_v<T, char>          &&
                      !std::is_same_v<T, signed char>   &&
                      !std::is_same_v<T, unsigned char>  &&
                      !std::is_same_v<T, bool>           &&
                      !std::is_same_v<T, std::string>) {
            int next = std::cin.peek();
            if (next != '\n' && next != std::char_traits<char>::eof()) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return false;
            }
        }
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}
template <>
inline bool _scan<char>(char& value) {
    if (std::cin >> value) {
        int next = std::cin.peek();
        if (next != '\n' && next != std::char_traits<char>::eof()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}
template <>
inline bool _scan<signed char>(signed char& value) {
    char c;
    if (std::cin >> c) {
        int next = std::cin.peek();
        if (next != '\n' && next != std::char_traits<char>::eof()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        value = static_cast<signed char>(c);
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}
template <>
inline bool _scan<unsigned char>(unsigned char& value) {
    char c;
    if (std::cin >> c) {
        int next = std::cin.peek();
        if (next != '\n' && next != std::char_traits<char>::eof()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        value = static_cast<unsigned char>(c);
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}
template <>
inline bool _scan<std::string>(std::string& value) {
    if (std::getline(std::cin, value))
        return !value.empty();
    std::cin.clear();
    return false;
}
namespace detail {
    template <typename T>
    std::string to_str(const T& val) {
        std::ostringstream oss;
        if constexpr (std::is_same_v<T, bool>)
            oss << std::boolalpha;
        else if constexpr (std::is_same_v<T, signed char> || std::is_same_v<T, unsigned char>)
            oss << static_cast<int>(val);
        else
            oss << val;
        return oss.str();
    }
    inline std::string format(const std::string& fmt, const std::vector<std::string>& args) {
        std::string result;
        result.reserve(fmt.size());
        std::size_t arg_idx = 0;
        for (std::size_t i = 0; i < fmt.size(); ++i) {
            if (fmt[i] == '%' && i + 1 < fmt.size() && fmt[i + 1] == 'v') {
                if (arg_idx >= args.size())
                    throw std::out_of_range("iop::print: more %v than arguments");
                result += args[arg_idx++];
                ++i;
            } else {
                result += fmt[i];
            }
        }
        return result;
    }
}
template <typename... Args>
void print(const std::string& fmt, const Args&... args) {
    std::vector<std::string> arg_strs = { detail::to_str(args)... };
    std::cout << detail::format(fmt, arg_strs) << '\n';
}
inline void print(const std::string& msg) {
    std::cout << msg << '\n';
}
}
using iop::print;
using iop::flush;
#define scan(variable, type) ::iop::_scan<type>(variable)
#endif