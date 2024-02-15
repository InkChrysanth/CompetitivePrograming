/*
������� 
void QSort(int a[],int low,int high)
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int k,n;
int Partition(int low,int high){
	a[0]=a[low]; //ȡ��һ��Ԫ��Ϊ���ĵ� 
	k=a[low]; //���ĵ��ֵ 
	while(low<high){
		while(low<high && a[high]>=k)--high;
		a[low]=a[high]; //�Һ����Сֵ�low���ֵ 
		while(low<high && a[low]<=k) ++low;
		a[high]=a[low]; //��ǰ��Ĵ�ֵ�high���ֵ 
	}
	a[low]=a[0];//�������ĵ��ֵ�����ĵ���ڵ������±�λ�� 
	return low; //�������ĵ���±�λ�� 
}

void QSort(int low,int high){ //������a���п������� 
	if(low<high){ //�������� 
	k=Partition(low,high)	;
	//��a[low..high] һ��Ϊ����kΪ����Ԫ���ź����λ�� 
	QSort(low,high-1); //�Ե��ӱ���еݹ����� 
	QSort(low+1,high); //�Ը��ӱ���еݹ����� 
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	QSort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
