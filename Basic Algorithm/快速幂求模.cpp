/*
�� a �� b �η��� p ȡģ��ֵ��
�����ʽ
�������� a,b,p ,��ͬһ���ÿո������
�����ʽ
���һ����������ʾa^b mod p��ֵ��
���ݷ�Χ
0��a,b,p��109
���ݱ�֤ p��0
����������
3 2 7
���������
2
*/
#include<bits/stdc++.h>
using namespace std;
long long int  a,b,p,s=1;//s����˻�
int main() {
	cin>>a>>b>>p;
	while(b){
		if(b&1) s=(s*a)%p;
		a=(a*a)%p;b>>=1;
	}
	cout<<s<<endl;
}
