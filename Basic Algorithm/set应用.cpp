/*
set��Ӧ�� 
set�����������������±� 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int>s;
	set<int>::iterator it;
	int x;
	pair<set<int>::iterator,bool>rst;//����pair���͵ı���
	for(int i=0;i<10;i++){
		cin>>x;
		rst=s.insert(x);//��set���������
		if(rst.second==true) cout<<x<<" YES"<<endl;
		else cout<<x<<"NO"<<endl;
	} 
	for(it=s.begin();it!=s.end();it++) cout<<*it<<" ";
	cout<<endl;
	return 0;
}
