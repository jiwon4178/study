#include <iostream>
#include <iostream>

int main() {

	int money;

	std::cin >> money;

	int res = 0;

	money = 1000 - money;

	while (money > 0) {
		res++;
		if (money >= 500) {
			money -= 500;
			continue;
		}
		else if (money >= 100) {
			money -= 100;
			continue;
		}
		else if (money >= 50) {
			money -= 50;
			continue;
		}
		else if (money >= 10) {
			money -= 10;
			continue;
		}
		else if (money >= 5) {
			money -= 5;
			continue;
		}
		else {
			money -= 1;
			continue;
		}
	}

	std::cout << res;
}