/*
�����������㷨��Ӧ�� 
*/
#include<bits/stdc++.h>
using namespace std;
char ch;
typedef struct BiTree;
typedef BiTree *BT;
struct BiTree{
	int data;
	BT lchild;
	BT rchild;
};
BT bt;
//����������
void CreateBitree(BiTree &T) {
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T=new BiTree;
		T->data=ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
	return ;
}
//��Ҷ�ӽ����� 
int LeafCount(BiTree T){
	if(T==NULL) 
	    return 0;
	if(T->lchild==NULL && T->rchild==NULL) 
	    return 1;
	else
	    return LeafCount(T->lchild)+LeafCount(T->rchild);
}

//���ܽ�����
int Count(BiTree T){
	if(T==NULL) 
	    return 0;
	else 
	    return Count(T->lchild)+Count(T->rchild)+1;	
}

//���������
int Depth(BitTree T) {
	if(T==NULL)
	   return 0;
	else
	    return max(Depth(T->lchild) ,Depth(T->rchild)) +1;  
}

//���ƶ�����
int Copy(BiTree T,Bitree &NewT) {
	if(T==NULL){
		NewT=NULL; return 0;
	}
	else{
		NewT=new BitNode;
		NewT->data=T->data;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
}
int main(){
	
	CreateBitree(T);
	return 0;
}
