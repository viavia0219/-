#include <stdio.h>
#include <stdlib.h>
/*
��̬����һ������  ��̬�ڴ�����+ģ�黯���
1.������������һ����ͷ��ʾ��������
2.�������
3.������
4.ɾ���ڵ� 
5.��ӡ�����������ԣ� 
*/
struct student
{
	char name[20];
	int num;
	int math;
}; 
struct Node
{
	struct student data;             //������ 
	struct Node* next;   //ָ���� 
};
/******************************************��������***************************************/ 
 struct Node* createList()
{
  struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //headNode��ָ���ɽṹ����� 
    //����ʹ��ǰ���뱻��ʼ��
    //headNode->data = 1;   //������һ�㲻��ʼ�� 
  headNode->next = NULL;
  return headNode; 
}
/*****************************************�������****************************************/
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
} 
/*****************************************��ӡ����****************************************/
void printList(struct Node* headNode) 
{
 struct Node* pMove = headNode->next;   //����һ�����ƶ���ָ��ӵڶ����ڵ��ӡ
 printf("name\tnum\tmath\t");
 while(pMove)          //������ڵ㲻Ϊ��ʱ��ӡ
 {
 	printf("%s\t%d\t%d\n",pMove->data.name,pMove->data.num,pMove->data.math);
 	pMove = pMove->next;    //ָ��������һλ 
 } 
  printf("\n"); 
}
/*****************************************������(��ͷ������)****************************************/ 
void  insertNodeByHead(struct Node* headNode,struct student data) //�����ĸ������ͷ������ʲô���� 
{
	//1.��������Ľ��
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
/*****************************************ɾ�����(ָ��λ��(���)ɾ��)****************************************/ 
void deleteNodeByAppoinNum(struct Node* headNode,int num)  //ָ��λ�ã�ָ������ 
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if(posNode == NULL) //�����ǿյ�
	  printf("�޷�ɾ��������Ϊ��\n");
	else 
	{
		while(posNode->data.num != num)  //ѭ��������Ҳ����ͼ�����
		{
		  	posNodeFront=posNode;
		  	posNode=posNodeFront->next;
		  	if(posNode == NULL )
		  	{
		  		printf("û���ҵ������Ϣ���޷�ɾ��\n");
		  		return ; //����ѭ�� 
			}
		} 
		posNodeFront->next = posNode->next;
		free(posNode); 
	 } 
} 





 
int main()
{ 
  struct Node* list = createList();  // ����һ����Ϊlist������ 
  struct student info;  //����һ����Ϊinfoѧ���ṹ��
  while(1)
  {
  	printf("������ѧ��������:\n");
	scanf("%s",info.name); 
	printf("������ѧ����ѧ��:\n");
	scanf("%d",&info.num);
	printf("������ѧ������ѧ�ɼ�:\n");
	scanf("%d",&info.math);
	insertNodeByHead(list,info);   //�������� 
	printf("continue(Y/N)?\n");
	setbuf(stdin,NULL);    //���������
	int choice=getchar();
	if(choice == 'N'||choice == 'n' )
	{
		break;
	}
   } 
   printList(list);
   printf("������Ҫɾ����ѧ����ţ�");
   scanf("%d",&info.num);
   deleteNodeByAppoinNum(list,info.num);
   printList(list);
   system("pause");
  return 0;	
} 
