/*N�ʺ����� 
*/
#include<bits/stdc++.h>
using namespace std;
int N,Z;
int queenPos[1005] ;
void NQueen(int k){
	int i;
	if(k==N) { //��0~k-1�лʺ��Ѿ��ںõ�����£��ڵ�k�м����Ļʺ� 
	    Z++;
		for(i=0;i<N;i++) cout<<queenPos[i]+1<<" ";
		cout<<endl;
		return ;
	}
	for(i=0;i<N;i++){//���Ե�k���ʺ��λ�� 
		int j;
		for(j=0;j<k;j++){ //���Ѿ��ںõ�k���ʺ��λ�ñȽϣ����Ƿ��ͻ 
			if(queenPos[j]==i || abs(queenPos[j]-i)==abs(k-j)) break;
		}
		if(j==k) { //��ǰѡ��λ�ò���ͻ 
		   queenPos[k]=i; //����k���ʺ�ڷ���λ��i 
		   NQueen(k+1);
	    }
	
	}
}
int main(){
	cin>>N;
	NQueen(0);
	cout<<Z;
	return 0;
	
}
