/*
8 3
1 3 -1 -3 5 3 6 7
���
 -1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int n,k;
int a[N],q[N];
int main(){
	cin.tie(0);
	cin>>n>>k;
	int hh=0,tt=-1;
	for(int i=0;i<n;i++)cin>>a[i];	
	for(int i=0;i<n;i++){ //�������Ӧ�±��a���������Ե��� 
		if(hh<=tt && q[hh]<i-k+1) hh++;//�Ѷ��������k���䷶Χ��ǰ�����ȥ�� 
		while(hh<=tt &&a[q[tt]]>=a[i]) tt--; //�Ѷ���ǰ���a[i]�������ȥ,a[hh]ʼ�մ����Сֵ 
		q[++tt]=i; //���뵱ǰ��� 
		if(i>=k-1) cout<<a[q[hh]]<<" ";//���ﵽһ�����䷶Χ��ÿ��һ���������һ����Сֵ 
	}
	cout<<endl;
	hh=0;tt=-1;
	for(int i=0;i<n;i++){ //�������Ӧ�±��a���������Եݼ�
		if(hh<=tt && q[hh]<i-k+1) hh++;
		while(hh<=tt &&a[q[tt]]<=a[i]) tt--;
		q[++tt]=i;
		if(i>=k-1) cout<<a[q[hh]]<<" ";
	}
	cout<<endl;
}

