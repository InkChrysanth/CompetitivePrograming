/*
   ����һ��n����¥��(1<=n<=12),��Ŵ��µ���һ��Ϊ1��n,������1��Ϊ����
   ��ʱһ�ο���1����2����3�� �����߷�������ֻ�ܿ������̤�ϣ����������㣩
   �ʣ��˴�¥���ߵ���n�������ж����ֲ�ͬ���߷��� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int f[maxn],n,x,f1,f2,f3,f4;
int main(){
	cin>>n>>x;
	if(x==1) f1=0;
	else f1=1;
	if(x==2) f2=0;
	else f2=1+f1;
	if(x==3) f3=0;
	else f3=1+f1+f2;
	if(n==1) f4=f1;
	else if(n==2) f4=f2;
	else if(n==3) f4=f3;
	else{
		for(int i=4;i<=n;i++)
		{
			if(x==i) f4=0;
			else f4=f1+f2+f3;
			f1=f2;f2=f3;f3=f4;
		}
	}
	cout<<f4;
	return 0;
}
