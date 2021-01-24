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
	//left랑 right node는 비어있음.
	head->left = NULL;
	head->right = NULL;
	head->key = firstkey;
}


//이진 나무 탐색 알고리즘
struct node* TreeSearch(struct node* head, int xkey) {
	struct node* t;
	t = head->right;
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
	if (p == NULL) {

	}
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


void TreeDelete(struct node* head, int xkey) {

}
void main() {


}