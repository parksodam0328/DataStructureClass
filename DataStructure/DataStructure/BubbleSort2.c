#include <stdio.h>

void BubbleSort(int a[], int n){
	int i=1, j, temp,chk=1;
	while (chk==1){
		chk = 0;
		for (j = 0; j < n - i; j++){
			if (a[j]>a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				chk = 1;
			}
		}
		i++;
	}
}

int main(void){
	int a[] = { 17, 8, 20, 11, 5, 12, 15, 7 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	BubbleSort(a, n);
	printf("\n버블 정렬 후 : ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}