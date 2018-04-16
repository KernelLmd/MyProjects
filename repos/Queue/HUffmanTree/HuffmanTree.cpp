#include <queue>
#include <stdio.h>
#include <functional>

using namespace std;

priority_queue <int, vector<int>, greater<int> > Q;
//����һ��С����
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (Q.empty() == false) Q.pop(); 
		//��ն���Ԫ��
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			Q.push(x);
			//��Ȩֵ�������
		}
		int ans = 0;
		//�����
		while (Q.size() > 1) {
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();

			ans += a + b;
			Q.push(a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}