/*
����ֱ�� 
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
���52 
*/
void dfs(int u,int fa){ //ֱ��ģ�� 
	int mx=0;//mxΪu�ڵ�����
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to,w=e[i].w;
		if(v==fa) continue ;
		dfs(v,u);//v���+u֮ǰ��� +w
		ans=max(ans,mx+w+dp[v]) ;
		mx=max(mx,dp[v]+w);
	}
	dp[u]=mx;//������u��������������µ�ǰu����� 
}
