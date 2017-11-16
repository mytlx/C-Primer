# Chapter 4. Expressions

## Exercise 4.1
> 表达式`5+10*20/2`的求值结果是多少？  

105


## Exercise 4.2
> 根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。  
> ```cpp
> (a) *vec.begin()  //=>  *(vec.begin())     
> (b) *vec.begin() + 1  //=> (*(vec.begin())) + 1
> ```


## Exercise 4.3
> C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。
> 这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。

C++的效率确实是优势，但是这样的设计很容易出现很多bug，所以如果不是特别熟悉，不要轻易使用那些容易引起歧义的语句吧

## Exercise 4.4
> 在下面的表达式中添加括号，说明其求值的过程及最终结果。编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断。  
> ```cpp
> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2   
> // => ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
> ```

91


## Exercise 4.5
> 写出下列表达式的求值结果。
> ```cpp
> (a) -30 * 3 + 21 / 5  // => (-30 * 3) + (21 / 5) == -86
> (b) -30 + 3 * 21 / 5  // => -30 + ((3 * 21) / 5) == -18
> (c) 30 / 3 * 21 % 5  // => ((30 / 3) * 21) % 5 == 0
> (d) -30 / 3 * 21 % 4  // => ((-30 /3) * 21) % 4 == -2
> ```


## Exercise 4.6
> 写出一条表达式用于确定一个整数是奇数还是偶数
```cpp 
i % 2 == 0? "even" : "odd"
```


## Exercise 4.7
> 溢出是何含义？ 写出三条将导致溢出的表达式
```cpp
short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```


## Exercise 4.8
> 说明在逻辑与、逻辑或及相等性运算符中运算对象求值的顺序

- 逻辑与（&&）：当且仅当左侧运算对象为真时才对右侧运算对象求值
- 逻辑或（||）：当且仅当左侧运算对象为假时才对右侧运算对象求值
- 相等性（==）：左右对象的值相等时返回true，否则返回false


## Exercise 4.9
> 解释在下面的if语句中条件部分的判断过程
> ```cpp
> const char *cp = "Hello World";
> if(cp && *cp)
> ```

首先判断cp是否为真，cp是指向字符串的指针，不是空指针，所以是true，所以之后判断`*cp`是否为真，因为`*cp`为字符串，有具体的值，所以是true，所以，`true && true == true`


## Exercise 4.10
> 为whle循环写一个条件，使其从标准输入中读取整数，遇到42时停止。
> ```cpp
> int i = 0
> while(cin >> i && i != 42)
> ```


## Exercise 4.11
> 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。
> ```cpp
> (a > b) && (b > c) && (c > d)
> ```


## Exercise 4.12
> 假设i、j和k是三个整数，说明表达式`i != j < k`的含义。

因为`<`的优先级高于`!=`， 所以首先判断`j < k`是否为真， 若为真， 则判断`i != 1`; 若为假， 则判断`i != 0`


## Exercise 4.13
> 在下述语句中，当赋值完成后i和d的值分别是多少？
> ```cpp
> int i; double d;
> (a) d = i = 3.5;  // => i == 3, d == 3.0
> (b) i = d = 3.5;  // => i == 3, d == 3.5
> ```


## Exercise 4.14
> 执行下述if语句后将发生什么情况？
> ```cpp
> if (42 = i)   // 编译器报错，42非左值，不能执行赋值操作
> if (i = 42)   // 将42赋值给i，因为42为true，所以if语句为true，但如果本意是比较`i == 42`，可能后续会出现bug
> ```


## Exercise 4.15
> 下面的赋值是非法的，为什么？应该如何修改？
> ```cpp
> double dval; int ival; int *pi;
> dval = ival = pi = 0;   // => dval = ival = 0; pi = 0;
> ```

因为无法从`int*`类型转换成`int`类型，所以会出错


## Exercise 4.16
> 尽管下面的语句合法，但他们实际执行的行为可能和预期并不一样，为什么？应如何修改？
> ```cpp
> (a) if(p = getPtr() != 0)  
>     // 因为'!='的优先级要高于'='，所以实际执行是 if(p = (getPtr() != 0)), 将比较结果赋值给了p  
>     // => if((p = getPtr()) != 0)  
> (b) if(i = 1024)  
>     // 虽然不会报错，但是原意应该是对比i和1024，但是现在是将1024赋值给i  
>     // => if(i == 1024)


## Exercise 4.17
> 说明前置递增运算符和后置递增运算符的区别。

- 前置递增运算符：首先将运算对象加1，然后将改变后的对象作为左值返回。 
- 后置递增运算符：将运算对象加1，将原始值的副本作为右值返回。


## Exercise 4.18
> 如果第132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

可能发生错误，解引用一个不存在的元素


## Exercise 4.19
> 假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？  
> ```cpp
> (a) ptr != 0 && `*ptr++  `
>     // 确定ptr非0， 然后解引用ptr，再把ptr向前移动一个单位  
> (b) ival++ && ival  
>     // 判断ival是不是真，然后将ival加1， 再判断ival是不是真  
> (c) vec[ival++] <= vec[ival]  
>     //表达式不正确，关系运算符两端的对象都用到了ival，左侧还改变了ival的值  
>     // => vec[ival] <= vec[ival+1]


## Exercise 4.20
> 假设iter的类型是vector<string>::iterator，说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
> ```cpp
> (a) *iter++;  // 解引用iter，并将指针向前移动一个单位
> (b) (*iter)++;  // 不合法，*iter是个string类型，不能执行++操作
> (c) *iter.empty(); // 不合法，成员运算符优先级高
> (d) iter->empty(); // 判断iter指向的值是否为空
> (e) ++*iter;  // 不合法，右结合律，*iter是string对象，不能执行++操作
> (f) iter++->empty();  // 判断iter->empty()，再将指针向前移动一个单位
> ```
  
  
## [Exercise 4.21](ex4_21.cpp)
> 编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数和，然后将这些奇数值翻倍。
  
  
## [Exercise 4.22](ex4_22.cpp)


## Exercise 4.23
> 因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？
> ```cpp
> string s = "word";
> string p1 = s + s[s.size()-1] == 's' ? "" : "s";   // => string p1 = s + (s[s.size()-1] == 's' ? "" : "s");
> ```

优先级：'+' > '==' > '?:' > '=', 所以先计算s + s[s.size()-1] , 再判断是否相等


## Exercise 4.24
> 本节的示例程序将成绩划分成high pass、pass和fail三种，它的依据是条件运算符满足右结合律。假如条件远算符满足的是左结合律，求值过程将是怎样的？

如果是左结合,等同于
```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
如果grade>90, 则第一个？结果是high pass， 第二个？结果是fail，矛盾


## Exercise 4.25
> 如果一台机器上int占32位、char占8位，用的是Latin-1字符集，其中字符'q'的二进制形式是01110001，那么表达式~'q'<<6的值是什么？

因为是32位，写完整为`‭0000 0000 0000 0000 0000 0000 0111 0001‬`，取反可得`‭1111 1111 1111 1111 1111 1111 1000 1110‬`，左移六位可得`‭1111 1111 1111 1111 1110 0011 1000 0000‬`化成十进制为`-7296`


## Exercise 4.26
> 在本节关于测验成绩的例子中，如果使用unsigned int作为quiz1的类型会发生什么情况？

unsigned long类型可以保证在任何机器上都至少拥有32位，但是unsigned int就不一定了


## Exercise 4.27
> 下面表达式的结果是什么？
> ```cpp
> unsigned long ul1 = 3, ul2 = 7;
> (a) ul1 & ul2   // => 0011 => 3
> (b) ul1 | ul2   // => 0111 => 7
> (c) ul1 && ul2  // => true
> (d) ul1 || ul2  // => true  
> ```


## [Exercise 4.28](Cpp-Primer-5th/ch04/ex4_28.cpp)


## Exercise 4.29
> 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想想的一样吗？如果不一样，为什么？
> ```cpp
> int x[10]; int *p = x;
> cout << sizeof(x) / sizeof(*x) << endl;
> cout << sizeof(p) / sizeof(*p) << endl;
> ```

对数组使用得到的是数组大小，所以第一个是求数组大小，结果为10，第二个一开始我认为是1/10，


## Exercise 4.30
> 根据4.12节中的表（第147页），在下述表达式的适当位置加上括号，使得加上括号之后表达式的含义与原来的含义相同。
> ```cpp
> (a) sizeof x + y    // => (sizeof x) + y
> (b) sizeof p->mem[i]    // => sizeof(p->mem[i])
> (c) sizeof a < b    // => (sizeof a) < b
> (d) sizeof f()    // => (sizeof f()) 如果f()返回类型是void，则未定义，如果不是，则返回返回类型的大小
> ```


## Exercise 4.31
> 本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

本章4.5节有讲到：**除非必须，否则不用递增递减运算符的后置版本**
```cpp
for(vector<int>::size_type ix = 0;ix != ivec,size();ix++,cnt--)
    ivec[ix] = cnt;
```
> **除非必须，否则不用递增递减运算符的后置版本**    
> 有C语言背景的读者可能对优先使用前置版本递增运算符有所疑问，其实原因非常简单：前置版本的递增运算符避免了不必要的工作，它把值加1后直接返回改变了的运算对象。与之相比，后置版本需要将原始值存储下来以便于返回这个未修改的内容。如果我们不需要修改前的值，那么后置版本的操作就是一种浪费。    
> 对于整数和指针类型来说，编译器可能对这种额外的工作进行一定的优化；但是对于相对复杂的迭代器类型，这种额外的工作就消耗巨大了。建议养成使用前置版本的习惯，这样不仅不需要担心性能的问题，而且更重要的是写出的代码会更符合编程的初衷。


## Exercise 4.32
> 解释下面这个循环的含义。
> ```cpp
> constexpr int size = 5;
> int ia[size] = {1,2,3,4,5};
> for(int *ptr = ia, ix=0;ix != size && ptr != ia+size;++ix, ++ptr)
> { /*...*/ }
> ```

ptr是指向数组的指针，ix是数组下标，他么作用相同，控制循环条件，遍历数组


## Exercise 4.33
> 根据4.12节中的表（第147页）说明下面这条表达式的含义。
> ```cpp
> someValue ? ++x, ++y : --x, --y;
> ```

如果someValue为true，则x和y执行加一操作；如果someValue为false，则x和y执行减一操作，这个题愿意是这样，但是由于逗号的优先级最低，所以表达式等价于：  
> ```cpp
> (someValue ? ++x, ++y : --x), --y;
> ```

所以，如果someValue为true，对y的值会造成影响。


## Exercise 4.34
> 根绝本节给出的变量定义，说出在下面的表达式中将发生什么样的类型转换：
> ```cpp
> (a) if(fval);   // float => bool
> (b) dval = fval + ival;   // int => float => double
> (c) dval + ival * cval;   // char => int => double
> ```
> 需要注意每种运算符遵循的是左结合律还是右结合律。


## Exercise 4.35
> 假设有如下的定义，
> ```cpp
> char cval;    int ival;   usigned int ui;
> float fval;   double dval;
> ```
> 请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
> ```cpp
> (a) cval = 'a' + 3;   // a => int, result => char
> (b) fval = ui - ival * 1.0;   // ui and ival => double => float
> (c) dval = ui * fval;   // ui => float, result => double
> (d) cval = ival + fval + dval;    // ival => float, result1 => double, result2 => char
> ```


## Exercise 4.36
> 假设i是int类型，d是double类型，书写表达式i*=d使其执行整数类型的乘法而非浮点类型的乘法。  
```cpp
i *= static<int>(d);
```


## Exercise 4.37
> 用命名的强制类型转换改写下列旧式的转换语句。
> ```cpp
> int i; double d; const string *ps; char *pc; void *pv;
> (a) pv = (void*)ps;   // pv = static_cast<void*>(const_cast<string*>(ps));
> (b) i = int(*pc);   // i = static<int>(*pc);
> (c) pv = &d;    // pv = static_cast<void*>(&d);
> (d）pc = (char*) pv;   // pc = static_cast<char*>(pv); pc = reinterpret_cast<char*>(pv);
> ```


## Exercise 4.38
> 说明下面这条表达式的含义。
> ```cpp
> double slope = static_cast<double>(j/i);
> ```

把j/i转换成double赋值给slope












