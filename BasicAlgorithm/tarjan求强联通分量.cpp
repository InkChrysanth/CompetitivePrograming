trajan(u) //
{
	DFN[u]=Low[u]=++Index//Ϊ�ڵ�u�趨�����ź�Low��ֵ
	Stack.push(u) //�����Uѹ��ջ�� 
	for each(u,v) in E //ö��ÿһ���� 
	    if(visnotvisted) //������Vδ�����ʹ� 
	       tarjan(v) //���������� 
	       Low[u]=min(Low[u],Low[v])
	    else if(vinS)  //������V����ջ�� 
	       Low[u]=min(Low[u],DFN[v])
	if(DFN[u]==Low[u])  //������u��ǿ��ͨ�����ĸ� 
	repeat{
		v=S.pop //��v��ջ��Ϊ��ǿ��ͨ������һ������ 
		printv
		until(u==v)
	}    	    
}

void tarjan(int x){
	dfn[x]=low[x]=++tot;//��ջ dfn[]�ݹ���ʵ�˳��,low[]��ʾ���ٵķ���ʱ�䣨���������� 
	sta[++num]=x;insta[x]=true;
	for(int i=head[x];i;i=edge[i].next){
		if(!dfn[edge[i].to]){ //δ�����ʹ� 
			tarjan(dege[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else if(insta[edge[i].to]) //����ջ�� 
		    low[x]=min(low[x],dfn[edge[i].to]);
	}
	if(low[x]==dfn[x]){
		sa=0;//ͳ��ǿ��ͨ�����е�ĸ��� 
		do{	
		       sa++;
			    insta[sta[num--]]=false;
		   }while(x!=sta[num+1]) ; //��ջ
		
		if(sa==2){
			puts("2");exit(0);//��2��û��Ҫ������ 
		}
		if(sa>1) ans=min(ans,sa);//ȡ��Сֵ 
	}
}
