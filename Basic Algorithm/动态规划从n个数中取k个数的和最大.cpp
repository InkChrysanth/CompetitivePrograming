/*
��̬�滮��n������ȡk�����ĺ���� 
��̬�滮5��Ҫ��

�׶Σ�
״̬��
����
����
״̬ת�Ʒ��̣� 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],f[maxn][maxn],n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)f[i][1]=a[i];
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=k;j++)
	      f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[i]);//����i����ʱ�����������ȡ�벻ȡi 
	cout<<f[n][k]<<endl;
}
