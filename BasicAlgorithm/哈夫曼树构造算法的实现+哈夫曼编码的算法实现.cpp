/*
�������������㷨��ʵ�� 
T[s1].parent=i;T[s2].parent=i;
T[i].lch=s1;T[i].rch=s2;
T[i].weight=T[s1].weight+T[s2].weight;
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int visit=0x7f;
struct node{
	int weight,weight1;//weight1��������ֵ��weight�������򣬳�ʼֵһ�� 
	int parent,lch,rch,id;
	friend bool operator < ( const node a, const node b ){
		if(a.weight==b.weight) 
		    return a.weight1>b.weight1; //
		else 
		    return  a.weight>b.weight; //ʵ�ֽṹ��С���ѵ����� 
	}
};

priority_queue<node >T;
node p[maxn];
char HC[maxn][10];//����������� 
int n;
void CreatHuffman(string &HC[]){ //�����������	
	for(int i=1;i<=n;i++){
		char cd[n];
		cd[n-1]='\0';
		int start=n-1,c=i,f=p[i].parent;
		while(f!=0){
			start--;
			if(p[f].lch==c) cd[start]='0';
			else cd[start]='1';
			c=f,f=p[f].parent;
		}
		strcpy(HC[i],cd);
	}	
}
int main(){

	cin>>n;
	int m=2*n-1;
	int a,i=0;	
	while(n--){
		cin>>a;
		i++;
		p[i].weight=p[i].weight1=a;
		p[i].id=i;
		p[i].parent=p[i].rch=p[i].lch=0;
		T.push(p[i]);
	}
	while(i!=m){
		node p1,p2;
		p1=T.top();
		T.pop();
		p2=T.top();
		T.pop();
		p[++i].lch=p1.id;
		p[i].rch=p2.id;
		p[i].id=i;
		p[i].weight=p[i].weight1=p1.weight1+p2.weight1;
		p[p1.id].parent=p[p2.id].parent=i;//�����Һ��ӽ��ĸ���ָ�������ɵĽ�� 
		p1.weight=p2.weight=visit; //���Ѿ��и����Ѿ����ϲ���weight��һ���ǳ����ֵ�����ź���ȥ 
		T.push(p1);
		T.push(p2);
		T.push(p[i]);
	}
	node p1;
//	p1=T.top();
//	T.pop();
//	p1.weight=visit;
//	T.push(p1);
	for(int k=1;k<=i;k++){
		cout<<p[k].weight1<<" "<<p[k].id<<" "<<p[k].parent<<" "<<p[k].rch<<" "<<p[k].lch<<endl;
	}
	p1=T.top();
	    cout<<p1.weight1<<" "<<p1.id<<" "<<p1.parent<<" "<<p1.rch<<" "<<p1.lch<<endl;	
    CreatHuffman(HC)	;
	for(int i=1;i<=n;i++) cout<<HC[i]<<"  ";	
	return 0;
}
