/*
������ʵ�������ĺϲ� 
pc->next=pa?pa:pb;
if(pa)
   pc->next=pa;
else
   pc->next=pb;
delete lb;    //�ͷ�Lb��ͷ��� 
*/
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	pa=La->next ;pb=Lb->next; //pa,pbָ��ֱ�ָ�����������Ԫ��ַ 
	pc=Lc=La; //��La��ͷ�����ΪLc��ͷ���
	while(pa&& pb) {
		if(pa->data<=pb->data) {
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb; //����ʣ��� (pa=NULL�Ļ� pc->next=pb;pb=NULL�Ļ�pc->next=pa; 
	delete Lb; //�ͷ�Lb��ͷ��� 
	 
}
