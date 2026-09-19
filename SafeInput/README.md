# safeInput.h

Header-only C++ safe input library. Output is your choice — `printf`, `cout`, custom logger, whatever.

---

## Include

```cpp
#include "safeInput.h"
```

---

## `scan<T>(var)`

Reads one line from stdin, validates, parses into `var`. Returns `bool`.

```cpp
if (scan<int>(age)) {
    // valid — use age
} else {
    // bad input — empty, overflow, junk, EOF
}
```

### Supported types

| Type | Rule |
|---|---|
| `int`, `long`, `unsigned`, etc. | Parses integer, rejects overflow + trailing junk |
| `float`, `double` | Rejects trailing junk |
| `char` | Exactly 1-character line only |
| `signed char` / `unsigned char` | Same as `char`, cast |
| `std::string` | Full line, rejects empty |
| `bool` | `true`/`false`/`1`/`0` only |

### Return values

| Return | Meaning |
|---|---|
| `true` | Parse succeeded, `var` is valid |
| `false` | EOF, empty line, overflow, junk after value, bad bool literal |

### Overflow check

Integers are double-parsed via `long long` and range-checked against `std::numeric_limits<T>`.

### Junk check

Non-string types reject trailing characters — `"42abc"` → `false`.

---

## `flush()`

```cpp
flush();
```

Discards stdin up to `\n`. Rarely needed — `scan` uses `getline` internally — but useful if mixing raw `>>` reads with `scan`.

---

## Usage patterns

### Retry loop

```cpp
int age;
while (true) {
    std::cout << "Enter age: ";
    if (scan<int>(age) && age >= 0) break;
    std::cout << "Invalid.\n";
}
```

```cpp
int age;
while (true) {
    printf("Enter age: ");
    if (scan<int>(age) && age >= 0) break;
    printf("Invalid.\n");
}
```

### if / else

```cpp
std::string name;
if (scan<std::string>(name)) {
    printf("Hello, %s\n", name.c_str());
} else {
    printf("No input.\n");
}
```

### Multiple fields

```cpp
std::string name;
double score;

std::cout << "Name: ";  scan<std::string>(name);
std::cout << "Score: "; scan<double>(score);

std::cout << "Result — " << name << ": " << score << "\n";
```

### Bool

```cpp
bool flag;
if (scan<bool>(flag)) {
    // accepts: true / false / 1 / 0
}
```

### Char

```cpp
char grade;
if (scan<char>(grade)) {
    // exactly one character
}
```

---

## Compile

```sh
g++ -std=c++17 -Wall -o prog main.cpp
```

Requires **C++17** (`if constexpr`, `std::is_same_v`).
