# STL-函数对象
## 函数对象
### 函数对象概念
概念：  
 * **重载函数调用操作符**的类，其对象常称为**函数对象**  
 * **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**  
  
本质：  
 * 函数对象(仿函数)是一个类，不是一个函数  
  
### 函数对象使用
特点：  
 * 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值  
 * 函数对象超出普通函数的概念，函数对象可以有自己的状态  
 * 函数对象可以作为参数传递  
  
## 谓词
### 谓词概念
概念：  
 * 返回bool类型的仿函数称为**谓词**  
 * 如果operator()接收一个参数，那么叫做一元谓词  
 * 如果operator()接收两个参数，那么叫做二元谓词  
  
### 一元谓词
### 二元谓词
  
## 内建函数对象
### 内建函数对象意义
概念：  
 * STL内建了一些函数对象  
  
分类：  
 * 算数仿函数  
 * 关系仿函数  
 * 逻辑仿函数  
  
用法：  
 * 这些仿函数所产生的对象，用法和一般函数完全相同  
 * 使用内奸函数对象，需要引入头文件#include<functional>  
  
### 算数仿函数
功能描述：  
 * 实现四则运算  
 * 其中negate时一元运算，其他都是二元运算  
  
仿函数原型：  
 * template<class T> T plus<T> //加法仿函数  
 * template<class T> T minus<T> //减法仿函数  
 * template<class T> T multiplies<T> //乘法仿函数  
 * template<class T> T divides<T> //除法仿函数  
 * template<class T> T modulus<T> //取模仿函数  
 * template<class T> T negate<T> //取反仿函数  
  
### 关系仿函数
仿函数原型：  
 * template<class T> bool equal_to<T> //等于  
 * template<class T> bool not_equal_to<T> //不等于  
 * template<class T> bool greater<T> //大于(最常用)  
 * template<class T> bool greater_equal<T> //大于等于  
 * template<class T> bool less<T> //小于  
 * template<class T> bool less_equal<T> //小于等于  
  
### 逻辑仿函数
仿函数原型：  
 * template<class T> bool logical_and<T> //逻辑与  
 * template<class T> bool logical_or<T> //逻辑或  
 * template<class T> bool logical_not<T> //逻辑非  
  
