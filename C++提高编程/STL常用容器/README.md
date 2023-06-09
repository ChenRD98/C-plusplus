# STL常用容器
## string容器
### string基本概念
本质：  
 * string是C++风格的字符串，而string本质上是一个类  
  
string和char*区别：
 * char* 是一个指针  
 * string是一个类，类内封装了char*，管理这个字符串，是一个char*型的容器  
  
特点：  
string类内部封装了很多成员函数  
例如：查找find，拷贝copy，删除delete，替换replace，插入insert  
string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责  
  
### string构造函数
构造函数原型：  
 * string(); //创建一个空的字符串 例如：string str；  
 * string(const char* s); //使用字符串s初始化  
 * string(const string& str); //拷贝构造，使用一个string对象初始化另一个string对象  
 * string(int n, char c); //使用n个字符c初始化  
  
### string赋值操作
赋值的函数原型：  
 * string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串  
 * string& operator=(const string &s); //把字符串s赋给当前的字符串  
 * string& operator=(char c); //字符赋给当前的字符串  
 * string& assign(const char* s); //把字符串s赋给当前的字符串  
 * string& assign(const char* s， int n); //把字符串s的前n个字符赋给当前的字符串  
 * string& assign(const string &s); //把字符串s赋给当前字符串  
 * string& assign(int n, char c); //用n个字符c赋给当前字符串  
  
### string字符串拼接
函数原型：  
 * string& operator+=(const char* str); //重载+=操作符  
 * string& operator+=(const char c);  
 * string& operator+=(const string& str);  
 * string& append(const char* s); //把字符串s连接到当前的字符串结尾  
 * string& append(const char* s， int n); //把字符串s的前n个字符连接到当前的字符串结尾  
 * string& append(const string &s); //同operator+=(const string& str)  
 * string& append(const string &s, int pos, int n); //字符串s中从pos开始的n个字符c连接到当前字符串结尾  
  
### string查找和替换
函数原型：  
 * int find(const string& str, int pos = 0) const; //查找str第一次出现位置，从pos开始查找  
 * int find(const char* s, int pos = 0) const; //查找s第一次出现位置，从pos开始查找  
 * int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次出现位置  
 * int find(const char c, int pos = 0) const; //查找字符c第一次出现位置，从pos开始查找  
 * int rfind(const string& str, int pos = npos) const; //查找str最后一次出现位置，从pos开始查找  
 * int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置，从pos开始查找  
 * int rfind(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符最后一次出现位置  
 * int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置，从pos开始查找  
 * string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str  
 * string& replace(int pos, int n, const char* s); //替换从pos开始n个字符为字符串s  
总结：  
 * rfind从右往左查找，find从左往右找  
 * find找到后返回查找的第一个字符位置，找不到返回-1  
 * replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串  
  
### string字符串比较
比较方式：  
 * 字符串比较是按字符的ASCII码进行对比  
 = 返回 0  
 > 返回 1  
 < 返回 -1  
  
函数原型：  
 * int compare(const string &s) const; //与字符串s比较  
 * int cmpare(const char *s) const; //与字符串s比较  
  
总结：字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义不大  
  
### string字符存取
string中单字符存取方式：  
 * char& operator[](int n); //通过[]方式取字符  
 * char& at(int n); //通过at方式获取字符  
  
### string插入和删除
函数原型：  
 * string& insert(int pos, const char* s); //插入字符串  
 * string& insert(int pos, const string& s); //插入字符串  
 * string& insert(int pos, int n, char c); //在指定位置插入n个字符c  
 * string& erase(int pos, int n = npos); //删除从Pos开始的n个字符  
  
### string子串
函数原型：  
 * string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串  
  
## vector容器
### vector基本概念
功能：  
 * vector数据结构和**数组非常相似**，也称为**单端数组**  
  
vector与普通数组区别：  
 * 不同之处在于数组是静态空间，而vector可以**动态扩展**  
  
动态扩展：  
 * 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/vector%E5%AE%B9%E5%99%A8/vector%E5%AE%B9%E5%99%A8.png)  
 * vector容器的迭代器是支持随机访问的迭代器  
  
### vector构造函数
函数原型：  
 * vector<T> v; //采用模板实现类实现，默认构造函数  
 * vector(v.begin(), v.end()); //将v[begin(),end())区间内的元素拷贝给本身  
 * vector(n, elem); //构造函数将n个elem拷贝给本身  
 * vector(const vector &vec); //拷贝构造函数  
  
### vector赋值操作
函数原型：  
 * vector& operator=(const vector &vec); //重载等号操作符  
 * assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身  
 * assign(n, elem); //将n个elem拷贝赋值给本身  
  
### vector容量和大小
函数原型：  
 * empty(); //判断容器是否为空  
 * capacity(); //容器的容量  
 * size(); //返回容器中元素的个数  
 * resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
 * resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
  
### vector插入和删除
函数原型：  
 * push_back(ele); //尾部插入元素ele
 * pop_back(); //删除最后一个元素  
 * insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
 * insert(const_iterator pis, int count, ele); //迭代器指向位置pos插入count个元素ele  
 * erase(const_iterator pos); //删除迭代器指向的元素  
 * erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素  
 * clear(); //删除容器中所有元素  
  
### vector数据存取
函数原型：  
 * at(int idx); //返回索引idx所指的数据  
 * operator[]; //返回索引idx所指的数据  
 * front(); //返回容器中第一个数据元素  
 * back(); //返回容器中最后一个数据元素  
  
### vector互换容器
函数原型：  
 * swap(vec); //将vec与本身的元素互换  
 巧用swap可以收缩内存空间，vector<int>(v).swap(v)，vector<int>(v)匿名对象，当前行执行完系统回收  
  
### vector预留空间
功能描述：  
 * 减少vector在动态扩展容量时的扩展次数  
  
函数原型：  
 * reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问  
  
## deque容器
### deque容器基本概念
功能：  
 * 双端数组，可以对头端进行插入删除操作  
  
deque与vector区别：  
 * vector对于头部的插入删除效率低，数据量越大，效率越低  
 * deque相对而言，对头部的插入删除速度会比vector快  
 * vector访问元素时的速度会比deque快，这和两者内部实现有关  
  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/deque%E5%AE%B9%E5%99%A8/deque%E5%AE%B9%E5%99%A8.png)  
  
deque内部工作原理：  
deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据  
中控器维护的时每个缓冲区的地址，使得使用deque时像一片连续的内存空间  
  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/deque%E5%AE%B9%E5%99%A8/deque%E5%AE%B9%E5%99%A8%E5%86%85%E9%83%A8%E5%B7%A5%E4%BD%9C%E5%8E%9F%E7%90%86.png)  
  
 * deque容器的迭代器也支持随机访问  
  
### deque构造函数
函数原型：  
 * deque<T> deqT; //默认构造形式  
 * deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身  
 * deque(n, elem); //构造函数将n个elem拷贝给本身  
 * deque(const deque &deq); //拷贝构造函数
  
### deque赋值操作
函数原型：  
 * deque& operator=(const deque &deq); //重载等号操作符  
 * assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身  
 * assign(n, elem); //将n个elem拷贝赋值给本身  
  
### deque大小操作
函数原型：  
 * deque.empty(); //判断容器是否为空
 * deque.size(); //返回容器中的元素个数  
 * deque.resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
 * deque.resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
  
### deque插入和删除
函数原型：  
两端插入操作：  
 * push_back(elem); //在容器尾部添加一个数据  
 * push_front(elem); //在容器头部插入一个数据  
 * pop_back(); //删除容器最后一个数据  
 * pop_front(); //删除容器第一个数据  
  
指定位置操作：  
 * insert(pos, elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置  
 * insert(pos, n, elem); //在pos位置插入n个elem数据，无返回值  
 * insert(pos, beg, end); //在pos位置插入[beg, end)区间中的数据，无返回值  
 * clear(); //清空容器的所有数据  
 * erase(beg, end); //删除[beg, end)区间中的数据，返回下一个数据的位置  
 * erase(pos); //删除pos位置的数据，返回下一个数据的位置  
  
总结：插入和删除提供的位置时迭代器！  
  
### deque数据存取
函数原型：  
 * at(int idx); //返回索引idx所指的数据  
 * operator=[]; //返回索引idx所指的数据  
 * front(); //返回容器中第一个数据元素  
 * back(); //返回容器中最后一个数据元素  
  
### deque排序
算法：
 * sort(iterator beg, iterator end); //对beg和end区间内元素进行排序  
总结：sort算法使用时需要包含algorithm头文件。对于支持随机访问的迭代器的容器，都可以使用sort算法直接排序  
  
## 案例-评委打分
### 案例描述
有5名选手：选手ABCDE，10个评委分别对每一个选手打分，去掉最高分，去除评委中最低分，取平均分  
### 实现步骤
 1.创建五名选手，放到vector中  
 2.遍历vector容器，取出每一个选手，执行for循环，可以把10个评分打分存到deque容器中  
 3.sort算法对deque容器中分束排序，取出最高分和最低分  
 4.deque容器遍历一遍，累加总分  
stack基本概念 5.获取平均分  
  
## stack容器
### stack基本概念
概念：stack是一种**先进后出**(First In Last Out, FILO)的数据结构，它只有一个出口  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/stack%E5%AE%B9%E5%99%A8/stack%E5%AE%B9%E5%99%A8.png)  
  
栈中只有顶端的元素才可以被外界使用，因此栈没有遍历操作  
栈中进入数据称为——入栈push  
栈中弹出数据称为——出栈pop  
  
### stack常用接口
构造函数：  
 * stack<T> stk; //stack采用模板类实现，stack对象的默认构造形式  
 * stack(const stack &stk); //拷贝构造函数  
  
赋值操作：  
 * stack& operator=(const stack &stk); //重载等号操作符  
  
数据存取：  
 * push(elem); //向栈顶添加元素  
 * pop(); //从栈顶移除第一个元素  
 * top(); //返回栈顶元素  
  
大小操作：  
 * empty(); //判断堆栈是否为空  
 * size(); //返回栈的大小  
  
## queue容器
### queue基本概念
概念：Queue是一种**先进先出**(First In First Out, FIFO)的数据结构，它有两个出口  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/queue%E5%AE%B9%E5%99%A8/queue%E5%AE%B9%E5%99%A8.png)  
  
队列容器允许从一端新增元素，从另一端移除元素  
队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为  
队列中进数据称为——入队push  
队列中出数据称为——出队pop  
  
### queue常用接口
构造函数：  
 * queue<T> que; //queue采用模板类实现，queue对象的默认构造形式  
 * queue(const queue &que); //拷贝构造函数  
  
赋值操作：  
 * queue& operator=(const queue &que); //重载等号操作符  
  
数据存取：  
 * push(elem); //向队尾添加元素  
 * pop(); //从队头移除第一个元素  
 * back(); //返回最后一个元素  
 * front(); //返回第一个元素    
  
大小操作：  
 * empty(); //判断堆栈是否为空  
 * size(); //返回栈的大小  
  
## list容器
### list基本概念
功能：将数据进行链式存储  
**链表**(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的  
  
链表的组成：链表由一系列**结点**组成  
结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**  
  
STL中的链表是一个双向循环链表  
![](https://github.com/ChenRD98/C-plusplus/blob/master/C%2B%2B%E6%8F%90%E9%AB%98%E7%BC%96%E7%A8%8B/STL%E5%B8%B8%E7%94%A8%E5%AE%B9%E5%99%A8/list%E5%AE%B9%E5%99%A8/list%E5%AE%B9%E5%99%A8.png)  
由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于**双向迭代器**  
  
list优点：  
 * 采用动态存储分配，不会造成内存浪费和溢出  
 * 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素  
  
list缺点：
 * 链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大  
List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector中不成立的  
  
总结：STL中**list和vector是两个最常被使用的容器**，各有优缺点  
  
### list构造函数
函数原理：  
 * list<T> lst; //list采用模板类实现，对象的默认构造形式  
 * list(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身  
 * list(n, elem); //构造函数将n个elem拷贝给本身  
 * list(const list *lst); //拷贝构造函数  
  
### list赋值和交换
函数原型：  
 * assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身  
 * assign(n, elem); //将n个elem拷贝赋值给本身  
 * list& operator=(const list &lst); //重载符号操作符  
 * swap(lst); //将lst与本身的元素互换  
  
### list大小操作
函数原型：  
 * size(); //返回容器中元素的个数  
 * empty(); //判断容器是否为空  
 * resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
 * resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem填充新位置。如果容器变短，则末尾超出容器长度的元素被删除  
  
### list插入和删除
函数原型：  
 * push_back(elem); //在容器尾部加入一个元素  
 * push_front(elem); //在容器头部插入一个数据  
 * pop_back(); //删除容器最后一个数据  
 * pop_front(); //删除容器第一个数据  
 * insert(pos, elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置  
 * insert(pos, n, elem); //在pos位置插入n个elem数据，无返回值  
 * insert(pos, beg, end); //在pos位置插入[beg, end)区间中的数据，无返回值  
 * clear(); //清空容器的所有数据  
 * erase(beg, end); //删除[beg, end)区间中的数据，返回下一个数据的位置  
 * erase(pos); //删除pos位置的数据，返回下一个数据的位置  
 * remove(elem); //删除容器中所有与elem值匹配的元素  
  
### list数据存取
函数原型：  
 * front(); //返回第一个元素  
 * back(); //返回最后一个元素  
  
### list反转和排序
函数原型：  
 * reverse(); //反转链表  
 * sort(); //链表排序  
  
### 排序案例
案例描述：将Person自定义数据类型进行排序，Person中属性由姓名、年龄、身高  
排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序  
  
总结：  
 * 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序  
 * 高级排序只是在排序规则上再进行一次逻辑规则制定，不复杂  
  
## set/ multiset容器
### set基本概念
简介：所有元素都会在插入时自动被排序  
  
本质：set/multiset属于**关联式容器**，底层结构式用**二叉树**实现的  
  
set和multiset区别：  
 * set不允许容器中有重复的元素  
 * multiset允许容器中有重复的元素  
  
### set构造和赋值
构造：  
 * set<T> st; //默认构造函数；  
 * set(const set &st); //拷贝构造函数  
  
赋值：  
 * set& operator=(const set &st); //重载等号操作符  
  
### set大小和交换
函数原型：  
 * size(); //返回容器中元素的数目  
 * empty(); //判断容器是否为空  
 * swap(st); //交换两个集合容器  
  
### set插入和删除
函数原型：  
 * insert(elem); //在容器中插入元素  
 * clear(); //清除所有元素  
 * erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器  
 * erase(beg, end); //删除区间[beg, end)的所有元素，返回下一个元素的迭代器  
 * erase(elem); //删除容器中值为elem的元素  
  
### set查找和统计
函数原型：  
 * find(key); //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();  
 * count(key); //统计key元素个数  
  
### set和multiset区别
区别：  
 * set不可以插入重复数据，而multiset可以  
 * set插入数据的同时会返回插入结果，表示插入是否成功  
 * multiset不会检测数据，因此可以插入重复数据  
  
### pair对组创建
功能描述：成对出现的数据。利用对组可以返回两个数据  
  
两种创建方式：  
 * pair<type, type> p (value1, value2);  
 * pair<type, type> p = make_pair(value1, value2);  
  
### set容器排序
主要技术点：利用仿函数，可以改变排序规则  
  
总结：  
 * set在插入数据后就不能改变排序规则了，所以利用仿函数myCompare定义排序规则  
 * 对于自定义数据类型，set必须指定排序规则才可以插入数据  
  
## map/ multimap容器
### map基本概念
简介：  
 * map中所有元素都是pair  
 * pair中第一个元素是key(键值)，起到索引作用，第二个元素为value(实值)  
 * 所有元素都会根据元素的键值自动排序  
  
本质：  
 * map/multimap属于**关联式容器**，底层结构是用二叉树实现  
  
优点：  
 * 可以根据key值快速找到value值  
  
map和multimap区别：  
 * map不允许容器中有重复key值元素  
 * multimap允许容器中有重复key值元素  
  
### map构造和赋值
函数原型：  
构造：  
 * map<T1, T2> mp; //map默认构造函数  
 * map(const map &mp); //拷贝构造函数  
  
赋值：  
 * map& operator=(const map &mp); //重载等号操作符  
  
### map大小和交换
函数原型：  
 * size(); //返回容器中元素的数目  
 * empty(); //判断容器是否为空  
 * swap(mp); //交换两个map容器  
  
### map插入和删除
函数原型：  
 * insert(elem); //在容器中插入元素  
 * clear(); //清除所有元素  
 * erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器  
 * erase(beg, end); //删除区间[beg, end)的所有元素，返回下一个元素的迭代器  
 * erase(key); //删除容器中值为key的元素  
  
### map查找和统计
函数原型：  
 * find(key); //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回mp.end();  
 * count(key); //统计key的元素个数  
  
### map排序
 * map容器默认排序规则为 按照key值进行 从小到大排序  
 * 利用仿函数，可以改变排序规则  
  
总结： 
 * 利用仿函数可以指定map容器的排序规则  
 * 对于自定义数据类型，map必须要指定排序规则，同set容器  
  
## 案例-员工分组
### 案例描述
 * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在哪个部门工作  
 * 员工信息有：姓名 工资组成；部门分为：策划、美术、研发  
 * 随机给10名员工分配部门和工资  
 * 通过multimap进行信息的插入 key(部门编号) value(员工)  
 * 分部门显示员工信息  
  
### 实现步骤
 1.创建10名员工，放到vector中  
 2.遍历vector容器，取出每个员工，进行随机分组  
 3.分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中  
 4.分部门显示员工信息  
  
