#include <stdio.h>
#include "binaryTree.h"
#include "stack.h"
#include "queue.h"

Node* creatTree(DataType* array, int* pi)
{
	if (array[*pi] != '#')
	{
		Node* root = (Node*)malloc(sizeof(Node));
		root->_data = array[*pi];
		++(*pi);
		root->_left = creatTree(array, pi);
		++(*pi);
		root->_right = creatTree(array, pi);
		return root;
	}
	else
		return NULL;
}

void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

void destoryTree(Node** root)
{
	//����ɿռ��ͷţ�ָ���ֵҲ�Ѿ����
	if (*root)
	{
		//�ͷŽڵ�
		Node* cur = *root;
		destoryTree(&cur->_left);
		destoryTree(&cur->_right);
		free(cur);
		*root = NULL;
	}
}

void destoryTree2(Node* root)
{
	//������ɿռ��ͷţ�����ָ���ֵû�����
	if (root)
	{
		//�ͷŽڵ�
		Node* cur = root;
		destoryTree2(cur->_left);
		destoryTree2(cur->_right);
		free(cur);
		root = NULL;
	}
}

int getLeafSize(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//Ҷ�ӵĸ�����Ϊ����������Ҷ�Ӻ�
	return getLeafSize(root->_left) + getLeafSize(root->_right);
}

//������������ͳ��Ҷ��
void getLeafSize2(Node* root, int* num)
{
	if (root)
	{
		if (root->_left == NULL && root->_right == NULL)
		{
			++(*num);
			return;
		}
		getLeafSize2(root->_left, num);
		getLeafSize2(root->_right, num);
	}
}

int getKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	//��һ�㣺�ڵ����Ϊ1
	if (k == 1)
		return 1;
	return getKSize(root->_left, k - 1) 
		+ getKSize(root->_right, k - 1);

}

Node* find(Node* root, DataType data)
{
	Node* ret;
	//����һ�ֱ�����ÿ�κ͵�ǰ�������Ľڵ�Ƚ�
	if (root == NULL)
		return NULL;
	if (root->_data == data)
		return root;
	//������������
	ret = find(root->_left, data);
	if (ret != NULL)
		return ret;
	ret = find(root->_right, data);
	if (ret != NULL)
		return ret;
	return NULL;
}

void preOrderNoR(Node* root)
{
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1)
	{
		//�ӵ�ǰ����λ�ã�һֱ����������ߵ�·��
		while (cur)
		{
			printf("%c ", cur->_data);
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);

		//����������
		cur = top->_right;
	}
	printf("\n");
}

void preOrder(Node* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}

void inOrderNoR(Node* root)
{
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1)
	{
		//�ӵ�ǰ����λ�ã�һֱ����������ߵ�·��
		while (cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);

		//���ʵ�ǰ�ڵ�
		printf("%c ", top->_data);

		//����������
		cur = top->_right;
	}
	printf("\n");
}


void postOrderNoR(Node* root)
{
	Node* cur, *top, *prev;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	prev = NULL;
	while (cur || stackEmpty(&st) != 1)
	{
		////�ӵ�ǰ����λ�ã�һֱ����������ߵ�·��
		while (cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//�жϵ�ǰ�ڵ��Ƿ���Է���
		top = stackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			//���û��������,�����������Ѿ��������: top->_right == prev
			//���Է��ʵ�ǰ�ڵ�
			printf("%c ", top->_data);
			stackPop(&st);
			prev = top;
		}
		else  //��ǰջ��Ԫ�ػ���������û�з��ʣ��ȷ���������
			cur = top->_right;
	}
	printf("\n");
}

void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);	
	}
}


void leverOrder(Node* root)
{
	//�ö��еĳ���˳��ģ����������˳��
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1)
	{
		//��ȡ��ͷԪ��
		Node* cur = queueFront(&q);
		queuePop(&q);
		printf("%c ", cur->_data);
		//�������
		if (cur->_left)
			queuePush(&q, cur->_left);
		if (cur->_right)
			queuePush(&q, cur->_right);
	}
	printf("\n");


}

int isCompleteTree(Node* root)
{
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1)
	{
		Node* cur = queueFront(&q);
		queuePop(&q);
		//�����ǰ��ͷԪ��Ϊ�սڵ㣬��Ҫ�ж�ʣ��ڵ��Ƿ�Ϊ�սڵ�
		if (cur == NULL)
			break;
		//���Һ�����ӣ�����Ҫ�ж�
		queuePush(&q, cur->_left);
		queuePush(&q, cur->_right);
	}

	//��Ҫ�ж�ʣ��ڵ��Ƿ�Ϊ�սڵ�
	while (queueEmpty(&q) != 1)
	{
		Node* cur = queueFront(&q);
		queuePop(&q);
		// �����ǰ�ڵ�Ϊ�ǿսڵ㣬˵���ڿսڵ�֮������˷ǿսڵ�--> �ڵ�����в�����
		if (cur)
			return 0;
	}
	return 1;
}

