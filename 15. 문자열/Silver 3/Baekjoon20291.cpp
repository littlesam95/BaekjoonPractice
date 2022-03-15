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
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int N;
string S;
unordered_map<string, int> MAP;
unordered_map<string, int>::iterator IT;
vector<pair<string, int> > Vec;

string Split(string Str) {
	string res = "";
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == '.') {
			res = "";
		}
		else {
			res += Str[i];
		}
	}
	return res;
}

void Input() {
	cin >> N;
	while (N--) {
		cin >> S;
		S = Split(S);
		MAP[S]++;
	};
}

void Settings() {
	for (IT = MAP.begin(); IT != MAP.end(); IT++) {
		string A = IT->first;
		int B = IT->second;
		Vec.push_back(make_pair(A, B));
	}
	sort(Vec.begin(), Vec.end());
}

void Find_Answer() {
	for (int i = 0; i < Vec.size(); i++) {
		cout << Vec[i].first << " " << Vec[i].second << "\n";
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