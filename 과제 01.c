#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

void pre_processing(int N, int* data, int* query_min) {

	int M = pow(N, 0.5);
	

	int x = 0;
	
		int min = 0;
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (count == 0)
				min = data[i];
			
			if (data[i] < min) {
				min = data[i];
			}
			count++;


			if (count >= M || i == N-1) { // 구간 끝남
				count = 0;
				query_min[x] = min;
				x++;
			}

		
	}

	for (int i = 0; i < x; i++) {
		printf("%d ", query_min[i]);
	}
	printf("\n");
}

int main() {

	FILE* stream;
	stream = fopen("data.txt", "r");
	int N;
	fscanf(stream, "%d", &N);
	int data[10000];
	int query_min[10000];
	for (int k = 0; k < N; k++) {
		fscanf(stream, "%d", &data[k]);
	}

	for (int k = 0; k < N; k++) {
		printf("%d ", data[k]);
	}
	printf("\n");

	int i, j;
	scanf("%d %d", &i, &j);
	
	pre_processing(N, data, query_min);
	int M = pow(N, 0.5);

	int min=999999;
	int init_G = i / M;
	int end_G = j / M;
	for (int k = i; k <= j; k++) { // k : 인덱스
		
		if (k % M == 0) { //시작 원소
			if (k + M - 1 <= j) {  // 구간최솟값 사용가능
				if (min > query_min[k / M]) {
					min = query_min[k / M];
					k += M;
				}
			}
			else {
				if (data[k] < min)
					min = data[k];
			}
		}

		else {
			if (data[k] < min)
				min = data[k];
		}
	}

	printf("최솟값 : %d", min);
	
	

	fclose(stream);
}
