#include <iostream>

int cnt = 0;

bool check(int* chess, int num) {
	int i;
	for (i = 0; i < num; i++) {
		if (chess[i] == chess[num]) {	//같은 열인지
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
	if (tmp == N) {	//체스판 조건만족해서 다채우는 경우
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[tmp] = i;	//일단 올림
			if (check(chess, tmp)) {	//조건확인
				count(chess, N, tmp + 1);	//맞으면 다음행으로 넘어감
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