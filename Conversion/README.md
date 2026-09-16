# Conversion.h
In this header its a simple program that allows you to convert a varibles datatype into a another type with build in safety.

___

Example Code: 

```cpp
#include "Conversion.h"
#include <numbers>
int main(){
  double pi = std::numbers::pi;
  int a = Convert(pi, int); // from pi .14... will be removed so it will be only a.
  return 0;
}
```

The basic syntax for it is this:
```cpp
type <variable name> = Convert(variable which consists the data, type);// type in convert must be same as the type assigned to this variable this is for people who are using the auto keyword.
```

___
