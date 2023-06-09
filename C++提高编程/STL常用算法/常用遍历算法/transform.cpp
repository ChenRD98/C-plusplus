#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Transform {
public:
	int operator()(int v) {
		return v + 1000;
	}
};

class MyPrint {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), Transform());
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}