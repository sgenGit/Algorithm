// ���� Ž��
#include <string.h>
#include <stdio.h>

int sequential_search(int n, int data[], int target) {
	
	for (int i = 0; i < n; i++) {
		if (data[i] == target)
			return i;
	}
	return -1;
}


// ���� �˻�

int binary_search(char *data[], int n, char *target) {
	int begin = 0;
	int end = n-1;
	
		while(begin <= end) {
			int middle = (begin + end) / 2;

			int tmp = strcmp(target, data[middle]);
			if (tmp == 0) //ã��
				return middle;
			else if (tmp > 0) { //�̵� ���ʿ��� ã�ƺ�����
				end = middle - 1;
			}
			else
				begin = middle + 1; // �̵� �����ʿ��� ã�ƺ���
	}

		return -1;
}