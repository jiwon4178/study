#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#define MIN(a,b) a<b ? a:b
#define INF 789789789;

void ascending_sort(std::vector<int>& inputVec)
{
	int tmp(0);

	for (int q = 0; q < inputVec.size() - 1; ++q) {
		for (int i = 0; i < inputVec.size() - 1; ++i) {
			if (inputVec.at(i) > inputVec.at(i + 1)) {
				tmp = inputVec.at(i);
				inputVec.at(i) = inputVec.at(i + 1);
				inputVec.at(i + 1) = tmp;
			}
		}
	}
}

void descending_sort(std::vector<int>& inputVec)
{
	int tmp(0);

	for (int q = 0; q < inputVec.size() - 1; ++q) {
		for (int i = 0; i < inputVec.size() - 1; ++i) {
			if (inputVec.at(i) < inputVec.at(i + 1)) {
				tmp = inputVec.at(i);
				inputVec.at(i) = inputVec.at(i + 1);
				inputVec.at(i + 1) = tmp;
			}
		}
	}
}

int main() {

	int num;
	std::vector <int> money;
	std::vector <int> m_count_g;
	std::string str1, s_num;
	getline(std::cin, s_num);
	num = stoi(s_num);
	getline(std::cin, str1);

	char buff1[100];
	strcpy(buff1, str1.c_str());
	char* tok1 = strtok(buff1, " ");

	while (tok1 != NULL) {
		std::string str2(tok1);

		money.insert(money.end(), stoi(str2));
		tok1 = strtok(NULL, " ");
	}

	descending_sort(money);

	for (int i = 0; i < money.size(); i++)
		std::cout << money[i] << " ";
	std::cout << "\n";
	
	int num_b = num;
	std::vector <int> count_b;

	//brute-force
	for (int i = money.size() - 1; i >= 0; i--) {
		int num_b = num;
		int tmp = -1;
		int cnt = 0;

		for (int j = i; j >= 0; j--) {
			if (num_b >= money[j]) {
				tmp = num_b / money[j];
				cnt += tmp;
				num_b %= money[j];
			}
		}
		count_b.push_back(cnt);
	}
	

	//greedy better
	int num_g = num;
	int count = 0;


	for (int i = 0; i < money.size(); i++) {
		m_count_g.push_back(num_g / money[i]);
		num_g %= money[i];
	}
	for (int j = 0; j < m_count_g.size(); j++) {
		std::cout << m_count_g[j] << "\t";
		count += m_count_g[j];
	}

	std::cout << "greedy : " << count << std::endl;





}