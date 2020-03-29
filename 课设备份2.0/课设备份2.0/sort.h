#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#pragma warning(disable:4996)




typedef struct NODE//定义节点类型
{
	int number;//该节点的数据域，存放生成的随机数
	int subscript;//统计这是第几个节点，类似于数组下表的作用。
	struct NODE *next;//该节点的指针域，指向下一个节点
}node;//node为 节点 type

//排序实现

int QUICK_SORT(node * quick_head, node *quick_tail);//快排函数，传入该链表的头指针和尾指针
//此函数的数据结构为单向链表
//故不能像往常快拍一样，头尾相对，依次比较，单链表没有前驱指针。
//采用改变链表内部data域的值来解决排序问题。



node* Divide_SORT(node * quick_head, node *quick_tail);//划分
//快排核心思想实现
//通过和枢值比较来讲一个数据链分成两部分
//在递归就可以不断地进行排序



//冒泡

int BUBBLE_SORT(node *p,node *q);


//选择排序
void SELECTION_sort(node* p, node *q);

//插入排序
//void INSERTION_sort(node *x, node *y);


//
//node* MERGE_DIVIDE(node*p, node *q);
//node* MERGE_sort(node *p, node *p_tail, node *q, node *q_tail);






//测试功能
void PRIN_linklist(node *p);



struct LINKLIST  //该节点为链表信息的一个节点可以充当监视哨
{
	node *head; // 头指针  指向链表的头节点
	node *tail;//尾指针  指向链表的最后一个节点
	node *mid;
	////////////快速排序是可能会为了减小遍历。这里可能会生成一个中间指针。
	//用于指向该链表的中间节点，在快拍时，直接找到中间的节点就可以以
	//盖中间节点的位置需要在随机数赋值是利用 MAX_SIZE/2取得
};



void random_made(node *p, int MAX_SIZE, node **q, node **mid);//随机数生成函数
//随机数函数的参数为，随机数个数，链表头结点



void ClearList(node *p);//清空链表




int JUDGE(node *p);//判断链表是否为空。如果为空链表，则直接退出，不做排序



void DistoryList(node *p);//c程序运行完时，销毁整个链表



void menu();//主选择菜单











///#####################################################
//文件操作

//函数原型
//FILE *fopen(const char *filename, const char *mode);

//参数
//filename-- 这是 C 字符串，包含了要打开的文件名称。
//mode-- 这是 C 字符串，包含了文件访问模式。



void Txt_Write(FILE *TEXT, node *linklist_first,int key);

#endif