/*
 �˻����
 312 ��N=3,M=1;(N<=40,M<=6) NΪλ����MΪ*�ŵĸ��� 
 (1)3*12=36
 (2)31*2=62 
*/
#include<iostream>
#include<string>
using namespace std;
string s;
long long man,f[41][41]={{0}},n,k;
long long cs(int ks,int js)//����һ�ε�ֵ
{
    long long sum=0,t=1;
    for(int i=js;i>=ks;i--){sum=sum+(s[i]-'0')*t,t=t*10;}
    return sum;
}
int main()
{
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){f[0][i]=cs(0,i);}//�߽磬��û�г˺ŵ���������Ž�����ǰiλ
    for(int i=1;i<=k;i++) //iΪ�˺Ÿ���
    {
        for(int j=1;j<=n;j++)//jΪ���ָ��� 
        {
            for(int h=j;h>=i;h--) //hΪ�˺ŵ�λ�� ��λ��Ӧ�ô���ĩβ����һ���ڶ�λ֮�� 
            {
                f[i][j]=max(f[i][j],f[i-1][h-1]*cs(h,j));//״̬ת��
            }
        }
    }
    cout<<f[k][n-1];//������Ž�
    return 0;
}
