#include <stdio.h>
#include <algorithm>
using namespace std;

struct goods  //��ʾ������Ʒ�Ľṹ��
{
	double j; //����Ʒ����
	double f; //����Ʒ�ܼ�ֵ
	double s; //����Ʒ�Լ۱�
	bool operator < (const goods &A) const {
		//����С�������
		return s > A.s;
	}
};

struct goods buf[1000];

int main() {
	double m;
	int n;
	while (scanf("%lf%d", &m, &n) != EOF) {
		if (m == -1 && n == -1) break;

		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &buf[i].j, &buf[i].f); //����
			buf[i].s = buf[i].j / buf[i].f; //�����Լ۱�

		}

		sort(buf, buf + n);

		int idx = 0;
        //��ǰ�����±�
		double ans = 0;
		//�ۼ����õ�������
		while (m > 0 && idx < n) {
			/*
			ѭ������Ϊ����Ʒʣ�ࣨidx < n����
			����Ǯʣ�ࣨm > 0��ʱ����ѭ��
			*/
			if (m > buf[idx].f) {
				ans += buf[idx].j;
				m -= buf[idx].f;

			}
			else {
				ans += buf[idx].j * m / buf[idx].f;
				m = 0;
			}

			idx++;
		}

		printf("%.3lf\n", ans);
	}

	return 0;
}