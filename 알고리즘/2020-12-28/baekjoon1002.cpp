#include <iostream>
#include <cmath>
#include <algorithm>

double cal_d(double x1, double y1, double x2, double y2) {
	
	std::cout << x1 << y1 << x2 << y2 << std::endl;
	std::cout << x1 - y1 << std::endl;
	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	std::cout << pow(x1 - x2, 2) + pow(x2 - y2, 2) << std::endl;
	return d;
}



int main(void) {

	double x1, y1, r1, x2, y2, r2 = 0;
	double d = 0;
	int count = 0;
	std::cin >> count;
	double* res = new double[count];
	for (int i = 0; i < count; i++) {
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = cal_d(x1, y1, x2, y2);
		std::cout << "d : " << d << std::endl;
		if (d == 0)
			if (r1 == r2) {
				res[i] = -1;
				continue;
			}
			else {
				res[i] = 0;
				continue;
			}
		else {
			double plus = r1 + r2;
			if (d == plus) {
				res[i] = 1;
				continue;
			}
			else if(d > plus){
				res[i] = 0;
				continue;
			}
			else {
				if (d + std::min(r1, r2) < std::max(r1, r2)) {
					res[i] = 0;
					continue;
				}
				else if (d + std::min(r1, r2) == std::max(r1, r2)) {
					res[i] = 1;
					continue;
				}
				else {
					res[i] = 2;
					continue;
				}
			}
		}
	}

	for (int i = 0; i < count; i++) {
		std::cout << res[i] << std::endl;
	}
	
	delete [] res;
}