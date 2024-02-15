/*
3
3
0 1
1 2
2 0
3
2
0 1
0 2
*/
#include<bits/stdc++.h>
using namespace std;
const int N=505;
int m,n;
int color[N];
vector<int>node[N];
bool dfs(int v,int c){
	color[v]=c;
	//Ϊ��ǰ������ɫ 
	for(int i=0;i<node[v].size();i++){
		//����������֮���ӵĶ��㣬�����ڶ��� 
		if(color[node[v][i]]==c)
		//������ڵĶ���ͬɫ���ͷ���false 
		     return false;
		if(color[node[v][i]]==0 && !dfs(node[v][i],-c)) 
		//������ڶ���δȾɫ���ͽ���ȾΪ�෴��ɫ��-c,������dfs 
		     return false;
	}
	return true;
	//ֱ�����ж��㶼��Ⱦɫ����û��������ͬɫ���㣬�ͷ���true 
}
void solve(){
	for(int i=0;i<n;i++){
	//�������ж���	
		if(color[i]==0){
	    //���δȾɫ���ͽ�������		
			if(!dfs(i,1)){ //ֻҪ��һ�㲻������˳� 
				printf("NOT BICOLORABLE.\n");
				//�������falseֵ���Ͳ��Ƕ���ͼ 
				return ; //�������� 
			}
		}
	}
	printf("BICOLORABLE.\n");
	//δ��������ͬɫ�����Ƕ���ͼ 
}
int main(){
	int u,v;
	while(scanf("%d%d",&n,&m)){
		memset(node,0,sizeof(node));
		memset(color,0,sizeof(color));
		for(int i=0;i<m;i++){
			cin>>u>>v; //��Ϊ������ͼ������Ҫ˫����붥�� 
			node[u].push_back(v); //��u������v���� 
			node[v].push_back(u); //��v������u���� 
		}
		solve();
	}
	return 0;
}
