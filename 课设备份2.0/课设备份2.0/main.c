#include"sort.h"

void main()
{

	srand((unsigned int)time(NULL));//随机数种子

	int open_1 = 1;//下一个while的开关
	int MAX_SIZE = 0;//MAX_SIZE 代表需要生成随机数个数	
	while (open_1)
	{
		printf("请输入生成随机数的个数（至少20000个）\n");
		scanf("%d", &MAX_SIZE);
		if (MAX_SIZE < 20000)
		{
			printf("不符要求\n");//不符要求
			printf("请重新输入\n\n");//请重新输入
			system("cls");
			open_1 = 1;
		}
		else
		{
			open_1 = 0;
		}
	}
	struct LINKLIST linklist;//定义一个结构体，该结构体用于存放头指针，尾指针等信息。
	linklist.head = (node *)malloc(sizeof(node));//申请头结点，是linklist的head指针指向头结点
	//注意！！！！！！！！！！！！
	//头结点已经申请成功
	//后续节点申请MAX_SIZE个！！！
	//


	/**/
	/**/
	//（此次课设在此出现free（）函数越界问题
	//
	/**/
	/**/
	if (!linklist.head)
	{
		printf("动态内存申请失败，程序异常退出\n");//避免动态内存申请是申请失败的情况
		exit(-1);
	}
	(linklist.head)->number = MAX_SIZE;//头结点数据域为链表长度
	(linklist.head)->subscript = 0;//头结点下标规定为0
	(linklist.head)->next = NULL;//头结点指针域为空
	linklist.mid = NULL;//初始化为空，防止指针乱指
	/*linklist.head即为头结点的坐标
	头结点的数据域number 存放生成的随机数的所有个数
	在以后万一有需要统计链表元素个数的时候，直接访问即可。省去了遍历的过程
	*/
	linklist.tail = linklist.head;//空链表头尾指针指向对齐，且
	/*头结点生成成功，但是光有一个头结点。链表还是个空表
	所以要让头指针和尾指针都指向头结点
	*/

	//
	//printf("%p", linklist.mid);
	//

	random_made(linklist.head, MAX_SIZE, &linklist.tail, &linklist.mid);//随机数生成函数
	PRIN_linklist(linklist.head);

	/*
	linklist.head是头结点的地址，生成的随机数都是要在头结点之后的。
	MAX_SIZE是随机数的个数。
	linklist.tail是为节点指针。用于在最后指向为节点
	同时在一开始通过比较linklist.head linklist.tail是否相等来判断这个这个链表中是不是已经有其他的值
	如果有 则清空链表 如果没有 则进行随机数的生成 并写进链表
	*/

	/*
	printf("\n%d,%d,%p\n", (linklist.tail)->number,(linklist.tail)->subscript,linklist.tail->next);
	*/
	menu();
	int KEY = 0;

	int open_2 = 0;
	if (!JUDGE(linklist.head))
	{
		printf("数据链表为空，无法进行排序\n");
		exit(-1);
	}
	else
	{
		while (!open_2)
		{
			FILE *TEST = NULL;//文件指针初始化为空，防止野指针
			
			printf("\n请输入你选择的功能号\n");
			scanf("%d", &KEY);
			switch (KEY)
			{
			case 1:
				SELECTION_sort(linklist.head, linklist.tail);//选择排序实现
				Txt_Write(TEST, linklist.head->next,KEY);//文件写入
				open_2 = 1; 
				//PRIN_linklist(linklist.head);//老式printf 测试功能控制台显示结果
				break;//open_为出口开关条件控制变量

			//case 2:
			//	//INSERTION_sort(linklist.head, linklist.tail);

			//	PRIN_linklist(linklist.head);

			//	open_2 = 1;
			//	break;
			case 2:
				
				BUBBLE_SORT(linklist.head, linklist.tail); 
				Txt_Write(TEST, linklist.head->next, KEY);//文件写入
				//PRIN_linklist(linklist.head); 
				open_2 = 1; 
				break;
			case 3:
				
				QUICK_SORT(linklist.head, linklist.tail);
				Txt_Write(TEST, linklist.head->next, KEY);//文件写入
				//PRIN_linklist(linklist.head);
				open_2 = 1;
			break;

			/*case 5:open_2 = 1; break;
			case 6:MERGE_DIVIDE(linklist.head->next,linklist.tail);
				PRIN_linklist(linklist.head); 
				open_2 = 1;
				break;*/
			default:open_2 = 0; break;
			}

		}
	}

	DistoryList(linklist.head);
	//free(&linklist);//不能这样！因为linklist 是一个临时变量，在栈上
	
	system("pause");
}