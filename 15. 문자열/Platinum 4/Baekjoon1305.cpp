#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int L;
string S;
vector<int> fail;
int answer;

// 중복되는 문자의 개수(fail[L-1])를 구해서(예를 들면, aabaaa면 중복되는 문자의 개수는 2개) L에서 빼주면 그게 광고 내용이다.
void make_fail() {
	fail.clear();
	fail.resize(L, 0);
	for (int i = 1, j = 0; i < L; i++) {
		while ((j > 0) && (S[i] != S[j])) {
			j = fail[j - 1];
		};
		if (S[i] == S[j]) {
			j++;
			fail[i] = j;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L;
	cin >> S;
	make_fail();
	answer = L - fail[L - 1];
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}