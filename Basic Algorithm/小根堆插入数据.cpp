//�������ǲ��ȶ����� 
//priority_queue<int>que//��������
//priority_queue<int ,vector<int> ,greater<int> >que С���� 
void put(int x){ //С���ѵ����ݲ��� 
	int p;
	len++;
	heap[len]=x;
	p=len;
	while(p!=1 && heap[p/2])>heap[p])
	{
		swap(heap[p],heap[p/2]);
		p/=2;
	}
}

int get(){ //ȡ�����
    int x=heap[1] ,p,q;//�Ѹ�����ֵ��������x����; 
    heap[1]=heap[len];len--;p=1; //�����һ����㸳������㣬���鳤�ȼ�1 
    while(p*2<=len){ // ��p���к��ӵ�ʱ�� 
    	if(p*2+1>len ||heap[p*2]<heap[p*2+1]) //��Pû���Һ��ӻ������ӵ�ֵС���Һ���
		     q=p*2;//ѡ���� 
		else
		     q=p*2+1; //ѡ�Һ��� 
	    if(heap[q]<heap[p])	{ //�������ӽ��󣬽���ֵ 
	    	swap(heap[p],heap[q]);
	    	p=q; //��q����p 
		}
		else 
		      return x; //�Ѿ�����С���Ѷ����˳�����	    
	}
    return x; //���ظ����	
}


