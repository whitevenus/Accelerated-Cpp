# 第 3 章 《使用批量数据》 编程练习题之自答

## 3.2

**题**：把一个整数集合分为个数相等的四部分，而且第一部分含有的整数值比其他各部分的都大，第二部分的值比第一部分的小比其他两部分的大，剩下的两部分则以此类推。按照上面的要求，编写一个程序来计算并且打印这四部分。

**解**：

```c++
#include <iostream>
#include <vector>
#include <algorithm> // 用于sort函数

using std::vector;    using std::cout;
using std::cin;       using std::endl;


int main() {
    vector<int> numbers;
    int n, temp;

    // 读取整数集合
    cout << "请输入整数集合的元素数量：";
    cin >> n;
    cout << "请输入整数集合的元素，每个元素后跟一个空格或回车：" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        numbers.push_back(temp);
    }

    // 检查元素数量是否可以被4整除
    if (n % 4 != 0) {
        cout << "元素数量必须能被4整除。" << endl;
        return 1;
    }

    // 对整数集合进行排序
    sort(numbers.begin(), numbers.end());

    // 计算每个部分的元素数量
    int part_size = n / 4;

    // 打印四个部分
    cout << endl << "第一部分（最大值）：" << endl;
    for (int i = n - 1; i >= n - part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "第二部分：" << endl;
    for (int i = 3 * part_size - 1; i >= 2 * part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "第三部分：" << endl;
    for (int i = 2 * part_size - 1; i >= part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "第四部分（最小值）：" << endl;
    for (int i = part_size - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

```

## 3.3

**题**：编写一个程序来计算在它的输入中每个不同的单词所出现的次数。

**解**：

```c++
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
```

## 3.4

**题**：编写一个程序来报告它的输入中最长以及最短的字符串的长度。

**解**：

注意设置`min`为一个超级大的数。

```c++
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
```

## 3.5

**题**：编写一个程序来同时限踪 n 个学生的成绩。要求程序能够保持两个向量的同步：第一个应保存学生的姓名；第二个保存总成绩，而这个总成绩能根据读到的输入来计算。读者应假定家庭作业成绩的个数是固定的。

**解**：

```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::string;  using std::streamsize;
using std::setprecision;

int main() {
    int n, homework_count;
    vector<string> names;
    vector<double> total_scores;

    // 读取学生数量和家庭作业数量
    cout << "请输入学生数量：";
    cin >> n;
    cout << "请输入家庭作业的数量：";
    cin >> homework_count;

    // 读取学生姓名和成绩
    for (int i = 0; i < n; ++i) {
        string name;
        cout << "请输入第 " << i + 1 << " 名学生的姓名：";
        cin >> name;
        names.push_back(name);

        cout << "请输入 " << name << " 的期中和期末成绩: ";
        double midterm, final;
        cin >> midterm >> final;
        cout << "输入" << homework_count << "个家庭作业成绩：";

        vector<double> homework;
        double x;
        for (int j = 0; j < homework_count; ++j) {
            cin >> x;
            homework.push_back(x);
        }

        typedef vector<double>::size_type vec_sz;

        vec_sz size = homework.size();
        if (size == 0) {
          cout << endl << "你必须输入你的成绩，请重新尝试." << endl;
          return 1;
        }

        sort(homework.begin(), homework.end());

        vec_sz mid = size / 2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

        double total = 0.2 * midterm + 0.4 * final + 0.4 * median;
        total_scores.push_back(total);
    }

    // 打印学生姓名和总成绩
    cout << "\n学生姓名和总成绩：" << endl;
    streamsize pre = cout.precision();
    for (int i = 0; i < n; ++i) {
        cout << names[i] << ": " << setprecision(3)
        << total_scores[i] << setprecision(pre) << endl;
    }
    return 0;
}

```

