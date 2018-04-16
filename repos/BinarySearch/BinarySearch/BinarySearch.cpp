#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Student {
	//���ڱ�ʾѧ������Ľṹ��
	char no[100]; //ѧ��
	char name[100]; //����
	int age; //����
	char sex[5]; //�Ա�
	bool operator < (const Student & A) const {
		//����<�����
		return strcmp(no, A.no) < 0;
	}
};

struct Student buf[1000];

int main(int argc, char** argv) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%d", &buf[i].no, &buf[i].name,
				&buf[i].sex, &buf[i].age);
		} //��������

		sort(buf, buf + n); //����������ʹ�䰴ѧ����������

		int m;
		scanf("%d", &m); //��m��ѯ��

		while (m-- != 0) { //��֤��ѯ����Ϊm 
			int ans = -1; //Ŀ��Ԫ���±꣬��ʼ��Ϊ-1
			char x[30];
			scanf("%s", x); //������ѧ��
			int top = n - 1, base = 0;
			//��ʼʱ����ʼ�±�0�������±�n-1�������Ӽ�Ϊ��������
			while (top >= base) {
				//�����Ӽ�����ʱ�ظ����ֲ���
				int mid = (top + base) / 2;
				//�����м���±�
				int tmp = strcmp(buf[mid].no, x);
				//�Ƚ��м��ѧ����Ŀ��ѧ�� 
				if (tmp == 0) {
					ans = mid;
					break;
					//����ȣ��������ɣ��������ֲ��� 
				}
				else if (tmp > 0) top = mid - 1;
				//�����ڣ�������±��Ϊ�м��ǰһ�����±� 
				else base = mid + 1;
				//��С�ڣ���ʼ���±��Ϊ�м���һ�������� 

			} //while

			if (ans == -1) {
				printf("No Answer!\n");
			}
			else printf("%s %s %s %d\n", buf[ans].no, buf[ans].name,
				buf[ans].sex, buf[ans].age);
		} //while  
	} //while 
	return 0;
}