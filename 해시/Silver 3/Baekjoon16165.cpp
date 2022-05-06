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
#define MAX 101
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
unordered_map<string, int> Girl_Group;
set<string> Member[MAX];
unordered_map<string, int>::iterator ITM;
set<string>::iterator ITS;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		int L;
		cin >> S;
		Girl_Group.insert(make_pair(S, i));
		cin >> L;
		for (int i = 0; i < L; i++) {
			string T;
			cin >> T;
			Member[Girl_Group[S]].insert(T);
		}
	}
}

void Settings(string S, int L) {
	if (L == 0) {
		for (auto ITS = Member[Girl_Group[S]].begin(); ITS != Member[Girl_Group[S]].end(); ITS++) {
			cout << *ITS << "\n";
		}
	}
	else if (L == 1) {
		for (auto ITM = Girl_Group.begin(); ITM != Girl_Group.end(); ITM++) {
			if (Member[Girl_Group[ITM->first]].find(S) != Member[Girl_Group[ITM->first]].end()) {
				cout << ITM->first << "\n";
				return;
			}
		}
	}
}

void Find_Answer() {
	while (M--) {
		string S;
		int L;
		cin >> S;
		cin >> L;
		Settings(S, L);
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}