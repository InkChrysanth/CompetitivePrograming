/*
ɸѡ��n���ڵ�����
�ռ任ʱ�䣬�ӿ��˼����ٶ� 
*/ 
#include<bits/stdc++.h>
using namespace std;
int isPrime[10005],n; //�������isPrime[i]Ϊ1�����ʾi������ 
// char isPrime[10005] ��char���Խ�ʡ�ռ䣬charֻռ1���ֽڣ�intռ4���ֽ� 
int main(){
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++) isPrime[i]=1;
	for(i=2;i<=sqrt(n);i++) //ÿ�ν�һ���������б������Ϊ������ 
	{
		if(isPrime[i]){//ֻ���������ı��� 
			for(j=2;j<=n/i;j++) isPrime[i*j]=0;
		}
		
	}
	for(i=2;i<=n;i++) {
		if(isPrime[i]) cout<<i<<" ";
	}
	return 0;
}
