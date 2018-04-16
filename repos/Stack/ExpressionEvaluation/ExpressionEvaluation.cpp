#include <stack>
#include <stdio.h>

using namespace std;

char str[220];
int mat[][5] = {
	/*
	���ȼ�������mat[i][j] == 1,���ʾi���������ȼ�
	����j���������������������Ϊ+Ϊ1�ţ�-Ϊ2�ţ�*Ϊ
	3�ţ�/Ϊ4�ţ�������Ϊ����ڱ��ʽ��β�ı�������Ϊ
	0��
	*/
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 1, 1, 0, 0,
	1, 1, 1, 0, 0,
};

stack<int> op; //�����ջ��������������
stack<double> in;
//����ջ�����������ܴ��ڸ����������Ա���Ԫ��Ϊdouble

void getOp(bool &reto, int &retn, int &i) {
	/*
	��ñ��ʽ����һ��Ԫ�غ��������������н���ʱ��
	���ñ���retoΪtrue�����ʾ��Ԫ��Ϊһ���������
	���ű��������ñ���retn�У����򣬱�ʾ��Ԫ��Ϊ
	һ�����֣���ֵ���������ñ���retn�У����ñ���i
	��ʾ����
	*/
	if (i == 0 && op.empty() == true) {
		reto = true; //
		retn = 0;
		return;
	}

	if (str[i] >= '0' && str[i] <= '9') {
		reto = false; //
	}

	else {
		reto = true;
		if (str[i] == '+') {
			retn = 1;
		}
		else if (str[i] == '-') {
			retn = 2;
		}
		else if (str[i] == '*') {
			retn = 3;
		}
		else if (str[i] == '/') {
			retn = 4;
		}

		i += 2;
		return;
	}
	retn = 0;
	for (; str[i] != ' ' && str[i] != 0; i++) {
		retn *= 10;
		retn += str[i] - '0';

	}
	if (str[i] == ' ') i++;
	return;

}

int main() {
	while (scanf("%s", str)) {
		if (str[0] == '0' && str[1] == 0) break;
		bool retop; int retnum;
		int idx = 0;
		while (!op.empty()) op.pop();
		while (!in.empty()) in.pop();
		while (true) {
			getOp(retop, retnum, idx);
			if (retop == false) {
				in.push((double)retnum);

			}
			else {
				double tmp;
				if (op.empty() == true ||
					mat[retnum][op.top()] == 1) {
					op.push(retnum);
				}
				else {
					while (mat[retnum][op.top()] == 0) {
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						if (ret == 1) tmp = a + b;
						else if (ret == 2) tmp = a - b;
						else if (ret == 3) tmp = a * b;
						else tmp = a / b;
						in.push(tmp);

					}
					op.push(retnum);

				}
			}
			if (op.size() == 2 && op.top() == 0) break;

		}
		printf("%.2f\n", in.top());
	} //while 
	return 0;
} //main 