#include <iostream>
#include "any_of.h"

template <typename T> 
typename std::enable_if_t<any_of<T, size_t, int, float, double>::value, void>
print_number(T value) {
  std::cout << value << "\n";
}

int main() {
  std::cout << std::boolalpha;
  std::cout << any_of<int, int, float>::value << "\n";    // true
  std::cout << any_of<int, char, double>::value << "\n";  // false

  std::cout << any_but<char, std::string, int, float>::value << "\n"; // true

  print_number(5);   // OK
  // print_number('c'); // error: no matching function for call to 'print_number'
}