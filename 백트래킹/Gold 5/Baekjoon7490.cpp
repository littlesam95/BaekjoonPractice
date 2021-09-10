#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 16

using namespace std;
int T, N;
char op[3];
vector<string> answer;

void init() {
	answer.clear();
	op[0] = '+';
	op[1] = '-';
	op[2] = ' ';
}

int calc(int A, int B, int op) {
	if (op == 0) {
		return (A + B);
	}
	else if (op == 1) {
		return (A - B);
	}
}

void dfs(int X, string S) {
	if (X == N) {
		queue<string> q;
		string num = "";
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '+') {
				q.push(num);
				num = "";
				q.push("+");
			}
			else if (S[i] == '-') {
				q.push(num);
				num = "";
				q.push("-");
			}
			else if (S[i] == ' ') {
				continue;
			}
			else {
				num += S[i];
			}
		}
		q.push(num);
		int res = INT_MIN;
		int op = -1;
		while (!q.empty()) {
			string tmp = q.front();
			q.pop();
			if (tmp[0] == '+') {
				op = 0;
			}
			else if (tmp[0] == '-') {
				op = 1;
			}
			else {
				if (res == INT_MIN) {
					res = stoi(tmp);
				}
				else {
					res = calc(res, stoi(tmp), op);
				}
			}
		};
		if (res == 0) {
			answer.push_back(S);
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		string newS = S + op[i] + to_string(X + 1);
		dfs(X + 1, newS);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N;
		dfs(1, "1");
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}