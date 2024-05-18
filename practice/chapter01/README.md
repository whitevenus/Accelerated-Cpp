# 第 1 章 《使用字符串》 编程练习题之自答

## 1.1

**题**：以下的定义有效吗？理由是什么？

```txt
const std::string hello = "Hello";
const std::string message = hello + ", world" + "!";
```

**解**：

这是有效的定义。因为它满足以下这些规则：

+ 定义常量同时必须进行初始化。

+ 运算符`+`可以实现字符串与字符串直接量的拼接，并且其是**左结合**的。
+ 另外常量的初始化值不要求必须为常量。

## 1.2 

**题**：以下的定义有效吗？理由是什么？

```txt
const std::string exclam = "!";
const std::string message = "Hello" + ", world" + exclam;
```

**解**：

这是无效的定义，因为它违反了这条规定：

+ 运算符`+`是左结合的，不能作用与两个字符串直接量。

## 1.3

**题**：以下的程序有效吗？如果有效的话，它是做什么的？如果无效，为什么呢？

```txt
#include <iostream> 
#include <string> 

int main()
{ 
	{ const std::string s = "a string"; 
	  std::cout << s << std::endl; } 
	
	{ const std::string s = "another string";
	  std::cout << s << std::endl; } 
	 return 0;
}
```

**解**：

该程序是有效的，每一个`{}`开启一个独立的作用域。该程序会先后输出`a string`和`another string`。

## 1.4

**题**：下面的这个程序又怎样呢？如果我们把倒数第三行的`}}`改成`};}`的话，会出现什么情况呢？

```txt
#include <iostream> 
#include <string> 

int main()
{ 
	{ const std::string s = "a string"; 
	  std::cout << s << std::endl;
	{ const std::string s = "another string";
	  // std::cout << s << std::endl; }}
	  std::cout << s << std::endl; };}
	 return 0;
}
```

**解**：

没改之前程序是有效的，其作用和 1.3 的程序的作用一致。

改了以后的程序也是有效的，其作用和没改之前的程序的作用一致。并且说明`}`后面的分号`;`可有可无。

## 1.5

**题**：下面这个程序呢？如果有效，它是做什么的？如果无效，说出理由，然后把它改写成有效的程序。

```txt
#include <iostream> 
#include <string> 

int main()
{ 
	{ std::string s = "a string"; 
	{ std::string x = s + ", really"; 
	  std::cout << s << std::endl; }
	  std::cout << x << std::endl;  // x is out of its scope here
	}
	 return 0;
}
```

**解**：

这个程序是无效的，因为**局部变量**具有生存期，其只存活在其所属的作用域中。变量`x`定义在内层`{}`定义的作用域内，却在该作用域外使用。这违反了局部变量的特性。将其改为以下程序便是有效的程序：

```c++
#include <iostream> 
#include <string> 

int main()
{ 
	{ std::string s = "a string"; 
	{ std::string x = s + ", really"; 
	  std::cout << x << std::endl; }
	  std::cout << s << std::endl;
	}
	 return 0;
}
```

## 1.6

**题**：在下面的程序向你发出输入请求的时候，如果你输入了两个名字（例如：Samuel Beckett），它会怎么样处理呢？在运行程序之前先预测一下结果，然后上机试一下。

```txt
#include <iostream> 
#include <string> 

int main() 
{ 
	std::cout << "what ia your name? ";
  std::string name; 
  std::cin >> name;
  std::cout << "Hello, " << name
            << std::endl << "And what is yours? "; 
  std::cin >> name; 
  std::cout << "Hello, " << name
  << "; nice to meet you too!" << std::endl;
  return 0;
}
```

**解**：

该程序会输出：

```bash
what ia your name?  Samuel Beckett
Hello, Samuel
And what is yours? Hello, Beckett; nice to meet you too! 
```

