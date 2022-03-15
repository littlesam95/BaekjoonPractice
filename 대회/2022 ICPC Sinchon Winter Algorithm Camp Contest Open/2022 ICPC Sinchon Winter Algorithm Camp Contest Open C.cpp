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
#define INF 1e12

using namespace std;
int N, M;
deque<int> DQ;
bool QueueStack[MAX];
vector<int> Vec;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int A;
		cin >> A;
		QueueStack[i] = A;
	}
	for (int i = 1; i <= N; i++) {
		int B;
		cin >> B;
		if (!QueueStack[i]) {
			DQ.push_back(B);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int C;
		cin >> C;
		if (DQ.empty()) {
			cout << C << " ";
		}
		else {
			cout << DQ.back() << " ";
			DQ.pop_back();
			DQ.push_front(C);
		}
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}