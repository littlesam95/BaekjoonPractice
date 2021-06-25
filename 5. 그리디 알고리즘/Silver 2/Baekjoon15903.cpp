#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<unsigned long long> card;
unsigned long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		unsigned long long number;
		cin >> number;
		card.push_back(number);
	}

	while (m--) {
		sort(card.begin(), card.end());
		unsigned long long sum = card[0] + card[1];
		card[0] = sum;
		card[1] = sum;
	};

	for (int i = 0; i < n; i++) {
		answer += card[i];
	}
	
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}