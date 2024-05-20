#include <iostream>
#include <string>

using std::cin;   using std::cout;
using std::endl;  using std::string;


int main()
{
  cout << "Please enter your first name: ";
  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";

  int pad;
  cout << "Please enter num of pad: ";
  cin >> pad;  
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  cout << endl;
  for (int r = 0; r != rows; ++r) {
    // 首行和尾行
    if (r == 0 || r == rows - 1) {
      string stars(cols, '*');
      cout << stars << endl;
    } else if (r == pad + 1) {
      string spaces((cols - greeting.size() - 2) / 2, ' ');
      cout << "*" + spaces + greeting + spaces + "*" << endl;
    } else {
      string spaces(cols - 2, ' ');
      cout << "*" + spaces + "*" << endl;
    }
  }
  return 0;
}