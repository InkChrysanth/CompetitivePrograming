/*
������������к�
-2 11 -4 13 -5 -2 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn],a[maxn],s[maxn],n;
int main(){
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		dp[i]=a[i]; //����ʼ��Ϊ�Լ� ������Ҫ�� 
	}
//	dp[1]=a[1];
	for(j=2;j<=n;j++){
		for(k=1;k<j;k++){
			dp[j]=max(dp[j],dp[k]+s[j]-s[k]);
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
