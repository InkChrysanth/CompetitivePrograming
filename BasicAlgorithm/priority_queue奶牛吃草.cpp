/*
5
25 3
105 30
20 50
10 17
100 10
shuchu 10
��һ��Ϊ��ţ����ʱ�䣬�ڶ���Ϊ��ţ�Բ�ʱ�䣬�����Щ��ţ�ȴ������ʱ��
�ȴ������б��С����ţ������Ȩ 
friend bool operator �����������Ԫ���������ص���boolֵoperator���������������
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct cow{
	int start,over,z;
	 friend bool operator < ( const cow a, const cow b ){
		return  a.z>b.z; //ʵ�ֽṹ��С���ѵ����� 
	} 
}c[maxn];
priority_queue<cow>q; //�ṹ������ȶ��� 
int read(){ //���ٶ�ȡ 
	int s=0,f=1;char c=getchar();
	while(c<'0' || c>'9') if(c=='-') f=-1,c=getchar();
	while(c>='0' &&c<='9') s=s*10+c-'0',c=getchar();
	return s*f;
}
bool cmp(cow a,cow b){
	return a.start<b.start;
}
int ans=0;
int main(){
	int n=read();
	for(int i=1;i<=n;i++) c[i].start=read(),c[i].over=read(),c[i].z=i;
	sort(c+1,c+n+1,cmp); //������ʱ��������� 
	q.push(c[1]);
	int ans=c[1].start;
	int cnt=2;
	int now=c[1].start+c[1].over;
	while(cnt<=n ||!q.empty()){
		if(q.empty()){
			q.push(c[cnt]);
			now=c[cnt].start+c[cnt].over;
			cnt++;
		}		
		while(c[cnt].start<=now &&cnt<=n ){
			q.push(c[cnt]);
			cnt++;
		}
		q.pop();
		cow f=q.top();		
		ans=max(ans,now-f.start);		
		now=f.start+f.over;
	}
	cout<<ans<<endl;;
	return 0;
}
