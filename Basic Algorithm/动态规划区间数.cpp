/*
����һ�����������ﲻ��������4��62�����ж��ٸ� ��
1-100����80�� 
f[i][j]��ʾ��iλ�����λΪjʱ����ͳ���� 
*/ 
#include<bits/stdc++.h>
using namespace std ;
const int maxn=1005;
int f[8][10];
int dp(int n){
	int k,w=1;
	int sum=0;
	while(n>0){//�ֽ�˼·�൱����
		k=n%10;
	    for(int i=0;i<k;i++) sum+=f[w][i];
		n/=10;
		w++;
	}
	return sum;
}
int main(){
	int a,b;	
	memset(f,0,sizeof(f));
	f[0][0]=1;//��ʼ��
	for(int i=1;i<=7;i++){//Ԥ����
		for(int j=0;j<=9;j++){
			if(j==4) f[i][j]=0;//���λ����4��ֱ����Ϊ0 
			else{
				for(int k=0;k<=9;k++)
				if(!(j==6&&k==2))f[i][j]+=f[i-1][k]; //�����λû�г���62������ļ����ۼ� 
			}
		}
	}
	cin>>a>>b;
	cout<<dp(b)-dp(a-1)<<endl;
	return 0;
}
