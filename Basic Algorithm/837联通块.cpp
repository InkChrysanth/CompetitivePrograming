#include<iostream>
using namespace std;
const int N=1e5+10;
//siz[N]ָ������NΪ���ڵ��������ͨ���е������
int f[N],siz[N];
int find(int x)//Ѱ��x�ĸ��ڵ�+·��ѹ��
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        siz[i]=1;
    }
    while(m--)
    {
        char a[3];
        int b,c;
        scanf("%s",a);
        if(a[1]=='1')//�ж�a��b�Ƿ���ͬһ����ͨ����
        {
            scanf("%d%d",&b,&c);
            //���b��c���ڼ���Ϊͬһ����,�򷵻�ture ���򷵻�No
            if(find(b)==find(c)) printf("Yes\n");
            else printf("No\n");
        }
        else if(a[1]=='2')//����b������ͨ��ĵ�ĸ���
        {
            scanf("%d",&b);
            printf("%d\n",siz[find(b)]);
        }
        else
        {
            scanf("%d%d",&b,&c);
            if(find(b)!=find(c))//���b��c������ͨ�鲻���,����кϲ�
            {
                /*��c��b����������ͨ��ϲ�ʱ,�ºϲ�����ͨ���
                ���ڵ�Ϊb�ĸ��ڵ�
                */
                //���ºϲ������ͨ��ĵ�ĸ���
                siz[find(c)]+=siz[find(b)];
                //�ϲ���ͨ��
                f[find(b)]=find(c);
            }
        }
    }
}

