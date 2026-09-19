#ifndef SAFE_INPUT_HPP
#define SAFE_INPUT_HPP

#include <limits>
#include <sstream>
#include <string>
#include <type_traits>

namespace iop {

inline void flush() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
bool scan_impl(T& value) {
    std::string line;
    if (!std::getline(std::cin, line)) { std::cin.clear(); return false; }
    if (line.empty()) return false;

    std::istringstream ss(line);

    if constexpr (std::is_same_v<T, bool>)
        ss >> std::boolalpha >> value;
    else if (!(ss >> value))
        return false;

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

    if constexpr (!std::is_same_v<T, std::string>) {
        char leftover;
        if (ss >> leftover) return false;
    }

    return true;
}

template <> inline bool scan_impl<char>(char& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    if (line.size() != 1) return false;
    value = line[0]; return true;
}

template <> inline bool scan_impl<signed char>(signed char& value) {
    char c; if (!scan_impl<char>(c)) return false;
    value = static_cast<signed char>(c); return true;
}

template <> inline bool scan_impl<unsigned char>(unsigned char& value) {
    char c; if (!scan_impl<char>(c)) return false;
    value = static_cast<unsigned char>(c); return true;
}

template <> inline bool scan_impl<std::string>(std::string& value) {
    if (!std::getline(std::cin, value)) return false;
    return !value.empty();
}

template <> inline bool scan_impl<bool>(bool& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    if (line == "true"  || line == "1") { value = true;  return true; }
    if (line == "false" || line == "0") { value = false; return true; }
    return false;
}

} // namespace iop

using iop::flush;

template <typename T>
inline bool scan(T& var) { return iop::scan_impl<T>(var); }

#endif