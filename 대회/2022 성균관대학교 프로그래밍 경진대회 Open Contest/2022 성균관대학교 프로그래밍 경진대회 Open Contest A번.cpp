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
int N;
int A[MAX];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

void Find_Answer() {
	int IDX = 1;
	while (1) {
		int Cnt = 1;
		bool Flag = false;
		for (int i = IDX + 1; i <= N; i++) {
			if (A[IDX] != A[i]) {
				IDX = i;
				Flag = true;
				break;
			}
			Cnt++;
		}
		if (Flag) {
			for (int i = 0; i < Cnt; i++) {
				cout << IDX << " ";
			}
		}
		else {
			for (int i = 0; i < Cnt; i++) {
				cout << -1 << " ";
			}
			break;
		}
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}