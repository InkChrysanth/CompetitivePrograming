void make_set(int x){
	p[x]=x;
	rank[x]=0; //rank[]�����ĸ߶� 
}
int find_set(int x){
	if(x!=p[x])
	   p[x]=find_set(p[x]);
	return p[x] ;  
}
void union1(int x,int y){
	x=find_set(x);
	y=find_set(y);
	if(x!=y){
		if(rank[x]>rank[y])
		     p[y]=x; //y����x�� 
		else {
			 p[x]=y;
			 if(rank[x]==rank[y]) //�������y �����ң�ԭ�����ȸ�������+1 
			    rank[y]=rank[y]+1;
		}		        
	}
}
