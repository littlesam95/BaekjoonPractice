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
	double Cost;
	int Portion, Here;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Cost > B.Cost);
	}
};

int N, K;
double MAP[MAX][MAX];
double Cost[MAX][MAX];
double answer = INF;

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			MAP[i][j] = (S[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			Cost[i][j] = INF;
		}
	}
}

void Dijkstra() {
	priority_queue<INFO, vector<INFO>, COMP> PQ;
	Cost[0][0] = 0;
	PQ.push({ 0,0,0 });

	while (!PQ.empty()) {
		double CurCost = PQ.top().Cost;
		int CurK = PQ.top().Portion;
		int CurX = PQ.top().Here;
		PQ.pop();

		if (Cost[CurX][CurK] < CurCost) {
			continue;
		}

		for (int i = 0; i < N; i++) {
			if (i == CurX) {
				continue;
			}
			double nextCost = MAP[CurX][i];
			// 포션을 사용
			if ((CurK < K) && (Cost[i][CurK + 1] > CurCost + (nextCost / 2))) {
				Cost[i][CurK + 1] = CurCost + (nextCost / 2);
				PQ.push({ Cost[i][CurK + 1],CurK + 1,i });
			}

			// 포션을 사용하지 않음
			if (Cost[i][CurK] > CurCost + nextCost) {
				Cost[i][CurK] = CurCost + nextCost;
				PQ.push({ Cost[i][CurK],CurK,i });
			}
		}
	};
}

void Find_Answer() {
	for (int i = 0; i <= K; i++) {
		answer = min(answer, Cost[1][i]);
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Dijkstra();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}