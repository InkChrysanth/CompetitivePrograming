#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int prim[N],cnt;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) prim[cnt++]=i;
        for(int j=0;prim[j]<=n/i;j++) {
                st[prim[j]*i]=true;
                if(i%prim[j]==0) break; //i%prim[j]==0��ôprim[j]һ����i����С������
        } //nֻ�ᱻ������С������ɸ�� ��i=6,prim[j]=2ʱ�Ͳ���j++,����18��3�������ɸ����18ͬʱ��2ɸ���������ͳ����ظ�ɸ 
        
    }
}
int main(){
    int n;
    cin>>n;
    get_primes(n);
    cout<<cnt<<endl;
    return 0;
}
