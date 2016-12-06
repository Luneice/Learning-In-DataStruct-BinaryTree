// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//
//C��αC++����
#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "conio.h"
#define MAXSIZE 100
using namespace std;

typedef char elemtype;
typedef struct  bitree
{
	elemtype data;
	struct bitree *lchild, *rchild;
}BTREE;

BTREE *create()
{//�ǵݹ鴴�������� 
	BTREE *q[100]; //����q������Ϊ���д�Ŷ��������н�㣬100Ϊ�������
	BTREE *s;                //���������еĽ��
	BTREE *root;            //��������ĸ�ָ�� 
	int front = 1, rear = 0, i;      //������е�ͷ��βָ��
	char ch;                 //����data��ֵ
	root = NULL;
	for (i = 0;i < 100;i++)
		q[i] = NULL;
	printf("�밴�����������������еĽ��:\n");
	printf("�ս���Զ��Ŵ��棬��#�Ž���!\n");
	cin >> ch;
	while (ch != '#')     //����ֵΪ#��,�㷨����
	{
		s = NULL;
		if (ch != ',')    //�������ݲ�Ϊ����,��ʾ��Ϊ����,����Ϊ����
		{
			s = (BTREE *)malloc(sizeof(BTREE));   s->data = ch;
			s->lchild = NULL;                     s->rchild = NULL;
		}
		rear++;
		q[rear] = s;    //�½���������� 
		if (rear == 1)
			root = s;
		else
		{
			if ((s != NULL) && (q[front] != NULL))
			{
				if (rear % 2 == 0)
					q[front]->lchild = s;   //rearΪż��,sΪ˫������
				else
					q[front]->rchild = s;   //rearΪ����,sΪ˫���Һ���
			}
			if (rear % 2 == 1) front++;    //����
		}
		cin >> ch;
	}
	return root;
}

void preorder(BTREE *root)
{//�ǵݹ�ʵ�ֵ��������


	BTREE *p, *a[MAXSIZE];
	int top = 0;
	p = root;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			cout << p->data << endl;
			a[top++] = p;
			p = p->lchild;

		}
		if (top > 0)
		{
			p = a[--top];
			p = p->rchild;
		}
	}

}

void inorder(BTREE *root)
{//�ǵݹ�ʵ�ֵ�������� 
	BTREE *p, *a[MAXSIZE];
	int top = 0;
	p = root;
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			a[top] = p;
			top++;
			p = p->lchild;
		}
		if (top > 0)
		{
			top--;
			p = a[top];
			cout << p->data << endl;
			p = p->rchild;
		}
	}

}

void postorder(BTREE *root)
{//�ǵݹ�ʵ�ֵĺ������  
	BTREE *p, *s1[100];             //s1ջ������н��
	int s2[100], top = 0, b;           //s2ջ��Ž�ջ��־
	p = root;
	do
	{
		while (p != NULL)
		{
			s1[top] = p;
			s2[top++] = 0;    //��һ�ν�ջ��־Ϊ0
			p = p->lchild;
		}
		if (top > 0)
		{
			b = s2[--top];
			p = s1[top];
			if (b == 0)
			{
				s1[top] = p;
				s2[top++] = 1;  //�ڶ��ν�ջ��־Ϊ0
				p = p->rchild;
			}
			else
			{
				cout << p->data << endl;
				p = NULL;
			}
		}
	} while (top > 0);
}

void  lorder(BTREE  *root)
{//�ǵݹ�ʵ�ֵĲ�α���  
	BTREE *q[MAXSIZE], *p;      // maxsizeΪ������� 
	int f, r;                   // f,r������ͷβָ��
	q[1] = root;
	f = r = 1;
	while (f <= r)
	{
		p = q[f];
		f++;                 //����
		cout << p->data << endl;
		if (p->lchild != NULL)
		{
			r++;
			q[r] = p->lchild;
		}        //���
		if (p->rchild != NULL)
		{
			r++;
			q[r] = p->rchild;
		}   //���
	}
}

void showmenu()
{//��ʾ�˵�
	cout<<"    ������������ʾ\n";
	cout<<"\t1������������\n";
	cout<<"\t2���������������\n";
	cout<<"\t3���������������\n";
	cout<<"\t4���������������\n";
	cout<<"\t5����α���������\n";
	cout<<"\t6���˳�����\n";
}

void main()
{
	system("title ������");
	system("color f0");
	BTREE *root = NULL;
	int no;
	while (1)
	{
		showmenu();
		cout<<"   ���������ѡ��";
		cin >> no;
		fflush(stdin);//������̻�����
		switch (no)
		{
		case 1:root = create();
			cout << "�����������ɹ����������������\n";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "����������������Ϊ��\n";
			preorder(root);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "����������������Ϊ��\n";
			inorder(root);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "����������������Ϊ��\n";
			postorder(root);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "��������α������Ϊ��\n";
			lorder(root);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:return;
		default:
			cout << "�������������������룡\n";
		}
	}
}


