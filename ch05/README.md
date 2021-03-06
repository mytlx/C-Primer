# Chapter 5. Statements


## Exercise 5.1
> 什么是空语句？什么时候会用到空语句？

只含有一个单独分号的语句叫空语句
```cpp
;   //空语句
```
如果程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。例如，
```cpp
while(cin << s && s != sought)
    ;   //空语句
```


## Exercise 5.2
> 什么是块？什么时候会用到块？

复合语句是指用花括号括起来的（可能为空的）语句和声明的序列，复合语句也被称为块。  
如果程序的某个地方，语法上需要一条语句，但是逻辑上需要多条语句，则应该使用块。例如，
```cpp
while(val <= 10){
    sum += val;     // 把sum + val的值赋给sum
    ++val;          // 给val加1
}
```


## Exercise 5.3
> 使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。
> ```cpp
> while (val <= 10) {
>     sum += val;   // 将sum + val赋予sum
>     ++val;        // 将val加1
> }
> ```

改写后：
```cpp
while (val <= 10) {
    sum += val, ++val;
}
```
可读性降低了。


## Exercise 5.4
> 说明下列例子的含义，如果存在问题，试着修改它。
> ```cpp
> (a) while (string::iterator iter != s.end())
>     {/*......*/}
> (b) while (bool status = find(word))
>     {/*......*/}
>     if (!status)  {/*......*/}
> ```

(a) 中iter未指向对象，不合法  
(b) 中status未在while块内，所以if中未声明


## [Exercise 5.5]()


















