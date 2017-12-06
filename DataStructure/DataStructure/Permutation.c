#include <stdio.h>
#define R 3

int b[R] = { 0 };
int cnt = 0;
void printPer(){
	int i;
	for (i = 0; i < R; i++)
		printf("%3d", b[i]);
	printf("\n");
	cnt++;
}
void swap(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void Permutation(int a[], int n, int r){
	int i;
	if (r == R)
		printPer();
	else{
		for (i = r; i < n; i++){
			swap(a + r, a + i);
			b[r] = a[r];
			Permutation(a, n, r + 1);
			swap(a + r, a + i);
		}
	}
}
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(a) / sizeof(int);

	printf("%d 개 제비뽑기의 중복 순열\n", R);
	Permutation(a, n, 0);
	printf("모든 경우의 수 : %d", cnt);

	return 0;
}