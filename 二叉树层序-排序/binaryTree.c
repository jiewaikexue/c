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
	//即完成空间释放，指针的值也已经清空
	if (*root)
	{
		//释放节点
		Node* cur = *root;
		destoryTree(&cur->_left);
		destoryTree(&cur->_right);
		free(cur);
		*root = NULL;
	}
}

void destoryTree2(Node* root)
{
	//可以完成空间释放，但是指针的值没有清空
	if (root)
	{
		//释放节点
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
	//叶子的个数即为左右子树的叶子和
	return getLeafSize(root->_left) + getLeafSize(root->_right);
}

//遍历二叉树，统计叶子
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
	//第一层：节点个数为1
	if (k == 1)
		return 1;
	return getKSize(root->_left, k - 1) 
		+ getKSize(root->_right, k - 1);

}

Node* find(Node* root, DataType data)
{
	Node* ret;
	//任意一种遍历，每次和当前遍历到的节点比较
	if (root == NULL)
		return NULL;
	if (root->_data == data)
		return root;
	//查找左右子树
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
		//从当前根的位置，一直遍历完最左边的路径
		while (cur)
		{
			printf("%c ", cur->_data);
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);

		//访问右子树
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
		//从当前根的位置，一直遍历完最左边的路径
		while (cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);

		//访问当前节点
		printf("%c ", top->_data);

		//访问右子树
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
		////从当前根的位置，一直遍历完最左边的路径
		while (cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//判断当前节点是否可以访问
		top = stackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			//如果没有右子树,或者右子树已经访问完成: top->_right == prev
			//可以访问当前节点
			printf("%c ", top->_data);
			stackPop(&st);
			prev = top;
		}
		else  //当前栈顶元素还有右子树没有访问，先访问右子树
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
	//用队列的出队顺序模拟层序遍历的顺序
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1)
	{
		//获取队头元素
		Node* cur = queueFront(&q);
		queuePop(&q);
		printf("%c ", cur->_data);
		//孩子入队
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
		//如果当前队头元素为空节点，需要判断剩余节点是否都为空节点
		if (cur == NULL)
			break;
		//左右孩子入队，不需要判断
		queuePush(&q, cur->_left);
		queuePush(&q, cur->_right);
	}

	//需要判断剩余节点是否都为空节点
	while (queueEmpty(&q) != 1)
	{
		Node* cur = queueFront(&q);
		queuePop(&q);
		// 如果当前节点为非空节点，说明在空节点之间包含了非空节点--> 节点的排列不连续
		if (cur)
			return 0;
	}
	return 1;
}

