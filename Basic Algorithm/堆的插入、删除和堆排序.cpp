#include<bits/stdc++.h>
using namespace std;
const int n=7;
int a[n]={3,5,1,7,6,4,2};
int heap[200],len=0;
void Insert(int x){
	int pa,son;
	heap[0]=-10000;//�ڱ�
	son=++len;
	pa=son/2;
	while(x<heap[pa]) {
		heap[son]=heap[pa]; //����Ԫ������ 
		son=pa;pa=son/2;    //�±��ϸ� 
	}
	heap[son]=x; //����x 
}
int DeleteMin()//ȡ����ɾ����Ԫ�� 
{
	int pa,son;
	int h=heap[1];
	int t=heap[len--];
	pa=1;son=pa*2;
	while(son<=len){
		if(son<len && heap[son+1]<heap[son]) son++;
		if(t<=heap[son]) break;
		heap[pa]=heap[son]; //����Ԫ������ 
		pa=son;son=pa*2;  //�±��³� 
	}
	heap[pa]=t; //����βԪ�� 
	return h;   //���ظ�Ԫ�� 
}
int main(){
	for(int i=0;i<n;i++) Insert(a[i]); //��С���� 
	for(int i=0;i<n;i++) cout<<DeleteMin()<<" "; //�����Ԫ�� 
	return 0;
}
	
