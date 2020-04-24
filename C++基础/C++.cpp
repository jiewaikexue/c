#include "header1.h"
#include "header2.h"

#include <stdio.h>
#include <stdlib.h>


//全局域
//int  global = 10;

int fun()
{
	//局部域
	int a = 1;
	return a;
}

//文件域
static void fun2()
{

}

void testNamespace()
{
	//成员使用方式：
	//1.命名空间 + ::(作用域限定符）+ 成员(变量 + 函数）
	//全局域： 没有名字
	::global = 10;
	global = 1;
	header1::global = 200;
	header1::var2 = 10;
	header1::internal::var = 1;
}

//成员使用方式：
// 2.  using + 完整作用域的变量
using header1::internal::var;

//可以给命名空间起别名， 可以简化命名空间的书写
namespace hi = header1::internal;

void testNamespace2()
{
	var = 1;
	header1::internal::var = 2;
	header1::var2 = 10;
	header1::fun2();
	header1::fun3();
	header1::global = 1;
	hi::var = 2;
}

//成员的使用方式:
// 3 using + namespace + 命名空间名称
// 相当于把命名空间下的所有成员暴露在全局域中
// 不建议使用此种方式
//using namespace header1;
/*
void testNamespace3()
{
	var2 = 1;
	fun2();  //造成命名冲突
	fun3();
	global = 1;  //和全局域中的global造成命名冲突
}
*/
#include <stdio.h>
//早期C++ cout使用： #include <iostream.h>
//vc6.0 支持 #include <iostream.h>
//C++
#include <iostream>
using std::cout;
using namespace std;
void testInput()
{
	int a = 10;
	printf("%d\n", a);
	printf("C++ output\n");
	std::cout << a;
	cout << a << "\n";

	float b;
	scanf("%d", &a);
	scanf("%f", &b);

	cin >> a >> b;  //  函数重载 +  运算符重载 + 引用
	cout << a << " " << b << "\n";

}
//缺省参数： 定义函数/声明函数时给参数一个默认值， 声明或者定义，只能选其一给默认值
//函数声明
void fun4(int a = 100);
//定义
void fun4(int a)
{
	cout << a << endl;
}

//全缺省： 所有的参数都有默认值
void fun5(int a = 1, int b = 2, int c = 3)
{
	cout << a << b << c << std::endl;
}

//半缺省： 从右到左的顺序给参数默认值，部分参数没有设置默认值
void fun6(int a, int b = 1, int c = 2)
{
	cout << a << b << c << endl;
}
//半缺省： 从右到左的顺序给参数默认值, 中间不能有间隔，部分参数没有设置默认值
/*
void fun7(int a, int b = 1, int c, int d = 2)
{
	cout << a << b << c << endl;  // end line  endl   endl <--等效--> "\n"
}
*/
//函数重载：前提： 在同一个作用域下    ---->  同一个系列的不同版本的手机 
//        函数名相同， 参数信息不同的多个函数构成函数重载
//        参数信息: 参数个数，参数类型， 参数的顺序
void fun6(int a)
{
	cout << a << endl;
}

void fun7(int a, float b, char c)
{
	cout << "fun7(int a, float b, char c)" << endl;
}
//参数个数不同
void fun7(int a)
{
	cout << "fun7(int a)" << endl;
}
//参数类型不同
void fun7(char a, char b, char c)
{
	cout << "fun7(char a, char b, char c)" << endl;
}

//参数顺序不同
void fun7(char c, float b, int a)
{
	cout << "fun7(char c, float b, int a)" << endl;
}

void test3()
{
	int a = 10;
	float b = 2.0;
	char c = 'c';
	fun7(a, b, c);  // g++：_Z4fun7ifc
	fun7(a);    // g++: _Z4fun7i
	fun7(c, c, c);  // g++: _Z4fun7ccc
	fun7(c, b, a);  // g++: _Z4fun7cfi
}

int addInt(int a, int b)
{
	return a + b;
}

char addChar(char a, char b)
{
	return a + b;
}

float addFloat(float a, float b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

char add(char a, char b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

void test4()
{
	int a = 1;
	float b = 2;
	char c = 'c';
	cout << add(a, a) << endl;
	cout << add(b, b) << endl;
	cout << add(c, c) << endl;
}

//extern "C" int sub(int a, int b);
int sub(int a, int b);

int main()
{
	//testInput();
	//fun4();  //标配
	//fun4(5); //选配
	//fun5();

	//fun5(10);
	//fun5(10, 20);
	//fun5(10, 20, 30);

	////fun6(0);
	//fun6(10, 20);
	//fun6(10, 20, 30);
	//test3();
	//test4();
	sub(10, 2);
	return 0;
}