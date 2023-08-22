/*
Bash's Big Day
    ����n��������{ai}, ��һ���Ӽ�S,����gcd(S1,...,Sk)>1,ͬʱ|S|�����ܴ�1<=n,ai<=10^5,����
|S|��ʾ����S��Ԫ�ظ�����
�������ʽ��  
     ��һ��һ������n
	 �ڶ��У�n������ai
�������ʽ��
     һ��һ��������S�����е�Ԫ�ظ���	  
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn],maxx;
bool b[maxn]={1,1};

vector<int>prime;
void IsPrime(int n){
	for(int i=2;i<=n;i++){
		if(b[i]==0){
			prime.push_back(i);
		}
		else{
			for(int j=0;j<prime.size() && prime[j]*i<=n;j++){
				b[prime[j]*i]=true ;
				if(i%prime[j]==0) break;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x=sqrt(a[n])+1;
	IsPrime(x);
	int k=prime.size();
	for(int i=0;i<k;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j]%prime[i]==0) sum++;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx<<endl;
	return 0;
}
