/*
����С�����Ż�,ʱ�临�Ӷ�Ϊ(M+N)*logN 

*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int>pii;
const int N=1e5+5;
const int M =1e5+5;
vector<pii>e[N];
int dist[N],vis[N];
int n,m;
void dijkstra(int src){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[src]=0;
	for(int k=1;k<n;k++){
		int min=0x7f;
		int z=-1
		for(int i=1;i<=n;i++)
		     if(!vis[i] && dist[i]<min)
		          {z=i;min=dist[i];u=i;//�ҳ���̵ĵ� 
				  }
		if(z==-1)    return ;//�Ż��ɳ��Ѿ����� 
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,c=e[u][i].second;
			if(!vis[v] && dist[v]>dist[u]+c) dist[v]=dist[u]+c;
		}
	}
}
int main(){
	
}
