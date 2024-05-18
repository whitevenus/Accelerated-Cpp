# 第 0 章 《开始学习 C++》 编程练习题之自答

## 0.1

**题**：下面的表达式是做什么的？

```txt
3 + 4;
```

**解**：

表达式后紧跟分号`;`表示让系统环境丢弃该表达式的结果。另外该表达式无任何副作用产生，因此该表达式无任何意义。

## 0.2

**题**：编写一个程序，使它在运行时输出：

```txt
This (") is a quote, and this (\) is a backlash.
```

**解**：

```c++
#include <iostream>

int main()
{
  std::cout << "This (\") is a quote, and this (\\) is a backlash." << std::endl;
  return 0;
}
```

## 0.3

**题**：字符串直接量`\t`代表一个水平制表符，不同的C++实现以不同的形式显示制表符。在你的实现中实验一下，看它是怎样处理制表符的。

**解**：

```c++
// 一个小小的C程序
#include <iostream>

int main()  
{
  std::cout << "Hello,\tworld!" << std::endl;
  return 0;
}
```

在MacOS的C++实现中，`\t`表示**两个**空白字符。

## 0.4

**题**：编写一个程序，运行时以 Hello,world! 程序作为这个程序的输出。

**解**：

```c++
#include <iostream>

int main()  
{
  std::cout << "#include <iostream>\n" << std::endl;
  std::cout << "int main()" << std::endl;
  std::cout << "{" << std::endl;
  std::cout << "\tstd::cout << \"Hello, World!\" << std::endl;" << std::endl;
  std::cout << "\treturn 0;" << std::endl;
  std::cout << "}" << std::endl;
  return 0;
}
```

## 0.5

**题**：下面的程序是一个有效的程序吗？说出理由

```txt
#include <iostream> 
int main()	std::cout << "Hello, world!" << std::endl;
```

**解**：

这是一个无效的程序。因为哪怕函数体只包含一条语句，但必须使用`{}`进行包裹。这是因为`{}`在C++编译器眼中有特殊的意义。

## 0.6

**题：**下面的程序是一个有效的程序吗？说出理由

```txt
#include <iostream>
int main()	{{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}
```

**解**：

这是一个有效的程序。因为C++ 程序允许**自由风格**编码，每一个`{}`都是一个单独的作用域。

## 0.7

**题**：那下面这个程序呢？

```txt
#include <iostream>
int main()
{
  /*这是一个注释，因为我们是用了/*和*/来作为他的界定符，
   所以它占据了几行的范围*/
   std::cout << "Does this work?" << std::endl;
   return 0;
}
```

**解**：

这是一个无效的程序。因为多行注释以`/*`开始，以`*/`结束。因此在第四行`*/`之后的字符被当作名称，而C++编译器并不认识知道这些字符代表什么，因此会编译失败。

## 0.8

**题**：这个呢？

```txt
#include <iostream>
int main()
{
	//这是一个注释，它占据了几行的范围
	//在这里，我们是用了//而不是/*
	//和*/来为注释定界
	std::cout << "Does this work?" << std::endl;
	return 0;
}
```

**解**：

这是一个有效的程序。因为`//`是一段注释的开始，其后可以跟任意字符，直到行尾结束。

## 0.9

**题**：最短的有效程序是什么？

**解**：

```c++
int main(){}
```

一个C++程序必须包含`main`函数，C++编译器允许省略 main函数中的返回语句，如果省略了，它会自动补上`return 0;`这条语句。

## 0.10

**题**：重写 Hello, world! 程序，让程序中每一个允许出现空白字符的地方换行。

**解**：

```c++
#include <iostream>
int
main
( 
)
{
  std
  ::
  cout
  <<
  "Hello, world!"
  <<
  std
  ::
  endl
  ;
  return
  0 
  ;
}
```

C++允许自由风格编码，但`#include <iostream>`必须在一行中。

