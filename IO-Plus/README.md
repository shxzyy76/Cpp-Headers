# IO-Plus.h

A lightweight C++ header that replaces unsafe `cin`/`scanf` input with safe, type-validated alternatives — and simplifies `printf`-style printing.

---

## Features

- `scan<T>(var)` — safe input, rejects bad types, junk, and overflow
- `print(fmt, args...)` — readable alternative to `printf` using `%v`
- Single header, no dependencies

---

## Usage

### Include

```cpp
#include "IO-Plus.h"
```

---

### `scan<T>(var)`

Reads a line from stdin and validates it strictly against type `T`.  
Returns `true` on success, `false` on bad input — no exceptions thrown.

```cpp
int n;
if (scan<int>(n)) {
    // valid int
} else {
    // bad input
}
```

```cpp
auto move = 0;
if (scan<int>(move)) { ... }  // explicit type, auto friendly
```

**Supported types:**

| Type | Accepts |
|---|---|
| `int`, `long`, `short`, etc. | integers only, overflow rejected |
| `float`, `double` | floating point only |
| `char` | single character only |
| `signed char`, `unsigned char` | single character only |
| `bool` | `"true"`, `"false"`, `"1"`, `"0"` |
| `std::string` | any non-empty line |

**Rejected inputs:**

| Input | Type | Result |
|---|---|---|
| `"42abc"` | `int` | Rejected |
| `"abc"` | `int` | Rejected |
| `"ab"` | `char` | Rejected |
| `"99999999999"` | `int` | Rejected due to overflow |
| `"3.14"` | `int` | Rejected |
| `"42"` | `int` | Allowed |
| `"a"` | `char` | Allowed |

---

### `print(fmt, args...)`

Prints a formatted string using `%v` as the placeholder for any type.

```cpp
print("Hello, %v!", "world");         // Hello, world!
print("x = %v, y = %v", 10, 3.14);   // x = 10, y = 3.14
print("flag = %v", true);             // flag = true
```

Simpler alternative to `printf` — no format specifiers per type needed.

---

### `flush()`

Clears the input buffer manually if needed.

```cpp
flush();
```

---

## Example

```cpp
#include "IO-Plus.h"

int main() {
    print("Enter your name: ");
    std::string name;
    if (scan<std::string>(name))
        print("Hello, %v!", name);

    print("Enter an integer: ");
    auto n = 0;
    if (scan<int>(n))
        print("Got: %v", n);
    else
        print("Invalid input.");
}
```

---

## Requirements

- C++17 or later
- Standard library only

---

## Part of

This header is part of a collection of C++ utility headers aimed at simplifying common but verbose or unsafe standard library patterns.
