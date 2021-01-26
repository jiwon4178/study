#include <iostream>
#define MAX(x, y) x > y ? x : y


struct node {
	struct node* left;
	int key;
	struct node* right;
};


node* TreeInit(int firstkey) {
	struct node* head;
	head = (struct node*)malloc(sizeof * head);
	//left�� right node�� �������.
	head->left = NULL;
	head->right = NULL;
	head->key = firstkey;
	return head;
}


//���� ���� Ž�� �˰���
struct node* TreeSearch(struct node* head, int xkey) {
	struct node* t;
	t = head;
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

//����Ʈ�� ��� �˰���
void printTree(struct node* head,struct node* p, int level)
{
	struct node* t;
	t = p;
	int i; 
	// ���� Ʈ���� ������� ���� ����Դϴ�.
	if (t != NULL)
	{
		printTree(head, t->right, level + 1);
		printf("\n");
		// ���� ��Ʈ ����� ����Դϴ�.
		if (t == head)
		{
			std::cout << "Root -> ";
		}
		// i�� ���������� ���� ��Ʈ�� �ƴ� ����� ������ �Դϴ�.
		for (i = 0; i < level && t != head; i++)
		{
			std::cout << "        ";
		}
		// �ڽ��� ��ġ�� �����͸� ����մϴ�.
		std::cout << t->key;
		// ���� ��嵵 ������ݴϴ�.
		printTree(head, t->left, level + 1);
	}
	else {
		return;
	}
}


//����Ʈ�� ���� �˰���
void TreeDelete(struct node* head, int xkey) {
	struct node* p, * c, * t, * x;
	p = head;
	x = TreeSearch(head, xkey);
	if (x == NULL) {
		std::cout << "\n������ ���ڰ� Ʈ���� �������� �ʽ��ϴ�. " << std::endl;
		return;
	}
	else {
		t = x;
	}
	
	if (t->right == NULL) {//����  �ڽĸ� ����
		x->key = t->left->key;
		free(t->left);
		t->left = NULL;
		return;
	}
	else if (t->right->left == NULL){//������ �ڽ� ���� + ������ �ڽ��� ���� �ڽ� ����
		x->key = t->right->key;//�� �Űܿ�
		x->right = t->right->right;
		free(t->right);
		t->right = NULL;
		return;
	}
	else {
		c = x->right;
		while (c->left->left != NULL) {
			c = c->left;
		}
		x->key = c->left->key;//�� �Űܿ�
		t = c->left;
		c->left = c->left->right;
		free(t);
		t = NULL;
		return;
	}
	free(t);
	t=NULL;
	return;
}

void main() {

	int num;
	std::cout << "�����Է�: ";
	std::cin >> num;
	struct node* head;
	head = (struct node*)malloc(sizeof * head);
	head = TreeInit(num);
	int tmp = 1;
	while (1) {
		printTree(head,head,1);
		std::cout << "\n\n���� : 1   ���� : 2    >> ";
		std::cin >> tmp;
		if (tmp == 1) {
			std::cout << "\n ������ ���� �Է�: ";
			std::cin >> num;
			TreeInsert(head, num);
		}
		else if (tmp == 2) {
			std::cout << "\n ������ ���� �Է� : ";
			std::cin >> num;
			TreeDelete(head, num);
		}
	}

}