/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4 
���
2 2
3 5
4 4 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10e5+5;
int n,m,s;
struct Node{ //����ṹ�壬����յ��Ȩֵ 
	int v,w; //�յ㣬Ȩֵ 
	Node(int _v,int _w) {v=_v; w=_w;	}
	//���幹�캯��������ӱߴ��� 
};
vector<Node>G[MAXN];
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(Node(v,w)); //��Ȩ����ͼ�ӱ� 
	}
//	G[u].push_back(Node(v,w)); //��Ȩ����ͼ�ӱ� 
//	G[v].push_back(Node(u,w));
    int k=G[s].size(); //���Ч�� 
    for(int i=0;i<k;i++)
         cout<<G[s][i].v<<" "<<G[s][i].w<<endl;
	return 0;
}
