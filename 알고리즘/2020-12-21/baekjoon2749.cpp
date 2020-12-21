#include <stdio.h>
#include <iostream>

const int M = 1000000;


int fibo[1500000] = { 0 };// �����Լ��ȿ� ������ �迭�� �ʹ� Ŀ�� ������ �ѱ��� ����� ����

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