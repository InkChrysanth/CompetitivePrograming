/*
���Ա� 
*/
#include<bits/stdc++.h> 
using namespace std;
#define LS 1000
typedef struct{
	float p;
	int e;
}Polynomial;
typedef struct{
	Polynomial *elem; //�洢�ռ�Ļ���ַ 
	int length; //����ʽ�е�ǰ��ĸ��� 
}SqList; //����ʽ��˳��洢�ṹ����ΪSqList 
int main(){
	SqList L;//�������L,L��SqList�������͵ģ�L��˳��� 
	 L.elem[0].e=7;
	 L.elem[0].p=1;
	return 0;
}
