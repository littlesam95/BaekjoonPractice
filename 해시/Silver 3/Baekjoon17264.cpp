#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5
#define LL long long
#define INF 1e9

using namespace std;
int N, P, W, L, G;
unordered_map<string, int> MAP;
int Score = 0;
bool Answer = false;

void Input() {
	cin >> N >> P;
	cin >> W >> L >> G;
	for (int i = 0; i < P; i++) {
		string Name, Result;
		cin >> Name >> Result;
		if (Result == "W") {
			MAP.insert(make_pair(Name, W));
		}
		else if (Result == "L") {
			MAP.insert(make_pair(Name, -L));
		}
	}
}

void Settings() {
	for (int i = 0; i < N; i++) {
		string Name;
		cin >> Name;
		if (MAP.find(Name) != MAP.end()) {
			Score += MAP[Name];
		}
		else {
			Score -= L;
		}
		if (Score < 0) {
			Score = 0;
		}
		else if (Score >= G) {
			Answer = true;
		}
	}
}

void Find_Answer() {
	if (Answer) {
		cout << "I AM NOT IRONMAN!!\n";
	}
	else {
		cout << "I AM IRONMAN!!\n";
	}
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