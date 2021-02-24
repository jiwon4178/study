#include <iostream>
#include <cstring>

void rabinKarp(std::string text, std::string pattern) {

	int textSize = text.size();
	int patSize = pattern.size();

	int txtHash = 0, patHash = 0;// �ؽ� �ʱ�ȭ
	int D = 26; // ���ĺ� ����
	int mod = 1000000009;
	int power = 1; //������



	if (patSize > textSize) {	// ã���� �ϴ� ������ �־��� txt���� ª��
		return;
	}
	else {
		for (int i = 0; i < patSize; i++) {	//first hash value
			std::cout << "txtHash * D + text[i] " << txtHash * D + text[i] << std::endl;
			std::cout << "patHash * D + pattern[i] " << patHash * D + pattern[i] << std::endl;
			txtHash = (txtHash * D + text[i]) % mod;
			patHash = (patHash * D + pattern[i]) % mod;

			if (i < patSize -1) {	//hash�� ����� ����� �ڸ����� ������
				power = (power * D) % mod;
			}
		}
	}
	//������� �ʱ� �ؽð� ����

	std::cout << "txtHash: " << txtHash << std::endl;
	std::cout << "patHash: " << patHash << std::endl;



	//�ؽ� ����
	for (int j = 0; j < textSize - patSize + 1; j++) {
		std::cout << "txtHash: " << txtHash << std::endl;
		//std::cout << "patHash: " << patHash << std::endl;
		if (txtHash == patHash) {//�ش� ��ġ�� hash���̶� ������ hash���� ���ٸ� ������ �������� Ȯ��
			for (int k = 0; k <= patSize; k++) {
				std::cout << "pat[" << k << "]: " << pattern[k] << std::endl;
				std::cout << "text[" << j + k << "]: " << text[j + k] << std::endl;
				std::cout << "k " << k << "patSize " << patSize << std::endl;
				if (k == patSize)
					std::cout << "������ " << j+1 << "��ġ���� �߻�" << std::endl;
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