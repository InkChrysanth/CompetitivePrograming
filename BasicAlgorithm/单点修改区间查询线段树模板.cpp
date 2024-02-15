/*
6
1 3 5 7 9 11
���36 
��һ�������Ż�
���scanf/printf(���գ�
�ر�أ��������Ϊ�ַ�ʱ����ʹ��һЩС���ɣ����������
char op=getchar();
while(op<'A' || op>'Z') op=getchar(); //�Ե������õ��ַ� 
(����λ�����Ż���Ч�������ԣ�����
1.struct Segment{ }tree[MAXN<<2];
2.mid��ȡֵ int mid=(l+r)>>1;
3.�����ӽڵ�ı��
p<<1
p<<1|1; 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN];
struct SegmentTree{ //SegmentTree�߶�����ȫ�� 
	int l,r; //�������Ҷ˵� 
	//������Ϣ��������Ϣ���߶�������ͷϷ 
	int sum; //����� 
}tree[MAXN*4];
void bulid(int p,int l,int r){ //�����ţ�������˵㣬�����Ҷ˵� 
	tree[p].l=l;tree[p].r=r;//��ʶ�������Ҷ˵� 
	if(l==r){tree[p].sum=a[l];return;}//Ҷ�ڵ�洢ʵ������Ԫ�� 
	int mid=(l+r)/2;
	bulid(p*2,l,mid); //�ݹ���� 
	bulid(p*2+1,mid+1,r); //�ݹ��Ұ� 
	//����ʱ�������丽����Ϣ 
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum ;//����͸���pushup 
}
void update(int p,int x,int v){ //�߶��������޸� 
	if(tree[p].l==tree[p].r) {tree[p].sum=v;return;	} //�ҵ�Ŀ�ֱ꣬�Ӹ��� 
	 //�۰���ң��޸ĵ�x�����������Ұ룩 
	int mid=(tree[p].l + tree[p].r)/2;//�������е� 
	if(x<=mid) update(p*2,x,v); //�ݹ������� 
	else update(p*2+1,x,v); //�ݹ�����Ұ� 
	//����ʱ�������丽����Ϣ,����͸��� 
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum; 
}
int query(int p,int l,int r){ //�����ѯд��1 
	if(l<=tree[p].l && tree[p].r<=r) return tree[p].sum; //��ȫ���� 
	int mid=(tree[p].l+tree[p].r)/2;
	int val =0;
	if(l<=mid) val+=query(2*p,l,r); //�� 
	if(r>mid) val+=query(p*2+1,l,r); //�� 
	return val;
}
int query1(int p,int l,int r){ //�����ѯд��2 
	if(tree[p].l==tree[p].r) return tree[p].sum;
	int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) return query1(p*2,l,r); //��ȫ���� 
	else if(l>mid) return query1(p*2+1,l,r);//��ȫ���� 
	else return query1(p*2,l,r)+query1(p*2+1,l,r);//����е� 
}
void print(int p){
	cout<<p<<" "<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].sum<<endl;
	if(tree[p].l==tree[p].r) return ;
	print(p*2);
	print(p*2+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	bulid(1,1,n);
	update(1,5,1); //�� 
//	print(1);
	cout<<query1(1,2,5)<<endl; //�� 
	return 0;
}
