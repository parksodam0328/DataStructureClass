#include <stdio.h>

void BubbleSort(int a[], int n){
	int i, j, temp;
	for (i = 1; i < n; i++){
		for (j = 0; j < n - i; j++){
			if (a[j]>a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main(void){
	int a[] = { 17, 8, 20, 11, 5, 12, 15, 7 };
	int i, n = sizeof(a) / sizeof(int);

	printf("���� �� : ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	BubbleSort(a, n);
	printf("\n���� ���� �� : ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}