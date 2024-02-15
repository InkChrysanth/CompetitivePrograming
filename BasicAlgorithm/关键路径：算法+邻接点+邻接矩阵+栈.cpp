/*
�ؼ�·�����㷨+�ڽӵ�+�ڽӾ���+ջ 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=51;
int A[maxn][maxn],W[maxn][maxn];//�ڽӵ㣬�ڽӾ��� 
int cd[maxn],rd[maxn];//���ȡ���� 
int sd,zd;//ʼ�㡢�յ� 
int Stack[maxn],s;//����ȶ���ջ��ָ�� 
int topo[maxn],t;//�������У������� 
int ve[maxn],vl[maxn];//�¼������磬����ʱ�� 
int ae[maxn],al[maxn];//������磬����ʱ�� 
int B[maxn][maxn];//�ؼ�·��������ڽӵ� 
int path[maxn],cd2[maxn];//�ؼ�·�����㣬���� 
int N,M;//������������ 
void Print(int,int);//����ؼ�·�� 

void Init() //��ʼ�� 
{
	int i,j,k,l;//
	N=8,M=10;
	int E[15][3]={{1,2,4},{1,3,6},{2,4,1},{3,4,1},{4,5,9},
	              {4,6,6},{4,7,7} ,{5,8,3},{6,8,7},{7,8,4}};
	for(i=1;i<=M;i++){
		j=E[i-1][0];k=E[i-1][1];l=E[i-1][2];
		cd[j]++;//�洢��j�ĳ��� 
		A[j][cd[j]]=k;//�洢�ڽӵ� 
		rd[k]++;//�洢��k����� 
		W[j][k]=l;//�ڽӾ���洢��Ȩ 
	}
	for(i=1;i<=N;i++){
		if(rd[i]==0) sd=i; //ʼ�� 
		if(cd[i]==0) zd=i; //�յ� 
	}		
}
bool TopoOrder(){//�������� 
	int i,j,k;
	int num=0;//������ 
	Stack[++s]=sd;//ʼ����ջ 
	while(s){
		i=Stack[s--];//��ջ 
		num++;//���� 
		topo[++t]=i;//��¼�������� 
		for(j=1;j<=cd[i];j++)
		{
			k=A[i][j];//ȡ���ڽӵ� 
			rd[k]--;//��ȼ�1 
			if(rd[k]==0) Stack[++s]=k;//�����ȱ��0��̵���ջ 
			if(ve[i]+W[i][k]>ve[k])//�����¼������緢���¼� 
			   ve[k]=ve[i]+W[i][k];
		}
	}
	if(num==N) return 1;//�޻�· 
	else return 0;	//�л�· 
}
void CritlPath() //�ؼ�·�� 
{
	int i,j,k,l;
	if(TopoOrder())//�޻�· 
	{ //��ʼ���¼�����ٷ����¼� 
		for(i=1;i<=N;i++) vl[i]=ve[N];//����������������vlֵ 
		for(l=N;l>=1;l--)
		{
			k=topo[l];
			for(j=cd[k];j>=1;j--)
			{
				i=A[k][j];//ȡ���ڽӵ� 
				if(vl[i]-W[k][i]<vl[k])
				   vl[k]=vl[i]-W[k][i];
			}
		}
		j=0;//��ae,al�͹ؼ�� 
		for(i=1;i<=N;i++)
		    for(l=1;l<=cd[i];l++){
		    	k=A[i][l];//ȡ���ڽӵ� 
		    	ae[++j]=ve[i];al[j]=vl[k]-W[i][k];
		    	if(ae[j]==al[j]){//�ؼ�� 
		    		B[i][++cd2[i]]=k;//�洢�ڽӵ� 
				}
			}
	    printf("�¼�ve:")	;//�����¼� 
		for(i=1;i<=N;i++) printf("%2d ",ve[i])	;
		printf("\n�¼�v1:")	;
		for(i=1;i<=N;i++) printf("%2d ",vl[i])	;
		printf("\n�ae:")	;
		for(i=1;i<=N;i++) printf("%2d ",ae[i])	;
		printf("\n�al:")	;
		for(i=1;i<=N;i++) printf("%2d ",al[i])	;
		printf("\n\n�ؼ�·�� ��");
		Print(sd,1);//����ؼ�·��		 
	}
}
void Print(int v,int deep)//����ؼ�·�� 
{
	path[deep]=v;//�洢�ؼ�·������ 
	if(v==zd){//�����յ㣬���·�� 
		for(int j=1;j<=deep;j++)
		    printf("%d ",path[j]);
		printf("\n")   ; 
	}
	else{
		for(int j=1;j<=cd2[v];j++)
		   Print(B[v][j],deep+1);//�ݹ� 
	}
}
int main(){
	Init();//��ʼ�� 
	CritlPath();//�ؼ�·�� 
}

