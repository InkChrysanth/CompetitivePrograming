/*
4 5
1 2
1 3
2 3
2 4
3 4
���ݹ����Ƿ����ݹ��㷨�����ѵ���Ҫ����һ��Ҫ�������� 
&&(g[cur][i]>cur)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
bool G[maxn][maxn];
int ans[maxn],length,n,m,start;
bool visit[maxn];
void print(int length){
	for(int i=1;i<length;i++){
		printf("%d--",ans[i]);
	}
	printf("%d\n",ans[length]);
}
void dfs(int last, int cur){  //
    visit[cur] = true;//visit��ʾ�����ʹ� 
    ans[++length] = cur; //lenth��¼�����ĵ�ĸ�������¼�ҵ��Ļ��еڼ���ı�� 
    for(int i=1;i<=n;i++){ //�������к͵�cur�����ı� 
        if(G[cur][i]&&!visit[i] && i== start && i!=last){ //�ص���㣬���ɹ��ܶ��ٻ� 
            ans[++length] = i;
            print(length);
            length--; //�˵���һ�� 
            //break;����Ҫbreak,��ΪҪ�����еĻ� 
        }
        if(G[cur][i]&&!visit[i] )  dfs(cur,i);//���������g[cur][i]>cur��֤����ĵ�����ִ���ǰ��Ų����ظ�?
    }//�������i�����������δ���ʹ��Ķ��� 
    length--;//���� 
    visit[cur] = false;//���� 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		G[x][y]=1;
		G[y][x]=1;
	}
	for(start=1;start<=n;start++){
		length=0;
		dfs(0,start);
	}
	return 0;
}
