/*
�������� 
    �����ϵ�һ���ڵ�ɾ�����õ������ͨ�飬��ɾȥ��Щ������õ�����ͨ���
�ڵ�����ֵ��С�������ɾ���ĵ�ͨ��������Ϊ�������ġ�	 
6
1 2
2 3
2 5
3 4
3 6
���
2 3 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=55555;
const int maxm=111111;
int tot,ans,x,y,n,f[maxn],head[maxn],nxt[maxm],edg[maxm],cnt[maxn];
bool vis[maxn];
void AddEdge(int x,int y){ //���� 
	edg[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int u,int fa){
	cnt[u]=1;//cnt[x]��¼��uΪ���������Ĵ�С
	for(int j=head[u];j;j=nxt[j]) { //ö��u��ÿһ������ 
		int v=edg[j];
		if(v!=fa){
			dfs(v,u); //�ȼ���v�Ĵ� 		
			f[u]=max(f[u],cnt[v]); //u��������� 
			cnt[u]+=cnt[v]; //uΪ��������С 
		}
	}
	f[u]=max(f[u],n-cnt[u]); //ɾ��u��u�ĸ������ڵ���ͨ��Ĵ�СΪn-cnt[u] 
	ans=min(ans,f[u]); //Ҫ����ͨ�龡����С 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		AddEdge(x,y);AddEdge(y,x);
	}
	ans=n;//����ͨ����С������̨
	dfs(1,0) ;//�Ե����� 
	for(int i=1;i<=n;i++)
	    if(f[i]==ans) printf("%d ",i);
	printf("\n")    ;
	return 0;
}
