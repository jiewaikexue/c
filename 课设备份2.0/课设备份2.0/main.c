#include"sort.h"

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
				Txt_Write(TEST, linklist.head->next,KEY);//�ļ�д��
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