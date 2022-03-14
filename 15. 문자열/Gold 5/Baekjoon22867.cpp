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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
struct COMP {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		if (A.first == B.first) {
			return (A.second > B.second);
		}
		return (A.first > B.first);
	}
};

struct COMP2 {
	bool operator() (pair<int, int> A, pair<int, int> B) {
		if (A.second == B.second) {
			return (A.first < B.first);
		}
		return (A.second > B.second);
	}
};

int N;
string InTime, OutTime;
priority_queue<pair<int, int>, vector<pair<int, int> >, COMP> BUS;
priority_queue<pair<int, int>, vector<pair<int, int> >, COMP2> STATION;
int Cnt = 0;
int answer = 0;

int TimeCalc(string S) {
	string Hour = S.substr(0, 2);
	string Minute = S.substr(3, 2);
	string Sec = S.substr(6, 2);
	string mSec = S.substr(9, 3);
	return ((stoi(Hour) * 3600000) + (stoi(Minute) * 60000) + (stoi(Sec) * 1000) + stoi(mSec));
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> InTime >> OutTime;
		BUS.push(make_pair(TimeCalc(InTime), TimeCalc(OutTime)));
	}
}

void Settings() {
	STATION.push(BUS.top());
	BUS.pop();
	answer++;
	Cnt++;
	while (!BUS.empty()) {
		int In = BUS.top().first;
		int Out = BUS.top().second;
		if (STATION.top().second <= In) {
			while (!STATION.empty()) {
				int Out2 = STATION.top().second;
				if (Out2 <= In) {
					STATION.pop();
					Cnt--;
				}
				else {
					break;
				}
			};
		}
		STATION.push(BUS.top());
		BUS.pop();
		Cnt++;
		answer = max(answer, Cnt);
	};
}

void Find_Answer() {
	cout << answer << "\n";
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