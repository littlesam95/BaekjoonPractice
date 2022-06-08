#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50
#define LL long long
#define INF 1e9

using namespace std;
int T;
int N;
vector<LL> Vec;
LL Answer;

void Init() {
	Vec.clear();
	Answer = 0;
}

LL GCD(LL N, LL M) {
	while (1) {
		LL R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

void Settings() {
	sort(Vec.begin(), Vec.end(), greater<int>());
	for (int i = 0; i < Vec.size(); i++) {
		for (int j = (i + 1); j < Vec.size(); j++) {
			Answer += GCD(Vec[i], Vec[j]);
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		Init();
		cin >> N;
		for (int i = 0; i < N; i++) {
			LL I;
			cin >> I;
			Vec.push_back(I);
		}
		Settings();
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}