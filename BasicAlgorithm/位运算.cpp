/*
λ����
a^b=c����a^c=b,b^c=a; 
���������ʵ�ֲ�ͨ�������ߣ����ܽ�������������ֵ��
int a=5,b=7;
a=a^b;
b=b^a;
a=a^b; ��ٷ���֤ 
*/
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	a=a^b;
    b=b^a;
    a=a^b;
    cout<<a<<endl;
    return 0;
}
