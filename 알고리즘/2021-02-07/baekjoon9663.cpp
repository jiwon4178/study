#include <iostream>

int cnt = 0;

bool check(int* chess, int num) {
	int i;
	for (i = 0; i < num; i++) {
		if (chess[i] == chess[num]) {	//���� ������
			return false;
		}
		else if ((i - num) == chess[i] - chess[num]) {	// y = x
			return false;
		}
		else if (-(i - num) == chess[i] - chess[num]) { // y = -x
			return false;
		}
	}
	return true;
}

void count(int* chess, int N, int tmp) {
	if (tmp == N) {	//ü���� ���Ǹ����ؼ� ��ä��� ���
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[tmp] = i;	//�ϴ� �ø�
			if (check(chess, tmp)) {	//����Ȯ��
				count(chess, N, tmp + 1);	//������ ���������� �Ѿ
			}
		}
	}
}


int main() {
	int N;
	std::cin >> N;

	int* chess = new int[N];

	count(chess, N, 0);

	std::cout << cnt;


}