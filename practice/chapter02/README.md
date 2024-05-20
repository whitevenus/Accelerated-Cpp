# 第 2 章 《循环和计数》 编程练习题之自答

## 2.1&2.2

**题**：

2.1：改写框架程序，输出跟框架没有间隔的问候语。

2.2：在我们的框架程序中, 我们使用了一定数目的空格来把问候语和顶部以及底部边界分隔开米。现在, 重新编写这个程序,在重写的程序中使用数量跟原程序不同的空格来把各边界和问候语分隔开。

**解**：

只需修改本节示例程序的`pad`值即可。

```c++
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

  const int pad = 0;
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  cout << endl;
  for (int r = 0; r != rows; ++r) {
    string::size_type c = 0;
    while(c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        if ( r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }
  return 0;
}
```

## 2.3

**题**：重写框架程序,让用户自己提供在框架和问候语之间的空格个数。

**解**：

```c++
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
    string::size_type c = 0;
    while(c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        if ( r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }
  return 0;
}
```

## 2.4

**题**：在框架程序中的空白行是用来把边界和问候语分隔开的, 程序每次一个字符地输出了大部分的空白行。改写这个程序, 让它在单独的一条输出表达式中输出所有的空白行。

**解**：

```c++
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
```

## 2.5

**题**：编写—个程序, 让它输出一系列的 “*” 字符,程序输出的这些字符将构成一个正方形, 一个长方形和一个三角形。

**解**：

```c++
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
```

## 2.6

**题**：下面的代码是做什么的?

```txt
int i = 0; 
while (i < 10) { 
	i += 1; 
	std::cout << i << std::endl; 
}
```

**解**：

该段代码换行输出 1 ～ 10.

## 2.7

**题**：编写一个程序来依次输出从 10 ～-5 的整数。

**解**：

```c++
#include <iostream>

int main()
{
  int i = 11; 
  while (i > -5) { 
    i -= 1; 
    std::cout << i << std::endl; 
  }
}
```

## 2.8

**题**：编写一个程序来计算区同[1,10)中的所有数值的乘积。

**解**：

使用`ret`对结果进行累积。

```c++
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
```

## 2.9

**题**：编写一个程序, 让用户输入两个数值并告知用户在这两个数值中哪一个较大。

**解**：

```c++
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
```

## 2.10

**题**：在下面的程序中，对`std::`的每一次使用进行解释。

```txt
int main()
{
	int k = 0;
	while (k != n) {						// 不变式：到目前为止，我们已经输出了k个星号
		using std::cout;
		cout << "*";
	}
	std::cout << std::endl;      // 在这里必须使用std
}
```

**解**：

使用`using`声明的名称与其他名称具有相同的特性，在`while`循环体里使用`using std::cout`声明，则表示在循环体内可以使用`cout`代替`std::cout`。而在循环体外必须使用完整写法`std::cout`和`std::endl`。

