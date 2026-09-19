#include "safeInput.h"
#include <cstdio>

int main() {
    // --- print ---
    printf("Hello World\n");
    printf("Formatted: %d and %.2f\n", 42, 3.14);

    // --- int ---
    int i;
    printf("Enter an int: ");
    if (scan<int>(i)) printf("int: %d\n", i);
    else printf("Invalid int\n");

    // --- long ---
    long l;
    printf("Enter a long: ");
    if (scan<long>(l)) printf("long: %ld\n", l);
    else printf("Invalid long\n");

    // --- long long ---
    long long ll;
    printf("Enter a long long: ");
    if (scan<long long>(ll)) printf("long long: %lld\n", ll);
    else printf("Invalid long long\n");

    // --- short ---
    short s;
    printf("Enter a short: ");
    if (scan<short>(s)) printf("short: %hd\n", s);
    else printf("Invalid short\n");

    // --- unsigned int ---
    unsigned int ui;
    printf("Enter an unsigned int: ");
    if (scan<unsigned int>(ui)) printf("unsigned int: %u\n", ui);
    else printf("Invalid unsigned int\n");

    // --- unsigned long ---
    unsigned long ul;
    printf("Enter an unsigned long: ");
    if (scan<unsigned long>(ul)) printf("unsigned long: %lu\n", ul);
    else printf("Invalid unsigned long\n");

    // --- unsigned long long ---
    unsigned long long ull;
    printf("Enter an unsigned long long: ");
    if (scan<unsigned long long>(ull)) printf("unsigned long long: %llu\n", ull);
    else printf("Invalid unsigned long long\n");

    // --- unsigned short ---
    unsigned short us;
    printf("Enter an unsigned short: ");
    if (scan<unsigned short>(us)) printf("unsigned short: %hu\n", us);
    else printf("Invalid unsigned short\n");

    // --- float ---
    float f;
    printf("Enter a float: ");
    if (scan<float>(f)) printf("float: %f\n", f);
    else printf("Invalid float\n");

    // --- double ---
    double d;
    printf("Enter a double: ");
    if (scan<double>(d)) printf("double: %f\n", d);
    else printf("Invalid double\n");

    // --- long double ---
    long double ld;
    printf("Enter a long double: ");
    if (scan<long double>(ld)) printf("long double: %Lf\n", ld);
    else printf("Invalid long double\n");

    // --- bool ---
    bool b;
    printf("Enter a bool (true/false): ");
    if (scan<bool>(b)) printf("bool: %s\n", b ? "true" : "false");
    else printf("Invalid bool\n");

    // --- char ---
    char c;
    printf("Enter a char: ");
    if (scan<char>(c)) printf("char: %c\n", c);
    else printf("Invalid char\n");

    // --- signed char ---
    signed char sc;
    printf("Enter a signed char: ");
    if (scan<signed char>(sc)) printf("signed char: %d\n", sc);
    else printf("Invalid signed char\n");

    // --- unsigned char ---
    unsigned char uc;
    printf("Enter an unsigned char: ");
    if (scan<unsigned char>(uc)) printf("unsigned char: %u\n", uc);
    else printf("Invalid unsigned char\n");

    // --- string ---
    std::string str;
    printf("Enter a string: ");
    if (scan<std::string>(str)) printf("string: %s\n", str.c_str());
    else printf("Invalid string\n");

    // --- pointer ---
    int val = 99;
    int* ptr = &val;
    printf("pointer address: %p\n", (void*)ptr);
    printf("pointer value: %d\n", *ptr);

    return 0;
}