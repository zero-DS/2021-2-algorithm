#include <stdio.h>
#pragma warning (disable : 4996)

void Josephus(int n, int k);
int list[5005] = { 0, };

int main() {
	int N, K1, K2;
	printf("대상 인원은 몇 명인가요?: ");
	scanf("%d", &N);
	printf("\n평일 당직의 Constant Factor는 몇인가요?: ");
	scanf("%d", &K1);
	printf("\n주말 당직의 Constant Factor는 몇인가요?: ");
	scanf("%d", &K2);
	printf("\n평일 당직 리스트입니다\n");
	Josephus(N, K1);
	printf("\n주말 당직 리스트입니다\n");
	Josephus(N, K2);
	return 0;
}
void Josephus(int n, int k) {
	int i = 0, j = 0, l = 0, m = 0;
	for (m = 0; m <= n; m++)list[m] = 0;
	printf("\n<");
	if (n == 1) {
		printf("1");
	}
	else {
		for (m = 0; m < n; m++) {
			l = 0;
			for (j = 0; j < k + l; j++) {
				i++;
				if (i > n) i = 1;
				if (list[i] != 0) {
					l++;
				}
			}
			printf("%d", i);
			if (m != n - 1) printf(", ");
			list[i] = 1;
		}
	}
	printf(">\n");
}
