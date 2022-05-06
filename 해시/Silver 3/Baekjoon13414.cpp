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
#define MAX 500001
#define LL long long
#define INF 1e9

using namespace std;
int K, L;
unordered_map<string, int> MAP;
unordered_map<string, int>::iterator IT;
vector<pair<string, int> > Vec;

void Input() {
	cin >> K >> L;
	for (int i = 0; i < L; i++) {
		string S;
		cin >> S;
		if (MAP.find(S) == MAP.end()) {
			MAP.insert(make_pair(S, i));
		}
		else {
			MAP[S] = i;
		}
	}
}

bool Comp(pair<string, int> A, pair<string, int> B) {
	return (A.second < B.second);
}

void Settings() {
	for (auto IT = MAP.begin(); IT != MAP.end(); IT++) {
		Vec.push_back(make_pair(IT->first, IT->second));
	}
	sort(Vec.begin(), Vec.end(), Comp);
}

void Find_Answer() {
	for (int i = 0; i < min(K, (int)Vec.size()); i++) {
		cout << Vec[i].first << "\n";
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