/*
������ 
*/
#include<bits/stdc++.h>
using namespace std;
/*
typedef struct Lnode{
	int  data;
	struct Lnode *next;
}*LinkList;
*/
typedef struct{
	char num[8];
	char name[8];
	int score;
}ElemType;
typedef struct Lnode{
	ElemType data;
	struct Lnode *next;
}Lnode,*LinkList;
/*
Lnode *LocateELem_L(LinkList L,Elemtype(e)){
	Lnode *p;
	p=L->next;
	while(p && p->data!=e)
	    p=p->next;
	return p;    
}
*/
int main(){
	Lnode *p;
	LinkList L;
	L =new Lnode;
//	L=(LinkList)malloc(sizeof(Lnode)); //�����ڴ� 
    L->next=NULL;
    /*
    p=L;
    L=->next;
    delete p;
    //free(p) ; ��malloc�����ַʱ����;
	*/ 
	//��������ĳ���
	int count=0;
	p=L->next;
	while(p){ //��������ĳ��� 
		count++;
		p=p->next ;
	}
	
	//��ȡ���Ա�L�еĵ�i������Ԫ�ص����ݣ�ͨ������e����
	p=L->next;
	int i,j=1;
	while(p && j<i) {
		p=p->next;++j;
	}
	if(!p || j>i) return 0 ;
	cout<<p->data.num<<endl; //ȡ��i��Ԫ�ص�num��Աֵ 
	
	//�ҵ�ֵΪe������Ԫ�� 
	p=L->next;
	while(p && p->data.num==1)
	    p=p->next;
	Lnode *pp=p;
	
	//���ٵ�����
    while(L){ //���ٵ����� 
    	p=L;
    	L=L->next;
    	delete p;
	}
	
	//��յ�����
	p=L->next;
	while(p){ //��յ����� 
		L->next=p->next;
		delete p;
		p=L->next;
	}
	L->next=NULL;
	
	
	return 0;
}
