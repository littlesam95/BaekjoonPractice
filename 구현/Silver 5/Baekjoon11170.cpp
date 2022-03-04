#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1000001

using namespace std;
int T, N, M;
int MAP[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		string S = to_string(i);
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '0') {
				MAP[i]++;
			}
		}
	}
}

int main() {
	FIRST;
	init();
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int answer = 0;
		for (int i = N; i <= M; i++) {
			answer += MAP[i];
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}