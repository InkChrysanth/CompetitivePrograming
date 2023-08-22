//LCA�������� 
int LCA(int x,int y){ //������LCA 
	if(depth[x]<depth[y]) swap(x,y);  
	while(depth[x]!=depth[y]) x=fa[x]; //��������ߵ���ͬ�� 
	while(x!=y) x=fa[x],y=fa[y]; //һ��������
	return x;//LCA
}
//�Ż����ñ�������������� 
/*
Ԥ����
��f[x][i](i=0...logn)Ϊ��x����ƶ�2^i�������λ�ã���f[x][0]����x�ĸ���2^0=1���� 
��x,y�����LCA:
���Ƚ�x,y�ᵽͬһ��ȣ�������x��ǰ��y��Ӵ�Сö�ٲ���2^i,
��y����f[x][i]�������x.����i=0...logn,���Ӷ�O(logn) 
����ʱx==y�򷵻ؽ��(y)
�Ӵ�Сö�ٲ���2^i,��f[x][i]!=f[y][i]�����x,y������i=0...logn��˸��Ӷ�O(logn)
���𰸼�Ϊ��ǰx/y���ĸ��ڵ㣬��f[x][0] 
*/
//Ԥ���������� 
void dfs(int u,int father){ //��Ӧ����Ԥ����f����
     dep[u]=dep[father]+1; //���+1�� 
     for(int i=1;(1<<i)<=dep[u];i++)   
          f[u][i]=f[f[u][i-1]][i-1];//2^i=2^(i-1)+2^(i-1)=2*2^(i-1)
    //��u�ƶ�2^i�ξ��൱�ڴ�u�ƶ�2^(i-1)�κ����ƶ�2^(i-1)��
	for(int i=head[u];i;i=edge[i].next) {
		int v=edge[i].to;
		if(v==father) continue ; //������ 
		f[v][0]=u;  //u��v�ĸ��� 
		dfs(v,u);
	}     	
}
//CODEģ��
const int logN=18;
int LCA(int x,int y){ //Ѱ�ҹ������� 
	if(depth[x]<depth[y]) swap(x,y);
	/*
	for(int i=logN;i>=0;--i) //��x ������yͬһ��� 
	   if(depth[f[x][i]]>=depth[y])
	       x=f[x][i];
	*/
	int c=depth[x]-depth[y];
	for(int i=0;i<=14;i++){
		if(c &(1<<i)) x=up[y][i];
	} //��ͬ�� λ�����Ż�
	if(x==y) return x;
	for(int i=logN;i>=0;--i) //һ��������
	    if(f[x][i]!=f[y][i]) 
	       x=f[x][i],y=f[y][i];
	return f[x][0] ;//�����������LCA���·�����������һ��      
} 
