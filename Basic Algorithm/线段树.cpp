/*
�߶����������ܲ��䣬����ֻ��Ҫ��bulid��update����������pushup���� 
*/
struct SegmentTree
{
	int l,tr;
	int sum; //����� 
	int dat; //������������Ӷκ� 
	int lmax;//������˵���������Ӷκ� 
	int rmax;//�����Ҷ˵���������Ӷκ� 
	
}tree[MAXN<<2];
void bulid(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	if(l==r){tree[p].sum=tree[p].dat=tree[p].lmax=tree[p].rmax=a[l]	;return ;} //Ҷ�ڵ�
	int mid=(l+r)/2; //�۰� 
	bulid(p*2,l,mid);//���ӽڵ�[l,mid],���p*2 
	bulid(p*2+1,mid+1,r);//���ӽڵ�[mid+1,r],���p*2+1 
	//�������ϴ�����Ϣ
	tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
	tree[p].lmax=max(tree[p*2].lmax,tree[p*2].sum+tree[p*2+1].lmax) ;
	tree[p].rmax=max(tree[p*2+1].rmax,tree[p*2+1].sum+tree[p*2].rmax) ;
	tree[p].dat=max(tree[p*2].dat,max(tree[p*2+1].dat,tree[p*2].rmax+tree[p*2+1].lmax));
}
