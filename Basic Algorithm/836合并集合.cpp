/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int a[N],p[N];
int find(int x){ //·��ѹ�� 
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	while(m--){
		char c[2];int x,y;//���ַ���������ĸ����������ȫ 
		cin>>c>>x>>y;
		if(c[0]=='M') p[find(x)]=find(y);
		else
		{
			if(find(x)==find(y)) puts("YES");//����Ϊʲô������p[x]==p[y]��Ϊû��find()��һ���Ļ��������Ϲ鲢�Ժ�û֪ͨ�� 
			else puts("NO");
		}
	}
	return 0;
}

