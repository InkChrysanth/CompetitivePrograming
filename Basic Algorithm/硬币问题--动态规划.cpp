/*
Ӳ�����⣬�൱����ȫ�������� 
���õ��ƾ����õݹ� 
0��1����f(i,j)=max{f(i-1,j),f(i-1,j-v[i])+w[i]} ����i-1 ;
0/1�����е�ÿ����Ʒֻ��һ������һ������û���ˣ�ֻ�з�����һ����Ʒ������Ҫi-1 
��ȫ����f(i,j)=max{f(i-1,j),f(i,j-v[i]+w[i]}  ����i����Ҫ-1; 
��ȫ������Ʒ�ж����ֻҪ��֤j>=v[i]�Ϳ��Լ����� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int minv[maxn],maxv[maxn];
int s,n,v[101];
int main(){
	cin>>s>>n;
	minv[0]=maxv[0]=0;
	for(int i=1;i<=s;i++){
		minv[i]=0x7f;maxv[i]=-0x7f;
	}
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=s;i++) //sΪ�׶� 
	   for(int j=1;j<=n;j++)//jΪ״̬ 
	      if(i>=v[j]){
	      	minv[i]=min(minv[i],minv[i-v[j]]+1);
	      	maxv[i]=max(maxv[i],maxv[i-v[j]]+1);
		  }
    printf("%d %d\n",minv[s],maxv[s])	;	  
}
