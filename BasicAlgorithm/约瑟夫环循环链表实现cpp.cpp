/*
Լɪ�򻷵�ѭ������ʵ�� 
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *h,*t,*p; //hͷָ��,tβָ��,p�ƶ�ָ�� 
int main(){
	int i,j,n,m; 
	cin>>n>>m;
	h=new node; //����ͷ��� 
	h->data=1;
	h->next=0;
	t=h;
	for(i=2;i<=n;i++){ //�����½�� 
		p=new node;
		p->data=i;
		p->next=NULL;
		t->next=p;
		t=p;
	}
	t->next=h;t=h; //���ɻ� 
	for(i=1;i<=n;i++){ //������� 
		for(j=1;j<m-1;j++){
			t=t->next;//ÿ�������һλ 
		}
		cout<<t->next->data<<" ";
		t->next=t->next->next;
	}
	return 0;
}
