/*
�ռ��Ż� 
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 10005
int *maxSum;
int d[Max][Max];
int n;
int main(){
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=i;j++)
	   {
	   	   cin>>d[i][j];
	   }
	maxSum=d[n]; //maxSumָ���n�� 
	for(i=n-1;i>=1;i--) //�ӵ������� 
	   for(j=1;j<=i;j++)
	   {
	   maxSum[j]=max(maxSum[j],maxSum[j+1])+d[i][j];//��ֵ���������һ�� һֱ�³� 
	   }
	cout<<maxSum[1]<<endl;
	return 0;  
}
