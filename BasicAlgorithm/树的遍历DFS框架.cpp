/*
���ı���dfs���

*/
void dfs(x) {
   (1) //λ��1��x��ǰ��һ����ʼ�� 
   ����x��ÿ������y{
   	    (2) //������֮ǰ��ÿһ�����ӳ�ʼ�� 
   	    dfs(y); //����������y��������Ѿ���ȫ�������� 
   	    (3) //���� x��y֮�����ϵ��Ҳ������һЩͳ�ư�y����Ϣͳ�Ƶ�x��ȥ 
   } 
    (4) //�������¿��� 
}//������ȱ�����ʱ�临�Ӷ���O(N),NΪ���еĽڵ��� 
const int MAXN=1e5_10;
int fa[MAXN],tot=0,head[MAXN];
struct node{
	int v,w,next;
}edge[MAXN];
void Addedge(int x,int y,int d){ //��ʽ��ǰ�ǽ���
     edge[++tot].v=y;
	 edge[tot].w=d;
	 edge[tot].next=head[x] ;
	 head[x]=tot;
	 fa[y]=x;	
}
