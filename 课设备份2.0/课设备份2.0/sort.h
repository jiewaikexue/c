#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#pragma warning(disable:4996)




typedef struct NODE//����ڵ�����
{
	int number;//�ýڵ�������򣬴�����ɵ������
	int subscript;//ͳ�����ǵڼ����ڵ㣬�����������±�����á�
	struct NODE *next;//�ýڵ��ָ����ָ����һ���ڵ�
}node;//nodeΪ �ڵ� type

//����ʵ��

int QUICK_SORT(node * quick_head, node *quick_tail);//���ź���������������ͷָ���βָ��
//�˺��������ݽṹΪ��������
//�ʲ�������������һ����ͷβ��ԣ����αȽϣ�������û��ǰ��ָ�롣
//���øı������ڲ�data���ֵ������������⡣



node* Divide_SORT(node * quick_head, node *quick_tail);//����
//���ź���˼��ʵ��
//ͨ������ֵ�Ƚ�����һ���������ֳ�������
//�ڵݹ�Ϳ��Բ��ϵؽ�������



//ð��

int BUBBLE_SORT(node *p,node *q);


//ѡ������
void SELECTION_sort(node* p, node *q);

//��������
//void INSERTION_sort(node *x, node *y);


//
//node* MERGE_DIVIDE(node*p, node *q);
//node* MERGE_sort(node *p, node *p_tail, node *q, node *q_tail);






//���Թ���
void PRIN_linklist(node *p);



struct LINKLIST  //�ýڵ�Ϊ������Ϣ��һ���ڵ���Գ䵱������
{
	node *head; // ͷָ��  ָ�������ͷ�ڵ�
	node *tail;//βָ��  ָ����������һ���ڵ�
	node *mid;
	////////////���������ǿ��ܻ�Ϊ�˼�С������������ܻ�����һ���м�ָ�롣
	//����ָ���������м�ڵ㣬�ڿ���ʱ��ֱ���ҵ��м�Ľڵ�Ϳ�����
	//���м�ڵ��λ����Ҫ���������ֵ������ MAX_SIZE/2ȡ��
};



void random_made(node *p, int MAX_SIZE, node **q, node **mid);//��������ɺ���
//����������Ĳ���Ϊ�����������������ͷ���



void ClearList(node *p);//�������




int JUDGE(node *p);//�ж������Ƿ�Ϊ�ա����Ϊ��������ֱ���˳�����������



void DistoryList(node *p);//c����������ʱ��������������



void menu();//��ѡ��˵�











///#####################################################
//�ļ�����

//����ԭ��
//FILE *fopen(const char *filename, const char *mode);

//����
//filename-- ���� C �ַ�����������Ҫ�򿪵��ļ����ơ�
//mode-- ���� C �ַ������������ļ�����ģʽ��



void Txt_Write(FILE *TEXT, node *linklist_first,int key);

#endif