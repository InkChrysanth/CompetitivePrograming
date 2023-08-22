/*
����һ����n���㣬q��ѯ�ʣ�ÿ��ѯ�ʵ�x����y����֮��ľ��롣1<=q,n<=10^5
6
1 2
1 3
2 4
2 5
3 6
2
2 6
5 6
���
3
4 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,tot,dep[N],f[N][22],dis[N],head[N];
struct node{ //�ֹ����� 
	int to,nxt,w;
}e[2*N];
void add(int x,int y){ //���� 
	e[++tot].to=y;e[tot].nxt=head[x];head[x]=tot;
}
void dfs(int u,int fa){ //Ԥ���������� 
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
	   f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i>0;i=e[i].nxt)   { //�õݹ麯������ÿһ����֧ 
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){ //�ҹ������� 
	if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){ //�ﵽ��ͬ�߶� 
    	if(dep[f[x][i]]>=dep[y])
    	   x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){ //������ͬ�߶Ⱥ�ʼһ������ 
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int query(int u,int v){ //��ѯ��� 
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){ //��ʼ���� 
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); 
		add(y,x); //˫��  
	}
	dfs(1,0); //Ԥ���������� 
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y)); //���ѯ�ʽ�� 
	}
	return 0;
}
}
