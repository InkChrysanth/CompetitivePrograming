/*
���� 
4 5
1 2
1 3
2 3
2 4
3 4
1 2 3 1
2 3 4 2
���ݹ����Ƿ����ݹ��㷨�����ѵ���Ҫ����һ��Ҫ�������� 
*/
#include<bits/stdc++.h>
using namespace std ;
#define MAXN 1005
using namespace std;
int n, m, x, lenth, g[MAXN][MAXN], num[MAXN], ans[MAXN];
bool visit[MAXN];
void print(){
    for(int i=1;i<lenth;i++) printf("%d ",ans[i]);
    // printf("\n");
    printf("%d\n",ans[lenth]);
}
void dfs(int last, int cur){  //ͼ��ģ���ڽӱ�洢����cur�㿪ʼ��ѯ��last��ʾ�ϴη��ʵĵ� 
    visit[cur] = true;//visit��ʾ�����ʹ� 
    ans[++lenth] = cur; //lenth��¼�����ĵ�ĸ�������¼�ҵ��Ļ��еڼ���ı�� 
    for(int i=1;i<=num[cur];i++){ //�������к͵�cur�����ı� 
        if(g[cur][i] == x && g[cur][i]!=last){ //�ص���㣬���ɹ��ܶ��ٻ� 
            ans[++lenth] = g[cur][i];
            print();
            lenth--; //�˵���һ�� 
            //break;����Ҫbreak,��ΪҪ�����еĻ� 
        }
        if(!visit[g[cur][i]] &&(g[cur][i]>cur))  dfs(cur,g[cur][i]);//���������g[cur][i]>cur��֤����ĵ�����ִ���ǰ��Ų����ظ�?
    }//�������i�����������δ���ʹ��Ķ��� 
    lenth--;//���� 
    visit[cur] = false;//���� 
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){ //��ģ���ڽӱ��ͼ 
        int u, v;
        scanf("%d%d",&u,&v);
        g[u][++num[u]] = v; g[v][++num[v]] = u; //���Ϊ��u�������ĵ�num[u]���ߵ���һ����Ϊv������num[u]��¼��u�����ıߵı�� 
    }
    for(x=1;x<=n;x++) //ÿ���㶼��Ϊ��㳢�Է��ʣ���Ϊ���Ǵ��κ�һ�㿪ʼ�����ҹ�����ͼ 
         lenth = 0,dfs(0,x);//val��ʾ���ĸ��㿪ʼ�ѻ��� 
    return 0;
}

