#include <iostream>

int main() {

	int N, len, cnt = 0, N_min, M, tmp;
	std::cin >> N;
	len = N;


	// 자리수 구하기
	while (len !=0 ) {
		len = len / 10;
		cnt++;
	}

	// 10보다 작은 경우 짝수만 해당
	if (N < 10) {
		if (N % 2 == 0) {
			std::cout << N / 2;
			return 0;
		}
		else {
			std::cout << 0;
			return 0;
		}
	}

	//가장 작은수부터 시작
	N_min = N - 9 * cnt;

	//std::cout << "N_min = " << N_min << std::endl;

	while (N_min < N) {
		M = N_min;
		tmp = N_min;
		//std::cout << "N_min : " << N_min << std::endl;
		while (tmp != 0) {
			//std::cout << "tmp = " << tmp << std::endl;
			M += tmp % 10;
			tmp = tmp / 10;
		}
		//std::cout << "M = " << M << std::endl;
		if (N == M) { 
			//std::cout << "N_min : " << N_min << " M : " << M << std::endl;
			std::cout << N_min;
			return 0; 
		}
		else {
			N_min++;
		}
	}

	// N보다 커질경우 분해합되는경우 아님. 
	std::cout << 0;

	return 0;


}
