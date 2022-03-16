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
int N, M;
unordered_set<string> S;
unordered_set<string>::iterator IT;

vector<string> Split(string Str) {
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == ',') {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += Str[i];
		}
	}
	res.push_back(tmp);
	return res;
}

void Input() {
	cin >> N >> M;
	while (N--) {
		string Keyword;
		cin >> Keyword;
		S.insert(Keyword);
	};
	while (M--) {
		string Keyword;
		cin >> Keyword;
		vector<string> Vec = Split(Keyword);
		for (int i = 0; i < Vec.size(); i++) {
			string Key = Vec[i];
			if (S.find(Key) != S.end()) {
				IT = S.find(Key);
				S.erase(IT);
			}
		}
		cout << S.size() << "\n";
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}