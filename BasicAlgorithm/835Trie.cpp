/*
Trie�����ٴ洢���ҵ��� 
5
I abc
Q abc
Q ab
I ab
Q ab
*/
#include<bits/stdc++.h> 
using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx;//idx��ÿһ�����ı�� 
char str[N];
void insert( char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a'; //��a-zӳ�䵽0-25 
		if(!son[p][u]) son[p][u]=++idx; //û�оʹ������о��ߵ���֧ 
		p=son[p][u];
	}
	cnt[p]++;//ͳ��������ʳ��ֵĴ��� 
}
int  query(char str[]){
	int p=0;
	for(int i=0;str[i];i++){
		int u=str[i]-'a';
		if(!son[p][u]) return 0;
		p=son[p][u]; //���������� 
	}
	return cnt[p]; //�ҵ�β������ʵĸ��� 
}
int main(){
	int n;
	cin.tie(0);
	cin>>n;
	while(n--){
		char str1,str2[N];
		cin>>str1>>str2;
		if(str1=='I') insert(str2);
		if(str1=='Q') cout<<query(str2)<<endl;
	}
	return 0;
}
