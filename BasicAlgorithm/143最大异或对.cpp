#include<iostream>
#include<algorithm>
using namespace std;
int const N=100010,M=31*N;

int n;
int a[N];
int son[M][2],idx;
//M����һ�����ִ������ƿ��Ե��೤

void insert(int x)
{
    int p=0;  //���ڵ�
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;   /////ȡX�ĵ�iλ�Ķ���������ʲô  x>>k&1(ǰ���ģ��)
        if(!son[p][u]) son[p][u]=++idx; ///��������з���û�и��ӽڵ�,��������·
        p=son[p][u]; //ָ��ָ����һ��
    }
}
int search(int x)
{
    int p=0;int res=0;
    for(int i=30;i>=0;i--)
    {                               ///�����λ��ʼ��
        int u=x>>i&1;
        if(son[p][!u]) ////�����ǰ���ж�Ӧ�Ĳ���ͬ����
        {   ///pָ���ָ����ͬ���ĵ�ַ

          p=son[p][!u];
          res=res*2+1;
             ///*2�൱����һλ  Ȼ������ҵ���Ӧλ�ϲ�ͬ����res+1 ����    001
        }                                                       ///       010 
        else                                            ////          --->011                                                                           //�տ�ʼ��0��ʱ����һ��������+0    ����0��1��ʱ��ԭ��0����һλ,�жϵ�ǰλ��ͬ������,ͬ+0,��+1
        {
            p=son[p][u];
            res=res*2+0;
        }
    }
    return res;
}
int main(void)
{
    cin.tie(0);
    cin>>n;
    idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {   
        res=max(res,search(a[i]));  ///search(a[i])���ҵ���a[i]ֵ��������ֵ
    }
    cout<<res<<endl;
}

