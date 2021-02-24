#include <stdio.h>

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Quick_Sort(int* data, int first_index, int last_index) {
	int pivot_index = first_index;
	int j = pivot_index;
	int i = first_index +1;
	if (first_index < last_index) { // if문 반드시 걸어주기!!!!!!!!!!!!!!! 아니면 무한루프이다

		for (; i <= last_index; i++) { //탐색
			if (data[pivot_index] > data[i]) {
				j++;
				swap(&data[j], &data[i]);
			}
		}

		swap(&data[j], &data[pivot_index]);
		pivot_index = j;

		Quick_Sort(data, first_index, pivot_index - 1); //왼쪽 재귀
		Quick_Sort(data, pivot_index + 1, last_index); //오른쪽 재귀
	}

}


int main() {
	int data[] = { 5, 4, 2, 1, 6, 9, 7 , 0, 8 };
	Quick_Sort(data, 0, 8);

	printf("정렬후 다음과 같이 변경 되었습니다.\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", data[i]);
	}

}