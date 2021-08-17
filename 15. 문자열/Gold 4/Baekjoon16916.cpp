#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
string S, P;
int fail[MAX];
int N, M, R;
int answer = 0;

// KMP 알고리즘을 사용하여 시간 단축
void make_fail() {
	for (int i = 1, j = 0; i < N; i++) {
		while ((j > 0) && (S[i] != S[j])) {
			j = fail[j - 1];
		};
		if (S[i] == S[j]) {
			j++;
			fail[i] = j;
		}
	}
}

void kmp() {
	make_fail();
	for (int i = 0, j = 0; i < N; i++) {
		while ((j > 0) && (S[i] != P[j])) {
			j = fail[j - 1];
		};
		if (S[i] == P[j]) {
			if (j == M - 1) {
				answer++;
				break;
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	cin >> P;
	N = S.size();
	M = P.size();
	kmp();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}