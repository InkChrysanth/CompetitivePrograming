/*
ŷ�����������ǣ���������n,С�ڻ����n������������n���ʵ�������Ŀ
��1-1,8λ1,3,5,7��4λ 
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>s;
int gcd(int a,int b){ //�����Լ�� (�Ƶ�+���ǣ� 
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	    if(gcd(i,n)==1) s.push_back(i);
	int k=s.size()  ;  
	cout<<k<<endl;
	for(int i=0;i<k;i++)  cout<<s[i] <<" " ;
	return 0;
}
	
