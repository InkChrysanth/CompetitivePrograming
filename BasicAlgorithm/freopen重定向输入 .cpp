/*
freopen�ض������� 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("c:\\tmp\\test.txt","r",stdin);
	//�˺��������붼�����ļ�c:\tmp\test.txtע��c:\\tmp\\test.txt�����˫//
	int n,mx=0;
	while(cin>>n) {
		if(n>mx) mx=n;
	}
	printf("%d",mx);
	return 0;
}
