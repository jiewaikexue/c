#include"queeu.h"
void main()
{
	Queue Queue = { 0, NULL, 4 ,3};
	queueInit(&Queue, 4);
	
	
	queuePop(&Queue);

	system("pause");

}