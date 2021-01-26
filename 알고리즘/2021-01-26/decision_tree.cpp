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
	//left랑 right node는 비어있음.
	head->left = NULL;
	head->right = NULL;
	head->key = firstkey;
	return head;
}


//이진 나무 탐색 알고리즘
struct node* TreeSearch(struct node* head, int xkey) {
	struct node* t;
	t = head;
	while (t != NULL) {
		if (xkey == t->key)	//head노드랑 key같으면 끝
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


//이진 나무 삽입 알고리즘
void TreeInsert(struct node* head, int xkey) {
	struct node* p, * t;
	p = head; t = p; 
	while (t != NULL) {
		p = t;
		if (xkey == t->key) {	//동일 키값 이미 존재
			return;
		} 
		else if (xkey < t->key) {  //xkey값이 작으면 왼쪽노드로 보냄
			t = t->left;
		}
		else if (xkey > t->key) {	//xkey값이 크면 오른쪽노드로 보냄
			t = t->right;
		}
	}
	//while문이 끝나면 xkey값의 위치가 정해짐
	t = (struct node*)malloc(sizeof * t);	// xkey가 들어갈 새로운 노드 생성
	t->key = xkey;
	t->left = NULL;
	t->right = NULL;

	//xkey의 크기에 따라 왼쪽노드 혹은 오른쪽 노드에 연결
	if (xkey < p->key) {
		p->left = t;
	}
	else {
		p->right = t;
	}

}

//이진트리 출력 알고리즘
void printTree(struct node* head,struct node* p, int level)
{
	struct node* t;
	t = p;
	int i; 
	// 현재 트리가 비어있지 않은 경우입니다.
	if (t != NULL)
	{
		printTree(head, t->right, level + 1);
		printf("\n");
		// 현재 루트 노드인 경우입니다.
		if (t == head)
		{
			std::cout << "Root -> ";
		}
		// i가 현레벨보다 낮고 루트가 아닌 경우일 때까지 입니다.
		for (i = 0; i < level && t != head; i++)
		{
			std::cout << "        ";
		}
		// 자신의 위치에 데이터를 출력합니다.
		std::cout << t->key;
		// 왼쪽 노드도 출력해줍니다.
		printTree(head, t->left, level + 1);
	}
	else {
		return;
	}
}


//이진트리 삭제 알고리즘
void TreeDelete(struct node* head, int xkey) {
	struct node* p, * c, * t, * x;
	p = head;
	x = TreeSearch(head, xkey);
	if (x == NULL) {
		std::cout << "\n삭제할 숫자가 트리에 존재하지 않습니다. " << std::endl;
		return;
	}
	else {
		t = x;
	}
	
	if (t->right == NULL) {//왼쪽  자식만 있음
		x->key = t->left->key;
		free(t->left);
		t->left = NULL;
		return;
	}
	else if (t->right->left == NULL){//오른쪽 자식 있음 + 오른쪽 자식의 왼쪽 자식 없음
		x->key = t->right->key;//값 옮겨옴
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
		x->key = c->left->key;//값 옮겨옴
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
	std::cout << "숫자입력: ";
	std::cin >> num;
	struct node* head;
	head = (struct node*)malloc(sizeof * head);
	head = TreeInit(num);
	int tmp = 1;
	while (1) {
		printTree(head,head,1);
		std::cout << "\n\n삽입 : 1   삭제 : 2    >> ";
		std::cin >> tmp;
		if (tmp == 1) {
			std::cout << "\n 삽입할 숫자 입력: ";
			std::cin >> num;
			TreeInsert(head, num);
		}
		else if (tmp == 2) {
			std::cout << "\n 삭제할 숫자 입력 : ";
			std::cin >> num;
			TreeDelete(head, num);
		}
	}

}