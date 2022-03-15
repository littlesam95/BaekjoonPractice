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
#define MAX 1000001
#define LL long long
#define INF 1e9

using namespace std;
string S, T;
queue<int> Q[26];
int answer = 0;

void Input() {
	cin >> S;
	cin >> T;
}

void Settings() {
	for (int i = 0; i < S.size(); i++) {
		Q[S[i] - 'a'].push(i + 1);
	}
	while (1) {
		bool Flag = true;
		for (int i = 0; i < (T.size() - 1); i++) {
			if ((Q[T[i] - 'a'].empty()) || (Q[T[i + 1] - 'a'].empty())) {
				Flag = false;
				break;
			}
			while (1) {
				if (Q[T[i] - 'a'].front() < Q[T[i + 1] - 'a'].front()) {
					Q[T[i] - 'a'].pop();
					break;
				}
				else {
					Q[T[i + 1] - 'a'].pop();
					if (Q[T[i + 1] - 'a'].empty()) {
						Flag = false;
						break;
					}
				}
			};
		}
		if (Flag) {
			if (Q[T[T.size() - 1] - 'a'].empty()) {
				Flag = false;
				break;
			}
			Q[T[T.size() - 1] - 'a'].pop();
			answer++;
		}
		else {
			break;
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