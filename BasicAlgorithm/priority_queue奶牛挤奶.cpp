/*
5
1 10
2 4
3 6
5 8
4 7
��� 4 
friend bool operator �����������Ԫ���������ص���boolֵoperator���������������
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct cow{
	int start,over;
	 friend bool operator < ( const cow a, const cow b ){
		return  a.over>b.over; //ʵ�ֽṹ��С���ѵ����� 
	}
}c[maxn];
priority_queue<cow>q; //�ṹ������ȶ��� 
int read(){ //���ٶ�ȡ 
	int s=0,f=1;char c=getchar();
	while(c<'0' || c>'9') if(c=='-') f=-1,c=getchar();
	while(c>='0' &&c<='9') s=(s<<3)+(s<<1)+c^48,c=getchar();
	return s*f;
}
bool cmp(cow a,cow b){
	return a.start<b.start;
}
int ans=0;
int main(){
	int n=read();
	for(int i=1;i<=n;i++) c[i].start=read(),c[i].over=read();
	sort(c+1,c+n+1,cmp); //������ʱ��������� 
	int ans=1;
	q.push(c[1]);
	for(int i=2;i<=n;i++){
		cow x=q.top();
		if(c[i].start>x.over){ //���Է���һ��ţ�� 
			q.pop(); //ԭ�ȵĵ��� 
			q.push(c[i]);//�����µģ�
		}
		else{
			ans++; 
			q.push(c[i]);
		}		
	}
	cout<<ans;
	return 0;
}
