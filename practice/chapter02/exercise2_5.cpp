#include <iostream>
#include <string>

using std::cin;   using std::cout;
using std::endl;  using std::string;

int main()
{
  int height = 3, width = 5;

  // 正方形
  cout << "正方形：" << endl;
  for (int r = 0; r < height; ++r) {
    int c = 0;
    while (c != height) {
      cout << "*";
      ++c;
    }
    cout << endl;
  }

  // 长方形
  cout << "长方形：" << endl;
  for (int r = 0; r < height; ++r) {
    int c = 0;
    while (c != width) {
      cout << "*";
      ++c;
    }
    cout << endl;
  }

  // 长方形
  cout << "三角形：" << endl;
  // 外层循环控制行数
    for (int i = 0; i < height; ++i) {
        // 打印每行前面的空格
        for (int j = 0; j < height - i - 1; ++j) {
            std::cout << " ";
        }
        // 打印每行的星号
        for (int j = 0; j < 2 * i + 1; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl; // 换行
    }


  return 0;
}