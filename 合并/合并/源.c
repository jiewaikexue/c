
#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#pragma warning(disable:4996)




typedef struct NODE//����ڵ�����
{
	int number;//�ýڵ�������򣬴�����ɵ������
	int subscript;//ͳ�����ǵڼ����ڵ㣬�����������±�����á�
	struct NODE *next;//�ýڵ��ָ����ָ����һ���ڵ�
}node;//nodeΪ �ڵ� type

//����ʵ��

int QUICK_SORT(node * quick_head, node *quick_tail);//���ź���������������ͷָ���βָ��
//�˺��������ݽṹΪ��������
//�ʲ�������������һ����ͷβ��ԣ����αȽϣ�������û��ǰ��ָ�롣
//���øı������ڲ�data���ֵ������������⡣



node* Divide_SORT(node * quick_head, node *quick_tail);//����
//���ź���˼��ʵ��
//ͨ������ֵ�Ƚ�����һ���������ֳ�������
//�ڵݹ�Ϳ��Բ��ϵؽ�������



//ð��

int BUBBLE_SORT(node *p, node *q);


//ѡ������
void SELECTION_sort(node* p, node *q);

//��������
//void INSERTION_sort(node *x, node *y);


//
//node* MERGE_DIVIDE(node*p, node *q);
//node* MERGE_sort(node *p, node *p_tail, node *q, node *q_tail);






//���Թ���
void PRIN_linklist(node *p);



struct LINKLIST  //�ýڵ�Ϊ������Ϣ��һ���ڵ���Գ䵱������
{
	node *head; // ͷָ��  ָ�������ͷ�ڵ�
	node *tail;//βָ��  ָ����������һ���ڵ�
	node *mid;
	////////////���������ǿ��ܻ�Ϊ�˼�С������������ܻ�����һ���м�ָ�롣
	//����ָ���������м�ڵ㣬�ڿ���ʱ��ֱ���ҵ��м�Ľڵ�Ϳ�����
	//���м�ڵ��λ����Ҫ���������ֵ������ MAX_SIZE/2ȡ��
};



void random_made(node *p, int MAX_SIZE, node **q, node **mid);//��������ɺ���
//����������Ĳ���Ϊ�����������������ͷ���



void ClearList(node *p);//�������




int JUDGE(node *p);//�ж������Ƿ�Ϊ�ա����Ϊ��������ֱ���˳�����������



void DistoryList(node *p);//c����������ʱ��������������



void menu();//��ѡ��˵�











///#####################################################
//�ļ�����

//����ԭ��
//FILE *fopen(const char *filename, const char *mode);

//����
//filename-- ���� C �ַ�����������Ҫ�򿪵��ļ����ơ�
//mode-- ���� C �ַ������������ļ�����ģʽ��



void Txt_Write(FILE *TEXT, node *linklist_first, int key);



//��ѡ��˵�
void menu()
{
	printf("\t\t\t#########################################\n");
	printf("\t\t\t#######      ���򷽷�ѡ��˵�    ########\n");
	printf("\t\t\t#########################################\n");
	printf("\t\t\t#######        1.ѡ������        ########\n");

	printf("\t\t\t#######        2.ð������        ########\n");
	printf("\t\t\t#######        3.��������        ########\n");

	printf("\t\t\t#########################################\n");
}

//��������
void DistoryList(node *p)//�����ָ��ͷ����ָ��
{
	node *Disp = NULL;

	while (p->next)
	{
		Disp = p->next;
		free(p);

		p = Disp;
	}

}


//�ж������Ƿ�Ϊ��
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
//�������
void ClearList(node *p)
{
	node *clear_p;//��¼��ǰ�ڵ��һ��ָ��
	while (p)//ֱ���ͷŵ����һ���ڵ㣬Ϊ�ڵ��ָ����Ϊ�գ�������ѭ��������ѭ���˳�
	{
		clear_p = p;//���浱ǰ�ڵ�
		p = p->next;//pָ����һ���ڵ�
		free(clear_p);//�ͷŵ�ǰ�ڵ�
	}
}


//�������������
void random_made(node *p, int MAX_SIZE, node **q, node **mid)//pָ��ͷ��㣬q��βָ�롣mid���м�ָ�롣
{
	if (p != *q)
	{
		ClearList(p);
		/*��һ��ʼͨ���Ƚ�linklist.head linklist.tail���ֲ����
		����������� */
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//ִ�е�һ��ѭ��ʱ
		(node*)p->next = (node *)malloc(sizeof(node));//p->nextָ���һ���ڵ�
		if (!p->next)
		{
			printf("��%d���ڴ����ʧ�ܣ������쳣����\n");
			exit(-1);
		}
		p = p->next;//pָ���һ���ڵ㣨��ǰ�ڵ㣩
		p->number = rand() % 20001;//�Ե�һ���ڵ����������и�ֵ
		p->subscript = i + 1;
		p->next = NULL;//�Ե�һ���ڵ��ָ�����ÿա���Ϊ��ʱ����ڵ��Ǹ������β���ڵ�
		*q = p;//β��ָ��ָ��ǰ�ڵ㡣
		/*
		���Կ��ط�
		printf("��%5d���ڵ������%5d\n",i+1, p->subscript);
		*/

		if ((MAX_SIZE / 2) == i&&*mid == NULL)
		{
			*mid = p;
			//printf("%d,%d\n", (*mid)->number, (*mid)->subscript);
		}
	}
}

//���Թ���
void PRIN_linklist(node *p)
{
	node *PRIN_beging = p->next;
	if (!PRIN_beging)
	{
		printf("ͷָ��Ϊ�գ�������Ǹ������������쳣\n");
		exit(-1);
	}

	else
	{
		while (PRIN_beging)
		{
			printf("�ڸ���%5d�㣬�ڵ�������Ϊ%5d\n", PRIN_beging->subscript, PRIN_beging->number);
			PRIN_beging = PRIN_beging->next;
		}
	}
}

//�ı�д�뺯��ʵ��
void Txt_Write(FILE *TEXT, node *linklist_first, int key)
{
	node *p = linklist_first;
	TEXT = fopen("H:\\TEXT.txt", "w");//�򿪶�Ӧ�ļ���ֻ����д�롣��������ֵ���ظ�TEXT�ļ�ָ��

	while (p != NULL)
	{
		fprintf(TEXT, "�� %3d����:%5d\n", p->subscript, p->number);//ѭ������
		p = p->next;
	}
	switch (key)
	{
	case 1:fprintf(TEXT, "       ��������Ϊ  ѡ��  ����    "); break;
	case 2:fprintf(TEXT, "       ��������Ϊ  ð��  ����    "); break;
	case 3:fprintf(TEXT, "       ��������Ϊ  ����  ����    "); break;

	}
	fclose(TEXT);
}









//����Ϊ������

//�ĺ� ����


//���ź��Ļ���˼��ʵ��
node * Divide_SORT(node * quick_head, node *quick_tail)//�ֱ��Ӧlinklist_head��linklist_tail
//�ߴ�����������ͷָ���βָ��
{


	node * p = quick_head->next;//��Ϊͷָ��ָ��ͷ��㣬ͷ��㲢���ǵ�һ����Ч�Ľڵ㣬
	//������Ҫ��ȡͷ����е�ָ������Ѱ�ҵ���һ����Ч�ڵ�
	node *KEY_NODE = p;
	if (p != quick_tail)
	{
		node *q = p->next;//��Ϊ��ʱp�Ѿ�ָ���˵�һ����Ч�ڵ㣬����������Ҫ��ʼ��һ��ָ��ʹ��ָ��ڶ����ڵ�
		int key = 0;
		key = p->number;//ÿ��ȡ��һ���ڵ��������Ϊ����
		if (quick_head != quick_tail)
		{
			while (q)//qָ���Ѿ���������//q��ֵ����tailβָ��ʱ˵��������
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
	//һ�˱������ָ��p��q֮��Ķ��Ǳ�keyֵ�������
	//��qָ���ܵ����һ���ڵ�ʱ��while������������ʱp��q֮�䶼�Ǳ�keyֵ�������
	//p֮ǰ���Ǳ�keyֵ������
	//��ʱ��ֻ���p��ֵ��keyֵ���н������Ϳ������һ����p֮ǰȫ���Ǳ�pֵС�ģ���p֮��ȫ���Ǳ�p���һ������
	//��ʱ���һ�λ��֣�


	//���ػ��ֺ����ֵ����
	//��ֵ������Ե���ǰ1/2���ݵ�λ�ڵ�����ͺ�1/2���ݵ�ͷ�������
	//ֻ��Ҫ���ϵصݹ黮�֣����Ϳ���ʵ���������ݵ�������
}

//���ű���ݹ���
int QUICK_SORT(node * quick_head, node *quick_tail)
{



	if ((quick_head->next != quick_tail) && (quick_head != quick_tail))//һ��Ҫ����ͷβָ��ָͬ�������
	{

		//��������Ϊֻʣһ���ڵ�ʱ����ͷָ���βָ�����
		//����ͷָ���βָ��������һ��ָ��ΪNULL
		//����һֱ�ݹ飬ͨ���ݹ�����С�����ģʵ�ֶ���
		//ȷ����ֵ֮ǰ������ֵС��֮�󶼱ȸ�ֵ��

		node * divide = NULL;
		divide = Divide_SORT(quick_head, quick_tail);//divide�������մ˺����ķ���ֵ

		//�ú����ķ���ֵ���ص�����ֵ���±�
		node *QUICK_HEAD_p = quick_head;
		node *QUICK_TAIL_p = quick_tail;
		QUICK_SORT(QUICK_HEAD_p, divide);//��ǰ1/2���ݽ��еݹ�����
		//Ǯ����֮һ�����ݵ�һ��ʼʼ����ͷ��㿪ʼ
		QUICK_SORT(divide, quick_tail);
	}

}
//3HAOð������ //����

int BUBBLE_SORT(node *bubble_head, node *bubble_tail)
{
	node*p = bubble_head->next;//pָ��ӵ�һ���ڵ㿪ʼ
	node *q = p->next;
	node *end = bubble_tail;//���ָ����������ָ��     ��Ԫ�ظ���-����   ���ڵ�  ����Ҫ��������ð���㷨���Ż�
	node *flage = end;//��Ǳ�������end���ʹ��

	for (; p->next != NULL; p = p->next)//p->next==NULL˵���Ѿ�ȫ����������
	{
		int open_3 = 0;
		end = flage;
		q = p->next;//ÿ�κ�q��ָ�����һ���ڵ��ֵ�Ƚϣ������ñȽ�����
		int judge = 1;//���ĳһ����һ�ν���Ҳû����
		//��˵�����������Ѿ�����
		//���Կ�����ǰ�˳�
		//judge���������ж����
		for (; q != end->next; q = q->next)//�ؼ��ж�����
			//�����ߵ�ָ����ָ����ͬʱ��˵���������
			//Ȼ����qָ��endʱ���ǻ���һ��ѭ����

		{

			if (!open_3)
			{
				if (p->next == end)//ÿһ��q������һ��(q->next)->next)�������ڵ�һ�˵ĵ����ڶ����ڵ�ʱ(q->next)�Ѿ�ָ��Ϊ�գ���ʱ(q->next)->next)�Ѿ���ΪҰָ�롣Ҫ�����������
				{
					flage = q;//�������սڵ�ǰ��һ���ڵ�
					//��¼����ѭ����������end�ڵ�ĵ�ַ�������¸���end
					//�Դ���ʵ��ÿ���ٱȽ�һ��
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

//1�ţ�ѡ������

void SELECTION_sort(node* p, node *q)
{
	node *sele_head = p;
	node *sele_tail = q;
	node *sele_p = sele_head->next;
	node *sele_q = NULL;





	//while ʵ��
	for (; sele_p->next != NULL; sele_p = sele_p->next)//sele_pָ�����ֻ�ܱ�����β�ڵ��ǰһ���ڵ㣬��Ϊ������һ��sele_q = sele_p->next
	{
		int mine = 0;
		mine = sele_p->number;
		node *mine_p = NULL;//���ڼ�¼��Сֵ�ڵ��ָ�룬������һ�δ�Ƚ�֮���������������


		for (sele_q = sele_p->next; sele_q != NULL; sele_q = sele_q->next)//�����ȷ��sele_qָ����ָ��β�ڵ㵫�ǲ���Խ�磬β�ڵ���ʯ�����ݵ�һ��Ҫ��ȡ
		{

			if (mine > sele_q->number)
			{
				mine = sele_q->number;
				mine_p = sele_q;
			}
		}
		if (mine_p)
		{
			mine_p->number = sele_p->number;//�����Ƚϵ����Զ�Ҫ����С�������н�������Ȼ���������ظ�
			sele_p->number = mine;
		}


	}
}

//�鲢
//����
//node * MERGE_DIVIDE(node*p, node *q)//�ڴ��ε�ʱ����ȷ��p����ǵ�һ���ڵ㣬������ǰ�洫��������ͷ���
////��Ϊ����Ҫ�ݹ�
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
//		node *fast = p;//��ָ��
//		node *low = p;//��ָ��
//
//
//		//fast = p->next->next;
//
//		//��ָ��ÿ��������
//
//		//low = p->next;
//
//		//��ָ��ÿ����һ��  ��������ָ���ߵ�βָ���п�ʱ��ָ��͸պ��ߵ��м�
//
//
//		node *first = p;//���ָ��������¼ÿһ�ε���ʼ�ڵ�   
//		node *tail = q;//���ָ�����ڼ�¼ÿһ�εĽ����ڵ� ��������ĵݹ����
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


//�ϲ�����


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
//		while (a != p_tail->next) //����Ƚ�����a������b��ÿ��Ԫ��
//		{
//
//			if (a->number < b->number)
//			{
//				// ���a��bС, ��ô��ǰ���ĺ�̾���a
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
//		// ���ԭ��a�Ѿ�����,��ô�±����ͷ�b��ʣ��Ԫ��
//		// ������Ȼ��aΪ��׼��b���бȽ�
//		
//	}
//
//
//	return a;
//}


void main()
{

	srand((unsigned int)time(NULL));//���������

	int open_1 = 1;//��һ��while�Ŀ���
	int MAX_SIZE = 0;//MAX_SIZE ������Ҫ�������������	
	while (open_1)
	{
		printf("����������������ĸ���������20000����\n");
		scanf("%d", &MAX_SIZE);
		if (MAX_SIZE < 20000)
		{
			printf("����Ҫ��\n");//����Ҫ��
			printf("����������\n\n");//����������
			system("cls");
			open_1 = 1;
		}
		else
		{
			open_1 = 0;
		}
	}
	struct LINKLIST linklist;//����һ���ṹ�壬�ýṹ�����ڴ��ͷָ�룬βָ�����Ϣ��
	linklist.head = (node *)malloc(sizeof(node));//����ͷ��㣬��linklist��headָ��ָ��ͷ���
	//ע�⣡����������������������
	//ͷ����Ѿ�����ɹ�
	//�����ڵ�����MAX_SIZE��������
	//


	/**/
	/**/
	//���˴ο����ڴ˳���free��������Խ������
	//
	/**/
	/**/
	if (!linklist.head)
	{
		printf("��̬�ڴ�����ʧ�ܣ������쳣�˳�\n");//���⶯̬�ڴ�����������ʧ�ܵ����
		exit(-1);
	}
	(linklist.head)->number = MAX_SIZE;//ͷ���������Ϊ������
	(linklist.head)->subscript = 0;//ͷ����±�涨Ϊ0
	(linklist.head)->next = NULL;//ͷ���ָ����Ϊ��
	linklist.mid = NULL;//��ʼ��Ϊ�գ���ָֹ����ָ
	/*linklist.head��Ϊͷ��������
	ͷ����������number ������ɵ�����������и���
	���Ժ���һ����Ҫͳ������Ԫ�ظ�����ʱ��ֱ�ӷ��ʼ��ɡ�ʡȥ�˱����Ĺ���
	*/
	linklist.tail = linklist.head;//������ͷβָ��ָ����룬��
	/*ͷ������ɳɹ������ǹ���һ��ͷ��㡣�����Ǹ��ձ�
	����Ҫ��ͷָ���βָ�붼ָ��ͷ���
	*/

	//
	//printf("%p", linklist.mid);
	//

	random_made(linklist.head, MAX_SIZE, &linklist.tail, &linklist.mid);//��������ɺ���
	PRIN_linklist(linklist.head);

	/*
	linklist.head��ͷ���ĵ�ַ�����ɵ����������Ҫ��ͷ���֮��ġ�
	MAX_SIZE��������ĸ�����
	linklist.tail��Ϊ�ڵ�ָ�롣���������ָ��Ϊ�ڵ�
	ͬʱ��һ��ʼͨ���Ƚ�linklist.head linklist.tail�Ƿ�������ж��������������ǲ����Ѿ���������ֵ
	����� ��������� ���û�� ���������������� ��д������
	*/

	/*
	printf("\n%d,%d,%p\n", (linklist.tail)->number,(linklist.tail)->subscript,linklist.tail->next);
	*/
	menu();
	int KEY = 0;

	int open_2 = 0;
	if (!JUDGE(linklist.head))
	{
		printf("��������Ϊ�գ��޷���������\n");
		exit(-1);
	}
	else
	{
		while (!open_2)
		{
			FILE *TEST = NULL;//�ļ�ָ���ʼ��Ϊ�գ���ֹҰָ��

			printf("\n��������ѡ��Ĺ��ܺ�\n");
			scanf("%d", &KEY);
			switch (KEY)
			{
			case 1:
				SELECTION_sort(linklist.head, linklist.tail);//ѡ������ʵ��
				Txt_Write(TEST, linklist.head->next, KEY);//�ļ�д��
				open_2 = 1;
				//PRIN_linklist(linklist.head);//��ʽprintf ���Թ��ܿ���̨��ʾ���
				break;//open_Ϊ���ڿ����������Ʊ���

				//case 2:
				//	//INSERTION_sort(linklist.head, linklist.tail);

				//	PRIN_linklist(linklist.head);

				//	open_2 = 1;
				//	break;
			case 2:

				BUBBLE_SORT(linklist.head, linklist.tail);
				Txt_Write(TEST, linklist.head->next, KEY);//�ļ�д��
				//PRIN_linklist(linklist.head); 
				open_2 = 1;
				break;
			case 3:

				QUICK_SORT(linklist.head, linklist.tail);
				Txt_Write(TEST, linklist.head->next, KEY);//�ļ�д��
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
	//free(&linklist);//������������Ϊlinklist ��һ����ʱ��������ջ��

	system("pause");
}