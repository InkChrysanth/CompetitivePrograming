/*
����n �����������εĸ��� 
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,total;
int main(){
	cin>>n;
	for(a=1;a<=n/3;a++){ //a,b,c�������ߴ�С�������� 
		for(b=a;b<n/2;b++){//�������ߺʹ��ڵ����ߣ���b<a+c<n/2 
			c=n-a-b;
			if(c>=b && (a+b)>c){
				cout<<a<<' '<<b<<' '<<c<<endl;
				total++;
			}
		}
	}
	cout<<total<<endl;
	return 0;
}
