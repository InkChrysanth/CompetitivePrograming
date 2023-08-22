#include<bits/stdc++.h>
using namespace std;
typedef struct node;
typedef node *tree;
struct node
{
	char data;
	node *lchild,*rchild;
};
tree bt,NewT;
int a;
char ch;
void CreateBitree(tree &bt) {
	cin>>ch;
	if(ch=='#') bt=NULL;
	else{
		bt=new node;
		bt->data=ch;
		CreateBitree(bt->lchild);
		CreateBitree(bt->rchild);
	}
	return ;
}
void build(tree &bt)  //���� 
{
	cin>>a;	 
	if(a==0)  bt=NULL; 
	else
	{
		bt=new node;
		bt->data=a;
		build(bt->lchild);
		build(bt->rchild);
	}	    
	return ;
}
void printxx(tree bt)  //����������� 
{
	if(bt)
	{
	    cout<<bt->data<<"-> ";
		printxx(bt->lchild);	
		printxx(bt->rchild);
	}
}
void printzx(tree bt)  //����������� 
{
	if(bt)
	{
		printzx(bt->lchild);
		cout<<bt->data<<"-> ";
		printzx(bt->rchild);
	}
}
void printhx(tree bt)  //����������� 
{
	if(bt)
	{
		printhx(bt->lchild);		
		printhx(bt->rchild);
		cout<<bt->data<<"-> ";
	}
}
void FloorPrint(tree BT)  //�������
{
    tree temp[100];   //����pBTNodeָ�����͵�ָ������
    int tail = 0;
    int head = 0;
    temp[tail++] = BT;   

    while (tail > head)
    {
        if (temp[head])
        {
            cout << temp[head]->data << " �� ";
            temp[tail++] = temp[head]->lchild;
            temp[tail++] = temp[head]->rchild;
        }
        head++;  
    }
}
void FloorPrint_QUEUE(tree &BT) //�������_����ʵ�� ��ֵ 
{
    queue < tree> q;
    if (BT != NULL)
    {
        q.push(BT);   //���ڵ������
    }

    while (q.empty() == false)  //���в�Ϊ���ж�
    {
        cout << q.front()->data << " �� "; 

        if (q.front()->lchild != NULL)   //��������ӣ�leftChild�����
        {
            q.push(q.front()->lchild);   
        }

        if (q.front()->rchild != NULL)   //������Һ��ӣ�rightChild�����
        {
            q.push(q.front()->rchild);
        }
        q.pop();  //�Ѿ��������Ľڵ������
    }
}
//��Ҷ�ӽ������ 
int LeafCount(tree bt){
	if( bt==NULL) 
	    return 0;
	if(bt->lchild==NULL && bt->rchild==NULL) 
	    return 1;
	else
	    return LeafCount(bt->lchild)+LeafCount(bt->rchild);
}

//���ܽ�����
int Count(tree bt){
	if(bt==NULL) 
	    return 0;
	else 
	    return Count(bt->lchild)+Count(bt->rchild)+1;	
}

//���������
int Depth(tree bt) {
	if(bt==NULL)
	   return 0;
	else
	    return max(Depth(bt->lchild) ,Depth(bt->rchild)) +1;  
}

//���ƶ�����
int Copy(tree bt,tree &NewT) {
	if(bt==NULL){
		NewT=NULL; return 0;
	}
	else{
		NewT=new node;
		NewT->data=bt->data;
		Copy(bt->lchild,NewT->lchild);
		Copy(bt->rchild,NewT->rchild);
	}
}
int main()
{
		
//	build(bt); 
    CreateBitree(bt);
	cout<<"LeafCount:"<<LeafCount( bt)<<endl;
	cout<<"Count:"<<Count(bt)<<endl;
	cout<<"Depth:"<<Depth(bt)<<endl;
	printxx(bt);
	cout<<endl;
	printzx(bt);
	cout<<endl;
	printhx(bt);
	cout<<endl;
	FloorPrint(bt) ;
	cout<<endl;	
	FloorPrint_QUEUE(bt);
	cout<<endl;
	Copy(bt,NewT);
	cout<<"NewT:";
	printxx(NewT);
	cout<<endl;
	return 0;
}


