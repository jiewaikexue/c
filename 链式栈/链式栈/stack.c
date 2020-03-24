#include "sta.h"

void main()
{
	Stack stack = { NULL, NULL, 0 };
	stackPush(&stack, 1);	stackPush(&stack, 3);
	stackPush(&stack, 2);	stackPush(&stack, 3);
	stackPush(&stack, 3);	stackPush(&stack, 3);
	stackPush(&stack, 3);	stackPush(&stack, 3);
	stackPush(&stack, 3);	stackPush(&stack, 3);
	stackPush(&stack, 3);	stackPush(&stack, 3);
	stackPush(&stack, 3); stackPop(&stack);
	stackPush(&stack, 3); stackPop(&stack);
	stackPush(&stack, 3); stackPop(&stack);
	stackPop(&stack);
	stackPop(&stack);
	stackPop(&stack); 
	for (Node *x = stack.Top; x != NULL; x = x->next)
	{
		printf("%2d\n¡ı\n", x->num);
	}
	system("pause");
}