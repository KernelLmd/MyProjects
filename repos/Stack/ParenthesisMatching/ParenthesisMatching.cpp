#include <stdio.h>
#include <stack>

using namespace std;

stack<int> S; //����һ����ջ
char str[110]; //���������ַ���
char ans[110]; //��������ַ���

int main() {
	while (scanf("%s", str) != EOF) {
		//�����ַ���
		int i;
		for (i = 0; str[i] != 0; i++) {
			if (str[i] == '(') {
				//������������
				S.push(i);
				//���������±�����ջ��
				ans[i] = ' ';
				//����Ӧ������ַ���λ�ø�Ϊ�ո�

			}
			else if (str[i] == ')') {
				//������������
				if (S.empty() == false) {
					S.pop();
					ans[i] = ' ';
					//����и�λ��Ϊ�ո�
				}
				else ans[i] = '?';
				/*
				����ջΪ�գ����޷��ҵ�����������ƥ��,
				�޸����λ��Ϊ��
				*/
			}
			else ans[i] = ' ';

		}
		while (!S.empty()) {
			ans[S.top()] = '$';
			S.pop();
		} //while
		ans[i] = 0;
		puts(str);
		puts(ans);
	} //while
	return 0;
} //main