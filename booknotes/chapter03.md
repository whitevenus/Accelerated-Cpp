# 计算学生成绩

![概述](./images/04-avgScore.png)

## 程序片段

```c++
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using std::cout; using std::string; 
using std::cin; using std::endl; 
using std::streamsize;  using std::setprecision;

int main()
{
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades, "
          "followed by end-of-file: ";
  int count = 0;
  double sum = 0;
  double x;
  while (cin >> x) {
    ++count;
    sum += x;
  }

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
       << setprecision(prec) << endl;

  return 0;
}
```

在这门课程中, 每个学生的总成绩都由期末考成绩(占总成绩的40%)、期中考成绩(占20%〉和家庭作业的平均成绩(占40%〉构成。该程序根据学生输入的成绩计算学生总成绩。

## 深入解读

### 浮点型数值

**单精度浮点型**：`float`最多表示大致 6 位有效数字。

**双精度浮点型**：`double`至少能表示大致 10 位有效数字。

### 字符串直接量的自动拼接

如果两个以上的字符串直接量之间仅仅是被**空白符**分隔开，则其会被自动连接在一起。这使得我们可以以更具可读性的方式书写过长的字符串直接量。

### 隐含初始化

对于自定义类型，例如`string`，当我们在声明该类型变量的同时不进行初始化赋值操作，则该类型会自动的被隐含初始化为空字符串。

但是定义内置类型的局部变量时，系统并不会提供该便利。这意味着我们在定义基本类型的变量时，需要手动为其进行初始化，否则可能会导致程序出现意想不到的错误。

### 检测输入

`if(cin)`和`while(cin)`的意义：

`iostream`这个类提供了一个转换可以将`cin`对象转换为可以在条件表达式中使用的值。这个转换的值取决于`istream`对象的内部状态，该状态标志着最近一次读入值是否成功。若是成功，则其会被转换为`true`，否则为`false`。

读取数据失败的情况主要有下面三种：

+ 已经到达了文件结尾
+ 碰到的输入和要读取变量的类型不一致
+ 系统在输入装置中检测到一个硬件问题

### streamsize类型

位于头文件`<ios>`中，输入输出使用该类型表示长度。

### precision成员函数

该函数是`cout`对象的成员函数，用于返回流在输出浮点数时所使用的精度。

### setprecision控制器

位于头文件`<iomanip>`中，用于指明输出所包含的有效位数。

该控制器为流的后继输出设置了一个特定的有效位数，从而实现对流的控制。

# 用中值代替平均值

![概述](../../../docs/BackEnd/images/Accelerated-C++/05-用中值代替平均值.png)

## 程序片段

```c++
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>
using std::cout; using std::string; 
using std::cin; using std::endl; 
using std::streamsize;  using std::setprecision;
using std::vector; 

int main()
{
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades, "
          "followed by end-of-file: ";

  double x;
  vector<double> homework;
  while (cin >> x) {
    homework.push_back(x);
  }

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if (size == 0) {
    cout << endl << "You must enter your grades. "
                    "Please try again." << endl;
    return 1;
  }

  sort(homework.begin(), homework.end());
  
  vec_sz mid = size / 2;
  double median;
  median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + 0.4 * median
       << setprecision(prec) << endl;

  return 0;
}
```

该程序用中值代替平均值计算学生的总成绩。

## 深入解读

### 向量

标准库提供一种名为`vector`的容器，用于保存具有特定类型的数值，它的大小可以根据需要进行自动增长，并且允许高效的访问其中元素。

`vector<double> homeworl`：定义一个用于保存`double`类型值的向量`homework`。

### vector<...>::size_type类型

该类型和`string::size_type`类型具有相似的作用，是一个**无符号类型**，用于保存向量长度。

`vector`类的`size`成员函数返回一个用于表示当前向量长度的`size_type`类型值。

### typedef

该关键字用于为特定类型**起别名**，例如：

`typedef vector<double>::size_type vec_sz`表示`vec_sz`是`vector<doblue>::size_type`类型的一个替代名称，其生存期直到当前作用域结束。

### push_back成员函数

该函数被定义为`vector`类型的一部分，用于向变量末尾添加一个新的元素。作为副作用，它会将变量的长度加 1。

### sort函数

`sort`函数定义在头文件`<algorithm>`中，它将容器中的数据排列为非递减序列。参数指定了被排序元素的起始位置。

`vector`类的两个成员函数`begin`和`end`分别用来表示容器第一个元素和紧跟在容器最后一个元素之后的位置。

### 访问向量元素的方法

向量中的任意一个元素都有一个被称为**索引**的整数与之相关联

`homework[0]`表示向量的第一个元素，`homework[size - 1]`表示向量的最后一个元素。