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
#define MAX 11
#define LL long long
#define INF 1e9

using namespace std;
int N;
string S;
string Answer = "";

void Input() {
	cin >> N;
	cin >> S;
}

void Settings() {
	if (N <= 25) {
		Answer = S;
	}
	else {
		bool Flag = true;
		for (int i = 11; i < (N - 12); i++) {
			if (S[i] == '.') {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			Answer += S.substr(0, 11);
			Answer += "...";
			Answer += S.substr(N - 11);
		}
		else {
			Answer += S.substr(0, 9);
			Answer += "......";
			Answer += S.substr(N - 10);
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