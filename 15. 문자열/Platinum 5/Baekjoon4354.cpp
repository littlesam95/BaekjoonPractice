#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
string S;
vector<int> fail;
int M;
int answer;

void make_fail() {
	M = S.size();
	fail.clear();
	fail.resize(M, 0);
	for (int i = 1, j = 0; i < M; i++) {
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

	while (1) {
		cin >> S;
		if (S == ".") {
			break;
		}
		make_fail();
		if (M % (M - fail[M - 1]) != 0) { // ���λ�� ���̻簡 ��� �� �� �ִ� �κй��ڿ��� �ִ� ���
			// fail[S.length() - 1] > 1�ӿ��� �ݺ��Ǵ� ���ڿ��� �������� �ʴ� ���
			answer = 1;
		}
		else {
			answer = M / (M - fail[M - 1]);
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}