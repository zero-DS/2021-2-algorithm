#include <stdio.h>
#pragma warning (disable : 4996)

void Josephus(int n, int k);
int list[5005] = { 0, };

int main() {
	int N, K1, K2;
	printf("��� �ο��� �� ���ΰ���?: ");
	scanf("%d", &N);
	printf("\n���� ������ Constant Factor�� ���ΰ���?: ");
	scanf("%d", &K1);
	printf("\n�ָ� ������ Constant Factor�� ���ΰ���?: ");
	scanf("%d", &K2);
	printf("\n���� ���� ����Ʈ�Դϴ�\n");
	Josephus(N, K1);
	printf("\n�ָ� ���� ����Ʈ�Դϴ�\n");
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
