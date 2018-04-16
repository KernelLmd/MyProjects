#include <stdio.h>
#include <algorithm>

using namespace std;

struct program {
	//���ӽ�Ŀ�ṹ��
	int startTime;
	//��Ŀ��ʼʱ��
	int endTime;
	//��Ŀ����ʱ��
	bool operator < (const program &A) const {
		//���ս���ʱ����������
		return endTime < A.endTime;
	}
};

struct program buf[100];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &buf[i].startTime, 
				          &buf[i].endTime);
		}
		
		sort(buf, buf + n);

		int currentTime = 0, ans = 0;
		//��¼��ǰʱ������ĳ�ʼֵ0
		for (int i = 0; i < n; i++) {
			if (currentTime <= buf[i].startTime) {
				currentTime = buf[i].endTime;
				//��ǰʱ���Ϊ�ý�Ŀ����ʱ��
				ans++;

			}
		}

		printf("%d\n", ans); //���
	}

	return 0;
}