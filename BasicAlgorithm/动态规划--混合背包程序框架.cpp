/*
for i=1...n//n����Ʒ
   for j=0...v //���v
       if ��i����Ʒֻ��1����01������
	       f[i][j]=max{f[i-1][j],f[i-1][j-v[i]]+w[i]} 
	    else if ��i����Ʒ�����������ȫ������
		    f[i][j]=max{f[i-1][j],f[i][j-v[i]]+w[i]}
	    else  (���ر�����
		  f[i][j]=max{f[i-1][j],f[i][j-k*v[i]]+k*w[i]}		 kΪ��i����Ʒ�ĸ��� 
*/
