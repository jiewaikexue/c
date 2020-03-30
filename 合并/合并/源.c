
#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#pragma warning(disable:4996)




typedef struct NODE//定义节点类型
{
	int number;//该节点的数据域，存放生成的随机数
	int subscript;//统计这是第几个节点，类似于数组下表的作用。
	struct NODE *next;//该节点的指针域，指向下一个节点
}node;//node为 节点 type

//排序实现

int QUICK_SORT(node * quick_head, node *quick_tail);//快排函数，传入该链表的头指针和尾指针
//此函数的数据结构为单向链表
//故不能像往常快拍一样，头尾相对，依次比较，单链表没有前驱指针。
//采用改变链表内部data域的值来解决排序问题。



node* Divide_SORT(node * quick_head, node *quick_tail);//划分
//快排核心思想实现
//通过和枢值比较来讲一个数据链分成两部分
//在递归就可以不断地进行排序



//冒泡

int BUBBLE_SORT(node *p, node *q);


//选择排序
void SELECTION_sort(node* p, node *q);

//插入排序
//void INSERTION_sort(node *x, node *y);


//
//node* MERGE_DIVIDE(node*p, node *q);
//node* MERGE_sort(node *p, node *p_tail, node *q, node *q_tail);






//测试功能
void PRIN_linklist(node *p);



struct LINKLIST  //该节点为链表信息的一个节点可以充当监视哨
{
	node *head; // 头指针  指向链表的头节点
	node *tail;//尾指针  指向链表的最后一个节点
	node *mid;
	////////////快速排序是可能会为了减小遍历。这里可能会生成一个中间指针。
	//用于指向该链表的中间节点，在快拍时，直接找到中间的节点就可以以
	//盖中间节点的位置需要在随机数赋值是利用 MAX_SIZE/2取得
};



void random_made(node *p, int MAX_SIZE, node **q, node **mid);//随机数生成函数
//随机数函数的参数为，随机数个数，链表头结点



void ClearList(node *p);//清空链表




int JUDGE(node *p);//判断链表是否为空。如果为空链表，则直接退出，不做排序



void DistoryList(node *p);//c程序运行完时，销毁整个链表



void menu();//主选择菜单











///#####################################################
//文件操作

//函数原型
//FILE *fopen(const char *filename, const char *mode);

//参数
//filename-- 这是 C 字符串，包含了要打开的文件名称。
//mode-- 这是 C 字符串，包含了文件访问模式。



void Txt_Write(FILE *TEXT, node *linklist_first, int key);



//主选择菜单
void menu()
{
	printf("\t\t\t#########################################\n");
	printf("\t\t\t#######      排序方法选择菜单    ########\n");
	printf("\t\t\t#########################################\n");
	printf("\t\t\t#######        1.选择排序        ########\n");

	printf("\t\t\t#######        2.冒泡排序        ########\n");
	printf("\t\t\t#######        3.快速排序        ########\n");

	printf("\t\t\t#########################################\n");
}

//销毁链表
void DistoryList(node *p)//这个是指向头结点的指针
{
	node *Disp = NULL;

	while (p->next)
	{
		Disp = p->next;
		free(p);

		p = Disp;
	}

}


//判断链表是否为空
int JUDGE(node *p)
{
	if (!p->next)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//清空链表
void ClearList(node *p)
{
	node *clear_p;//记录当前节点的一个指针
	while (p)//直到释放到最后一个节点，为节点的指针域为空，不满足循环条件，循环退出
	{
		clear_p = p;//保存当前节点
		p = p->next;//p指向下一个节点
		free(clear_p);//释放当前节点
	}
}


//随机数链表生成
void random_made(node *p, int MAX_SIZE, node **q, node **mid)//p指向头结点，q是尾指针。mid是中间指针。
{
	if (p != *q)
	{
		ClearList(p);
		/*在一开始通过比较linklist.head linklist.tail发现不相等
		所以清空链表 */
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//执行第一次循环时
		(node*)p->next = (node *)malloc(sizeof(node));//p->next指向第一个节点
		if (!p->next)
		{
			printf("第%d次内存分配失败，程序异常结束\n");
			exit(-1);
		}
		p = p->next;//p指向第一个节点（当前节点）
		p->number = rand() % 20001;//对第一个节点的数据域进行赋值
		p->subscript = i + 1;
		p->next = NULL;//对第一个节点的指针域置空。因为此时这个节点是该链表的尾部节点
		*q = p;//尾部指针指向当前节点。
		/*
		测试开关阀
		printf("第%5d个节点的数是%5d\n",i+1, p->subscript);
		*/

		if ((MAX_SIZE / 2) == i&&*mid == NULL)
		{
			*mid = p;
			//printf("%d,%d\n", (*mid)->number, (*mid)->subscript);
		}
	}
}

//测试功能
void PRIN_linklist(node *p)
{
	node *PRIN_beging = p->next;
	if (!PRIN_beging)
	{
		printf("头指针为空，这可能是个空链表。程序异常\n");
		exit(-1);
	}

	else
	{
		while (PRIN_beging)
		{
			printf("第个节%5d点，节点内数据为%5d\n", PRIN_beging->subscript, PRIN_beging->number);
			PRIN_beging = PRIN_beging->next;
		}
	}
}

//文本写入函数实现
void Txt_Write(FILE *TEXT, node *linklist_first, int key)
{
	node *p = linklist_first;
	TEXT = fopen("H:\\TEXT.txt", "w");//打开对应文件，只允许写入。函数返回值返回给TEXT文件指针

	while (p != NULL)
	{
		fprintf(TEXT, "第 %3d个数:%5d\n", p->subscript, p->number);//循环输入
		p = p->next;
	}
	switch (key)
	{
	case 1:fprintf(TEXT, "       本次排序为  选择  排序    "); break;
	case 2:fprintf(TEXT, "       本次排序为  冒泡  排序    "); break;
	case 3:fprintf(TEXT, "       本次排序为  快速  排序    "); break;

	}
	fclose(TEXT);
}









//以下为排序函数

//四号 快排


//快排核心划分思想实现
node * Divide_SORT(node * quick_head, node *quick_tail)//分别对应linklist_head、linklist_tail
//暨传入的是链表的头指针和尾指针
{


	node * p = quick_head->next;//因为头指针指向头结点，头结点并不是第一个有效的节点，
	//所以需要读取头结点中的指针域来寻找到第一个有效节点
	node *KEY_NODE = p;
	if (p != quick_tail)
	{
		node *q = p->next;//因为此时p已经指向了第一个有效节点，所以我们需要初始化一个指针使其指向第二个节点
		int key = 0;
		key = p->number;//每次取第一个节点的数据作为枢轴
		if (quick_head != quick_tail)
		{
			while (q)//q指针已经遍历完了//q的值等于tail尾指针时说明结束了
			{
				if (q->number < key)
				{

					int x = 0;
					p = p->next;
					x = p->number;
					p->number = q->number;
					q->number = x;


				}

				if (quick_tail == q)
				{
					break;
				}
				q = q->next;
			}
		}


		KEY_NODE->number = p->number;
		p->number = key;

	}
	return p;
	//一趟比完后在指针p和q之间的都是比key值大的数，
	//当q指针跑到最后一个节点时，while函数结束，此时p和q之间都是比key值大的书字
	//p之前都是比key值晓得数
	//此时，只需把p的值和key值进行交换，就可以造成一个在p之前全部是比p值小的，在p之后全都是比p大的一个链表
	//此时完成一次划分；


	//返回划分后的枢值坐标
	//枢值坐标可以当做前1/2数据的位节点坐标和后1/2数据的头结点坐标
	//只需要不断地递归划分，最后就可以实现整体数据的有序性
}

//快排本身递归解决
int QUICK_SORT(node * quick_head, node *quick_tail)
{



	if ((quick_head->next != quick_tail) && (quick_head != quick_tail))//一定要避免头尾指针同指向的问题
	{

		//出口条件为只剩一个节点时—》头指针和尾指针相等
		//或者头指针和尾指针其中有一个指向为NULL
		//否则一直递归，通过递归来缩小问题规模实现二分
		//确定枢值之前都比枢值小，之后都比该值大

		node * divide = NULL;
		divide = Divide_SORT(quick_head, quick_tail);//divide用来接收此函数的返回值

		//该函数的返回值返回的是枢值得下标
		node *QUICK_HEAD_p = quick_head;
		node *QUICK_TAIL_p = quick_tail;
		QUICK_SORT(QUICK_HEAD_p, divide);//对前1/2数据进行递归排序
		//钱二分之一的数据的一开始始终是头结点开始
		QUICK_SORT(divide, quick_tail);
	}

}
//3HAO冒泡排序 //最优

int BUBBLE_SORT(node *bubble_head, node *bubble_tail)
{
	node*p = bubble_head->next;//p指针从第一个节点开始
	node *q = p->next;
	node *end = bubble_tail;//这个指针用来储存指向     第元素个数-趟数   个节点  ，主要是用来做冒泡算法的优化
	node *flage = end;//标记变量，与end结合使用

	for (; p->next != NULL; p = p->next)//p->next==NULL说明已经全部遍历完了
	{
		int open_3 = 0;
		end = flage;
		q = p->next;//每次和q所指向的下一个节点的值比较，，不用比较自身
		int judge = 1;//如果某一趟中一次交换也没有做
		//则说明这组数句已经有序
		//所以可以提前退出
		//judge函数用于判断这个
		for (; q != end->next; q = q->next)//关键判断条件
			//当二者的指针域指向相同时，说明两者相等
			//然而当q指向end时还是会做一次循环的

		{

			if (!open_3)
			{
				if (p->next == end)//每一个q都会走一遍(q->next)->next)，所以在第一趟的倒数第二个节点时(q->next)已经指向为空，此时(q->next)->next)已经成为野指针。要避免这种情况
				{
					flage = q;//储存最终节点前的一个节点
					//记录本次循环出口条件end节点的地址，并重新付给end
					//以此来实现每趟少比较一个
					open_3 = 1;
				}

			}
			if (p->number > q->number)
			{
				int x = 0;
				x = p->number;
				p->number = q->number;
				q->number = x;
				judge = 0;
			}

		}
		if (judge&&p != bubble_head->next)
		{
			return 0;
		}

	}
	return 0;
}

//1号，选择排序

void SELECTION_sort(node* p, node *q)
{
	node *sele_head = p;
	node *sele_tail = q;
	node *sele_p = sele_head->next;
	node *sele_q = NULL;





	//while 实现
	for (; sele_p->next != NULL; sele_p = sele_p->next)//sele_p指针最多只能遍历到尾节点的前一个节点，因为后面有一个sele_q = sele_p->next
	{
		int mine = 0;
		mine = sele_p->number;
		node *mine_p = NULL;//用于记录最小值节点的指针，方便在一次大比较之后进行两数交换；


		for (sele_q = sele_p->next; sele_q != NULL; sele_q = sele_q->next)//请务必确保sele_q指针能指向尾节点但是不能越界，尾节点中石油数据的一定要读取
		{

			if (mine > sele_q->number)
			{
				mine = sele_q->number;
				mine_p = sele_q;
			}
		}
		if (mine_p)
		{
			mine_p->number = sele_p->number;//用来比较得数以定要和最小的数进行交换，不然结果会出现重复
			sele_p->number = mine;
		}


	}
}

//归并
//划分
//node * MERGE_DIVIDE(node*p, node *q)//在传参的时候请确保p务必是第一个节点，不能像前面传参那样传头结点
////因为后面要递归
//{
//	node *merge_p = p;
//	node *merge_q = q;
//	if (merge_p == merge_q )
//	{
//		return merge_p;
//	}
//	
//	else
//	{
//		node *fast = p;//快指针
//		node *low = p;//慢指针
//
//
//		//fast = p->next->next;
//
//		//快指针每次走两步
//
//		//low = p->next;
//
//		//慢指针每次走一步  这样当快指针走到尾指针判空时慢指针就刚好走到中间
//
//
//		node *first = p;//这个指针用来记录每一段的起始节点   
//		node *tail = q;//这个指针用于记录每一段的结束节点 方便下面的递归调用
//
//		while (fast != tail&&fast->next != tail)
//		{
//			fast = fast->next->next;
//			low = low->next;
//		}
//		
//		node * mid = low;
//
//		return  MERGE_sort(MERGE_DIVIDE(first, mid), mid, MERGE_DIVIDE(mid->next, tail), tail);
//	}
//}


//合并排序


//node * merge_sort(node *p,node *p_tail, node *q,node *q_tail)
//{
//	
//	node *a= p;
//	node *b = q;
//	node *temp = b->next;
//	
//	while (b!= q_tail&&temp!=q_tail)
//	{
//		temp = b->next;
//		while (a != p_tail->next) //逐个比较链表a和链表b的每个元素
//		{
//
//			if (a->number < b->number)
//			{
//				// 如果a比b小, 那么当前结点的后继就是a
//				a = a->next;
//
//			}
//			else
//			{
//				int key = 0;
//				key = b->number;
//				b->number = a->number;
//				a->number = key;
//
//			}
//			if (b->number < temp->number)
//			{
//				b = b->next;
//			}
//			else
//			{
//				int key2 = 0;
//				key2 = b->number;
//				b->number = temp->number;
//				temp->number = key2;
//			}
//		}
//		
//		// 如果原表a已经排完,那么新表后面就放b的剩余元素
//		// 否则仍然以a为标准和b进行比较
//		
//	}
//
//
//	return a;
//}


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
				Txt_Write(TEST, linklist.head->next, KEY);//文件写入
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