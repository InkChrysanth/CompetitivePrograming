/*
��ţ��, ����ж�������ϴﵽ83 
83 5
1
5
10 
25 
50
���159
f[i][j]ǰi��Ӳ�ң������Ϊiʱ�����㷽������
�߽�������f(i,0)=1,f(0,j)=0;
��f(n,total)�� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[101],s,n,f[maxn][101];
int main(){
	cin>>s>>n;
	for(int i=1;i<=n;i++) {
	    cin>>a[i];
	    f[i][0] =1;
		} 
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	   for(int j=0;j<=s;j++){
	   	 for(int k=0;k*a[i]<=j;k++)
	   	    f[i][j]+=f[i-1][j-k*a[i]]; //ÿ�ζ��ۼ� 
	   }
	   cout<<f[n][s]<<endl;
	return 0;
}
