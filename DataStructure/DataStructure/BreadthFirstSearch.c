#include <stdio.h>

#define MAX 7
int queue[MAX];
int rear = -1, front = 0;

void add(int item){
	if (rear >= MAX){
		printf("Queue is Full!\n");
		return;
	}
	queue[++rear] = item;
}

int del(){
	if (front > rear) return -1;
	return queue[front++];
}

void BreadthFirstSearch(char v[], int a[][MAX]){
	int searchOk[MAX] = { 0, };
	int i, j;
	char ch;

	printf("시작 정점(A ~ G 중 입력) :");
	scanf_s("%c", &ch, 1);
	for (i = 0; i < MAX; i++)
	if (ch == v[i]) break;
	printf("%c", ch);
	searchOk[i] = 1;
	while (i >= 0){
		for (j = 0; j < MAX; j++){
			if (a[i][j] == 1 && searchOk[j] == 0){
				printf(" -> %c", v[j]);
				add(j); searchOk[j] = 1;
				i = j;
				break;
			}
		}
		if (j == MAX)i = del();
	}printf("\n\n");
}


int main(void){
	int i, j;
	char v[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int a[MAX][MAX] = { { 0, 1, 1, 1, 0, 0, 0 }, { 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 0, 1, 1 }, { 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 0, 1 }, { 0, 0, 1, 1, 0, 0, 1 }, { 0, 0, 1, 0, 1, 1, 0 } };
	printf("\n\t\t인접 정점\n");
	for (i = 0; i < MAX; i++){
		for (j = 0; j < MAX; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	BreadthFirstSearch(v, a);
	return 0;
}