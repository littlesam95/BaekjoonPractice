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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
vector<int> Tree[MAX];

void Input() {
	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		int A, B;
		cin >> A >> B;
		Tree[A].push_back(B);
		Tree[B].push_back(A);
	}
	cin >> Q;
}

void Find_Answer() {
	while (Q--) {
		int T, K;
		cin >> T >> K;
		if (T == 1) { // K번 정점이 단절점인가?
			if (Tree[K].size() >= 2) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		else if (T == 2) { // K번째 간선이 단절선인가?
			cout << "yes\n";
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