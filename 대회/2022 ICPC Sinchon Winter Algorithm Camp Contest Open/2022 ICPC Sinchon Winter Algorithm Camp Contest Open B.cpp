#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
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
int N;
vector<pair<int, int> > Score[4];
bool Rating[MAX];
vector<int> Gift_List;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int X, A, B, C, D;
		cin >> X >> A >> B >> C >> D;
		Score[0].push_back(make_pair(X, A));
		Score[1].push_back(make_pair(X, B));
		Score[2].push_back(make_pair(X, C));
		Score[3].push_back(make_pair(X, D));
	}
}

bool Comp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) {
		return (A.first < B.first);
	}
	return (A.second > B.second);
}

void Settings() {
	for (int i = 0; i < 4; i++) {
		sort(Score[i].begin(), Score[i].end(), Comp);
		for (int j = 0; j < Score[i].size(); j++) {
			int CurX = Score[i][j].first;
			if (!Rating[CurX]) {
				Rating[CurX] = true;
				Gift_List.push_back(CurX);
				break;
			}
		}
	}
}

void Find_Answer() {
	for (int i = 0; i < Gift_List.size(); i++) {
		cout << Gift_List[i] << " ";
	}
	cout << "\n";
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