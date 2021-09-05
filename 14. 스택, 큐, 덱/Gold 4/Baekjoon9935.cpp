#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
string S, E;
string T = "";
int last_idx;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	cin >> E;
	last_idx = E.size() - 1;
	for (int i = 0; i < S.size(); i++) {
		T += S[i];
		if (T[T.size() - 1] == E[last_idx]) {
			if (T.size() >= E.size()) {
				bool flag = true;
				int idx = 2;
				for (int j = last_idx - 1; j >= 0; j--) {
					if (T[T.size() - idx] == E[j]) {
						idx++;
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int j = 0; j < E.size(); j++) {
						T.pop_back();
					}
				}
			}
		}
	}
	if (T != "") {
		cout << T << "\n";
	}
	else {
		cout << "FRULA" << "\n";
	}

	getchar();
	getchar();
	return 0;
}