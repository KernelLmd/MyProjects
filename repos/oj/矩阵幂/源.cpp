#include <stdio.h>

int main() {
	int t, n, k;
	int a[11][11];
	int b[11][11];
	int c[11][11];

	while (scanf("%d%d", &n, &k) != EOF)
	{
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				b[i][j] = a[i][j];

			}
		}

		k--;

		while (k--) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					c[i][j] = 0;
					for (int m = 0; m < n; m++) {
						c[i][j] = c[i][j] + a[i][m] * b[m][j];
					} //��������
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					b[i][j] = c[i][j];
				} //��д��b������
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				printf("%d ", b[i][j]);
			}
			printf("%d\n", b[i][n - 1]);
		} //ע�������������пո�

	}
	return 0;
}