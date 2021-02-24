#include <stdio.h>
#pragma warning (disable : 4996)

int floor(int N, int K, int* data, int index, int high) {	
	if (index == -1)
		return 0;
	if (data[index] <= K) {
		high = data[index];
		return high;
	}
	else {
		floor(N, K, data, index - 1, high);
	}
}
int ceiling(int N, int K, int* data, int index, int low) {
	if (index == N)
		return 0;
	if (data[index] >= K) {
		low = data[index];
		return low;
	}
	else {
		ceiling(N, K, data, index + 1, low);
	}
}
int main() {
	int N, K;
	int data[1000];
	FILE* stream;
	stream = fopen("work22.txt", "r");

	fscanf(stream, "%d", &N);
	for (int i = 0; i < N; i++) {
		fscanf(stream, "%d", &data[i]);
	}
	fscanf(stream, "%d", &K);

	printf("N: %d, K: %d\n", N, K);
	for (int i = 0; i < N; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	int fl = floor(N, K, data, N - 1, 0); // 10을 리턴받음
	int ce = ceiling(N, K, data, 0, 0); // 0를 리턴받음 - > - 1 로 출력

	if (fl == 0)
		printf("-1\n");
	else
		printf("%d\n", fl);

	if (ce == 0)
		printf("-1\n");
	else
		printf("%d\n", ce);
}