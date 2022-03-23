#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
void weekday(int num) {
	switch (num%5) {
	case 0:
		cout << "������";
		break;
	case 1:
		cout << "ȭ����";
		break;
	case 2:
		cout << "������";
		break;
	case 3:
		cout << "�����";
		break;
	case 4:
		cout << "�ݿ���";
		break;
	}
}
void holiday(int num) {
	switch (num % 2) {
	case 0:
		cout << "�����";
		break;

	case 1:
		cout << "�Ͽ���";
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
	cout << "�ο����� �Է��ϼ���" << endl;
	cin >> num;
	cout << "���� ���� constant factor �Է�" << endl;
	cin >> wk;
	cout << "�ָ� ���� constant factor �Է�" << endl;
	cin >> hk;
	int* weekday_order = new int[num];
	int* holiday_order = new int[num];
	josephus(weekday_order, num, wk);
	josephus(holiday_order, num, hk);
	string* emp = new string[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "��° ����� �̸� �Է��ϼ���" << endl;
		cin >> emp[i];
	}
	for (int i = 0; i < num; i++) {
		cout << i / 5 + 1 << "��° ��";
		weekday(i);
		cout << "������" << emp[weekday_order[i]] << endl;
	}
	cout << "=======�ָ� ���� ������=======" << endl;
	for (int i = 0; i <( num / 7)*2; i++) {
		cout << i /7+1 << "��° ��";
		holiday(i);
		cout << "������" << emp[holiday_order[i]] << endl;
	}
	delete[](emp);
	delete[](weekday_order);
	delete[](holiday_order);
	return 0;
}