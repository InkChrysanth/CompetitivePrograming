/*
����ֱ��--�����ɣ�˫ dfs������
7 6
1 6 13 E
6 3 9 E
3 5 7 W
4 1 3 S
2 4 20 R
4 7 2 S 
*/
//2��dfs��ֱ�� 
#include<bits/stdc++.h>
using namespace std;
const int wx=5e5+17;
inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		sum=((sum<<1)+(sum<<3))+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
struct e{
	int nxt,to,dis;
}edge[wx];
int n,m,k,cnt;
int ans,maxn,pos;
int head[wx],dis[wx];
void add(int u,int v,int dis){
	edge[++cnt].to=v;edge[cnt].nxt=head[u];head[u]=cnt;edge[cnt].dis=dis;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to,w=edge[i].dis;
		if(v==fa) continue;
		dis[v]=dis[u]+w; //�̳о��� 
		dfs(v,u);
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x,y,z;
//		x=read();y=read();z=read();getchar();getchar();
        x=read();y=read();z=read();//���������ֻ��ȡ���� 
		add(x,y,z);
		add(y,x,z);
    }
    dfs(1,0); //��1�ң���1��Զ�ĵ�pos 
    for(int i=1;i<=n;i++){
    	if(maxn<dis[i]){
    		maxn=dis[i];pos=i;
		}
	}
	memset(dis,0,sizeof(dis));
	dfs(pos,0); //��pos������pos��Զ�ĵ� 
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	printf("%d\n",ans);
	return 0;
}
