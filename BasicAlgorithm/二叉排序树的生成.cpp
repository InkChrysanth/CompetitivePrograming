/*
 ���������������� 
 �������������Ƿǳ������һ���������嶨����κ�һ�����ݽṹ�鼮��

��ɾ��һ���ڵ���Ҫ���Ƕ�Ӧ�ڵ��״̬�������˵���ǣ��Ƿ�������ҽڵ㣬�ȵȡ���Ҫ��������������ۡ�

1.���Ҵ�ɾ���ڵ㣬�ڲ��ҵ�ͬʱ��Ҫ��¼һ�´�ɾ���ڵ�ĸ��ס�

2.�����ɾ���ڵ�����ҽڵ㶼�����ڣ���ôֱ��ɾ����

3.�����ɾ���ڵ����������������������ڣ��������������������������ڡ�ֱ�ӽ��������д��ڵ�һ�ߺ��������ɡ�

4.�����ɾ���ڵ������������ڣ�����������ӵġ���Ҫ���ն��������������ʴ���������������������ѡ��ڵ㲹����ɾ���ڵ��λ�á�

    �������������ѡ����Ӧ��ѡ�������������ұߵ��Ǹ�Ҷ�ӽڵ㣨����϶���Ҷ�ӣ��������Ҷ�ӣ���ô�Ͳ������ұߵĽڵ㣩

    �������������ѡ����Ӧ��ѡ��������������ߵ��Ǹ�Ҷ�ӽڵ㡣
*/
#include<bits/stdc++.h>
using namespace std;
int x;
struct node
{
	int data;
	node *lchild,*rchild;
};
node *bt;
void Jians(node* &bt ,int k){	
	if(bt==NULL) {
	   bt=new node;
	   bt->data=x;
	   bt->lchild=NULL;
	   bt->rchild=NULL;
	   return ;
	}
	if(k<bt->data) Jians(bt->lchild,k);
	else if(k==bt->data) return ;
    else if(k>bt->data) Jians(bt->rchild,k);	
}
void ZX(node* bt){
	if(bt) {
		ZX(bt->lchild);
		cout<<bt->data<<" ";
		ZX(bt->rchild);
	}
}
void  Del(node* &bt,int k)
{//1.Ѱ�Ҵ�ɾ���ڵ��������е�λ��,��������ڸý�㣬pָ���һֱ����ƶ�ֱ�����һλ
	node  *p,*f,*s,*q;
	p=bt;f=NULL;
	while(p)
	{
		if(p->data==k)   break;
		f=p;//fΪp��˫�׽��
		if(p->data>k) //������ 
			p=p->lchild;
		else
		p=p->rchild; //������ 
	}
	//2.�жϸõ��ڶ��������Ƿ����
	if(p==NULL) return ;
	//3.����֧�ṹ
	if(p->lchild==NULL)//p��������
	{
		if(f==NULL)
			bt=p->rchild;
		else  if(f->lchild==p)
			f->lchild=p->rchild;
		else 
			f->rchild=p->rchild;
		free(p);
	}
	else//˫��֧���
	{
		q=p;s=p->lchild;//��ʱ��p��ֵΪq��sΪp������������qΪs��˫��
		while(s->rchild)//����p���������в��������½�㡪�������
			{
				q=s;
				s=s->rchild;//sΪ����������㣬qΪ���������ڵ�ĸ�ĸ���
			}
	if(q==p)//�����ж�p�����������Ƿ�����������
		 q->lchild=s->lchild;//sΪp������������������������û����������
	else     
		q->rchild=s->lchild;
		p->data=s->data;
		free(s);
	}
	return  ;
}

int main(){
	while(cin>>x){
	   Jians(bt,x);	
	}	
	Del(bt,24);
	ZX(bt);
	return 0;
}
