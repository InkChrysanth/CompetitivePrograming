/*
�ַ���s��char s1[]������ 
���룺�ַ���getline(cin,s)�ַ�����gets(s);
�󳤶ȣ��ַ���s.length(),s.size();
        �ַ�����strlen(s1), 
isalpha(ch) ch����ĸ������true����false
ispunct(ch) ch�Ǳ����ţ������֡���ĸ��հ��ַ�������ַ���������true���� false
isspace(ch) ch�ǿհ��ַ�������true���� false 
isdigit(ch) ch�����֣�����true���� false
islower(ch) ch��Сд��ĸ������true���� false
isupper(ch) ch�Ǵ�д��ĸ������true���� false 
     
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
string s;
char s1[maxn];
int main(){
	getline(cin,s); //�ַ������� 
	gets(s1);       //�ַ��������� 
	int y=strlen(s1); //�ַ����� 
	int p=sizeof(s1); //������ 
	int z=s.length();	//�ַ��� 
	int x=s.size();
	cout<<x<<" "<<z<<endl;
	cout<<y<<" "<<p<<endl;
	s.push_back('a');
	x=s.size();
	cout<<x<<endl;
	return 0;
}
