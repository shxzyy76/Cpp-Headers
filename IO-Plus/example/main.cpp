#include "iop.hpp"

int main() {
    // --- print ---
    print("Hello World");
    print("Formatted: %v and %v", 42, 3.14);

    // --- int ---
    int i;
    print("Enter an int: ");
    if (scan<int>(i)) print("int: %v", i);
    else print("Invalid int");

    // --- long ---
    long l;
    print("Enter a long: ");
    if (scan<long>(l)) print("long: %v", l);
    else print("Invalid long");

    // --- long long ---
    long long ll;
    print("Enter a long long: ");
    if (scan<long long>(ll)) print("long long: %v", ll);
    else print("Invalid long long");

    // --- short ---
    short s;
    print("Enter a short: ");
    if (scan<short>(s)) print("short: %v", s);
    else print("Invalid short");

    // --- unsigned int ---
    unsigned int ui;
    print("Enter an unsigned int: ");
    if (scan<unsigned int>(ui)) print("unsigned int: %v", ui);
    else print("Invalid unsigned int");

    // --- unsigned long ---
    unsigned long ul;
    print("Enter an unsigned long: ");
    if (scan<unsigned long>(ul)) print("unsigned long: %v", ul);
    else print("Invalid unsigned long");

    // --- unsigned long long ---
    unsigned long long ull;
    print("Enter an unsigned long long: ");
    if (scan<unsigned long long>(ull)) print("unsigned long long: %v", ull);
    else print("Invalid unsigned long long");

    // --- unsigned short ---
    unsigned short us;
    print("Enter an unsigned short: ");
    if (scan<unsigned short>(us)) print("unsigned short: %v", us);
    else print("Invalid unsigned short");

    // --- float ---
    float f;
    print("Enter a float: ");
    if (scan<float>(f)) print("float: %v", f);
    else print("Invalid float");

    // --- double ---
    double d;
    print("Enter a double: ");
    if (scan<double>(d)) print("double: %v", d);
    else print("Invalid double");

    // --- long double ---
    long double ld;
    print("Enter a long double: ");
    if (scan<long double>(ld)) print("long double: %v", ld);
    else print("Invalid long double");

    // --- bool ---
    bool b;
    print("Enter a bool (true/false/1/0): ");
    if (scan<bool>(b)) print("bool: %v", b);
    else print("Invalid bool");

    // --- char ---
    char c;
    print("Enter a char: ");
    if (scan<char>(c)) print("char: %v", c);
    else print("Invalid char");

    // --- signed char ---
    signed char sc;
    print("Enter a signed char: ");
    if (scan<signed char>(sc)) print("signed char: %v", sc);
    else print("Invalid signed char");

    // --- unsigned char ---
    unsigned char uc;
    print("Enter an unsigned char: ");
    if (scan<unsigned char>(uc)) print("unsigned char: %v", uc);
    else print("Invalid unsigned char");

    // --- string ---
    std::string str;
    print("Enter a string: ");
    if (scan<std::string>(str)) print("string: %v", str);
    else print("Invalid string");

    // --- pointer ---
    int val = 99;
    int* ptr = &val;
    print("pointer address: %v", (void*)ptr);
    print("pointer value: %v", *ptr);

    return 0;
}
