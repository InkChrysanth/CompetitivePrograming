#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
vector<vector<int> >a;
int main(){
	int i,j,M,k,x,y,z;
	cin>>M>>k;//kΪԪ�ظ�����MΪ�еĸ��� 
	a.resize(M+1); //��ʼ����ռ� 
	for(vector<vector<int> >::iterator it=a.begin();it!=a.end();++it) (*it).resize(k/M+1);
	//��ʼ����ÿһ��һά����Ŀռ� 
	for(i=1;i<=k;i++){
			cin>>x>>y>>z;
			a[y][++a[y][0]]=z; //a[y][0]�������y�е�Ԫ�ظ��� 
		}
	for(i=1;i<=M;i++){
		for(j=1;j<=a[i][0];j++)
		cout<<a[i][j]<<" ";
	}
	return 0;
}
