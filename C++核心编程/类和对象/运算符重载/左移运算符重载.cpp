#include<iostream>
using namespace std;
//左移运算符重载
class Person {
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	//利用成员函数重载 左移运算符 p.operator<<(cout) 简化版本 p<<cout
	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	//void operator<< ( cout )
	int m_A;
	int m_B;
};
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream& out, Person& p) {
	out << "m_A = " << p.m_A << "m_B = " << p.m_B;
	return out;
}

void test01() {
	Person p(10, 10);
	//<<endl链式编程思想，需要前面返回的还是cout，不能是void
	cout << p << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}