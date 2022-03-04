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
#define MAX 51
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Cost, L, S;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Cost > B.Cost);
	}
};

int N, M, K;
int Station[11];
vector<pair<int, int> > Edge[11][MAX];
int Cost[11][MAX];
int answer;

void Init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= Station[i]; j++) {
			Cost[i][j] = INF;
		}
	}
	answer = INF;
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Station[i];
		for (int j = 1; j <= Station[i]; j++) {
			Cost[i][j] = INF;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int P1, P2, Q1, Q2;
		cin >> P1 >> P2 >> Q1 >> Q2;
		Edge[P1][P2].push_back(make_pair(Q1, Q2));
		Edge[Q1][Q2].push_back(make_pair(P1, P2));
	}
}

void Dijkstra(int T, int U1, int U2, int V1, int V2) {
	priority_queue<INFO, vector<INFO>, COMP> PQ;
	Cost[U1][U2] = 0;
	PQ.push({ 0,U1,U2 });

	while (!PQ.empty()) {
		INFO CurInfo = PQ.top();
		PQ.pop();
		int CurCost = CurInfo.Cost;
		int L = CurInfo.L;
		int S = CurInfo.S;

		if ((L == V1) && (S == V2)) {
			answer = CurCost;
			return;
		}

		if (Cost[L][S] < CurCost) {
			continue;
		}

		int nextL, nextS;
		// 같은 노선 왼쪽
		nextL = L;
		nextS = S - 1;
		if (Cost[nextL][nextS] > CurCost + 1) {
			Cost[nextL][nextS] = CurCost + 1;
			PQ.push({ Cost[nextL][nextS],nextL,nextS });
		}

		// 같은 노선 오른쪽
		nextL = L;
		nextS = S + 1;
		if (Cost[nextL][nextS] > CurCost + 1) {
			Cost[nextL][nextS] = CurCost + 1;
			PQ.push({ Cost[nextL][nextS],nextL,nextS });
		}

		// 환승역이 존재할 때
		for (int i = 0; i < Edge[L][S].size(); i++) {
			nextL = Edge[L][S][i].first;
			nextS = Edge[L][S][i].second;
			if (Cost[nextL][nextS] > CurCost + T) {
				Cost[nextL][nextS] = CurCost + T;
				PQ.push({ Cost[nextL][nextS],nextL,nextS });
			}
		}
	};
}

void Find_Answer() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		Init();
		int T, U1, U2, V1, V2;
		cin >> T >> U1 >> U2 >> V1 >> V2;
		Dijkstra(T, U1, U2, V1, V2);
		cout << answer << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}