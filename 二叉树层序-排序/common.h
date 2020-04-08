#pragma  once
typedef char DataType;
typedef struct Node
{
	struct Node* _left;
	struct Node* _right;
	DataType _data;
}Node;