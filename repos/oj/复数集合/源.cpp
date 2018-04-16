#include <queue>
#include <stdio.h>
#include <iostream>
#include <cmath> //hypot���ÿ�
#include <string>
using namespace std;

struct complex
{
	int real;
	int imag;
	double abs;//��ģ

	complex(int r, int i) {
		real = r;
		imag = i;
		abs = hypot(r, i); //��ģ
	}

	bool operator< (const complex & rhs) const {
		return this->abs < rhs.abs;
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		priority_queue <complex> maxheap;
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (str.compare("Pop") == 0) {
				if (maxheap.empty()) {
					cout << "empty" << endl;
				}
				else
				{
					struct complex tmp = maxheap.top();
					cout << tmp.real << '+' << 'i' << tmp.imag << endl;
				    //Ҳ����д��printf("%d+i%d", x, y);
					maxheap.pop();
					cout << "SIZE = " << maxheap.size() << endl;
				}
			}
			else {
				//���Զ������ֺ��ַ����������
				int real, imag;
				char i, plus;
				scanf("%d%c%c%d", &real, &i, &plus, &imag);
				//�������ַ�������ʽ���룬
				//Ҳ����д��scanf("%d+i%d%*c", &x, &y)
				complex tmp(real, imag);
				maxheap.push(tmp);

				cout << "SIZE = " 
					<< maxheap.size() << endl;
			}
		}
	}
	return 0;
}