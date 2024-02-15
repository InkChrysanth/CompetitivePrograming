/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/
#include<bits/stdc++.h> 
using namespace std;
int fa[150005];
int n,k,ans;
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
} //��ѯ 
inline int read()
{
	int sum=0;
	char ch=getchar();
	int flag=1;
	while(ch>'9' or ch<'0') {
	    if(ch=='-') flag=-1;
	    ch=getchar();
	    }
	while(ch>='0' && ch<='9') sum=sum*10+ch-48,ch=getchar();
	return flag*sum;
} //�����Ż�
int unity(int x,int y) 
{
	int r1=find(fa[x]),r2=find(fa[y]);
	fa[r1]=r2;
} //�ϲ� 
int main() 
{
	int x,y,z;
	n=read();k=read();
	for(int i=1;i<=3*n;i++) fa[i]=i; //����ÿ������� x Ϊ����x+n Ϊ���x+2*n Ϊ���
	for(int i=1;i<=k;i++)
	{
		z=read(),x=read(),y=read();
		if(x>n||y>n){ // �����ڸ�ʳ������ȻΪ��
			ans++;continue;
		}
		if(z==1)
		{
			if(find(x+n)==find(y) || find(x+2*n)==find(y)) {
				ans++;continue; //���1��2����л������ȻΪ����
			}
			unity(x,y);unity(x+n,y+n);unity(x+2*n,y+2*n);
			//���Ϊ�棬��ô1��ͬ���2��ͬ�࣬1��������2�����1�������2�����
		}
		else if(z==2)
		{
			if(x==y) { //��ʵ�Ƿϻ����ǿ�����΢ʡ��ʱ��
				ans++;continue;
			}
			if(find(x)==find(y)||find(x+2*n)==find(y)){
				ans++;continue; //���1��2��ͬ��������ȻΪ����
			}
			unity(x,y+2*n);unity(x+n,y);unity(x+2*n,y+n);
			//���Ϊ�棬��ô1��ͬ����2����У�1��������2��ͬ�࣬1�������2������
		}
	}
	printf("%d\n",ans);
	return 0;
}
