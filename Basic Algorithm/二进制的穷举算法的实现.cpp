/*
���nλ�Ķ����������㷨 
*/
#include<bits/stdc++.h>
using namespace std;
int b[100],n;
int main(){
	cin>>n;
	memset(b,0,sizeof(b));
	while(b[0]==0){
	    for(int i=1;i<=n;i++)
		    cout<<b[i];
	    cout<<endl;
		int j=n;
		while(b[j]==1)	j=j-1;//ָ����ǰ��
		b[j]=b[j]+1;//ÿ����ָ���Ƶ���λ��+1 
		for(int i=j+1;i<=n;i++)	
		   b[i]	=0; //����ָ������λ��ֵΪ0 
	}
	return 0;
}

