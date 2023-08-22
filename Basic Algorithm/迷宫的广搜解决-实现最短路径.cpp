/*
bfs()ò�Ʒֲ����Ѽ���������� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int fx[5][2]={{1,0},{-1,0},{0,-1},{0,1}};
char jz[maxn][maxn]; //�Թ����� 
int path[maxn][2]; //·�� 
int pre[maxn]; //ǰ�� 
int n,step,desx,desy,soux,souy;
bool vist[maxn][maxn];
void print(int x){ //��ӡ��� 
   if(pre[x]!=0) print(pre[x]) ;
	cout<<path[x][0]<<" "<<path[x][1]<<"->";
}
void bfs(){
	int head=0,tail=1;
	path[tail][0] =soux;
	path[tail][1] =souy;
	pre[tail]=0; 
	vist[soux][souy]=true;
	while(head!=tail){
	   head++;
	   for(int i=0;i<4;i++){ //4��������� 
	       int xx=path[head][0]+fx[i][0];
	       int yy=path[head][1]+fx[i][1];
	       if(jz[xx][yy]=='0'&& !vist[xx][yy]){
	       	   tail++;
	       	   path[tail][0]=xx;
	       	   path[tail][1]=yy;
	       	   pre[tail]=head; //����ǰ�� 
	       	   vist[xx][yy]=true;
	       	   if(xx==desx &&yy==desy){	 //�ҵ����       	   	
	       	   	print(tail);
	       	   	return ;
				  }
		   }
	   
	   }
	}
	cout<<"No Way:"<<endl;
    return ;	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++) 
	      cin>>jz[i][j];
	cin>>soux>>souy>>desx>>desy;
	bfs();
	return 0;    
}
