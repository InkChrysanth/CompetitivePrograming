/*
7
13 7 8 16 21 4 18
���һ�ι鲢����Ȼ���Ƚ�1-k��ɳ�ӹ鲢��һ�ѣ�����k+1��~n�� 
ɳ�ӹ鲢��һ�ѣ�Ȼ���ٽ�������ɳ�ӹ鲢
K:1~(n-1)
f[i][j]:��i~j��ɳ�ӹ鲢��һ��ʱ����С�鲢�ܴ���
Ŀ�꣺F[1][n]
f[i][j]= 0 1<=i<=n,j=i
f[i][j]=min(f[i][k]+f[k+1][j]+s[j]-s[i-1]) 1<=i<=n,i<j<=n 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[maxn],s[maxn],f[maxn][maxn],n;
int main(){
	int i,j,k,p,m;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];f[i][i]=0;
		s[i]=s[i-1]+a[i]; //ǰ׺�� 
	}
	for(p=2;p<=n;p++) { //���䳤��,�׶Σ��Ѿ��ϲ���һ����м����ˣ� 
		for(i=1;i<=n-p+1;i++)// ö��������� 
		{
			j=i+p-1;//�����յ㣨�����С����j�ı߽磬�Ѿ��ϲ�������ʣ�µĴ���һ�ѿ�ʼ�� 			
			m=INT_MAX;
			for(k=i;k<j;k++)
				m=min(m,f[i][k]+f[k+1][j]); //���ܵľ��ߣ�ö���м�� 
			f[i][j]=m+s[j] -s[i-1] ; //��ҪԤ����ǰ׺��s 			
		}
	}
	cout<<f[1][n];
	return 0;
}
