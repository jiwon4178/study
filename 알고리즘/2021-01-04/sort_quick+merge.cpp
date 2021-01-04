#include <iostream>

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int n;


void printArr(int arr[]) {

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int partition1(int arr[], int left, int right) {
	int value, tmp;
	int low, high;

	low = left;
	high = right + 1;
	value = arr[left];

	do {
		do {
			low++;
		} while (low <= right && arr[low] < value);
		do {
			high--;
		} while (high >= low && arr[high] > value);

		if (low < high) {
			SWAP(arr[low], arr[high], tmp);
		}
	} while (low < high);

	SWAP(arr[left], arr[high], tmp);

	return high;
}

int partition2(int arr[], int left, int right) {
	int value, tmp;
	int low, high;

	low = left;
	high = right + 1;
	value = arr[left];

	do {
		do {
			low++;
		} while (low <= right && arr[low] > value);
		do {
			high--;
		} while (high >= low && arr[high] < value);

		if (low < high) {
			SWAP(arr[low], arr[high], tmp);
		}
	} while (low < high);

	SWAP(arr[left], arr[high], tmp);

	return high;
}

void QuickSort(int arr[], int left, int right) {

	//std::cout << "되는거니 : ";
	if (left < right) {
		int k = partition1(arr, left, right);
		//std::cout << "k : " << k << std::endl;
		QuickSort(arr, left, k - 1);
		printArr(arr);
		QuickSort(arr, k + 1, right);

	}
}

void QuickSort_dsc(int arr[], int left, int right) {

	if (left < right) {
		int k = partition2(arr, left, right);
		QuickSort_dsc(arr, left, k - 1);
		printArr(arr);
		QuickSort_dsc(arr, k + 1, right);
	}
}

void Merge1(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int* b = new int[n];

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			b[k] = arr[i];
			i++;
		}
		else {
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int m = j; m <= right; m++) {
			b[k] = arr[m]; k++;
		}
	}
	else {
		for (int m = i; m <= mid; m++) {
			b[k] = arr[m]; k++;
		}
	}

	for (int m = left; m <= right; m++) {
		arr[m] = b[m];
	}

	delete[] b;
}

void Merge2(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int* b = new int[n];

	while (i <= mid && j <= right) {
		if (arr[i] >= arr[j]) {
			b[k] = arr[i];
			i++;
		}
		else {
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int m = j; m <= right; m++) {
			b[k] = arr[m]; k++;
		}
	}
	else {
		for (int m = i; m <= mid; m++) {
			b[k] = arr[m]; k++;
		}
	}

	for (int m = left; m <= right; m++) {
		arr[m] = b[m];
	}

	delete[] b;
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge1(arr, left, mid, right);
		printArr(arr);
	}
}

void MergeSort_dsc(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort_dsc(arr, left, mid);
		MergeSort_dsc(arr, mid + 1, right);
		Merge2(arr, left, mid, right);
		printArr(arr);
	}
}

void main() {

	int cnt;
	std::cout << "정렬할 원소의 개수 : ";
	std::cin >> cnt;
	n = cnt;

	int* nums1 = new int[cnt];
	int* nums2 = new int[cnt];
	int* nums3 = new int[cnt];
	int* nums4 = new int[cnt];

	int tmp = 0;
	for (int i = 0; i < cnt; i++) {
		std::cin >> tmp;
		nums1[i] = tmp;
		nums2[i] = tmp;
		nums3[i] = tmp;
		nums4[i] = tmp;
	}

	printArr(nums1);

	std::cout << "\n [퀵 정렬] \n" << std::endl;
	QuickSort(nums1, 0, cnt - 1);

	std::cout << "\n [퀵 정렬] _ 내림차순 \n" << std::endl;
	QuickSort_dsc(nums2, 0, cnt - 1);

	std::cout << "\n [병합 정렬] \n" << std::endl;
	MergeSort(nums3, 0, cnt - 1);

	std::cout << "\n [병합 정렬] _ 내림차순 \n" << std::endl;
	MergeSort_dsc(nums4, 0, cnt - 1);

	delete[] nums1;
	delete[] nums2;
	delete[] nums3;
	delete[] nums4;

}