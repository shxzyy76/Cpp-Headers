#pragma once

#include <string>
#include <stdexcept>
#include <cctype>
#include <type_traits>
#include <sstream>

using std::string;

struct _binary_tag {};
struct _Binary_tag {};

class binary {
protected:
    string _data;

    static bool _is_valid(const string& s) {
        if (s.empty()) return false;
        for (char c : s)
            if (c != '0' && c != '1' && c != ' ')
                return false;
        return true;
    }

    static string _bin_to_str(const string& s) {
        string result;
        string token;
        for (size_t i = 0; i <= s.size(); ++i) {
            char c = (i < s.size()) ? s[i] : ' ';
            if (c == ' ') {
                if (token.size() == 8) {
                    unsigned char val = 0;
                    for (char b : token)
                        val = (val << 1) | (b - '0');
                    result += static_cast<char>(val);
                }
                token.clear();
            } else {
                token += c;
            }
        }
        return result;
    }

    static string _int_to_bin(unsigned long long val) {
        if (val == 0) return "00000000";
        string result;
        while (val > 0) {
            result = (char)('0' + (val & 1)) + result;
            val >>= 1;
        }
        while (result.size() % 8 != 0)
            result = "0" + result;
        return result;
    }

    static string _str_to_bin(const string& s) {
        string result;
        string digit_buf;
        string char_buf;

        auto flush_chars = [&]() {
            if (!char_buf.empty()) {
                for (unsigned char c : char_buf) {
                    if (!result.empty()) result += ' ';
                    for (int bit = 7; bit >= 0; --bit)
                        result += ((c >> bit) & 1) ? '1' : '0';
                }
                char_buf.clear();
            }
        };

        auto flush_digits = [&]() {
            if (!digit_buf.empty()) {
                if (!result.empty()) result += ' ';
                unsigned long long num = std::stoull(digit_buf);
                result += _int_to_bin(num);
                digit_buf.clear();
            }
        };

        for (char c : s) {
            if (std::isdigit((unsigned char)c)) {
                flush_chars();
                digit_buf += c;
            } else {
                flush_digits();
                char_buf += c;
            }
        }
        flush_chars();
        flush_digits();
        return result;
    }

    binary(const string& s, bool) : _data(s) {}
    friend class Binary;

public:
    binary() = delete;

    binary(const string& s) {
        if (!_is_valid(s))
            throw std::invalid_argument("binary: only 0, 1, and spaces allowed");
        _data = s;
    }

    binary(const char* s) : binary(string(s)) {}

    binary(int)                = delete;
    binary(long)               = delete;
    binary(long long)          = delete;
    binary(unsigned int)       = delete;
    binary(unsigned long)      = delete;
    binary(unsigned long long) = delete;
    binary(float)              = delete;
    binary(double)             = delete;
    binary(long double)        = delete;
    binary(bool)               = delete;

    string str() const { return _data; }

    friend std::ostream& operator<<(std::ostream& os, const binary& b) {
        return os << b._data;
    }

    template<typename F>
    static binary make(const F& val) {
        if constexpr (std::is_same_v<F, string>)
            return binary(_str_to_bin(val), true);
        else if constexpr (std::is_same_v<F, bool>)
            return binary(val ? "00000001" : "00000000", true);
        else if constexpr (std::is_integral_v<F>)
            return binary(_int_to_bin(static_cast<unsigned long long>(val)), true);
        else if constexpr (std::is_floating_point_v<F>) {
            std::ostringstream oss;
            oss << val;
            return binary(_str_to_bin(oss.str()), true);
        }
        else
            throw std::invalid_argument("binary: unsupported type");
    }
};

class Binary : public binary {
public:
    Binary(const string& s) : binary(s) {}
    Binary(const char* s)   : binary(s) {}
    Binary(const binary& b) : binary(b._data, true) {}

    Binary(int)                = delete;
    Binary(long)               = delete;
    Binary(long long)          = delete;
    Binary(unsigned int)       = delete;
    Binary(unsigned long)      = delete;
    Binary(unsigned long long) = delete;
    Binary(float)              = delete;
    Binary(double)             = delete;
    Binary(long double)        = delete;
    Binary(bool)               = delete;

    template<typename F>
    static Binary make(const F& val) {
        return Binary(binary::make(val));
    }

    friend std::ostream& operator<<(std::ostream& os, const Binary& b) {
        return os << binary::_bin_to_str(b._data);
    }
};

template<typename F> binary Convert(const F& val, _binary_tag) { return binary::make(val); }
template<typename F> Binary Convert(const F& val, _Binary_tag) { return Binary::make(val); }

#define Convert(val, type) Convert(val, _##type##_tag{})