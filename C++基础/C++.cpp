#include "header1.h"
#include "header2.h"

#include <stdio.h>
#include <stdlib.h>


//ȫ����
//int  global = 10;

int fun()
{
	//�ֲ���
	int a = 1;
	return a;
}

//�ļ���
static void fun2()
{

}

void testNamespace()
{
	//��Աʹ�÷�ʽ��
	//1.�����ռ� + ::(�������޶�����+ ��Ա(���� + ������
	//ȫ���� û������
	::global = 10;
	global = 1;
	header1::global = 200;
	header1::var2 = 10;
	header1::internal::var = 1;
}

//��Աʹ�÷�ʽ��
// 2.  using + ����������ı���
using header1::internal::var;

//���Ը������ռ�������� ���Լ������ռ����д
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

//��Ա��ʹ�÷�ʽ:
// 3 using + namespace + �����ռ�����
// �൱�ڰ������ռ��µ����г�Ա��¶��ȫ������
// ������ʹ�ô��ַ�ʽ
//using namespace header1;
/*
void testNamespace3()
{
	var2 = 1;
	fun2();  //���������ͻ
	fun3();
	global = 1;  //��ȫ�����е�global���������ͻ
}
*/
#include <stdio.h>
//����C++ coutʹ�ã� #include <iostream.h>
//vc6.0 ֧�� #include <iostream.h>
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

	cin >> a >> b;  //  �������� +  ��������� + ����
	cout << a << " " << b << "\n";

}
//ȱʡ������ ���庯��/��������ʱ������һ��Ĭ��ֵ�� �������߶��壬ֻ��ѡ��һ��Ĭ��ֵ
//��������
void fun4(int a = 100);
//����
void fun4(int a)
{
	cout << a << endl;
}

//ȫȱʡ�� ���еĲ�������Ĭ��ֵ
void fun5(int a = 1, int b = 2, int c = 3)
{
	cout << a << b << c << std::endl;
}

//��ȱʡ�� ���ҵ����˳�������Ĭ��ֵ�����ֲ���û������Ĭ��ֵ
void fun6(int a, int b = 1, int c = 2)
{
	cout << a << b << c << endl;
}
//��ȱʡ�� ���ҵ����˳�������Ĭ��ֵ, �м䲻���м�������ֲ���û������Ĭ��ֵ
/*
void fun7(int a, int b = 1, int c, int d = 2)
{
	cout << a << b << c << endl;  // end line  endl   endl <--��Ч--> "\n"
}
*/
//�������أ�ǰ�᣺ ��ͬһ����������    ---->  ͬһ��ϵ�еĲ�ͬ�汾���ֻ� 
//        ��������ͬ�� ������Ϣ��ͬ�Ķ���������ɺ�������
//        ������Ϣ: �����������������ͣ� ������˳��
void fun6(int a)
{
	cout << a << endl;
}

void fun7(int a, float b, char c)
{
	cout << "fun7(int a, float b, char c)" << endl;
}
//����������ͬ
void fun7(int a)
{
	cout << "fun7(int a)" << endl;
}
//�������Ͳ�ͬ
void fun7(char a, char b, char c)
{
	cout << "fun7(char a, char b, char c)" << endl;
}

//����˳��ͬ
void fun7(char c, float b, int a)
{
	cout << "fun7(char c, float b, int a)" << endl;
}

void test3()
{
	int a = 10;
	float b = 2.0;
	char c = 'c';
	fun7(a, b, c);  // g++��_Z4fun7ifc
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
	//fun4();  //����
	//fun4(5); //ѡ��
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