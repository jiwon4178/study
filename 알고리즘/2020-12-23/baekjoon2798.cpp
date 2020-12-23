#include <stdio.h>
#include <iostream>



int main() {
    int num, num2, min_sum = 0, sum = 0;
    int min = 9876543219;
    int card[100] = { 0, };
    int i, j, k;
    std::cin >> num >> num2;
    for (i = 0; i < num; i++)
        std::cin >> card[i];

    for (i = 0; i < num - 2; i++) {
        for (j = i + 1; j < num - 1; j++) {
            for (k = j + 1; k < num; k++) {
                sum = card[i] + card[j] + card[k];
                if (num2 - sum < min && num2 - sum >= 0) {
                    min = num2 - sum;
                    min_sum = sum;
                }
            }
        }
    }
    std::cout << min_sum << std::endl;
}