/*
7
1 1 1 1 1 1 1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
��� 5 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,e,x,y,a[maxn],to[maxn],nxt[maxn],head[maxn],f[maxn][2];
void dfs(int u,int fa){
     f[u][0]=0;//���μ�
	 f[u][1]=a[u];//��ʼ��,�μӰѵ�u��ֵ�ӽ�ȥ 
	 for(int i=head[u];i;i=nxt[i])	//ö�ٵ�ǰ�ڵ�u�����к��� 
	    {
	    	int v=to[i];
	    	if(v==fa)  continue; //��֦�Ż� 
	    	dfs(v,u); //�ȼ��㺢��v�Ĵ� 
	    	f[u][0] +=max(f[v][0],f[v][1]); //���u���μӣ�u�ĺ���v���Բμ�Ҳ���Բ��μӣ�ȡ���ֵ�� 
	    	f[u][1]+=f[v][0]; //���u�μӣ�u�ĺ���v��һ�������ܲμ� 
		}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		e=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++) scanf("%d",a+i);//scanf("%d",&a[i]);
		while(scanf("%d%d",&x,&y),x+y){//����  x+y�����ж��ǲ�������0,0 
			to[++e]=x;nxt[e]=head[y];head[y]=e;
			to[++e]=y;nxt[e]=head[x];head[x]=e;
		}
		dfs(1,0); //��DFS��˳��DP�ӵ�һ���ڵ㿪ʼ 
		printf("%d\n",max(f[1][0],f[1][1])); //��Ϊ1�ŵ�μӺͲ��μӵ����ֵ 
	}
}
