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
#define MAX 250001
#define LL long long
#define INF 1e9

using namespace std;
LL N, W;
vector<LL> Vec[2];
LL Sum[2][MAX];
LL Answer = 0;

void Input() {
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		LL T, S;
		cin >> T >> S;
		if (T == 3) {
			Vec[0].push_back(S);
		}
		else if (T == 5) {
			Vec[1].push_back(S);
		}
	}
}

bool Comp(LL A, LL B) {
	return (A > B);
}

void Settings() {
	for (int i = 0; i < 2; i++) {
		sort(Vec[i].begin(), Vec[i].end(), Comp);
		for (int j = 0; j < Vec[i].size(); j++) {
			Sum[i][j + 1] = Sum[i][j] + Vec[i][j];
		}
	}
	for (LL i = 0; i <= (LL)Vec[0].size(); i++) {
		if ((i * 3) <= W) {
			LL Three = Sum[0][i];
			LL R = (W - (i * 3)) / 5;
			if (R <= (LL)Vec[1].size()) {
				LL Five = Sum[1][R];
				Answer = max(Answer, Three + Five);
			}
			else {
				LL Five = Sum[1][Vec[1].size()];
				Answer = max(Answer, Three + Five);
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