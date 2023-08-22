/*
f[i][j]s1="x1x2...xi"��s2="y1y2...yj"������������еĳ��� 
s1����Ϊn,s2����Ϊm,��f[n][m]��Ϊ�� 
��xi=yj;��f[i][j]=f[i-1][j-1]+1 
��xi!=yj,xi��yj�����ܲ����������������
   ��xi�������������-->f[i-1][j]
   ��yj�������������-->f[i][j-1] 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
char s1[maxn],s2[maxn];
int f[maxn][maxn],n,m;
int main(){
	cin>>s1>>s2;
	int i,j;	
	n=strlen(s1);//��ȡ�ַ������� 
	m=strlen(s2);//��ȡ�ַ������� 
	for(i=1;i<=n;i++) f[0][i]=0; //��ʼ 
	for(i=1;i<=m;i++) f[i][0]=0; //��ʼ 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1; //��� 
			else f[i][j]=max(f[i-1][j],f[i][j-1]);  //����� 
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
