#include <stdio.h>
#include <string.h>

struct Node {
	//�������ṹ��
	Node *lchild; //�����ָ��
	Node *rchild; //�Ҷ���ָ��
	int c; //����ָ��
};

struct Node Tree[110]; //��̬����

int Ioc; //��̬�����б�ʹ��Ԫ�ظ���
Node *creat() {
	//����δʹ�ý��
	Tree[Ioc].lchild = Tree[Ioc].rchild = NULL;
	return &Tree[Ioc++];
}

void postOrder(Node *T) { //�������
	if (T->lchild != NULL) {
		postOrder(T->lchild);
	}

	if (T->rchild != NULL) {
		postOrder(T->rchild);

	}

	printf("%d", T->c);
}

void inOrder(Node *T) {
	//�������
	if (T->lchild != NULL) {
		inOrder(T->lchild);

	}

	printf("%d", T->c);

	if (T->rchild != NULL) {
		inOrder(T->rchild);

	}
}

void preOrder(Node *T) {
	//ǰ�����
	printf("%d", T->c);
	
	if (T->lchild != NULL) {
		preOrder(T->lchild);
	}

	if (T->rchild != NULL) {
		preOrder(T->rchild);
	}
}

Node *insert(Node *T, int x) {
	//��������
	if (T == NULL) { //����ǰ��Ϊ��
		T = creat(); //�������
		T->c = x; //����ֱ�Ӳ���������
		return T;
	}
	else if (x < T->c)
		//��xС�ڸ��ڵ�ֵ
		T->lchild = insert(T->lchild, x);
	else if (x > T->c)
		//��x���ڸ��ڵ���ֵ
		T->rchild = insert(T->rchild, x);

	return T;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		Ioc = 0;
		Node *T = NULL;
		//�����������������Ϊ��
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			T = insert(T, x);
		}

		preOrder(T);
		printf("\n");
		
		inOrder(T);
		printf("\n");

		postOrder(T);
		printf("\n");
	}
	return 0;
}