/*
��ɭ�� 
*/
#include<bits/stdc++.h>
using namespace std;
int P;
long long a[510];
int main()
{
    cin>>P;    
    cout<<int(P*log(2)+1)<<endl; // ��һ��    
    long long tmp=pow(2,50);       // tmp=2^50    
    a[500]=1;
    int t50=P/50;                 // t50���ܳ���2^50�Ĵ��� 
	int t1=P-t50*50;              // t1�� ʣ�µģ�һ��һ������ȥ 
    for(int T=1;T<=t50;T++)
    {
        for(int i=500;i>=1;i--)
        {
            a[i]*=tmp;            // ÿһλ������2^50
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // �����λ
        }
    }    
        for(int i=500;i>=1;i--)
        {
            a[i]*=pow(2,t1);              // ÿһλ������2
        }
        for(int i=500;i>=1;i--)
        {
            a[i-1]+=a[i]/10;
            a[i]%=10;             // �����λ
        }   
    a[500]--; //���-1   
    for(int i=1;i<=500;i++)
    {
        cout<<a[i];
        if(i%50==0) cout<<endl;
    }
    return 0;
}
