#include<stdio.h>

int InterSearch(int a[], int n, int key){
	int pos, left = 0, right = n - 1;
	while (left <= right){
		if (left == right)pos = left;
		else{
			pos = left + (right - left)*(key - a[left]) / (a[right] - a[left]);
			if (pos < left)pos = left;
			if (pos>right)pos = right;
		}
		if (key == a[pos]) return pos;
		else if (key > a[pos]) left = pos+1;
		else right = pos - 1;
	}
	return -1;
}

int main(void){
	int a[] = { 1,3,5,7,15,32,37,46,52,99 };
	int n = sizeof(a) / sizeof(int);
	int key, index;
	printf("ã�� �� : ");
	scanf_s("%d", &key);
	index = InterSearch(a, n, key);
	if (index == -1) printf("ã���� �ϴ� ������ ����!\n");
	else printf("%d���� ã��!\n", index);
	return 0;
}