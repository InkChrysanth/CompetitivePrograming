#include<bits/stdc++.h>
/*
����С�����Ż�,ʱ�临�Ӷ�Ϊ(M+N)*logN 

*/
using namespace std;
const int maxn=10005;
int vis[maxn],n,m,d[maxn];
struct Node{
	int v,w;
	Node(int vv,int ww){v=vv;w=ww;}
};
vector<Node>G[maxn];
int main(){
	cin>>n>>m;
	memset(d,0x7f,sizeof(d));
	d[1]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(Node(v,w));
	}
	int T=1;
	for(int i=1;i<=n;i++){ //iֻ�������ѭ������ 
	    vis[T]=true;
        int k=G[T].size();
		for(int j=0;j<k;j++){
			if(!vis[G[T][j].v])
			    d[G[T][j].v]=min(d[G[T][j].v],d[T]+G[T][j].w);
		}
		int minn=0x7f;
		int Z=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(minn>d[i]) {
					minn=d[i];T=i;;Z=i;
				}
			}
		}
		if(Z==-1) break ;//�Ҳ����µĵ㣬����ʣ�µĵ㲻��ͨ 
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<endl;
	return 0;
}
