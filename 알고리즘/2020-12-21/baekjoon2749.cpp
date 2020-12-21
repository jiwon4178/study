#include <stdio.h>
#include <iostream>

const int M = 1000000;


int fibo[1500000] = { 0 };// 메인함수안에 넣으며 배열이 너무 커서 힙으로 넘기라는 경고문구 나옴

int main() {

	long long num = 0;
	std::cin >> num;

	num %= 1500000;

	

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= num; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= M;
	}

	std::cout << fibo[num];
}