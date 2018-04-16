#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

int main()
{
	char a[101];
	char b[101];
	char ch;
	int lena, lenb, flag;
	int count[11];


	while (scanf("%s", a) != EOF)
	{
		//���ջس���  
		//ch = getchar();
		//���ճ���  
		scanf("%s", b);
		//ch = getchar();
		//����  
		lena = strlen(a);
		lenb = strlen(b);
		//��ʼ��  
		memset(count, 0, sizeof(count));
		//��������  
		for (int i = 0; i < lena; i++)
		{
			count[a[i] - '0'] ++;
		}
		//���Է�����  
		switch (lenb)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			flag = 0;
			for (int key = b[0] - '0'; key <= 9; key++)
				//char key = b[0] - '0' + 1
			{
				if (count[key] >= lenb)
				{
					flag = 1;
					break;
				}
			}
			break;
		case 5:
			flag = 0;
			for (int key = b[0] - '0'; key <= 9; key++)
			{
				if (count[key] > 0 && 
					count[key + 1] > 0 && 
					count[key + 2] > 0 && 
					count[key + 3] > 0 && 
					count[key + 4] > 0)
				{
					flag = 1;
					break;
				}
			}
			break;
		}
		//��ӡ���  
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}