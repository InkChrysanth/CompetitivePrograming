/*
������int�͵ı���a��n(0<=n<=31),
Ҫ��дһ�����ʽ��ʹ�ñ��ʽ��ֵ��a�ĵ�nλ��ͬ 
*/
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a,n,x;
	cin>>a>>n;
	x=(a>>n) &1;
    //(a&(1<<n))>>n; //��n<31ʱ������n=31����ܳ��ַ���λΪ1ʹ����ɸ��� 
	cout<<x<<endl;
	return 0;
	
}
