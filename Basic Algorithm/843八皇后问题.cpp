#include<bits/stdc++.h>
using namespace std;
const int N=20; //��Ϊ�жԽ��ߣ���������Ҫ����һ���� 
int n;
char g[N][N];
bool col[N],dg[N],udg[N];
void dfs(int u){  
	if(u==n) { //U����ŵ��ڼ��� 
		for(int i=0;i<n;i++) puts(g[i]);
		puts(" ");
		return ;
	}
	for(int i=0;i<n;i++){ //��u�е�ʱ��ڼ��п��Է� 
		if(!col[i] && !dg[u+i] && !udg[u-i+n]){ //�Խ��ߵ���һ��Ҫ���� 
			col[i]=dg[u+i]=udg[u-i+n]=true;
			g[u][i]='G';
			dfs(u+1);
			col[i]=dg[u+i]=udg[u-i+n]=false; //���� 
			g[u][i]='.';
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
	       g[i][j]='.';
	dfs(0);
	return 0;
}
