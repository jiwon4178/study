#include <iostream>

double cal_d(int x1, int y1, int x2, int y2) {

	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	//std::cout << pow(x1 - x2, 2) + pow(x2 - y2, 2) << std::endl;
	return d;
}

int main(){

	int T, x1, y1, x2, y2, n, cx, cy, r;
	double d1, d2;
	int cnt;
	std::cin >> T;
	//std::cout << "T : " << T << std::endl;

	int* res = new int[T];
	for (int i = 0; i < T; i++) {
		cnt = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> cx >> cy >> r;
			d1 = cal_d(x1, y1, cx, cy);
			d2 = cal_d(x2, y2, cx, cy);
			if (d1 < (double)r) cnt++;
			if (d2 < (double)r) cnt++;
		}
		res[i] = cnt;
	}

	for (int i = 0; i < T; i++) {
		std::cout << res[i] << std::endl;
	}

	return 0;
}