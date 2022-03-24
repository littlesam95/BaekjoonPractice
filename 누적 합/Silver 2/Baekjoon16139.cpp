#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 200001
#define LL long long
#define INF 1e12

using namespace std;
string S;
int Q, L, R;
char Al;
int Broken[MAX];
int Sum[26][MAX];

void Settings() {
	for (int i = 0; i < 26; i++) {
		char Alpha = (char)(i + 97);
		for (int j = 0; j < S.size(); j++) {
			Sum[i][j] = Sum[i][j - 1] + ((S[j] == Alpha) ? 1 : 0);
		}
	}
}

void Find_Answer() {
	cout << Sum[Al - 'a'][R] - Sum[Al - 'a'][L - 1] << "\n";
}

void Input() {
	cin >> S;
	Settings();
	cin >> Q;
	while (Q--) {
		cin >> Al >> L >> R;
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