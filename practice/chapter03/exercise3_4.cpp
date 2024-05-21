#include <iostream>
#include <string>

using std::cout;    using std::cin;
using std::endl;    using std::string;  

int main()
{
  cout << "Please enter some string: ";
  string str;
  string::size_type min = 100000000, max = 0;
  while (cin >> str) {
    string::size_type length = str.size();
    if (length > max) {
      max = length;
    }
    if (length < min) {
      min = length;
    }
  }
  cout << endl << "最小的字符串长度：" << min << endl << "最大的字符串长度：" << max << endl;
}