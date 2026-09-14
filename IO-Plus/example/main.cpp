#include "IO-Plus.h"
int main() {
    // --- print ---
    print("Hello World");
    print("Formatted: %v and %v", 42, 3.14);
    // --- int ---
    int i;
    print("Enter an int: ");
    if (scan(i, int)) print("int: %v", i);
    else print("Invalid int");
    // --- long ---
    long l;
    print("Enter a long: ");
    if (scan(l, long)) print("long: %v", l);
    else print("Invalid long");
    // --- long long ---
    long long ll;
    print("Enter a long long: ");
    if (scan(ll, long long)) print("long long: %v", ll);
    else print("Invalid long long");
    // --- short ---
    short s;
    print("Enter a short: ");
    if (scan(s, short)) print("short: %v", s);
    else print("Invalid short");
    // --- unsigned int ---
    unsigned int ui;
    print("Enter an unsigned int: ");
    if (scan(ui, unsigned int)) print("unsigned int: %v", ui);
    else print("Invalid unsigned int");
    // --- unsigned long ---
    unsigned long ul;
    print("Enter an unsigned long: ");
    if (scan(ul, unsigned long)) print("unsigned long: %v", ul);
    else print("Invalid unsigned long");
    // --- unsigned long long ---
    unsigned long long ull;
    print("Enter an unsigned long long: ");
    if (scan(ull, unsigned long long)) print("unsigned long long: %v", ull);
    else print("Invalid unsigned long long");
    // --- unsigned short ---
    unsigned short us;
    print("Enter an unsigned short: ");
    if (scan(us, unsigned short)) print("unsigned short: %v", us);
    else print("Invalid unsigned short");
    // --- float ---
    float f;
    print("Enter a float: ");
    if (scan(f, float)) print("float: %v", f);
    else print("Invalid float");
    // --- double ---
    double d;
    print("Enter a double: ");
    if (scan(d, double)) print("double: %v", d);
    else print("Invalid double");
    // --- long double ---
    long double ld;
    print("Enter a long double: ");
    if (scan(ld, long double)) print("long double: %v", ld);
    else print("Invalid long double");
    // --- bool ---
    bool b;
    print("Enter a bool (true/false): ");
    if (scan(b, bool)) print("bool: %v", b);
    else print("Invalid bool");
    // --- char ---
    char c;
    print("Enter a char: ");
    if (scan(c, char)) print("char: %v", c);
    else print("Invalid char");
    // --- signed char ---
    signed char sc;
    print("Enter a signed char: ");
    if (scan(sc, signed char)) print("signed char: %v", sc);
    else print("Invalid signed char");
    // --- unsigned char ---
    unsigned char uc;
    print("Enter an unsigned char: ");
    if (scan(uc, unsigned char)) print("unsigned char: %v", uc);
    else print("Invalid unsigned char");
    // --- string ---
    std::string str;
    flush(); // clear buffer before getline
    print("Enter a string: ");
    if (scan(str, std::string)) print("string: %v", str);
    else print("Invalid string");
    // --- pointer ---
    int val = 99;
    int* ptr = &val;
    print("pointer address: %v", (void*)ptr);
    print("pointer value: %v", *ptr);
    return 0;
}