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
	if (A < S) { // A�� ��� �ð� ���� ��
		if (S - A >= L) { // �̵��ؾ� �ϴ� �Ÿ� L�� ��� ���� ������ �̵��� �� �ִٸ�
			return L;
		}
		else { // ��� ���� �ð��� �����ؾ� �Ѵٸ�
			LL L1 = S - A; // ���� �ð����� ��� ���� �ð����� �̵��� �Ÿ�
			LL L2 = L - L1; // ��� ���� �ð����� �̵��ؾ� �� ���� �Ÿ�
			LL T1 = E - S; // ��� �ð�
			if ((L2 * 2) <= T1) { // �̵��ؾ� �� ���� �ð��� ��� �ð� ���� �̵��� �ð� ���϶��
				return (L1 + (L2 * 2));
			}
			else { // L2�� L3�� �ʰ��Ѵٸ� L3��ŭ �̵��ϰ� L4��ŭ �̵�
				return (L + (T1 / 2));
			}
		}
	}
	else if ((A >= S) && (A < E)) { // A�� ��� �ð� �ȿ� ���� ��
		LL T1 = E - A; // ����� ������ ��ٱ����� �ð�
		if (T1 >= (L * 2)) { // ��� ������ ������ ����� �̵� �����ϸ�
			return L * 2;
		}
		else { // ����� ������ �� ���� �Ѵٸ�
			return (L + (T1 / 2));
		}
	}
	else if (A > E) { // A�� ��� �ð� ������ ������ �д� 1�� �̵��� �� �ִ�.
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
			if (isJam) { // ���ΰ� ȥ���� ��
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