#include <stdio.h>

int fivoSearch(int a[], int n, int key){
	int fibo[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	int pos, k = 0, index = 0;
	while (fibo[k] < n) k++;
	while (k>0){
		pos = index + fibo[k--];
		if (pos >= n || key < a[pos]);
		else if (key == a[pos]) return pos;
		else {// ã�����ϴ� ���� �����ʿ� �ִ�. (���� ��)
			index = pos;
			k--;
		}
	}
	return -1;
}

int main(void){
	int a[] = { 2, 46, 4, 78, 5, 3, 6, 8, 9, 65 };
	int n = sizeof(a) / sizeof(int);
	int index, key;
	printf("ã�� �� : ");
	scanf_s("%d", &key);
	index = fivoSearch(a, n, key);
	if (index == -1){
		printf("����\n");
	}
	else printf("%d���� ã��!\n",index);
	return 0;
	}