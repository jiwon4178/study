#include <iostream>
#define MAX(x, y) x > y ? x : y



class obj {

public:
	int num;
	int left;
	int right;
	obj() {};
	obj(int left_, int right_) {
		num = -1;
		left = left_;
		right = right_;
	}


};

void insert_data(obj**arr) {
	arr[0][0].left = 1;
	arr[0][0].right = 3;
	arr[0][1].left = 0;
	arr[0][1].right = 2;
	arr[0][2].left = 2;
	arr[0][2].right = 4;
	arr[0][3].left = 4;
	arr[0][3].right = 0;
	arr[0][4].left = 3;
	arr[0][4].right = -1;

	arr[1][0].left = 4;
	arr[1][0].right = 3;
	arr[1][1].left = 6;
	arr[1][1].right = 2;
	arr[1][2].left = 5;
	arr[1][2].right = 4;
	arr[1][3].left = 2;
	arr[1][3].right = 1;
	arr[1][4].left = 1;
	arr[1][4].right = -1;

	arr[2][0].left = 4;
	arr[2][0].right = 0;
	arr[2][1].left = 4;
	arr[2][1].right = 7;
	arr[2][2].left = 5;
	arr[2][2].right = 3;
	arr[2][3].left = 2;
	arr[2][3].right = 4;
	arr[2][4].left = 1;
	arr[2][4].right = -1;

	arr[3][0].left = 5;
	arr[3][0].right = 3;
	arr[3][1].left = 6;
	arr[3][1].right = 3;
	arr[3][2].left = 8;
	arr[3][2].right = 0;
	arr[3][3].left = 5;
	arr[3][3].right = 2;
	arr[3][4].left = 3;
	arr[3][4].right = -1;

	arr[4][0].left = -1;
	arr[4][0].right = 1;
	arr[4][1].left = -1;
	arr[4][1].right = 3;
	arr[4][2].left = -1;
	arr[4][2].right = 2;
	arr[4][3].left = -1;
	arr[4][3].right = 2;
	arr[4][4].left = -1;
	arr[4][4].right = -1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j].num = 0;
		}
	}


}


void right_line(obj** arr, int j ) {
	arr[0][j].num = arr[0][j - 1].num + arr[0][j - 1].right;
}

void left_line(obj** arr, int i) {
	arr[i][0].num = arr[i - 1][0].num + arr[i - 1][0].left;
}

void center_line(obj** arr, int i, int j) {
	arr[i][j].num = MAX(arr[i - 1][j].num + arr[i - 1][j].left, arr[i][j - 1].num + arr[i][j - 1].right);
}

void print_arr(obj** arr) {
for(int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++) {
		if (j == 4) {
			std::cout << arr[i][j].num << std::endl;
		}
		else {
			std::cout << arr[i][j].num << "  ";

		}
	}
}

void main() {
	
	obj** arr = new obj*[5];
	for (int i = 0; i < 5; i++)
		arr[i] = new obj[5];
	
	arr[0][0] = obj(1 , 2);
	
	insert_data(arr);

	print_arr(arr);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0) {
				if (j != 0) right_line(arr, j);
			}
			else if (j == 0) {
				left_line(arr, i);
			}
			else {
				center_line(arr, i, j);
			}

		}
	}

	print_arr(arr);
	
	for (int i = 0; i < 5; i++)
		delete[] arr[i];

	delete[] arr;
}
