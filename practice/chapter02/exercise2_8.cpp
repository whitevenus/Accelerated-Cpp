#include <iostream>

int main()
{
  int i = 1; 
  int ret = 1;
  while (i != 10) { 
    ret *= i; 
    i += 1; 
  }
  std::cout << ret << std::endl;
  return 0;
}