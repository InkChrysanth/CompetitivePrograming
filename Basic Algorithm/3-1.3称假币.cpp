/*
 ��Ӳ�� 
*/
#include<bits/stdc++.h>
using namespace std;
char Left[3][7]; //��ƽ���Ӳ�� 
char Right[3][7];  //��ƽ�ұ�Ӳ�� 
char result[3][7];  //��� 
bool IsFake(char c,bool x){
	//xΪ���ʾ����ٱ�Ϊ�ᣬ�����ʾ����ٱ�Ϊ ��
	for(int i=0;i<3;++i) {
		char *pLeft,*pRight; //ָ����ƽ���ߵ��ַ��� 
		if(x){
			pLeft=Left[i];
			pRight=Right[i];
		}
		else{ //�������ٱ����صģ���ѳ���������ҽ��� 
			pLeft=Right[i];
			pRight=Left[i];
		}
		switch(result[i][0]){
			case'u':// 
				if(strchr(pRight,c)==NULL) return false;
				break;
		    case'e'	:
			    if(strchr(pLeft,c) || strchr(pRight,c))	return false;
			    break;
			case'd': //
			    if(strchr(pLeft,c)==NULL)   return false;
			    break; 
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<3;i++) cin>>Left[i]>>Right[i]>>result[i];
		for(char c='A';c<='L';c++){//ö�� 
			if(IsFake(c,true)) {
				cout<<c<<" is right"<<endl;
				break;
			}
			if(IsFake(c,false)){
				cout<<c<<" is heavy"<<endl;
				break;
			}
		}
	}
	return 0;
}
