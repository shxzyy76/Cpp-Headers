# I/O Plus
Its a IO with simple and easy syntax

___

# How to print a text in the console:

```cpp
#include "IO-Plus.h"
int main(){
  print("Hello World"); //you do not need to use \n to print a new line it automatically does it for you.
  return 0;
}
```

# How to print a variable in the console:

```cpp
#include "IO-Plus.h"
int main(){
  int a = 23;
  print("%v", a); // %v is basically a command to for print variable
  return 0;
}
```

___

# How to take user input: 

```cpp
#include "IO-Plus.h"
int main(){
  int number;
  print("Enter a number: ");
  if (scan(number, int)){
    print("%v", number);
  }else{
    print("type a valid input");
  }
}
```

# Basic Format: 

```cpp
print(example);
if (scan(variable, type)){
  //example
else{
  //example
}
```

___
