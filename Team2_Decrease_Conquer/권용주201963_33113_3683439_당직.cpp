#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int p, n, k, cnt, a, b, index, check;

void josephus(int N) {
	cnt = 0;
	a = 0;
	index = 0;
	int arr[5000], arr2[5000];
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	while (1) {
		b = a % n;
		if (arr[b] != 0) {
			cnt++;
			check = 0;
		}
		else
			check = 1;

		if (cnt % N == 0 && check == 0) {
			arr2[index] = arr[b];
			index++;
			arr[b] = 0;
		}
		a++;
		if (index == n)
			break;
	}
	if (n == 1)
		printf("<%d>", arr2[0]);

	else {
		for (int i = 0; i < n - 1; i++) printf("%d, ", arr2[i]);
		printf("%d\n", arr2[n - 1]);
	}
}

int main()
{
	printf("입력(사람 수, 평일당직 factor, 주말당직 factor): ");
	scanf_s("%d %d %d", &n, &k, &p);
	printf("평일당직: ");
	josephus(k);
	printf("야간당직: ");
	josephus(p);
}