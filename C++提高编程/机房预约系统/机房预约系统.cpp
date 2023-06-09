#include "showMenu.h"
#include "globalFile.h"
#include "identity.h"
#include<fstream>
#include<string>
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入管理员子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		//管理员菜单
		manager->operMenu();
		//manger父类指针只能调用公共接口，所以需要强转回子类指针
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//登录功能
void LoginIn(string fileName, int type) {
	Identity* person = NULL;	//父类指针创建子类对象
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	
	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		//学生登陆
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		//教师登陆
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生登陆验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入的信息做对比
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单

				return;
			}
		}
	}
	else if (type == 2) {
		//教师登陆验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登陆验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "管理员验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登陆失败！" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {

	int select = 0;

	while (true) {
		showMenu();
		cin >> select;

		switch (select) {
		case 1:
			//学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			//退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}



	}

	system("pause");
	return 0;
}