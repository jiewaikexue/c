#pragma once
#include <stdlib.h>
#include "common.h"



typedef struct BinaryTree
{
	Node* _root;
}BinaryTree;

Node* creatTree(DataType* array, int* pi);
void destoryTree(Node** root);

int getLeafSize(Node* root);

int getKSize(Node* root, int k);

Node* find(Node* root, DataType data);

//�����ķǵݹ�: �ص�
//ǰ�к��򣬲���ǵݹ�
void preOrderNoR(Node* root);
void preOrder(Node* root);
void inOrderNoR(Node* root);
void inOrder(Node* root);
void postOrderNoR(Node* root);
void postOrder(Node* root);
void leverOrder(Node* root);
int isCompleteTree(Node* root);
