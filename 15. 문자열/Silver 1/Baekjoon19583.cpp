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
string S, E, Q;
int StartTime, EndTime, OutTime;
char ch[26];
string InTime, Name;
unordered_map<string, pair<int, int> > MAP;
unordered_map<string, pair<int, int> >::iterator IT;
int answer = 0;

int TimeCalc(string S) {
	string Hour = S.substr(0, 2);
	string Minute = S.substr(3, 2);
	return ((stoi(Hour) * 60) + stoi(Minute));
}

void Input() {
	cin >> S >> E >> Q;
	StartTime = TimeCalc(S);
	EndTime = TimeCalc(E);
	OutTime = TimeCalc(Q);
	cin.ignore();
	while (cin.getline(ch, 26)) {
		if (ch[0] == '\0') {
			break;
		}
		for (int i = 0; i < 5; i++) {
			InTime += ch[i];
		}
		for (int i = 6; i < 26; i++) {
			if (ch[i] == '\0') {
				break;
			}
			Name += ch[i];
		}
		if (MAP.find(Name) == MAP.end()) {
			MAP.insert(make_pair(Name, make_pair(TimeCalc(InTime), -1)));
		}
		else {
			if (MAP[Name].second == -1) {
				MAP[Name].second = TimeCalc(InTime);
			}
			else if (MAP[Name].second < EndTime) {
				MAP[Name].second = TimeCalc(InTime);
			}
		}
		InTime = "";
		Name = "";
	};
}

void Settings() {
	for (IT = MAP.begin(); IT != MAP.end(); IT++) {
		int Start = IT->second.first;
		int End = IT->second.second;
		if ((Start >= 0) && (Start <= StartTime)) {
			if ((End >= EndTime) && (End <= OutTime)) {
				answer++;
			}
		}
	}
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