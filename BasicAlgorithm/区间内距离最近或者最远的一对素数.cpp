/*
���һ�������о����������Զ��һ�����ڵ����� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000005;
bool a[maxn]={1,1}; //a[i]=false��ʾi������
vector<int>prime;
void IsPrime(int n){
	for(int i=2;i<=n;i++){ //ö������ƽ������ 
		if(a[i]==false) prime.push_back(i);//����С�ڵ���i���������������ö�� 
		for(int j=0;j<prime.size() &&prime[j]*i<=n;j++){//ö��С�ڵ���i������ 
			a[prime[j]*i]=true;
			if(i%prime[j]==0) break; //prime[j]�ܹ�����i,������ö�ٵ���������i����С�������� 
		}
	}
}//������prime������С�ڵ���n������������a�����¼��n���ڵ������� 
int main(){
	int L,R;
	cin>>L>>R;
	IsPrime(L-1);
	int k=prime.size();
	prime.clear();
	IsPrime(R);
	int k2=prime.size();
	if(k2-k<1) {
		cout<<-1<<endl;
		return 0;
	}
	int r1=k,r2=k;//r1��¼��С�ģ�r2��¼���� 
	int minn=prime[k+1]-prime[k];
	int maxn=prime[k+1]-prime[k];
	for(int i=k;i<k2;i++){
		if(prime[i+2]-prime[i+1]<minn) {
			r1=i+1;minn=prime[i+2]-prime[i+1];
		}
		if(prime[i+2]-prime[i+1]>maxn){
			r2=i+1;maxn=prime[i+2]-prime[i+1];
		}
	}
	cout<<prime[r1]<<" "<<prime[r1+1]<<" "<<prime[r2]<<" "<<prime[r2+1]<<endl;
	return 0;
}
