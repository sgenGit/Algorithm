#include <stdio.h>
// ���� ����
int main() {

}

void Bubble_Sort(int data[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (data[i] > data[i + 1]) {
				int tmp = data[i + 1];
				data[i + 1] = data[i];
				data[i] = tmp;
			}
		}
	}
}

// ���� ���� ( �������� �����شٰ� ���� )_ �����͵��� �̹� ������ �� ���� ����
void Insertion_Sort(int n, int data[]) {
	for (int i = 1; i < n; i++) {
		int tmp = data[i];
		int j = i - 1;
			while (j >= 0 && data[j] > tmp) {
				data[j+1] = data[j];
				j--;
		}

			data[j+1] = tmp;
	}
}

