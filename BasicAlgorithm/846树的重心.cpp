#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=2*N;
int e[M],ne[M],h[N],idx;
int maxx=N,n;
bool vis[N];
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u){
	vis[u]=true;
	int sum=0,size=0;
	for(int i=h[u];i!=-1;i=ne[i]) {
		int j=e[i];
		if(vis[j]) continue;
		int s=dfs(j); 
//		vis[j]=false ����ʱ����Ҫ��仰 
		size=max(size,s);//����̨�����uΪ���������������е����ֵ
		sum+=s; 
	}
	size=max(size,n-sum-1) ;//n-sum-1����Ϊ����Ҫ��ȥ���������ĺͻ�Ҫ�Ѹ����ҲҪ��ȥ 
	maxx=min(maxx,size);
	return sum+1; //������uΪ������������С 
}
int main(){
	cin.tie(0);
	int a,b;
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs(4); //����Ϊ��ı�� ���Բ���Ϊ0 
	cout<<maxx<<endl;
	return 0;
}
