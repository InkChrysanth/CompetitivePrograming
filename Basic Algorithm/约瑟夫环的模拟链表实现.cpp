/*
Լɪ�򻷵�ģ������ʵ�� 
*/
#include<bits/stdc++.h>
using namespace std;
const int n=5,m=3; 
int a[n+1],b[n+1]; //a[n+1]ָ�룬 b[n+1]�����˳�� 

int main(){
	int i,k=1,j=n;
	for(i=1;i<n;i++) a[i]=i+1; //ģ������ 
	a[n]=1; //��n��ָ���һ�ˣ��γ�һ���� 
	for(i=1;i<=n;i++) //n���˾�����Ϊֹ 
	{
		while(k<m){ //���� 
			j=a[j]; //�ƶ�ָ�� 
			k++; //�������� 1 
		}
		b[i]=a[j]; //����m; 
		a[j]=a[a[j]]; //m���� 
		k=1;		
	}
	for(i=1;i<=n;i++) cout<<b[i]<<" "; //��� 
	return 0;
}
