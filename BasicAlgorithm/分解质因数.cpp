#include<bits/stdc++.h>
using namespace std;
int get(int n,int p){
	int res=0;
	while(n){
		res+=n/p;
		n/=p;
	}
	return res;
}
int main(){
	cout<<get(8,2)<<endl; //8�Ľ׳˵�������2�ĸ��� 
	return 0;
}
