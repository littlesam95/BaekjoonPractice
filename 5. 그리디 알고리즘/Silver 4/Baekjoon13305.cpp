#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<unsigned long long> way;
vector<unsigned long long> oil;
unsigned long long answer = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		unsigned long long number;
		cin >> number;
		way.push_back(number);
	}
	for (int i = 0; i < N; i++) {
		unsigned long long number;
		cin >> number;
		oil.push_back(number);
	}

	answer += (way[0] * oil[0]);
	unsigned long long oil_idx = 0;
	unsigned long long idx = 1;
	while (idx < N - 1) {
		if (oil[oil_idx] >= oil[idx]) {
			oil_idx = idx;
		}
		answer += (way[idx] * oil[oil_idx]);
		idx++;
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}