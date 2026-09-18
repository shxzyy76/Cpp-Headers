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
bool scan_impl(T& value) {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cin.clear();
        return false;
    }
    if (line.empty()) return false;

    std::istringstream ss(line);

    if constexpr (std::is_same_v<T, bool>)
        ss >> std::boolalpha >> value;
    else if (!(ss >> value))
        return false;

    // overflow check for integers
    if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool> &&
                  !std::is_same_v<T, char> && !std::is_same_v<T, signed char> &&
                  !std::is_same_v<T, unsigned char>) {
        long long check;
        std::istringstream ss2(line);
        if (!(ss2 >> check)) return false;
        if (check > static_cast<long long>(std::numeric_limits<T>::max()) ||
            check < static_cast<long long>(std::numeric_limits<T>::min()))
            return false;
    }

    // junk check
    if constexpr (!std::is_same_v<T, std::string>) {
        char leftover;
        if (ss >> leftover) return false;
    }

    return true;
}

template <>
inline bool scan_impl<char>(char& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    if (line.size() != 1) return false;
    value = line[0];
    return true;
}

template <>
inline bool scan_impl<signed char>(signed char& value) {
    char c;
    if (!scan_impl<char>(c)) return false;
    value = static_cast<signed char>(c);
    return true;
}

template <>
inline bool scan_impl<unsigned char>(unsigned char& value) {
    char c;
    if (!scan_impl<char>(c)) return false;
    value = static_cast<unsigned char>(c);
    return true;
}

template <>
inline bool scan_impl<std::string>(std::string& value) {
    if (!std::getline(std::cin, value)) return false;
    return !value.empty();
}

template <>
inline bool scan_impl<bool>(bool& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    if (line == "true" || line == "1") { value = true;  return true; }
    if (line == "false"|| line == "0") { value = false; return true; }
    return false;
}

namespace detail {
    template <typename T>
    std::string to_str(const T& val) {
        std::ostringstream oss;
        if constexpr (std::is_same_v<T, bool>)
            oss << std::boolalpha << val;
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

} // namespace iop

using iop::print;
using iop::flush;

template <typename T>
inline bool scan(T& var) { return iop::scan_impl<T>(var); }

#endif
