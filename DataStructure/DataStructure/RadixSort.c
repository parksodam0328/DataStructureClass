#include <stdio.h>
#include <stdlib.h>

void RadixSort(int a[], int n){
	int i, max = a[0], digit = 1;
	int digit_cnt[10] = { 0, };
	int *bucket = (int *)malloc(sizeof(int)*n);
	//for (i = 1; i <10; i++)digit_cnt[i] += digit_cnt[i - 1];     //오름차순 정렬
	for (i = 8; i >= 0; i--)digit_cnt[i] += digit_cnt[i + 1];      //내림차순 정렬
	while (digit <= max){
		for (i = 0; i < n; i++) digit_cnt[a[i] / digit % 10]++;
		for (i = 8; i >=0; i--) digit_cnt[i] += digit_cnt[i + 1];
		for (i = n-1; i >= 0; i--)
			bucket[--digit_cnt[a[i] / digit % 10]] = a[i];
		for (i = 0; i < n; i++) a[i] = bucket[i];
		for (i = 0; i < 10; i++) digit_cnt[i] = 0;
		digit *= 10;
	}
	free(bucket);
}

int main(void){

	int a[] = { 10, 258, 125, 3684, 50, 15, 654, 85476, 300, 525, 67, 9207, 2631, 728, 35026, 6027, 430 };
	int i, n;
	n = sizeof(a) / sizeof(int);

	RadixSort(a, n);
	printf("정렬 후 : ");
	for (i = 0; i < n; i++)
		printf("	%d", a[i]);
	printf("\n");

	return 0;
}