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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End, Cost;
	bool isAble;
};

int N, M, K;
vector<INFO> Edge;
int Parent[MAX];
bool Flag = true;
int answer;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
	answer = 0;
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) {
		Parent[PY] = PX;
	}
	else {
		Parent[PX] = PY;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
}

bool isConnected() {
	for (int i = 2; i <= N; i++) {
		if (Find(i) != Find(1)) {
			return false;
		}
	}
	return true;
}

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int X, Y;
		cin >> X >> Y;
		Edge.push_back({ X,Y,i,true });
	}
	sort(Edge.begin(), Edge.end(), Comp);
}

void Settings() {
	int IDX = 0;
	int minCost = INF;
	for (int i = 0; i < Edge.size(); i++) {
		int C = Edge[i].Cost;
		int X = Edge[i].Start;
		int Y = Edge[i].End;
		bool isAble = Edge[i].isAble;
		if ((Find(X) != Find(Y)) && isAble) {
			if (minCost > C) {
				minCost = C;
				IDX = i;
			}
			Union(X, Y);
			answer += C;
		}
	}
	Edge[IDX].isAble = false;
}

void Find_Answer() {
	while (K--) {
		Init();
		if (!Flag) {
			cout << 0 << " ";
			continue;
		}
		Settings();
		if (isConnected()) {
			cout << answer << " ";
		}
		else {
			Flag = false;
			cout << 0 << " ";
		}
	};
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