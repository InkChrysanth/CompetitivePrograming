/*
ǿ��ͨ������tarjan�㷨+�ڽӵ�+ջ 
*/
#include<bits/stdc++.h>
using namespace std;
int A[100][100];//�ڽӵ� 
int Dfn[100],num;//��¼��ķ��ʴ��� 
int Low[100];//��̬��С��ķ��ʴ��� 
int Stack[100],t;//������ջ��������ջ 
bool out[100];//��ջ��� 
void DFS(int u){//�����㷨 
	int i,v;
	Dfn[u]=Low[u]=++num;//��¼u�ķ��ʴ��� 
	Stack[++t]=u;//��ջ 
	for(i=1;i<=A[u][0];i++){
		v=A[u][i];//ȡ��u����ڽӵ� 
		if(Dfn[v]==0){//vû���ʹ� 
			DFS(v);//���ã����ݵ���uʱ����СLow[u] 
			Low[u]=min(Low[u],Low[v]);
		}//v�ѷ�������ջ�У�˵��u,v�ѹ��ɻ� 
		else if(!out[v]){//ɭ�ֲ���ȥ�� 
			Low[u]=Low[v];//�л�ʱ����СLow[u] 
		}
	}//
	if(Dfn[u]==Low[u]){//u�Ƿ����ĸ� 
		printf("ǿ��ͨ����:");
		while(Stack[t]!=u){
			printf("%d ",Stack[t]);
			out[Stack[t--]]=1;//��ջ��� 
		}//u֮����ʵĵ����ջ 
		printf("%d ",u); //u��ջ��� 
		out[Stack[t--]]=1;
		cout<<endl;
	}
}
int main()
{
	int i,j,u,v,N=9,M=13;
	int E[20][2]={{1,2},{1,7},{2,3},{2,5},{2,9},{3,4},{4,2},
	              {5,6},{5,7},{5,8},{6,5},{8,6},{9,1} };
	for(i=0;i<M;i++){
		u=E[i][0];v=E[i][1];
		A[u][++A[u][0]]=v;//�ڽӵ� 
	} 
	for(i=1;i<=N;i++)  //ͼ����Ϊɭ��           
	   if(Dfn[i]==0)//iû���ʹ� 
	      DFS(i);//���� 
	return 0;      
}
