# Randomize
It is a easier way of creating a random number
how to create it: 

# Basic Example Syntax: 
```cpp
Random (variable name);
type (the type must store numbers only) (name) = (Variable of Random)(Min, Max);
```

# Example: 
```cpp
#include "Randomized.h"
#include "IO-Plus.h"
int main(){
  Random rng;
  int number = rng(1, 100);
  print("%v", number);
  return 0;
}
```

___
