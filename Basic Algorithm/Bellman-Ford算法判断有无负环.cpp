bool Bellman(int s){
	fill(d,d_Maxv,INF);
	d[s]=0;
	for(int i=0;i<n-1;i++) //ֻҪѭ��n-1�������s�����·�� 
	   bool update=false; ,
	    for(int u=0;u<n;u++){
	       if(d[u]=d_Maxv) continue ;//�Ż� 
	       for(int j=0;j<Adj[u].size();j++){
	       	int v=Adj[u][j].v;
	       	int dis=Adj[u][j].dis;
	       	if(d[u]+dis<d[v])
	       	    d[v]=d[u]+dis;
	       	    update=true;//�������ɳ� 
		   }
	    }
	    if(!update) break;//�Ż� �޷��ɳھ���ǰ����   
    for(int u=0;u<n;u++){ //�жϸ��� 
    	for(int j=0;j<Adj[u].size();j++){
    		int v=Adj[u][j].v;
    		int dis=Adj[u][j].dis;
    		if(d[u]+dis<d[v])
    		      return false; //�и����˳� 
		}
	}	
	return true;	   
}
