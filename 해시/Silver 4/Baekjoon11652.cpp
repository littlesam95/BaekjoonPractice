#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N;
unordered_map<LL, int> MAP;
unordered_map<LL, int>::iterator IT;
LL Answer;
int Answer_Cnt = 0;

void Input() {
	cin >> N;
	while (N--) {
		LL Card;
		cin >> Card;
		MAP[Card]++;
	};
}

void Settings() {
	for (auto IT = MAP.begin(); IT != MAP.end(); IT++) {
		if (Answer_Cnt < IT->second) {
			Answer_Cnt = IT->second;
			Answer = IT->first;
		}
		else if (Answer_Cnt == IT->second) {
			if (Answer > IT->first) {
				Answer = IT->first;
			}
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}