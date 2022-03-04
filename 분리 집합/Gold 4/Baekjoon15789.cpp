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
int N, M, C, H, K;
int Parent[MAX];
int Group_Size[MAX];
bool visited[MAX];
vector<int> Vec;
int answer;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = i;
		Group_Size[i] = 1;
	}
}

int Find(int X) {	
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union_Group(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (Group_Size[P_X] >= Group_Size[P_Y]) {
		Parent[P_Y] = P_X;
		Group_Size[P_X] += Group_Size[P_Y];
	}
	else {
		Parent[P_X] = P_Y;
		Group_Size[P_Y] += Group_Size[P_X];
	}
}

bool Comp(int A, int B) {
	return (A > B);
}

void Input() {
	Init();
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (Find(A) != Find(B)) {
			Union_Group(A, B);
		}
	}
	cin >> C >> H >> K;
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		int P = Find(i);
		if ((P == Find(C)) || (P == Find(H)) || visited[P]) {
			continue;
		}
		Vec.push_back(Group_Size[P]);
		visited[P] = true;
	}
	sort(Vec.begin(), Vec.end(), Comp);
	answer = Group_Size[C];
	if (Vec.size() >= K) {
		for (int i = 0; i < K; i++) {
			answer += Vec[i];
		}
	}
	else {
		for (int i = 0; i < Vec.size(); i++) {
			answer += Vec[i];
		}
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}