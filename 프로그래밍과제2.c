#include <stdio.h>
#pragma warning (disable:4996)

int cnt = 0;
int twoSum(int* data, int N, int K, int begin, int end) {

	if (begin >= end) {
		return;
	}
	else {
		if (data[begin] + data[end] == K) {
			cnt++;
			twoSum(data, N, K, begin+1, end - 1);

		}
		else if (data[begin] + data[end] > K)
			twoSum(data, N, K, begin, end - 1);
		else 
			twoSum(data, N, K, begin+1, end);

	}
}

int main() {
	FILE* stream;
	stream = fopen("work2.txt", "r");

	int data[1000]; //데이터 배열
	int N;
	int K;
	fscanf(stream, "%d", &N);
	for (int i = 0; i < N; i++) {
		fscanf(stream, "%d", &data[i]);
	}
	fscanf(stream, "%d", &K);

	int answer;
	twoSum(data, N, K, 0, N - 1);
	printf("%d", cnt);

	fclose(stream);
}