/*
�ַ���ƥ��BF��
*/ 
#include<bits/stdc++.h>
using namespace std;
string s,t;
int BF(string s,string t,int z){ //z�����s�ַ������ĸ�λ�ÿ�ʼ�ж� 
	int i=z,j=0;
	int x=s.length(),y=t.length();
  //int x=s.size(),y=t.size();	
	while(i<x && j<y){
		if(s[i]==t[j]) {
			i++;j++;
		}
		else{
			i=i-j+1;//i=i-(j-0)+1 
			j=0;
		}
		if(j==y) {
			return i-j+1;
		}
	}
	return -1;
}

int main(){
	cin>>s>>t;
	cout<<BF(s,t,0)<<endl;
	return 0;
}
