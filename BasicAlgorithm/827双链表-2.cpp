/*
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
*/ 
#include <iostream>

using namespace std;

const int N=100010;

int e[N],l[N],r[N],idx=0;

void insertL(int x)
{
    l[idx]=0;//�½ڵ�->pre=head
    r[idx]=r[0];//�½ڵ�->next=head->next
    r[0]=idx;//head->next=�½ڵ�
    l[r[idx]]=idx;//�½ڵ�->next->pre=�½ڵ�
    e[idx++]=x;//add x
}

void insertR(int x)
{
    r[idx]=1;//�½ڵ�->next=tail
    l[idx]=l[1];//�½ڵ�->pre=tail->pre
    r[l[idx]]=idx;//�½ڵ�->pre->next=�½ڵ�
    l[1]=idx;//tail->pre=�½ڵ�
    e[idx++]=x;//add x
}

void deleteK(int k)
{
    r[l[k]]=r[k];//k->pre->next=k->next
    l[r[k]]=l[k];//k->next->pre=k->pre
}

void insertKL(int k,int x)                                  
{
    l[idx]=l[k];//�½ڵ�->pre=k->pre
    r[idx]=k;//�½ڵ�->next=k
    r[l[idx]]=idx;//�½ڵ�->pre->next=�½ڵ�
    l[k]=idx;//k->pre=�½ڵ�
    e[idx++]=x;//add x
}

void insertKR(int k,int x)
{
    r[idx]=r[k];//�½ڵ�->next=k->next
    l[idx]=k;//�½ڵ�->pre=k
    l[r[idx]]=idx;//�½ڵ�->next->pre=�½ڵ�
    r[k]=idx;//k->next=�½ڵ�
    e[idx++]=x;//add x
}   

void init()
{
    r[0]=1;//head->next=tail 0Ϊ����ͷ 
    l[1]=0;//tail->pre=head  1Ϊ����β 
    idx=2;//add two nodes
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    int m;
    cin>>m;

    while(m-->0)
    {

        string command;
        int k,x;
        cin>>command;
        if(command=="L")
        {
            cin>>x;
            insertL(x);
        }
        else if(command=="R")
        {
            cin>>x;
            insertR(x);
        }
        else if (command=="D")
        {
            cin>>k;
            deleteK(k+1);//��Ϊ��ʼ�����������ڵ㣬���Ե�k�������±�Ϊk+2-1
        }
        else if (command=="IL")
        {
            cin>>k>>x;
            insertKL(k+1,x);
        }
        else if(command=="IR")
        {
            cin>>k>>x;
            insertKR(k+1,x);
        }

    }
    for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';//��ͷ��ʼ,��i!=tailʱ���
    cout<<endl;
    return 0;

}

