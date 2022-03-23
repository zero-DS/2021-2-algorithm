#include <iostream>
#include <vector>

using namespace std;

int n, k;

void duty(vector<string> p_list, bool is_weekend) {
	string day[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" }, week_type = "Weekdays";
	int DAYS = 5;
	if (is_weekend) {
		week_type = "Weekend";
		day[0] = "Sunday"; day[1] = "Saturday";
		DAYS = 2;
	}
	vector<string> cycle;
	int i = 0;
	while (!p_list.empty()) {
		i = (i + k - 1) % p_list.size();
		cycle.push_back(p_list[i]);
		p_list.erase(p_list.begin() + i);
	}

	int loop = (cycle.size() % DAYS) ? cycle.size() * DAYS : cycle.size();
	printf("\n<%s duty cycle>\n", week_type.c_str());
	for (int i = 0; i < loop; i++) {
		printf("%s: %s | ", day[i % DAYS].c_str(), cycle[i % cycle.size()].c_str());
		if (i % DAYS == DAYS - 1) printf("\n");
	}
	printf(".\n.\n.\n\n");
}
int main()
{
	vector<string> people;
	string s;
	cout << "N: "; cin >> n;
	for (int i = 0; i < n; i++) {
		printf("person %d name: ", i + 1); cin >> s;
		people.push_back(s);
	}
	printf("Weekdays constant factor: "); cin >> k;
	duty(people, 0);
	printf("Weekend constant factor: "); cin >> k;
	duty(people, 1);
}