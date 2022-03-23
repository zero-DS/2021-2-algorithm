#include <bits/stdc++.h>

#define WEEKDAYS 28
#define MONTH 30

using namespace std;

vector<pair<int, string>> month_list;

void jp_weekday(vector<string>& soldiers, int level)
{
	queue<int> q;
	int tmp, days = 0;
	int len = soldiers.size();

	for (int i = 0; i < len; i++) q.push(i);

	while (days<= WEEKDAYS) {
		for (int i = 0; i < level; i++) {
			days++;
			if (days > MONTH) break;

			tmp = q.front();
			month_list.push_back(make_pair(days, soldiers[tmp]));
			q.push(tmp);
			q.pop();
		}
		days += 2;
	}
	
	return;
}

void jp_weekend(vector<string>& soldiers, int level)
{
	queue<int> q;
	int tmp, days = 5;
	int len = soldiers.size();

	for (int i = 0; i < len; i++) q.push(i);

	while (days <= MONTH) {
		for (int i = 0; i < level; i++) {
			days++;
			tmp = q.front();
			month_list.push_back(make_pair(days, soldiers[tmp]));
			q.push(tmp);
			q.pop();
		}
		days += 5;
	}

	return;

}

int main()
{
	int n;
	string name;
	vector<string> soldiers;

	cout << "본 당직표는 월요일이 1일부터 시작하는 30일 달력을 기준으로 합니다" << endl;
	cout << "당직 병사들의 인원을 입력하세요(최소 7명 이상 입력해주세요): ";
	cin >> n;

	cout << "당직 병사들의 이름을 입력하세요: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 병사: ";
		cin >> name;
		soldiers.push_back(name);
	}

	jp_weekday(soldiers, 5);
	jp_weekend(soldiers, 2);

	cout << endl;
	cout << "주중 당직을 알려드리겠습니다." << endl;
	for (int i = 0; i < 22; i++) {
		if (i % 5 == 0 && i != 0) cout << endl;
		cout << month_list[i].first << "일: " << month_list[i].second << " ";
	}
	cout << endl;

	cout << endl;
	cout << "주말 당직을 알려드리겠습니다." << endl;
	for (int i = 22; i < month_list.size(); i++) {
		if (i % 2 == 0 && i != 22) cout << endl;
		cout << month_list[i].first << "일 " << month_list[i].second << " ";
	}

	return 0;
	
}