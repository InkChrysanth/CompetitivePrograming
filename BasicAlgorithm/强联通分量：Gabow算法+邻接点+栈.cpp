/*
ǿ��ͨ������Gabow(�Ӳ�)�㷨+�ڽӵ�+ջ 
*/
#include<bits/stdc++.h>
using namespace std;
int A[100][100]; //�ڽӵ� 
int Dfn[100],num; //��¼��ķ��ʴ��� 
int Stack1[100],t1; //������ջ��������ջ 
int Stack2[100],t2; //��̬ά�������ĸ� 
bool out[100]; //��ջ��� 
void DFS(int u){ //�����㷨 
	int i,v;
	Dfn[u]=++num; //��¼U�ķ��ʴ��� 
	Stack1[++t1]=Stack2[++t2]=u; //��ջ 
	for(i=1;i<=A[u][0];i++){
		v=A[u][i]; //ȡ��U���ڽӵ� 
		if(Dfn[v]==0){ //vû���ʹ� 
			DFS(v); //���� 
		}
		else if(out[v]==0){//v�ѷ��ʻ�û��ջ���л� 
			while(Dfn[Stack2[t2]]>Dfn[v]){
				--t2;
			} //v֮����ʵĵ㵯��ջ2 
		}
	} 
	//���ϲ����ǰ���жϸ� 
	if(u==Stack2[t2]){ //u�Ƿ����ĸ� 
		printf("ǿ��ͨ���� ");
		while(u!=Stack1[t1]){
			printf("%d ",Stack1[t1]);
			out[Stack1[t1]]=1; //��ջ��� 
			--t1;
		} //u֮����ʵĵ㵯��ջ1 
		printf("%d ",u); //u��ջ 
		out[u]=1; //��ջ��� 
		--t1;--t2; //�����ĸ�u��������ջ 
		cout<<endl;
	}
}
int main(){
	int i,j,u,v,N=9,M=13; //���������� 
	int E[20][2]={{1,2},{1,7},{2,3},{2,5},{2,9},{3,4},{4,2},
	              {5,6},{5,7},{5,8},{6,5},{8,6},{9,1} };
	for(i=0;i<M;i++){
		u=E[i][0];v=E[i][1];
		A[u][++A[u][0]]=v; //�ڽӵ� 
	}  
	for(i=1;i<=N;i++) //ͼ����Ϊɭ�� 
	   if(Dfn[i]==0) //iû���ʹ� 
	     DFS(i);  // ���� 
	return 0;     
}
