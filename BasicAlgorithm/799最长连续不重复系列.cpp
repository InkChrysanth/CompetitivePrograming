#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int a[N],s[N],n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int res=0;
	for(int i=0,j=0;i<n;i++){
		s[a[i]]++;
		while(s[a[i]]>1){
			s[a[j]]--; //j�����ߵ�ʱ��ǰ������ݲ����ˣ���������������� 
			j++;
		}
		res=max(res,i-j+1);
	}
	cout<<res<<endl;
}
