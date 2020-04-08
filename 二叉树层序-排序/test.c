#include <stdio.h>
#include "binaryTree.h"

void test()
{
	//char str[] = { "ABC##DE#G##F###" };
	char str[] = { "ABDG##H###CE#I##F##" };
	
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

void test3()
{
	//char str[] = { "ABC##DE#G##F###" };
	char str[] = { "ABDG##H###CE#I##F##" };

	int i = 0;
	Node* ret;
	int num;
	Node* root = creatTree(str, &i);
	leverOrder(root);

}

void test4()
{
	char str[] = { "ABDG##H###CE#I##F##" };
	char str2[] = { "ABDH##I##E##CF##G##" };
	int i = 0;
	Node* root1 = creatTree(str, &i);
	i = 0;
	Node* root2 = creatTree(str2, &i);
	printf("%s\t:%d\n", str, isCompleteTree(root1));
	printf("%s\t:%d\n", str2, isCompleteTree(root2));

}
/*
int main()
{
	//test();
	//test2();
	//test3();
	test4();
	return 0;
}
*/