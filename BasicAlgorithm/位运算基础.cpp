/*
bitset<8>b; //��ʾ����һ��nλ��������b 
b.count(); //���ض�������1 �ĸ��� 
 //b[i]����b�ĵ�iλ 
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,t[7]={1,2,3,3,2,1,5};
void swap1(int &a,int &b){
	a=a+b;b=a-b;a=a-b;
}
void swap(int &a,int &b){
	a=a^b;b=a^b;a=a^b;
	//b=(a^b)^b=a^(b^b)=a^0=a;a=a^b=(a^b)^a=a^a^b=0^b=b;
}
int main(){
	cin>>a>>b;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	int x;
	for(int i=1;i<=6;i++) x=t[i]^t[i+1];
	cout<<x<<endl;
	bitset<8>b;//��ʾ����һ��nλ��������b 
	b.count(); //���ض�������1 �ĸ��� 
	cout<<b[1]<<endl; //b[i]����b�ĵ�iλ 
}
