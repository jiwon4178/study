#include <iostream>
#define MAX(x, y) x > y ? x : y

struct node {
	struct node* left;
	int key;
	struct node* right;
};


void TreeInit(int firstkey) {
	struct node* t, * head;
	head = (struct node*)malloc(sizeof * head);
	//left�� right node�� �������.
	head->left = NULL;
	head->right = NULL;
	head->key = firstkey;
}


//���� ���� Ž�� �˰���
struct node* TreeSearch(struct node* head, int xkey) {
	struct node* t;
	t = head->right;
	while (t != NULL) {
		if (xkey == t->key)	//head���� key������ ��
			return t;
		else if (xkey < t->key) {	//head 
			t = t->left;
		}
		else if (xkey > t->key) {
			t = t->right;
		}
	}
	return NULL;
}


//���� ���� ���� �˰���
void TreeInsert(struct node* head, int xkey) {
	struct node* p, * t;
	if (p == NULL) {

	}
	p = head; t = p; 
	while (t != NULL) {
		p = t;
		if (xkey == t->key) {	//���� Ű�� �̹� ����
			return;
		} 
		else if (xkey < t->key) {  //xkey���� ������ ���ʳ��� ����
			t = t->left;
		}
		else if (xkey > t->key) {	//xkey���� ũ�� �����ʳ��� ����
			t = t->right;
		}
	}
	//while���� ������ xkey���� ��ġ�� ������
	t = (struct node*)malloc(sizeof * t);	// xkey�� �� ���ο� ��� ����
	t->key = xkey;
	t->left = NULL;
	t->right = NULL;

	//xkey�� ũ�⿡ ���� ���ʳ�� Ȥ�� ������ ��忡 ����
	if (xkey < p->key) {
		p->left = t;
	}
	else {
		p->right = t;
	}

}


void TreeDelete(struct node* head, int xkey) {

}
void main() {


}