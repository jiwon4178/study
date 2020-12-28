#include <iostream>
#include <algorithm>

void printArr(int arr[], int n) {
	
	for (int i = 0; i < n; i++) {
		std::cout << arr[i]<< " ";
	}
	std::cout << std::endl;
}

void SelectionSort(int arr[], int n) {

	int i, j;
	int minidx = 0;

	for (i = 0; i < n - 1; i++) {//최소값 인덱스 찾기
		minidx = i;
		for (j = i+1; j < n; j++) {	
			if (arr[j] < arr[minidx]) {
				minidx = j;
			}
		}
		if (minidx != i)
			std::swap(arr[i], arr[minidx]);
		printArr(arr, n);
	}


}

void InsertionSort(int arr[], int n) {
	//삽입정렬은 0번인덱스에 -1 있어야한다. 
	int i, j, v;
	int* newarr = new int[n + 1];	// 새로운 배열 생성
	newarr[0] = -1;
	std::swap_ranges(arr, arr + n, newarr + 1);
	for (i = 2; i <= n; i++) {
		v = newarr[i];
		j = i;
		while (newarr[j - 1] > v) {
			newarr[j] = newarr[j - 1]; j--;
		}
		newarr[j] = v;
		printArr(newarr, n+1);
	}
}

void ShellSort(int arr[], int n) {
	int h, i, j, v;
	h = 1;
	do h = 3 * h + 1; while (h < n);
	do {
		h = h / 3;
		for (i = h; i < n; i++) {
			v = arr[i];
			j = i;
			while (arr[j - h] > v) {
				arr[j] = arr[j - h];
				j -= h;
				if (j < h - 1) break;
			}
			arr[j] = v;
		}
		printArr(arr, n);
	} while (h > 1);
}

int main(void) {
	int cnt;
	std::cout << "정렬할 원소의 개수 : ";
	std::cin >> cnt;

	int* nums1 = new int[cnt];
	int* nums2 = new int[cnt];
	int* nums3 = new int[cnt];

	int tmp = 0;
	for (int i = 0; i < cnt; i++) {
		std::cin >> tmp;
		nums1[i] = tmp;
		nums2[i] = tmp;
		nums3[i] = tmp;
	}




	std::cout << "\n [선택 정렬] \n" << std::endl;
	SelectionSort(nums1, cnt);

	std::cout << "\n [삽입 정렬] \n" << std::endl;
	InsertionSort(nums2, cnt);

	std::cout << "\n [쉘 정렬] \n" << std::endl;
	ShellSort(nums3, cnt);

	delete[] nums1;
	delete[] nums2;
	delete[] nums3;
}