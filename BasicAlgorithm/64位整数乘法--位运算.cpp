/*
 64λ�����˷�
 �� a �� b �� p ȡģ��ֵ��
�����ʽ
��һ����������a���ڶ�����������b����������������p��
�����ʽ
���һ����������ʾa*b mod p��ֵ��
���ݷ�Χ
1��a,b,p��1018
����������
3
4
5
���������
2
*/
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
int main(){
    ULL a,b,p;
    cin>>a>>b>>p;
    ULL res=0;
    while(b){
        if(b&1)res=(res+a)%p;
        b>>=1;
        a=(a+a)%p;
    }
    cout<<res<<endl;
    return 0;
}
