#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct node{ //ģ������ 
	int x,l,r;
}b[maxn];
bool pd[maxn];
int T,Root,num=0;
int find(int z){
	if(b[z].l) find(b[z].l);
	num++; //���򾭹�һ�����+1 
	if(b[z].x==T) { //�ҵ� 
		cout<<num<<endl;
		return 0;
	}
	if(b[z].r) find(b[z].r) ;
}
int main()
{
	int i,n;
	cin>>n>>T;
	for(i=1;i<=n;i++){
		cin>>b[i].x>>b[i].l>>b[i].r;
		pd[b[i].l]=pd[b[i].r]=1;		
	}
	for(i=1;i<=n;i++){ //Ѱ������ 
		if(!pd[i]) {
			Root=i;break;
		}
	}
	find(Root); //������� 
	return 0;
}
