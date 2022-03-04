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
int N, M;
int A[MAX];
int Parent[MAX];
bool visited[MAX];
vector<int> Vec;
int answer = 0;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union_Country(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (A[P_X] >= A[P_Y]) {
		Parent[P_Y] = P_X;
		A[P_X] += A[P_Y];
		A[P_Y] = 0;
	}
	else {
		Parent[P_X] = P_Y;
		A[P_Y] += A[P_X];
		A[P_X] = 0;
	}
}

void Battle_Country(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (A[P_X] > A[P_Y]) {
		Parent[P_Y] = P_X;
		A[P_X] -= A[P_Y];
		A[P_Y] = 0;
	}
	else if (A[P_X] < A[P_Y]) {
		Parent[P_X] = P_Y;
		A[P_Y] -= A[P_X];
		A[P_X] = 0;
	}
	else {
		Parent[P_X] = -1;
		Parent[P_Y] = -1;
		A[P_X] = 0;
		A[P_Y] = 0;
	}
}

bool Comp(int A, int B) {
	return (A > B);
}

void Input() {
	Init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		int O, P, Q;
		cin >> O >> P >> Q;
		if (O == 1) { // O가 1이라면 P, Q 두 나라는 서로 동맹을 맺는다.
			if (Find(P) != Find(Q)) {
				Union_Country(P, Q);
			}
		}
		else if (O == 2) { // O가 2라면 P, Q 두 나라는 서로 전쟁을 한다.
			if (Find(P) != Find(Q)) {
				Battle_Country(P, Q);
			}
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		int Cur = Find(i);
		if (i == Cur) {
			answer++;
			Vec.push_back(A[Cur]);
		}
	}
	sort(Vec.begin(), Vec.end());
	cout << answer << "\n";
	for (int i = 0; i < Vec.size(); i++) {
		if (Vec[i] != 0) {
			cout << Vec[i] << " ";
		}
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}