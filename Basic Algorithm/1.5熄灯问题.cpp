#include<bits/stdc++.h>
using namespace std;
char oriLights[5]; //��������ԭʼ�ĵƾ��� 
char lights[5];    //��ŵƱ仯�еĵľ��� 
char result[5];   //���յĿ��ؽ�� 
int GetBit(char c,int i){ //ȡ��iλ�ı���ֵ0��1 
	return (c>>i) &1;
}
void SetBit(char &c,int i ,int v){//�ı�iλ��״̬��v 
	if(v){
		c|=(1<<i);
	}
	else 
	    c&=~(1<<i);
}
void FlipBit(char &c,int i) //��״̬�ķ�ת
{
	c^=(1<<i);
 } 
void OutputResult(int t,char result[]){//������ؾ��� 
	cout<<"PUZZLE #"<<t<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cout<<GetBit(result[i],j);
			if(j<5) cout<<" ";			
		}
		cout<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		for(int i=0;i<5;i++)
		   for(int j=0;j<6;j++){
		   	int s;
		   	cin>>s;
		   	SetBit(oriLights[i],j,s);
		   }
	    for(int n=0;n<64;n++){ //���64��״̬ 
		   int switchs=n; //һ��6յ����2^6��״̬��� 
		    memcpy(lights,oriLights,sizeof(oriLights));
		    for(int i=0;i<5;i++){
		    	result[i]=switchs;
			    for(int j=0;j<6;j++){
				   if(GetBit(switchs,j)){
					   if(j>0) 
					        FlipBit(lights[i],j-1);
					    FlipBit(lights[i],j)  ;
					    if(j<5)    
					      FlipBit(lights[i],j+1);
				    }
			    }
			if(i<4) //������һ�еĵƵ�״̬ 
			      lights[i+1]^=switchs;
			switchs=lights[i] ;//��һ�е�״̬    
		}
		if(lights[4]==0){ //���һ�ж������ 
		    OutputResult( t, result);
			break;
		}
	}	   
	}
	return 0;
}
