#include <stdio.h>
#define R 3

int b[R] = { 0 };
int cnt = 0;
void printRePer(){
	int i;
	for (i = 0; i < R; i++)
		printf("%3d", b[i]);
		printf("\n");
		cnt++;
}
void RePermutation(int a[], int n, int r){
	int i;
	if (r == R)
		printRePer();
	else{
		for (i = 0; i < n; i++){
			b[r] = a[i];
			RePermutation(a, n, r+1);
		}
	}
}
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(a) / sizeof(int);

	printf("%d 개 주사위의 중복 순열\n", R);
	RePermutation(a, n, 0);
	printf("모든 경우의 수 : %d", cnt);

	return 0;
}