#include<bits/stdc++.h>
using namespace std;
int a[1005];
int tmp[1005];
void Mer(int a[],int s,int m,int e,int tmp[]){
    int pb=0;
    int p1=s,p2=m+1;
    while(p1<=m && p2<=e){
    	if(a[p1]<a[p2]) tmp[pb++]=a[p1++];//���ݴ�С������������� 
    	else tmp[pb++]=a[p2++];
	}
	while(p1<=m) tmp[pb++]=a[p1++];//˼����������ΪʲôҪ�У� ����while(p1<=m && p2<=e)ѭ���˳����� 
	while(p2<=e) tmp[pb++]=a[p2++];//�˳�ʱ����p1<m����p2<e 
	for(int i=0;i<e-s+1;i++)	{
		a[s+i]=tmp[i]; // 
	}
}
void KuSort(int a[],int s,int e,int tmp[]){
	if(s<e){
		int m=s+(e-s)/2;
		KuSort(a,s,m,tmp);
		KuSort(a,m+1,e,tmp);
		Mer(a,s,m,e,tmp);
	}
}
int main()
{
	int n; 
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	KuSort(a,0,n-1,tmp);
	for(int i=0;i<n;++i) cout<<a[i]<<",";
	cout<<endl;
	return 0;
	
}
