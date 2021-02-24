// 순차 탐색
#include <string.h>
#include <stdio.h>

int sequential_search(int n, int data[], int target) {
	
	for (int i = 0; i < n; i++) {
		if (data[i] == target)
			return i;
	}
	return -1;
}


// 이진 검색

int binary_search(char *data[], int n, char *target) {
	int begin = 0;
	int end = n-1;
	
		while(begin <= end) {
			int middle = (begin + end) / 2;

			int tmp = strcmp(target, data[middle]);
			if (tmp == 0) //찾음
				return middle;
			else if (tmp > 0) { //미들 왼쪽에서 찾아봐야함
				end = middle - 1;
			}
			else
				begin = middle + 1; // 미들 오른쪽에서 찾아보기
	}

		return -1;
}