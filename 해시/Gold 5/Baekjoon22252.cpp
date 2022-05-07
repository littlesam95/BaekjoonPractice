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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
LL Q, N, K, B, C;
LL IDX = 0;
string Name;
unordered_map<string, int> MAP;
priority_queue<LL> PQ[MAX];
LL Answer = 0;

void Input() {
	cin >> Q;
}

void Settings() {
	for (int i = 0; i < Q; i++) {
		cin >> N >> Name;
		if (MAP.find(Name) == MAP.end()) {
			MAP.insert(make_pair(Name, IDX++));
		}
		if (N == 1) {
			cin >> K;
			for (int j = 0; j < K; j++) {
				cin >> C;
				PQ[MAP[Name]].push(C);
			}
		}
		else if (N == 2) {
			cin >> B;
			LL Size = PQ[MAP[Name]].size();
			for (int i = 0; i < min(B, Size); i++) {
				Answer += PQ[MAP[Name]].top();
				PQ[MAP[Name]].pop();
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