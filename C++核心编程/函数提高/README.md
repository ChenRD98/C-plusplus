# 函数提高
### 函数默认参数
在C++中，函数的形参可以有默认值  
注意：  
    1、如果某个位置已经有了默认值，这个位置之后都必须有默认值  
    2、函数声明和实现只能有一个有默认参数 
  
### 函数占位参数
C++中函数的形参列表里可以有占位参数，调用时必须填补该位置  
语法：返回值类型 函数名 （数据类型）{}  
占位参数可以有默认值  
  
### 函数重载
作用：函数名可以相同，提高复用性  
需要满足条件：  
*同一个作用域下  
*函数名相同  
*函数参数**类型不同**或者**个数不同**或者**顺序不同**  
  
注意：函数的返回值不可以作为函数重载的条件（返回值类型要相同）  
  
#### 函数重载注意事项
*引用作为重载条件  
*函数重载碰到函数默认参数 ，会出现二义性报错，避免出现  
 
