/*
�ַ�������
��һ������һ������n,��ʾ��n���ַ�������������2��n+1��ÿ��һ���ַ��� 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>str;
	int n;
	cin>>n;
	str.resize(n);
	for(int i=0;i<n;i++) getline(cin,str[i]);
	sort(str.begin(),str.end());
	for(int i=0;i<n;i++) cout<<str[i]<<endl;
	return 0;
}
