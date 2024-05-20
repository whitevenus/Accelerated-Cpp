#include <iostream>

using std::cin; using std::cout;
using std::endl;
int main()
{
  cout << "Please enter two numbers: ";
  int n, m;
  cin >> n >> m;
  int ret = n > m ? n : m;
  cout << "This lagger number is: " << ret << endl;
  return 0;
}