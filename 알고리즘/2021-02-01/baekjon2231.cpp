#include <iostream>

int main() {

	int N, len, cnt = 0, N_min, M, tmp;
	std::cin >> N;
	len = N;


	// �ڸ��� ���ϱ�
	while (len !=0 ) {
		len = len / 10;
		cnt++;
	}

	// 10���� ���� ��� ¦���� �ش�
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

	//���� ���������� ����
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

	// N���� Ŀ����� �����յǴ°�� �ƴ�. 
	std::cout << 0;

	return 0;


}
