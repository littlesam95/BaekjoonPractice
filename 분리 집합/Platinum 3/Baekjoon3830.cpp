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
int Parent[MAX];
int Dist[MAX];

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
		Dist[i] = 0;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	int PA = Find(Parent[X]);
	Dist[X] += Dist[Parent[X]]; // Dist[Node] = (Node���� Node�� Parent������ �Ÿ�) + (Node�� Parent���� Root������ �Ÿ�)
	// Dist[Node]�� �����Ϸ���, Node�� Parent���� Root������ �Ÿ��� �����ش�.
	return Parent[X] = PA;
}

void Union(int X, int Y, int W) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX != PY) { // Y�� X���� W��ŭ �� ���ſ�Ƿ�, Y�� Parent�� X�� ����صд�.
		Dist[PY] = (-Dist[Y]) + Dist[X] + W; // �׸��� Parent�� Node�� ����� ���Ը� ����Ѵ�.
		// Y�� ���Դ� Y�� Parent�� -Dist[Y]��ŭ�� ���� ���̰� ����.
		Parent[PY] = PX;
	}
}

void Query() {
	while (M--) {
		char CMD;
		cin >> CMD;
		if (CMD == '!') {
			int A, B, W;
			cin >> A >> B >> W;
			Union(A, B, W);
		}
		else if (CMD == '?') {
			int A, B;
			cin >> A >> B;
			int PA = Find(A);
			int PB = Find(B);
			if (PA == PB) {
				cout << Dist[B] - Dist[A] << "\n";
			}
			else {
				cout << "UNKNOWN\n";
			}
		}
	};
}

void Input() {
	while (1) {
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		Init();
		Query();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}