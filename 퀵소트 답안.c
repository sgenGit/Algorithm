#include <stdio.h>

// 퀵소트 :  Quick_ Sort Algorithm   ("피봇", 반반줄이기, 왼쪽 오른쪽)


void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


void quickSort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(&data[j], &data[i]);
				printf("i 가 %d 일때 \n", i);
				for (int i = 0; i < 5; i++) printf("%d ", data[i]);
				printf("\n");
			}
		}
		swap(&data[left], &data[j]);
		pivot = j;

		quickSort(left, pivot - 1, data); //왼쪽을 재귀
		printf("다음\n");
		quickSort(pivot + 1, right, data); //오른쪽을 재귀
		for (int i = 0; i < 5; i++) printf("%d ", data[i]);
		printf("\n");
	}

}

int main() {

	int arr[5] = { 5,4,3,2,1 };
	quickSort(0, 4, arr);
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

	return 0;
}