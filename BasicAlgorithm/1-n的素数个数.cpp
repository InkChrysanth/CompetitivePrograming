/*
ʱ�临�Ӷ�o(n); 
ŷ������ɸѡ���� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
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
int main() {
	int n;
	cin>>n;
	IsPrime(n);
	for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";
	cout<<endl;
	cout<<prime.size()<<endl;
	return 0;
}

