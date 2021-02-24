#include <iostream>
#include <cstring>

void rabinKarp(std::string text, std::string pattern) {

	int textSize = text.size();
	int patSize = pattern.size();

	int txtHash = 0, patHash = 0;// 해시 초기화
	int D = 26; // 알파벳 기준
	int mod = 1000000009;
	int power = 1; //제곱수



	if (patSize > textSize) {	// 찾고자 하는 패턴이 주어진 txt보다 짧음
		return;
	}
	else {
		for (int i = 0; i < patSize; i++) {	//first hash value
			std::cout << "txtHash * D + text[i] " << txtHash * D + text[i] << std::endl;
			std::cout << "patHash * D + pattern[i] " << patHash * D + pattern[i] << std::endl;
			txtHash = (txtHash * D + text[i]) % mod;
			patHash = (patHash * D + pattern[i]) % mod;

			if (i < patSize -1) {	//hash값 변경시 사용할 자리수의 제곱수
				power = (power * D) % mod;
			}
		}
	}
	//여기까지 초기 해시값 설정

	std::cout << "txtHash: " << txtHash << std::endl;
	std::cout << "patHash: " << patHash << std::endl;



	//해시 검정
	for (int j = 0; j < textSize - patSize + 1; j++) {
		std::cout << "txtHash: " << txtHash << std::endl;
		//std::cout << "patHash: " << patHash << std::endl;
		if (txtHash == patHash) {//해당 위치의 hash값이랑 패턴의 hash값이 같다면 동일한 문자인지 확인
			for (int k = 0; k <= patSize; k++) {
				std::cout << "pat[" << k << "]: " << pattern[k] << std::endl;
				std::cout << "text[" << j + k << "]: " << text[j + k] << std::endl;
				std::cout << "k " << k << "patSize " << patSize << std::endl;
				if (k == patSize)
					std::cout << "패턴이 " << j+1 << "위치에서 발생" << std::endl;
				if ((int)pattern[k] != (int)text[j + k]) {					
					break;
				}
				
			}
		}
		if (j < textSize - patSize) {
			txtHash = (D * (txtHash - text[j] * power) + text[j + patSize]) % mod;
		}
		if (txtHash < 0) {
			txtHash += mod;
		}

	}




	std::cout << "txt: " << textSize;
	std::cout << "pattern: " << patSize;

}



int main() {

	std::string text = "adfabcaodlekekg";
	std::string pattern = "abcaod";

	rabinKarp(text, pattern);

}