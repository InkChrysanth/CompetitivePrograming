/*
8
389 207 155 300 299 170 158 65
389
389 207 155
389 300 299 170 158 65(207,155��300,299���) 
 ����ʵ��ʱ�临�Ӷ�nlog(n) 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int h[maxn],n,opt[maxn],cnt;//opt[]����½�������� 
int num[10]={2,3,5,7,11,13,17,19};
int b[10]={19,17,13,11,7,5,3,2};
int main(){
	cin>>n;
	freopen("daodan.in","r",stdin);
	freopen("daodan.out","w",stdout);
	for(int i=1;i<=n;i++) cin>>h[i];
//	cout<<lower_bound(num,num+8,6)-num<<endl; 
//	cout<<lower_bound(b,b+8,6,greater<int>())-b<<endl;
    opt[1]=h[1];
    cnt=1;
    for(int i=2;i<=n;i++){
    	if(h[i]<opt[cnt])
    	     opt[++cnt]=h[i] ;//ֱ�Ӽ���
		else{//�ҵ��ڵ��÷ŵ�λ�� 
			int k=lower_bound(opt+1,opt+1+cnt,h[i],greater<int>())-opt; //��λ 
			opt[k]=h[i];//���¸߶� 
		}	  
	}
	cout<<cnt<<endl;
	return 0;
}
