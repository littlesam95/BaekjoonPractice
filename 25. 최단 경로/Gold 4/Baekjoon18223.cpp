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
#define INF 1e9

using namespace std;
int V, E, P;
vector<pair<int, int> > Edge[MAX];
int Cost1[MAX];
int Cost2[MAX];
int Cost3[MAX];
stack<int> ST;
int answer1 = 0;
int answer2 = 0;
int answer3 = 0;

void Input() {
	cin >> V >> E >> P;
	for (int i = 1; i <= V; i++) {
		Cost1[i] = INF;
		Cost2[i] = INF;
		Cost3[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
}

void Dijkstra1() {
	priority_queue<pair<int, int> > PQ;
	Cost1[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (CurX == V) {
			answer1 = CurCost;
			break;
		}
		if (Cost1[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost1[nextX] > CurCost + nextCost) {
				Cost1[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost1[nextX], nextX));
			}
		}
	};
}

void Dijkstra2() {
	priority_queue<pair<int, int> > PQ;
	Cost2[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (CurX == P) {
			answer2 = CurCost;
			break;
		}
		if (Cost2[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost2[nextX] > CurCost + nextCost) {
				Cost2[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost2[nextX], nextX));
			}
		}
	};
}

void Dijkstra3() {
	priority_queue<pair<int, int> > PQ;
	Cost3[P] = 0;
	PQ.push(make_pair(0, P));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (CurX == V) {
			answer3 = CurCost;
			break;
		}
		if (Cost3[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost3[nextX] > CurCost + nextCost) {
				Cost3[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost3[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	if (answer1 == answer2 + answer3) {
		cout << "SAVE HIM" << "\n";
	}
	else {
		cout << "GOOD BYE" << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Dijkstra1();
	Dijkstra2();
	Dijkstra3();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}