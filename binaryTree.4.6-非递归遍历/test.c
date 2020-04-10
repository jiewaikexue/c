#include <stdio.h>
#include "binaryTree.h"

void test()
{
	char str[] = { "ABC##DE#G##F###" };
	int i = 0;
	Node* ret;
	int num;
	Node* root = creatTree(str, &i);
	num = getKSize(root, 5);
	num = getKSize(root, 1);
	num = getKSize(root, 3);

	ret = find(root, 'F');
	ret = find(root, 'H');
	ret = find(root, 'a');
}

void test2()
{
	char str[] = { "ABC##DE#G##F###" };
	//Node* ret;
	int i = 0;
	Node* root = creatTree(str, &i);
	/*preOrderNoR(root);
	preOrder(root);*/

	/*inOrderNoR(root);
	inOrder(root);
	printf("\n");*/

	postOrderNoR(root);
	postOrder(root);
	printf("\n");
}
int main()
{
	//test();
	test2();
	return 0;
}