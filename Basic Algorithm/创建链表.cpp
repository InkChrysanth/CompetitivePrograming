#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head,*tail,*p;
void del(int k){
	node *pre;//ҪѰ�ҽ���ǰ��
	p=head;pre=p;
	while(p->next!=NULL){//�ж�p�Ƿ��Ƶ�β��� 
		if(p->data==k){
			pre->next=p->next;
			delete p;//�ͷ�p��ָ��Ľ�� 
			p=pre->next; //
		}		
		else
		{ //��ǰ�Ľ��ֵ��Ϊk,������� 
			pre=p;
			p=p->next;
		 } 
	}
	 if(p->data==k){ //whileѭ�������Ժ�pָ��������һ���ڵ㣬��Ҫ�������� 
	 	delete p; //ɾ�����һ���ڵ㣬pre�������һ���ڵ� 
	 	pre->next=NULL;
	 }
}
void inst(int key,int pos){
	node *pre,*np;
	p=head;pre=p;
	int k=0;//��¼��ǰ�ڵ��ǵڼ����ڵ� 
	while(p->next!=NULL){
		p=p->next;
		k++;
		if(k==5){
			np=new node;
			np->data=key;
			np->next=p;
			pre->next=np;
			break;
		}
		else{
			pre=p;
		}
	}
	if(k<5){
		np=new node;
		np->next=NULL;
		np->data=key;
		p->next=np;
	}
}
int main()
{
	int x;
	cin>>x;
	head=new node;
	tail=head;
	tail->next=NULL;
	while(x!=-999){
		p=new node;
		p->data=x;
		tail->next=p;
		tail=p;
		tail->next=NULL;
		cin>>x;		
	}
	del(8);
	inst(100,5);
	if(head->next!=NULL){
		p=head->next;
	    while(p->next!=NULL){
		    cout<<p->data<<" ";
		   p=p->next;
	    }
	     cout<<p->data;
	}
	else cout<<" ������"<<endl;
	return 0;
}
