/*
5
3 4 2 7 5
���
-1 3 -1 2 2
��a[x]>=a[y]��x<y��y���ֺ�Ϳ��԰�a[x]ɾ����ʣ���ϸ����������� 
*/
#include<iostream>
using namespace std;
const int N=100010;
int s[N],tt;
int n;
int main(){
	cin.tie(0);
    cin>>n;
   for(int i=0;i<n;i++)
   {
        int x;
        cin>>x;
        while(tt&&s[tt]>=x)tt--;
        if(tt)cout<<s[tt]<<" ";
        else cout<<"-1"<<" ";
        s[++tt]=x;

    }
    return 0;
}
