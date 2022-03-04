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
#define MAX 5001
#define LL long long
#define INF 1e18

using namespace std;
struct INFO {
	LL Dest, Dist;
	bool T;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Dist > B.Dist);
	}
};

LL N, M, S, E;
vector<INFO> Edge[MAX];
LL Cost[MAX];
LL answer = 0;

void Input() {
	cin >> N >> M >> S >> E;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	for (LL i = 0; i < M; i++) {
		LL A, B, L;
		bool T1, T2;
		cin >> A >> B >> L >> T1 >> T2;
		Edge[A].push_back({ B,L * 2,T1 });
		Edge[B].push_back({ A,L * 2,T2 });
	}
	S *= 2;
	E *= 2;
}

LL Calc(LL A, LL L) {
	if (A < S) { // A가 퇴근 시간 전일 때
		if (S - A >= L) { // 이동해야 하는 거리 L을 퇴근 시작 전까지 이동할 수 있다면
			return L;
		}
		else { // 퇴근 시작 시간을 오버해야 한다면
			LL L1 = S - A; // 시작 시간부터 퇴근 시작 시간까지 이동한 거리
			LL L2 = L - L1; // 퇴근 시작 시간부터 이동해야 할 남은 거리
			LL T1 = E - S; // 퇴근 시간
			if ((L2 * 2) <= T1) { // 이동해야 할 남은 시간이 퇴근 시간 동안 이동할 시간 이하라면
				return (L1 + (L2 * 2));
			}
			else { // L2가 L3을 초과한다면 L3만큼 이동하고 L4만큼 이동
				return (L + (T1 / 2));
			}
		}
	}
	else if ((A >= S) && (A < E)) { // A가 퇴근 시간 안에 있을 때
		LL T1 = E - A; // 출발할 때부터 퇴근까지의 시간
		if (T1 >= (L * 2)) { // 퇴근 끝나기 전까지 충분히 이동 가능하면
			return L * 2;
		}
		else { // 퇴근이 끝나도 더 가야 한다면
			return (L + (T1 / 2));
		}
	}
	else if (A > E) { // A가 퇴근 시간 이후일 때에는 분당 1을 이동할 수 있다.
		return L;
	}
}

void Dijkstra() {
	priority_queue<pair<LL, LL> > PQ;
	Cost[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		LL CurC = -PQ.top().first;
		LL CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurC) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextC = Edge[CurX][i].Dist;
			LL nextX = Edge[CurX][i].Dest;
			bool isJam = Edge[CurX][i].T;
			if (isJam) { // 도로가 혼잡할 때
				LL newC = Calc(CurC, nextC);
				nextC = newC;
			}
			if (Cost[nextX] > CurC + nextC) {
				Cost[nextX] = CurC + nextC;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	for (int i = 2; i <= N; i++) {
		answer = max(answer, Cost[i]);
	}
	if (answer % 2 == 0) {
		cout << answer / 2 << "\n";
	}
	else {
		cout << answer / 2 << ".5\n";
	}
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