#include<stdio.h> 
/*
scanf�����ǿ����������볤�ȵģ���scanf("%s",a)����д��
û��ʹ���������ƹ��ܣ������ǲ�����ַ������ȣ�C/C++Ҳ��
���������Խ��ġ���ֹ����Խ���������ȫ�ɳ���Ա���Ȱ���
��ɣ�Խ���˾ͻ����������Σ�պ��������������Ǿ��Բ���
����ġ�����Ϊ������顱����Խ���������ʱ����Խ�粿��û��
�ܵ����������š����������ȻҲ�ܡ�����������
*/
int main()
{
	char a[5], b[5];
	int i;
	printf("Input the value of a and b:");
	while (scanf("%s%s", a, b) != EOF)
	{
		printf("a=%s,b=%s\n", a, b);
		for (i = 0; i<5; i++)
			printf("%d:(%c) ", a[i], a[i]);
		printf("\n");
		for (i = 0; i<5; i++)
			printf("%d:(%c) ", b[i], b[i]);
		printf("\n");
		printf("Input the value of a and b:");
	}
	return 0;
}