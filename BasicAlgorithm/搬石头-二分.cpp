/*
25 5 2
2
11
14
17
21
*/
#include<bits/stdc++.h>
using namespace std;
int L,n,m,a[50005];
bool check(int mid){
	int last=0,tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]-last<mid) 
			tot++; //������ʯͷ 
		else 
		   last=a[i];
		
	}
	return tot<=m;
}
int main(){
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[++n]=L;
	int lft=0,rft=L;
	while(lft<=rft){
		int mid=lft+(rft-lft)/2;
		if(check(mid)) lft=mid+1; //�����������ԼӴ�ʯͷ�ļ�� 
		else rft=mid-1; //������������Сʯͷ�ļ�� 
	}
	cout<<rft<<endl;
}
