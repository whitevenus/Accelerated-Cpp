#include <iostream>
#include <vector>

using std::vector;    using std::string;
using std::cin;       using std::cout;
using std::endl;

int main()
{
  cout << "Please enter some string: ";
  vector<int> counts;
  vector<string> strings;
  string str;
  typedef vector<string>::size_type vec_str_sz;
  while (cin >> str) {
    vec_str_sz strings_size = strings.size();
    if (strings_size == 0) {
      strings.push_back(str);
      counts.push_back(1);
    } else {
      int flag = 0;
      for (vec_str_sz i = 0; i != strings_size; ++i) {
        if (str == strings[i]) {
          // cout << "相同了" << endl;
          ++counts[i];
          flag = 1;
        }
      }
      if (!flag) {
        strings.push_back(str);
        counts.push_back(1);
      }
    }
  }
  // 输出结果
  cout << endl;
  for(vec_str_sz i = 0; i != strings.size(); ++i) {
    cout << strings[i] << "出现的次数为: " << counts[i] << endl;
  }
}