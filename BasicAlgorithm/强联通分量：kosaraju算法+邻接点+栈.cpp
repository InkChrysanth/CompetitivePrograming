/*
ǿ��ͨ������kosaraju�㷨+�ڽӵ�+ջ 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=99;
int A1[maxn][maxn],A2[maxn][maxn];//�ڽӵ�
int vis1[maxn],vis2[maxn];//���ʱ�� 
int Stack[maxn],s;//ջ��ָ�� 
int Set[maxn],num;//��¼��һ����ͨͼ�������� 
void dfs1(int u){//����ԭͼ 
	int i,v;
	for(i=1;i<=A1[u][0];i++){
		v=A1[u][i];//ȡ��U���ڽӵ�
		if(!vis1[v]){
			vis1[v]=1;//��� 
			dfs1(v);//����ԭͼ 
		}
	}
	Stack[++s]=u;//������ջ 
	printf("%d ",u);//���� 
}
void dfs2(int u){//���ѷ�ͼ 
	int i,v;
	Set[u]=num;//�±�洢��num����ͨͼ��ĳ���� 
	for(i=1;i<=A2[u][0];i++){
		v=A2[u][i];//ȡ��u���ڽӵ� 
		if(!vis2[v]){
			vis2[v]=1;//��� 
			dfs2(v);//���ѷ�ͼ 
		}
	}	
}
int main(){
	int i,j,n=9,m=12,a,b;
	int E[15][3]={{1,2},{2,3},{3,1},{1,4},{4,5},{5,6},
	              {5,7},{7,6},{6,4},{5,8},{8,9},{9,8}};
	for(i=0;i<m;i++){
		a=E[i][0];b=E[i][1];
		A1[a][++A1[a][0]]=b;//�洢ԭͼ 
		A2[b][++A2[b][0]]=a;//�洢��ͼ 
	}              
	printf("��ջ˳��");
	for(i=1;i<=n;i++){
		if(!vis1[i]){
			vis1[i]=1;//��� 
			dfs1(i);//����ԭͼ 
		}
	}
	while(s){
		a=Stack[s--];//��ջ 
		if(!vis2[a]){
			vis2[a]=1;//��� 
			num++;
			dfs2(a);//���ѷ�ͼ 
		}
	}
	for(i=1;i<=num;i++){//���������ͨͼ 
		printf("\nǿ��ͨ����%d: ",i);
		for(j=1;j<=n;j++)
		   if(Set[j]==i) printf("%d ",j);
	}
}
