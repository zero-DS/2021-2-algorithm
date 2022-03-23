#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
void weekday(int num) {
	switch (num%5) {
	case 0:
		cout << "월요일";
		break;
	case 1:
		cout << "화요일";
		break;
	case 2:
		cout << "수요일";
		break;
	case 3:
		cout << "목요일";
		break;
	case 4:
		cout << "금요일";
		break;
	}
}
void holiday(int num) {
	switch (num % 2) {
	case 0:
		cout << "토요일";
		break;

	case 1:
		cout << "일요일";
		break;
	}
}
void josephus(int arr[], int n, int k) {
	int count = -1;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		q.push(i);
	}
	while (q.size() != 0) {
		count++;
		if ((count +1)%k==0) {
			arr[idx] = q.front();
			idx++;
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
}
int main(void) {
	int num;
	int wk;
	int hk;
	cout << "인원수를 입력하세요" << endl;
	cin >> num;
	cout << "평일 당직 constant factor 입력" << endl;
	cin >> wk;
	cout << "주말 당직 constant factor 입력" << endl;
	cin >> hk;
	int* weekday_order = new int[num];
	int* holiday_order = new int[num];
	josephus(weekday_order, num, wk);
	josephus(holiday_order, num, hk);
	string* emp = new string[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번째 사람의 이름 입력하세요" << endl;
		cin >> emp[i];
	}
	for (int i = 0; i < num; i++) {
		cout << i / 5 + 1 << "번째 주";
		weekday(i);
		cout << "당직은" << emp[weekday_order[i]] << endl;
	}
	cout << "=======주말 당직 순서는=======" << endl;
	for (int i = 0; i <( num / 7)*2; i++) {
		cout << i /7+1 << "번째 주";
		holiday(i);
		cout << "당직은" << emp[holiday_order[i]] << endl;
	}
	delete[](emp);
	delete[](weekday_order);
	delete[](holiday_order);
	return 0;
}