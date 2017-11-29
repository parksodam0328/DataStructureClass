#include <stdio.h>
int cnt = 0;
void QuickSort(int *a, int low, int high){
	int i, j, key, temp;
	cnt++;
	if (low < high){
		key = a[low];
		i = low;
		j = high;
		while (i < j){
			while (i < high && a[i] >= key) i++;
			while (j>low && a[j] <= key) j--; // ��������
			if (i < j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[low] = a[j];
		a[j] = key;

		QuickSort(a, low, j - 1);
		QuickSort(a, j + 1, high);
	}
	
}

int main(void){
	int a[] = { 15, 7, 2, 20, 33, 17, 26, 5};
	int i, n = sizeof(a) / sizeof(int);

	printf("���� �� : ");
	for (i = 0; i < n; i++) printf("%d	", a[i]);
	QuickSort(a, 0, n - 1);
	printf("\n�� ���� �� : ");
	for (i = 0; i < n; i++) printf("%d	", a[i]);
	printf("��� ��� : %d ", cnt);
	return 0;
}